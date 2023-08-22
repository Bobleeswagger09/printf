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
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char c = *str;
	char x = c;
	int j;

	if (str == NULL)
	{
		handle_string("(nil)", buffer, buff_ind, count);
		return;
	}
	while (*str)
	{
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		{
			for (j = 0; in[j]; j++)
			{
				if (in[j] == c)
				{
					x = out[j];
					break;
				}
			}
		}
		if (x == '\0')
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
			buffer[*buff_ind] = x;
			(*buff_ind)++;
		}
		str++;
	}
}
