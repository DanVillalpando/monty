#include "monty.h"
/***
 * Get the opcode of Monty file
 */char *op_code(void)
{
	int i = 0, j = 0;
	char *buf;
	size_t len = 20;

	buf = malloc(sizeof(char) * len);
	if (buf == NULL)
		return (NULL);

	while (line[i] == ' ')
		i++;
	while (line[i] != ' ' && line[i] != '\0')
	{
		buf[j] = line[i];
		i++;
		j++;
	}
	buf[j] = '\0';
	return (buf);
}
