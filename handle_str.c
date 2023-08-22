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
		handle_string("(null)", buffer, buff_ind, count);
		return;
	}
	while (*str)
	{
		if (*buff_ind == BUFFER_SIZE - 1)
		{
			*count = _write_buffer(buffer, buff_ind, count);
		}

		if (*str < 32 || *str >= 127)
		{
			buffer[(*buff_ind)++] = '\\';
			buffer[(*buff_ind)++] = 'x';
			buffer[(*buff_ind)++] = "0123456789ABCDEF"[(*str >> 4) & 0x0F];
			buffer[(*buff_ind)++] = "0123456789ABCDEF"[*str & 0x0F];
			str++;
			continue;
		}

		buffer[*buff_ind] = *str;
		(*buff_ind)++;
		str++;
	}
}
