#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define ARGUMENTS_SIZE 64

int main() 
{
    char prompt[] = "Shell > ";
    char buffer[BUFFER_SIZE];

    while (1) 
    {
        printf("%s", prompt);
        ssize_t input_length = read(0, buffer, BUFFER_SIZE);
        if (input_length == 0) 
	{
            break;
        }
        buffer[input_length - 1] = '\0';
        char* tokens[ARGUMENTS_SIZE];
        char* token = strtok(buffer, " ");
        int token_count = 0;
        while (token != NULL && token_count < ARGUMENTS_SIZE) 
	{
            tokens[token_count] = token;
            token = strtok(NULL, " ");
            token_count++;
        }
        tokens[token_count] = NULL;
        if (token_count > 0) 
	{
           
            if (access(tokens[0], X_OK) == 0) 
	    {
                int ret = execve(tokens[0], tokens, environ);
                if (ret == -1) 
		{
                    printf("Error executing the command\n");
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

