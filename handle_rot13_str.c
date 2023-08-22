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

void handle_rot13_str(const char *str, char *buffer, int *buff_ind, int *count)
{
	char x;
	unsigned int j;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	if (str == NULL)
	{
		handle_string("(AHYY)", buffer, buff_ind, count);
		return;
	}

	while (*str)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == *str)
			{
				x = out[j];
				if (*buff_ind == BUFFER_SIZE - 1)
				{
					*count = _write_buffer(buffer, buff_ind, count);
				}
				buffer[*buff_ind] = x;
				(*buff_ind)++;
				(*count)++;
				break;
			}
		}
		if (!in[j])
		{
			x = *str;
			if (*buff_ind == BUFFER_SIZE - 1)
			{
				*count = _write_buffer(buffer, buff_ind, count);
			}
			buffer[*buff_ind] = x;
			(*buff_ind)++;
			(*count)++;
		}
		str++;
	}
}
