#include <unistd.h>
#include "main.h"
/**
 * handle_string - funtion to handle a string
 *@str: constant string
 *@buffer: buffer array
 *@buff_ind: buffer index
 *@count: integer array
 * Return: void
 */

void handle_string(const char *str, char *buffer, int *buff_ind, int *count)
{
	if (str == NULL)
	{
		handle_string("(nil)", buffer, buff_ind, count);
		return;
	}
	while (*str)
	{
		if (*buff_ind == BUFFER_SIZE - 1)
		{
			*count = _write_buffer(buffer, buff_ind, count);
		}

		buffer[*buff_ind] = *str;
		(*buff_ind)++;
		str++;
	}

	if (*(str - 1) == '\0')
	{
		if (*buff_ind == BUFFER_SIZE - 1)
		{
			*count = _write_buffer(buffer, buff_ind, count);
		}
		buffer[*buff_ind] = '\\';
		(*buff_ind)++;
		buffer[*buff_ind] = '0';
		(*buff_ind)++;
	}
}
