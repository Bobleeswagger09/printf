#include <unistd.h>
#include "main.h"

/**
* handle_char - Adds a single character to the output buffer.
* @c: The character to be added to the buffer.
* @buffer: The output buffer where the character is stored.
* @buff_ind: A pointer to the current index in the buffer.
* @count: A pointer to the total count of characters printed.
*/

void handle_char(char c, char *buffer, int *buff_ind, int *count)
{
	if (c < 32 || c >= 127)
	{
		if (*buff_ind >= BUFFER_SIZE - 4)
		{
			*count = _write_buffer(buffer, buff_ind, count);
		}
		buffer[(*buff_ind)++] = '\\';
		buffer[(*buff_ind)++] = 'x';
		buffer[(*buff_ind)++] = "0123456789ABCDEF"[(c >> 4) & 0x0F];
		buffer[(*buff_ind)++] = "0123456789ABCDEF"[c & 0x0F];
		return;
	}

	if (*buff_ind == BUFFER_SIZE - 1)
	{
		*count = _write_buffer(buffer, buff_ind, count);
	}
	buffer[*buff_ind] = c;
	(*buff_ind)++;
}
