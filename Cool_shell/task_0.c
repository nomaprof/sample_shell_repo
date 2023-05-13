#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char prompt[] = "Shell > ";
	char buffer[BUFFER_SIZE];
	char *command;
	ssize_t input_length;
	char *argv[2];

	while (1)
	{
		printf("%s", prompt);
		fflush(stdout);

		input_length = read(0, buffer, BUFFER_SIZE);

		if (input_length == 0)
		{
			break;
		}

		buffer[input_length - 1] = '\0';
		command = strtok(buffer, " ");

		if (command != NULL)
		{
			if (access(command, X_OK) == 0)
			{
				pid_t pid = fork();
				if (pid == -1)
				{
					perror("fork");
					exit(EXIT_FAILURE);
				}
				else if (pid == 0)
				{
					argv[0] = command;

					argv[1] = NULL;

					execve(command, argv, NULL);
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

