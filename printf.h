#ifndef PRINTFLIB_H
# define PRINTFLIB_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdarg.h>
# include <stdint.h>
#include <stdio.h>
# define HEX "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"
# define DIG "0123456789"

// generic.c
int	ft_strlen(const char *s);
int		print_char(char c);
int		print_str(char *s);
int		putnbr_base(long int nb, char *base);
int		print_pointer(uintptr_t ptr, char *base, int flag);
// printf
int type_check(char format, va_list ap);
int ft_printf(const char *str, ...);


#endif