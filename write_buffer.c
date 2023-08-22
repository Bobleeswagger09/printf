#include "main.h"
#include <unistd.h>

/**
 * _write_buffer - writes buffer to standard output.
 *@buffer: buffer room.
 *@buff_ind: buffer element.
 *@count: pointer to integer.
 *Return: void.
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
