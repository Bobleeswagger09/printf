#include <unistd.h>
#include "main.h"

/**
 * handle_rot13_str - prints a rot13 string
 *@str: string constant
 *@buffer: buffer array
 *@buff_ind: buffer index
 *@count: integer pointer
 * Return: void
 */

void handle_rot13_str(const char *str, char *buffer,
		int *buff_ind, int *count)
{
	char c = *str;

	if (str == NULL)
	{
		handle_string("(nil)", buffer, buff_ind, count);
		return;
	}

	while (*str)
	{
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			if (c >= 'A' && c <= 'Z')
			{
				c = 'A' + (c - 'A' + 13) % 26;
			}
			else
			{
				c = 'a' + (c - 'a' + 13) % 26;
			}
		}
		if (c == '\0')
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
		else
		{
			if (*buff_ind == BUFFER_SIZE - 1)
			{
				*count = _write_buffer(buffer, buff_ind, count);
			}
			buffer[*buff_ind] = c;
			(*buff_ind)++;
		}

		str++;
	}
}

