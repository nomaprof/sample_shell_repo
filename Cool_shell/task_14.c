#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define ARGUMENTS_SIZE 64

char* get_variable_value(const char* variable) {
    if (strcmp(variable, "$?") == 0) {
        // Return the exit status of the last command
        int exit_status = WEXITSTATUS(system("echo $?"));
        char* value = malloc(sizeof(char) * 16);
        snprintf(value, 16, "%d", exit_status);
        return value;
    } else if (strcmp(variable, "$$") == 0) {
        // Return the process ID
        pid_t pid = getpid();
        char* value = malloc(sizeof(char) * 16);
        snprintf(value, 16, "%d", pid);
        return value;
    } else {
        // Check if it's an environment variable
        return getenv(variable);
    }
}

void replace_variables(char* command) {
    char* token = strtok(command, " ");
    while (token != NULL) {
        if (token[0] == '$') {
            // Replace the variable with its value
            char* variable = token + 1;  // Skip the leading '$'
            char* value = get_variable_value(variable);
            if (value != NULL) {
                // Replace the token with the variable value
                memmove(token, value, strlen(value) + 1);
            } else {
                // Variable not found, replace with an empty string
                token[0] = '\0';
            }
            free(value);
        }
        token = strtok(NULL, " ");
    }
}

int execute_command(char* command) {
    // Replace variables in the command
    replace_variables(command);

    // Rest of the code...

    // Handle other commands
    printf("Executing command: %s\n", command);
    return system(command);
}

