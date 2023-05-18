#include "cool_shell.h"

/* #define BUFFER_SIZE 1024 */

int main()
{
	/* char prompt[] = "Shell > "; */
	/* char buffer[BUFFER_SIZE]; */
	char **command;
	char *buffer;
	/* ssize_t input_length; */
	/* char *argv[2]; */

	while (1)
	{
		display("shell > ", STDOUT_FILENO);
		fflush(stdout);

		/* input_length = read(0, buffer, BUFFER_SIZE);

		if (input_length == 0)
		{
			break;
		}

		buffer[input_length - 1] = '\0'; */
		buffer = user_input();
		command = tokenizer(buffer);

		if (command[0] != NULL)
		{
			if (access(command[0], X_OK) == 0)
			{
				pid_t pid = fork();
				if (pid == -1)
				{
					perror("fork");
					exit(EXIT_FAILURE);
				}
				else if (pid == 0)
				{
					/* argv[0] = command; */

					/* argv[1] = NULL; */

					execve(command[0], command, NULL);
					perror("execve");
					_exit(EXIT_FAILURE);
				}
				else
				{
					waitpid(pid, NULL, 0);
				}
			}
			else
			{
			printf("Command not found\n");
			}
		}
	}

	return (0);
}

