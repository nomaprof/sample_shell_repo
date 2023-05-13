#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define ARGUMENTS_SIZE 64

int main() {
    char prompt[] = "Shell > ";
    char buffer[BUFFER_SIZE];

    while (1) {
        printf("%s", prompt);

        // Read user input
        ssize_t input_length = read(0, buffer, BUFFER_SIZE);
        if (input_length == 0) {
            break;  // End of file condition (Ctrl+D)
        }

        // Parse user input
        buffer[input_length - 1] = '\0';  // Replace newline character with null character

        // Tokenize the input to get the command and arguments
        char* tokens[ARGUMENTS_SIZE];
        char* token = strtok(buffer, " ");
        int token_count = 0;
        while (token != NULL && token_count < ARGUMENTS_SIZE) {
            tokens[token_count] = token;
            token = strtok(NULL, " ");
            token_count++;
        }
        tokens[token_count] = NULL;  // Set the last element to NULL for execve

        // Execute the command
        if (token_count > 0) {
            // Check if the executable file exists in the PATH
            char* path = getenv("PATH");
            char* command_path = NULL;

            if (path != NULL) {
                // Tokenize the PATH to search for the executable file
                char* path_token = strtok(path, ":");
                while (path_token != NULL) {
                    char command[BUFFER_SIZE];
                    snprintf(command, BUFFER_SIZE, "%s/%s", path_token, tokens[0]);

                    if (access(command, X_OK) == 0) {
                        command_path = strdup(command);
                        break;
                    }

                    path_token = strtok(NULL, ":");
                }
            }

            if (command_path != NULL) {
                // Execute the command
                int ret = execve(command_path, tokens, environ);
                if (ret == -1) {
                    printf("Error executing the command\n");
                }
                free(command_path);
            } else {
                printf("Command not found\n");
            }
        }
    }

    return 0;
}

