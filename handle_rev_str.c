#include <unistd.h>
#include "main.h"
/**
 * handle_rev_str - prints out a reversed string
 *@str: string constant
 *@buffer: buffer array
 *@buff_ind: buffer index
 *@count: integer pointer
 * Return: void
 */

void handle_rev_str(const char *str, char *buffer, int *buff_ind, int *count)
{
	int length = 0;
	int i;
	const char *temp = str;

	if (str == NULL)
	{
		handle_string("(nil)", buffer, buff_ind, count);
		return;
	}

	while (*temp)
	{
		length++;
		temp++;
	}

	for (i = length - 1; i >= 0; i--)
	{
		if (*buff_ind == BUFFER_SIZE - 1)
		{
			*count = _write_buffer(buffer, buff_ind, count);
		}
		buffer[*buff_ind] = str[i];
		(*buff_ind)++;
	}
}

