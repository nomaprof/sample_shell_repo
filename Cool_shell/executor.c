#include "cool_shell.h"

/**
 * executor - execute user commands
 * @command_now: what is the current command
 * @command_parsed: the type of command
 *
 * Return: no value
 */

void executor(char **command_now, int command_parsed)
{
	int status;
	pid_t PID;

	if (command_parsed == OUTSIDE_COMMAND || command_parsed == ROUTE_COMMAND)
	{
		PID =  fork();

		if (PID == 0)
		{
			do_the_command(command_now, command_parsed);
		}
		else
		{
			waitpid(PID, &status, 0);
			status >>= 8;
		}
	}
	else
	{
		do_the_command(command_now, command_parsed);
	}
}
