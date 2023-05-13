#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define ARGUMENTS_SIZE 64

int execute_command(char* command) {
    // Tokenize the command to get the command and arguments
    char* tokens[ARGUMENTS_SIZE];
    char* token = strtok(command, " ");
    int token_count = 0;
    while (token != NULL && token_count < ARGUMENTS_SIZE) {
        tokens[token_count] = token;
        token = strtok(NULL, " ");
        token_count++;
    }
    tokens[token_count] = NULL;  // Set the last element to NULL for execve

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
        return 0;
    }

    // Check if it's the unsetenv command
    if (token_count > 1 && strcmp(tokens[0], "unsetenv") == 0) {
        if (unsetenv(tokens[1]) == -1) {
            fprintf(stderr, "Failed to unset environment variable\n");
        }
        return 0;
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

        // Change directory
        if (chdir(directory) == -1) {
            fprintf(stderr, "Failed to change directory\n");
        }

        // Update PWD environment variable
        if (setenv("PWD", getcwd(NULL, 0), 1) == -1) {
            fprintf(stderr, "Failed to update PWD environment variable\n");
        }

        return 0;
    }

    // Handle other commands
    printf("Executing command: %s\n", command);
    return system(command);
}

int main() {
    char prompt[] = "Shell > ";
    char buffer[BUFFER_SIZE];

    while (1) {
        printf("%s", prompt);

        // Read user input
        if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
            break;  // End of file condition (Ctrl+D)
        }

        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Tokenize the input to get commands separated by semicolon
        char* command = strtok(buffer, ";");
        while (command != NULL) {
            int result = execute_command(command);

            // Tokenize the command to get commands separated by logical operators
            char* operator_token = strtok(NULL, " ");
            while (operator_token != NULL) {
                //

