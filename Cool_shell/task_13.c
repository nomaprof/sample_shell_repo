#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALIAS_NAME_LENGTH 64
#define MAX_ALIAS_VALUE_LENGTH 256

typedef struct Alias {
    char name[MAX_ALIAS_NAME_LENGTH];
    char value[MAX_ALIAS_VALUE_LENGTH];
    struct Alias* next;
} Alias;

Alias* alias_list = NULL;

void print_aliases() {
    Alias* alias = alias_list;
    while (alias != NULL) {
        printf("%s='%s'\n", alias->name, alias->value);
        alias = alias->next;
    }
}

Alias* find_alias(const char* name) {
    Alias* alias = alias_list;
    while (alias != NULL) {
        if (strcmp(alias->name, name) == 0) {
            return alias;
        }
        alias = alias->next;
    }
    return NULL;
}

void add_alias(const char* name, const char* value) {
    Alias* alias = find_alias(name);
    if (alias != NULL) {
        // Alias already exists, replace its value
        strcpy(alias->value, value);
    } else {
        // Create a new alias
        Alias* new_alias = malloc(sizeof(Alias));
        strcpy(new_alias->name, name);
        strcpy(new_alias->value, value);
        new_alias->next = alias_list;
        alias_list = new_alias;
    }
}

void remove_alias(const char* name) {
    Alias* prev_alias = NULL;
    Alias* alias = alias_list;
    while (alias != NULL) {
        if (strcmp(alias->name, name) == 0) {
            if (prev_alias != NULL) {
                prev_alias->next = alias->next;
            } else {
                alias_list = alias->next;
            }
            free(alias);
            break;
        }
        prev_alias = alias;
        alias = alias->next;
    }
}

void process_alias_command(const char* command) {
    char temp_command[MAX_ALIAS_VALUE_LENGTH];
    strcpy(temp_command, command);

    char* token = strtok(temp_command, " \t=");
    if (token == NULL) {
        // Print all aliases
        print_aliases();
        return;
    }

    // Print specific aliases
    while (token != NULL) {
        Alias* alias = find_alias(token);
        if (alias != NULL) {
            printf("%s='%s'\n", alias->name, alias->value);
        }
        token = strtok(NULL, " \t=");
    }
}

void process_assignment(const char* assignment) {
    char temp_assignment[MAX_ALIAS_VALUE_LENGTH];
    strcpy(temp_assignment, assignment);

    char* token = strtok(temp_assignment, "=");
    if (token == NULL) {
        return;
    }

    char* name = token;
    char* value = strtok(NULL, "=");

    if (value != NULL) {
        // Define or update an alias
        add_alias(name, value);
    } else {
        // Remove an alias
        remove_alias(name);
    }
}

int main() {
    char prompt[] = "Shell > ";
    char buffer[MAX_ALIAS_VALUE_LENGTH];

    while (1) {
        printf("%s", prompt);

        // Read user input
        if (fgets(buffer, MAX_ALIAS_VALUE_LENGTH, stdin) == NULL) {
            break;  // End of file condition (Ctrl+D)
        }

        // Remove trailing newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Check if it's an alias command
        if (strncmp(buffer, "alias", 5) == 0) {
            // Remove the "

