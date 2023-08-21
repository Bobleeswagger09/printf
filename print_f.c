#inlcude "main.h"

int _printf(const char *format, ...)
{
	int char_count;

	va_list augment_list;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(augment_list; format);

	while (*format)

	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_count++;
		}
		else{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == '%')
			{
				write(1, format, 1);
				char_count++;
			}

			else if (*format == 'c')
			{
				char c = va_arg(augment_list, int);
				write(1, &c, 1);
				char_count++;
			}

			else if (*format == 's')
			{
				char *str = va_aug(augment_lsit, char *);
				int str_len = 0;
				while(str[str_len] != '\0')
				{
					str_len++;
				}
				write(1, str, str_len);
				char_count += str_len;
			}
		}
		format++;
	}
	va_end(augment_list);
	return (char_count);
}

int main(){
	_printf("victor\n");
       	_printf("%c\n", 'v');
	_printf("%s\n", "String");
	_printf("%%\n");
	
	return(0);
}
