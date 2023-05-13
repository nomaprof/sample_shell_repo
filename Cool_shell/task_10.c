#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char prompt[] = "Shell > ";
    char buffer[BUFFER_SIZE];
    char current_directory[BUFFER_SIZE];
    char previous_directory[BUFFER_SIZE];

    while (1) {
        printf("%s", prompt);

        // Read user input
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            break;  // End of file condition (Ctrl+D)
        }

        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Tokenize the input to get the command and arguments
        char* token;
        char* tokens[3];
        int token_count = 0;

        token = strtok(buffer, " ");
        while (token != NULL && token_count < 3) {
            tokens[token_count++] = token;
            token = strtok(NULL, " ");
        }

        // Check if it's the exit command
        if (token_count > 0 && strcmp(tokens[0], "exit") == 0) {
            if (token_count > 1) {
                int exit_status = atoi(tokens[1]);
                exit(exit_status);
            } else {
                exit(0);
            }
        }

        // Check if it's the setenv command
        if (token_count > 2 && strcmp(tokens[0], "setenv") == 0) {
            if (setenv(tokens[1], tokens[2], 1) == -1) {
                fprintf(stderr, "Failed to set environment variable\n");
            }
            continue;
        }

        // Check if it's the unsetenv command
        if (token_count > 1 && strcmp(tokens[0], "unsetenv") == 0) {
            if (unsetenv(tokens[1]) == -1) {
                fprintf(stderr, "Failed to unset environment variable\n");
            }
            continue;
        }

        // Check if it's the cd command
        if (token_count > 0 && strcmp(tokens[0], "cd") == 0) {
            // Determine the directory to change to
            char* directory = NULL;
            if (token_count > 1) {
                directory = tokens[1];
            } else {
                directory = getenv("HOME");
            }

            // Save the current directory for 'cd -'
            if (getcwd(previous_directory, BUFFER_SIZE) == NULL) {
                fprintf(stderr, "Failed to get current directory\n");
                continue;
            }

            // Change directory
            if (chdir(directory) == -1) {
                fprintf(stderr, "Failed to change directory\n");
                continue;
            }

            // Update PWD environment variable
            if (setenv("PWD", getcwd(current_directory, BUFFER_SIZE), 1) == -1) {
                fprintf(stderr, "Failed to update PWD environment variable\n");
            }

            // Handle 'cd -' to switch back to the previous directory
            if (strcmp(directory, "-") == 0) {
                if (chdir(previous_directory) == -1) {
                    fprintf(stderr, "Failed to change directory to previous\n");
                }

                // Update PWD environment variable
                if (setenv("PWD", getcwd(current_directory, BUFFER_SIZE), 1) == -1) {
                    fprintf(stderr, "Failed to update PWD environment variable\n");
                }
            }

            continue;
        }

        // Handle other commands
        printf("

