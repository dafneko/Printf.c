#include "printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_str(char *s)
{
	int	len;

	if (!s)
		print_str("(null)");
	len = ft_strlen(s);
	while (*s)
	{
		print_char(*s);
		s++;
	}
	return (len);
}

int	putnbr_base(long int nb, char *base)
{
	int	base_len;
	int	count;

	base_len = ft_strlen(base);
	count = 0;
	if (nb < 0 && base_len == 10)
	{
		print_char('-');
		count += putnbr_base(-nb, base);
	}
	else if (nb < 0 && base_len == 16)
	{
		count--;
		count += putnbr_base((unsigned int)nb, base);
	}
	else if (nb >= base_len)
	{
		count += putnbr_base(nb / base_len, base);
		print_char(base[nb % base_len]);
	}
	else
		print_char(base[nb % base_len]);
	return (count + 1);
}

int	print_pointer(uintptr_t ptr, char *base, int flag)
{
	int base_len;
	int count;

	if (!ptr && flag)
		return (print_str("(nil)"));
	base_len = 16;
	count = 0;
	if (flag)
	{
		print_str("0x");
		count++;
		count += print_pointer(ptr, base, 0);
	}
	else if (ptr >= base_len)
	{
		count += print_pointer(ptr / base_len, base, 0);
		print_char(base[ptr % base_len]);
	}
	else
		print_char(base[ptr % base_len]);
	return (count + 1);
}