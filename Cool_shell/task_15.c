int execute_command(char* command) {
    // Find the position of the comment symbol (#)
    char* comment_pos = strchr(command, '#');
    if (comment_pos != NULL) {
        // Null-terminate the command at the comment symbol position
        *comment_pos = '\0';
    }

    // Trim leading and trailing whitespaces from the command
    char* trimmed_command = command;
    while (*trimmed_command == ' ' || *trimmed_command == '\t') {
        trimmed_command++;
    }
    int len = strlen(trimmed_command);
    while (len > 0 && (trimmed_command[len - 1] == ' ' || trimmed_command[len - 1] == '\t')) {
        trimmed_command[--len] = '\0';
    }

    // Replace variables in the command
    replace_variables(trimmed_command);

    // Rest of the code...

    // Handle other commands
    printf("Executing command: %s\n", trimmed_command);
    return system(trimmed_command);
}

