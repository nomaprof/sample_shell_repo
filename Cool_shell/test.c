#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Test 1: Execution of commands
    printf("Test 1: Execution of commands\n");
    system("ls");

    // Test 2: Handling of the PATH
    printf("\nTest 2: Handling of the PATH\n");
    system("/bin/ls");

    // Test 3: Error handling for non-existent command
    printf("\nTest 3: Error handling for non-existent command\n");
    system("foobar");

    // Test 4: Exit built-in command
    printf("\nTest 4: Exit built-in command\n");
    system("exit");

    // Test 5: Env built-in command
    printf("\nTest 5: Env built-in command\n");
    system("env");

    // Test 6: CD built-in command
    printf("\nTest 6: CD built-in command\n");
    system("cd /path/to/directory");

    // Test 7: CD built-in command with no argument
    printf("\nTest 7: CD built-in command with no argument\n");
    system("cd");

    // Test 8: CD built-in command with "-" argument
    printf("\nTest 8: CD built-in command with \"-\" argument\n");
    system("cd -");

    // Test 9: Alias built-in command
    printf("\nTest 9: Alias built-in command\n");
    system("alias myls='ls -l'");

    // Test 10: Variable substitution
    printf("\nTest 10: Variable substitution\n");
    system("echo $HOME");

    // Test 11: Command separator (;)
    printf("\nTest 11: Command separator (;)\n");
    system("ls; echo \"Hello, World!\"");

    // Test 12: Logical operators (&& and ||)
    printf("\nTest 12: Logical operators (&& and ||)\n");
    system("ls && echo \"Command succeeded\" || echo \"Command failed\"");

    return 0;
}

