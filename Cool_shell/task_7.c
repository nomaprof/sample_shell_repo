#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char** tokenize(char* line, int* token_count) {
    static char* tokens[BUFFER_SIZE];
    *token_count = 0;

    while (*line != '\0') {
        // Skip leading whitespace
        while (*line == ' ' || *line == '\t') {
            line++;
        }

        // Break loop if end of line
        if (*line == '\0') {
            break;
        }

        // Store the start of the token
        tokens[*token_count] = line;

        // Find the end of the token
        while (*line != ' ' && *line != '\t' && *line != '\0') {
            line++;
        }

        // Null-terminate the token and move to the next one
        if (*line != '\0') {
            *line = '\0';
            line++;
        }

        (*token_count)++;
    }

    return tokens;
}

char* custom_getline() {
    static char buffer[BUFFER_SIZE];
    static ssize_t buffer_length = 0;
    static ssize_t buffer_index = 0;

    char* line = NULL;
    ssize_t line_length = 0;

    while (1) {
        // If the buffer is empty, read more input
        if (buffer_index >= buffer_length) {
            buffer_length = read(0, buffer, BUFFER_SIZE);
            buffer_index = 0;
        }

        // If read returns 0, it means we reached the end of input (Ctrl+D)
        if (buffer_length == 0) {
            if (line_length == 0) {
                // No input, return NULL
                return NULL;
            } else {
                // End of input, return the line
                break;
            }
        }

        // Iterate over the buffer and process each character
        while (buffer_index < buffer_length) {
            char current_char = buffer[buffer_index++];
            if (current_char == '\n') {
                // End of line, return the line
                break;
            }

            // Append the character to the line
            line = realloc(line, (line_length + 1) * sizeof(char));
            line[line_length++] = current_char;
        }

        // If we reached the end of line, break the outer loop
        if (buffer_index < buffer_length) {
            break;
        }
    }

    // Null-terminate the line
    line = realloc(line, (line_length + 1) * sizeof(char));
    line[line_length] = '\0';

    return line;
}

int main() {
    while (1) {
        printf("Enter a line: ");

        char* line = custom_getline();
        if (line == NULL) {
            break;
        }

        int token_count = 0;
        char** tokens = tokenize(line, &token_count);

        printf("Tokens:\n");
        for (int i = 0; i < token_count; i++) {
            printf("%s\n", tokens[i]);
        }

        free(line);
    }

    return 0;
}

