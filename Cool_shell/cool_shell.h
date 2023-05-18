#ifndef COOL_SHELL_H
#define COOL_SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <stdbool.h>

/* Structure declarations */

/* Alias structure to store name-value pairs */
typedef struct {
    char* name;
    char* value;
} Alias;

/* Function declarations */

/* core.c */
void process_the_file(const char* filename);

/* display.c */
void show_the_prompt();
char* gather_the_input();

/* execute.c */
int unleash_the_command(char* command);
void escape_the_shell();
void reveal_the_env();
void journey_to_the_directory(char* directory);
void summon_the_alias(int argc, char* argv[]);

/* substitution.c */
char* seek_the_variable_value(const char* variable);
void perform_the_variable_substitution(char* command);

/* helpers.c */
void eliminate_the_whitespace(char* str);
void unveil_the_error(const char* message);

/* tokenizer */
char **tokenizer(char *buffer);

/* print */
void display(char *info, int flow);

/* duplicate string */
void cpystr(char *thecopied, char *copier);

/* find string length */
int lenstr(char *str);

/* get the user input */
char *user_input();

/* reallocate memory */
void *_realloc(void *pointer, unsigned int old_ans, unsigned int new_ans);

/* convert argv into integer */
int _atoi(char *str);

/* compare two strings */
int cmpstr(char *first, char *second);

/* join two strings together */
char *catstr(char *destination, char *source);

/* get length of prefix substring */
int spnstr(char *first, char *second);

/* get length of prefix not in string */
int spnstrc(char *first, char *second);

/* get first time a character is found in a string */
char *chrstr(char *str, char *cha);

#endif /* COOL_SHELL_H */

