#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

void display_prompt(void)
{
	printf("$ ");
}

void read_command(char *command)
{
	fgets(command, MAX_COMMAND_LENGTH, stdin);

	// Remove trailing newline character
	command[strcspn(command, "\n")] = '\0';
}

void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		return;
	}

	if (pid == 0)
	{
		// Child process
		if (execlp(command, command, NULL) == -1)
		{
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		// Parent process
		int status;
		waitpid(pid, &status, 0);

		if (WIFEXITED(status))
		{
			int exit_status = WEXITSTATUS(status);
			if (exit_status != 0)
				fprintf(stderr, "Command '%s' exited with status %d\n", command, exit_status);
		}
	}
}

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		display_prompt();
		read_command(command);

		if (strcmp(command, "exit") == 0)
			break;

		execute_command(command);
	}

	return 0;
}

