#include <unistd.h>
#include "main.h"
/**
 * handle_cust_str - function to handle string.
 *@str: string constant.
 *@buffer: buffer list.
 *@buff_ind: buffer index.
 *@count: pointer to an integer.
 *Return: nothing.
 */

void handle_cust_str(const char *str, char *buffer, int *buff_ind, int *count)
{
	if (str == NULL)
	{
		handle_string("(null)", buffer, buff_ind, count);
		return;
	}

	while (*str)
	{
		if (*buff_ind == BUFFER_SIZE - 1)
		{
			*count = _write_buffer(buffer, buff_ind, count);
		}
		if (*str >= 32 && *str < 127)
		{
			buffer[*buff_ind] = *str;
			(*buff_ind)++;
		}
		else
		{
			if (*buff_ind >= BUFFER_SIZE - 3)
			{
				*count = _write_buffer(buffer, buff_ind, count);
			}
			buffer[(*buff_ind)++] = '\\';

			buffer[(*buff_ind)++] = "0123456789ABCDEF"[*str & 0x0F];
		}
		str++;
	}
}

