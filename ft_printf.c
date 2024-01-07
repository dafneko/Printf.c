/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:03:06 by dkoca             #+#    #+#             */
/*   Updated: 2023/12/25 21:03:12 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

int	type_check(char format, va_list ap)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(ap, int));
	else if (format == 's')
		count += print_str(va_arg(ap, char *));
	else if (format == 'p')
		count += print_pointer(va_arg(ap, uintptr_t), HEX, 1);
	else if (format == 'd' || format == 'i')
		count += putnbr_base(va_arg(ap, int), DIG);
	else if (format == 'u')
		count += putnbr_base(va_arg(ap, unsigned int), DIG);
	else if (format == 'x')
		count += putnbr_base(va_arg(ap, int), HEX);
	else if (format == 'X')
	{
		count += putnbr_base(va_arg(ap, int), HEX_U);
		printf("in check = %i\n", count);
	}
	else if (format == '%')
		count += print_char('%');
	else
		count += print_char(format);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		count;

	va_start(ptr, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && *str)
		{
			count += type_check(*(++str), ptr);
			str++;
		}
		if (*str)
			count += print_char(*(str++));
	}
	va_end(ptr);
	return (count);
}

int	main(void)
{
	int count = 0;
	int mine = 0;
	char *p = "Hi";
	char *ptr = "Wow";
	// printf("Address = %p\n", p);
	// mine += ft_printf("this is mine %p\n", p);
	// count += printf("this is orig %p\n", p);
	// printf("org = %i\n", count);
	// mine += ft_printf("this is mine %X %s %i %d %u %x %c %% %p\n", 1234,"Hi", 45, 00, -10, 04, 'h', p);
	// count += printf("this is orig %X %s %i %d %u %x %c %% %p\n", 1234, "Hi", 45, 00, -10, 04, 'h', p);
	// mine += ft_printf("this is mine %X %X\n", 1234, -1234);
	// count += printf("this is orig %X %X\n", 1234, -1234);
	// mine += ft_printf("this is mine %x %x\n", 1234, -1234);
	// count += printf("this is orig %x %x\n", 1234, -1234);
	// mine += ft_printf("this is mine %p %p\n", ptr, p);
	// count += printf("this is orig %p %p\n", ptr, p);
	// mine += ft_printf("this is mine %s %s\n", "thy will be done", "42 is the best");
	// count += printf("this is orig %s %s\n", "thy will be done", "42 is the best");
	// mine += ft_printf("this is mine %i %d\n", 75385782, -88888);
	// count += printf("this is orig %i %d\n", 75385782, -88888);
	// mine += ft_printf("this is mine %u %u\n", 0001, 1164);
	// count += printf("this is orig %u %u\n", 0001, 1164);
	// mine += ft_printf("this is mine %c %c\n", 'o', 'g');
	// count += printf("this is orig %c %c\n", 'o', 'g');

	printf("mine = %i\n", mine);
	ft_printf("mine = %i\n", mine);
	printf("org = %i\n", count);
}