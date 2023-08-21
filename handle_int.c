#include <unistd.h>
#include  "main.h"

/**
 * handle_integer - handles integers
 *@num: integer number
 *@buffer: buffer array
 *@buff_ind: buffer index
 *@count: integer pointer
 *Return: void
 */

void handle_integer(int num, char *buffer, int *buff_ind, int *count)
{

	char temp_buffer[20];
	int temp_ind = 0;
	int is_negative = 0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	do {
		temp_buffer[temp_ind++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	if (is_negative)
	{
		temp_buffer[temp_ind++] = '-';
	}

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
