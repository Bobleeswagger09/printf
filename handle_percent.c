#include <unistd.h>
#include "main.h"

/**
 * handle_percent - handles percent
 *@buffer: buffer array
 *@buff_ind: buffer index
 *@count: integer pointer
 * Return: void
 */

void handle_percent(char *buffer, int *buff_ind, int *count)
{
	if (*buff_ind == BUFFER_SIZE - 1)
	{
		*count = _write_buffer(buffer, buff_ind, count);
	}
	buffer[*buff_ind] = '%';
	(*buff_ind)++;
}
