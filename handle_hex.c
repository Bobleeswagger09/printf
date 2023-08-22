#include <unistd.h>
#include "main.h"

/**
* handle_hexadecimal - Converts an unsigned integer
* to its hexadecimal representation and adds it to the buffer
* @num: The unsigned integer to be converted to hexadecimal
* @buffer: The output buffer where the hexadecimal representation is stored
* @buff_ind: A pointer to the current index in the buffer
* @count: A pointer to the total count of characters printed
* @uppercase: prints uppercase
*/

void handle_hexadecimal(unsigned int num,
char *buffer, int *buff_ind, int *count, int uppercase)
{
	char temp_buffer[20];
	int temp_ind = 0;
	char hex_chars_lower[] = "0123456789abcdef";
	char hex_chars_upper[] = "0123456789ABCDEF";
	char *hex_chars = uppercase ? hex_chars_upper : hex_chars_lower;

	if (num == 0)
	{
		if (*buff_ind == BUFFER_SIZE - 1)
		{
			*count = _write_buffer(buffer, buff_ind, count);
		}
		buffer[*buff_ind] = '0';
		(*buff_ind)++;
		return;
	}

	do {
		temp_buffer[temp_ind++] = hex_chars[num % 16];
		num /= 16;
	} while (num > 0);

	while (temp_ind > 0)
	{
		if (*buff_ind == BUFFER_SIZE - 1)
		{
			*count = _write_buffer(buffer, buff_ind, count);
		}
		buffer[*buff_ind] = temp_buffer[--temp_ind];
		(*buff_ind)++;
	}
}
