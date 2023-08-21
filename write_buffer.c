#include "main.h"
#include <unistd.h>

/**
 * _write_buffer - writes buffer to stdout
 *@buffer: buffer array
 *@buff_ind: buffer index
 *@count: integer pointer
 *Return: void
 */

int _write_buffer(char *buffer, int *buff_ind, int *count)
{
	if (*buff_ind > 0)
	{
		*count += write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
	return (*count);
}
