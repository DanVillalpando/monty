#include "monty.h"

char *line;
/***
 * Main interpreter code
 */int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	char *opcode;
	int i, j;
	stack_t *stack = NULL;
	FILE *file;
	ssize_t read;
	size_t size;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read != -1)
	{
		line = NULL;
		size = 0;
		i = 0;
		j = 0;
		read = getline(&line, &size, file);
		line_number++;
		while (line[j] == ' ')
			j++;
		while (line[i] != '\n' && line[i] != '\0')
			i++;
		if (line[j] == '\n' || line[j] == '#')
			continue;
		line[i] = '\0';
		if (line[0] == '\0')
			break;
		opcode = op_code();
		the_func(&stack, line_number, opcode);
		free(opcode);
		free(line);
	}
	fclose(file);
	free(line);
	return (0);
}
