#include "main.h"

/**
 * main - executes the shell process
 * @argc: arguement count
 * @argv: arguement vector
 * Return: 0
 */

int main(int argc, char **argv)
{
	size_t bytes;
	ssize_t bytes_read;
	char **arguements;
	char *input;

	(void)argc;
	arguements = argv;

	while (1)
	{
		printf("%s", ">>> ");
		bytes_read = getline(&input, &bytes, stdin);

		if (bytes_read == -1)
			break;

		arguements = get_tokens(input, bytes_read, arguements);

		create_childProcess(arguements);

	}
	free(input);

	return (0);
}

/**
 * create_childProcess - creates a child process
 * @arguements: command to be executed
 * Return: void
 */

void create_childProcess(char **arguements)
{
	pid_t pid, p_pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		execute_commands(arguements);
		exit(0);
	}
	else if (pid >  0)
	{
		p_pid = waitpid(pid, *status, 0);
		if (p_pid == -1)
		{
			perror("Folk Error");
			return;
		}
	}
}
