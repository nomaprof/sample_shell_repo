#ifndef COOL_SHELL_H
#define COOL_SHELL_H

// Structure declarations

// Alias structure to store name-value pairs
typedef struct {
    char* name;
    char* value;
} Alias;

// Function declarations

// core.c
void process_the_file(const char* filename);

// display.c
void show_the_prompt();
char* gather_the_input();

// execute.c
int unleash_the_command(char* command);
void escape_the_shell();
void reveal_the_env();
void journey_to_the_directory(char* directory);
void summon_the_alias(int argc, char* argv[]);

// substitution.c
char* seek_the_variable_value(const char* variable);
void perform_the_variable_substitution(char* command);

// helpers.c
void eliminate_the_whitespace(char* str);
void unveil_the_error(const char* message);

#endif /* COOL_SHELL_H */

