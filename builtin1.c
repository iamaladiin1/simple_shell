#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1000

void change_directory(const char* new_dir) {
    char current_dir[MAX_COMMAND_LENGTH];

    // Get the current working directory
    if (getcwd(current_dir, sizeof(current_dir)) == NULL) {
        perror("getcwd");
        return;
    }

    // Change directory to the new_dir
    if (chdir(new_dir) != 0) {
        perror("chdir");
        return;
    }

    // Update the PWD environment variable
    if (setenv("PWD", new_dir, 1) != 0) {
        perror("setenv");
        return;
    }

    // Print the new working directory
    printf("%s\n", new_dir);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file '%s'\n", filename);
        return 1;
    }

    char command[MAX_COMMAND_LENGTH];
    while (fgets(command, sizeof(command), file)) {
        // Remove the newline character at the end of the command if present
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        // Check if the command is 'cd' with no arguments
        if (strcmp(command, "cd") == 0 || strcmp(command, "cd $HOME") == 0) {
            // Change to the user's home directory
            const char* home_dir = getenv("HOME");
            change_directory(home_dir);
        } else if (strcmp(command, "cd -") == 0) {
            // Change to the previous directory
            const char* prev_dir = getenv("OLDPWD");
            if (prev_dir != NULL) {
                change_directory(prev_dir);
            } else {
                printf("Error: No previous directory recorded.\n");
            }
        } else if (strncmp(command, "cd ", 3) == 0) {
            // Extract the directory from the command (skip 'cd ')
            const char* new_dir = command + 3;
            change_directory(new_dir);
        } else {
            // Execute other commands using system()
            int result = system(command);
            if (result == -1) {
                printf("Error: Failed to execute command '%s'\n", command);
            }
        }
    }

    fclose(file);

    return 0;
}

