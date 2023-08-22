#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024

int _write_buffer(char *buffer, int *buff_ind, int *count);
int _printf(const char *format, ...);
void handle_char(char c, char *buffer, int *buff_ind, int *count);
void handle_string(const char *str, char *buffer, int *buff_ind, int *count);
void handle_integer(int num, char *buffer, int *buff_ind, int *count);
void handle_binary(unsigned int num, char *buffer, int *buff_ind, int *count);
void handle_un_int(unsigned int num, char *buffer, int *buff_ind, int *count);
void handle_octal(unsigned int num, char *buffer, int *buff_ind, int *count);
void handle_hexadecimal(unsigned int num, char *buffer, int *buff_ind, int *count, int uppercase);
void handle_percent(char *buffer, int *buff_ind, int *count);
void handle_cust_str(const char *str, char *buffer, int *buff_ind, int *count);
void handle_pointer(void *ptr, char *buffer, int *buff_ind, int *count);
void handle_rev_str(const char *str, char *buffer, int *buff_ind, int *count);
void handle_rot13_str(const char *str, char *buffer, int *buff_ind, int *count);

#endif

