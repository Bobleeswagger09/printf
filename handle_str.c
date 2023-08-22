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
}
