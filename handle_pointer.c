#include <unistd.h>
#include "main.h"
/**
 * handle_pointer - handles pointer
 *@ptr: void pointer
 *@buffer: buffer array
 *@buff_ind: buffer index
 *@count: integer pointer
 * Return: void
 */

void handle_pointer(void *ptr, char *buffer, int *buff_ind, int *count)
{
	unsigned long int address = (unsigned long int)ptr;
	char temp_buffer[20];
	int temp_ind = 0;
	char hex_chars[] = "0123456789abcdef";

	do {
		temp_buffer[temp_ind++] = hex_chars[address % 16];
		address /= 16;
	} while (address > 0);

	if (*buff_ind >= BUFFER_SIZE - temp_ind - 2)
	{
		*count = _write_buffer(buffer, buff_ind, count);
	}

	buffer[(*buff_ind)++] = '0';
	buffer[(*buff_ind)++] = 'x';
	while (temp_ind > 0)
	{
		buffer[*buff_ind] = temp_buffer[--temp_ind];
		(*buff_ind)++;
	}
}

