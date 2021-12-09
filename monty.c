#include "monty.h"

/**
* error_msg - function prints error usage message
* Return: void
*/
void error_msg(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
* file_error - function prints file error message
* @str: argument supplied by main
* Return void
*/
void file_error(char *str)
{
	fprintf(stderr, "Error: Can't open file %s\n", str);
	exit(EXIT_FAILURE);
}

/**
* main - function implements the opcodes
* @argc: count of variables supplied to the program
* @argv: An array of variables supplied to the program
* Return: 0
*/
int main(int argc, char **argv)
{
	FILE *file;
	size_t len = 0;
	char *buffer = NULL;
	char *str = NULL;
	stack_t *node = NULL;
	unsigned int line_count = 1;
	int status = 0;

	global.data = 1;
	if (argc != 2)
		error_msg();
	file = fopen(argv[1], "r");
	if (!file)
		file_error(argv[1]);
	while (getline(&buffer, &len, file) != -1)
	{
		if (status)
			break;
		if (*buffer == '\n')
		{
			line_count++;
			continue;
		}
		str = strtok(buffer, " \t\n");
		if (!str || *str == '#')
		{
			line_count++;
			continue;
		}
		global.arg = strtok(NULL, " \t\n");
		op_func(&node, str, line_count);
		line_count++;
	}
	free(buffer);
	free_list(node);
	fclose(file);
	return (0);
}
