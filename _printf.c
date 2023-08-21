#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
* _printf - implementing the printf function
* @format: type of format we accept
* Return: characters to be printed
*/

int _printf(const char *format, ...) {
    int buff_ind = 0;
    int count = 0;
    char buffer[BUFFER_SIZE];

    va_list args;
    va_start(args, format);


    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    handle_char(va_arg(args, int), buffer, &buff_ind, &count);
                    break;
                case 's':
                    handle_string(va_arg(args, char*), buffer, &buff_ind, &count);
                    break;
                case 'd':
                case 'i':
                    handle_integer(va_arg(args, int), buffer, &buff_ind, &count);
                    break;
                case 'b':
                    handle_binary(va_arg(args, unsigned int), buffer, &buff_ind, &count);
                    break;
                case 'u':
                    handle_unsigned(va_arg(args, unsigned int), buffer, &buff_ind, &count);
                    break;
                case 'o':
                    handle_octal(va_arg(args, unsigned int), buffer, &buff_ind, &count);
                    break;
                case 'x':
                case 'X':
                    handle_hexadecimal(va_arg(args, unsigned int), buffer, &buff_ind, &count);
                    break;
                case '%':
                    handle_percent(buffer, &buff_ind, &count);
                    break;
                default:
                    if (buff_ind == BUFFER_SIZE - 1) {
                        count = _write_buffer(buffer, &buff_ind, &count);
                    }
                    buffer[buff_ind++] = '%';
                    buffer[buff_ind++] = *format;
                    break;
            }
        } else {
            if (buff_ind == BUFFER_SIZE - 1) {
                count = _write_buffer(buffer, &buff_ind, &count);
            }
            buffer[buff_ind++] = *format;
        }

        format++;
    }

    count = _write_buffer(buffer, &buff_ind, &count);
    va_end(args);
    return count;
}
