#include <unistd.h>
#include "main.h"

/**
* handle_hexadecimal - Converts an unsigned integer to its hexadecimal representation and adds it to the buffer.
* @num: The unsigned integer to be converted to hexadecimal.
* @buffer: The output buffer where the hexadecimal representation is stored.
* @buff_ind: A pointer to the current index in the buffer.
* @count: A pointer to the total count of characters printed.
*/

void handle_hexadecimal(unsigned int num, char *buffer, int *buff_ind, int *count) {
    char temp_buffer[20];
    int temp_ind = 0;
    char hex_chars[] = "0123456789abcdef";

    do {
        temp_buffer[temp_ind++] = hex_chars[num % 16];
        num /= 16;
    } while (num > 0);

    while (temp_ind > 0) {
        if (*buff_ind == BUFFER_SIZE - 1) {
            *count = _write_buffer(buffer, buff_ind, count);
        }
        buffer[*buff_ind] = temp_buffer[--temp_ind];
        (*buff_ind)++;
    }
}
