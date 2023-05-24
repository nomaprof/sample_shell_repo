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

#define BUFFER_SIZE 1024
#define ARGUMENT_SIZE 64
#define OUTSIDE_COMMAND 1
#define INSIDE_COMMAND 2
#define ROUTE_COMMAND 3
#define INCORRECT_COMMAND -1

/* Structure declarations */

/**
 * struct aliases - map aliases
 * @name: the alias
 * @value: the realcommand
 *
 * Description - contains info for alias
 */


typedef struct aliases
{
	char *name;
	char *value;
} alias;

/**
 * struct map - map command to function
 * @command_identity: internal command name
 * @func: the function for command execution
 *
 * Description - contains infor for builtins
 */

/* function mapping for builtin commands */

typedef struct map
{
	char *command_identity;
	void (*func)(char **command);
} function_map;

/* Function declarations */

/* tokenizer */
char **tokenizer(char *buffer, char *delim);

/* print */
void display(char *info, int flow);

/* duplicate string */
void cpystr(char *thecopied, char *copier);

/* find string length */
int lenstr(char *str);

/* get the user input */
extern char *user_input();

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
char *chrstr(char *str, char cha);

/* split a string into tokens */
char *mystrtok(char *str, char *delim, char **pointer);

/* reallocate memory for tokenization */
void *_realloc(void *pointer, unsigned int old_ans, unsigned int new_ans);

/* find out if the command exists in the PATH */
char *path_check(char *command);

/* what is the environment variable */
char *whichenv(char *value);

/* execute the user command */
extern void executor(char **command_now, int command_parsed);

/* piping handling */
extern void not_interacting(void);

/* get the function that executes the command */
void(*whichfunc(char *command))(char **);

/* get the type of command as whether EXTERNAL, INTERNAL, PATH, or INCORRECT */
int determine_command(char *command);

/* builtin - exit the shell */
void stop(char **elemental_command);

/* bultin - return the environment variable */
void env(char **elemental_command __attribute__((unused)));

/* exit using ctrl+c */
void exit_handler(int signalid);

/* remove all comments */
void erase_comment(char *filein);

/* remove newline */
void no_newline(char *string);

/* do the command */
void do_the_command(char **elemental_command, int command_identity);

/* get the minimum of two variables */
#define min(x, y) (((x) < (y)) ? (x) : (y))

/* define external variables */
extern char **environ;
extern char *input;
extern char **commands;
extern char *name_of_shell;
extern int status;


#endif /* COOL_SHELL_H */
