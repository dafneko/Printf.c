/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkoca <dkoca@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:39:13 by dkoca             #+#    #+#             */
/*   Updated: 2024/01/08 16:39:16 by dkoca            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# define HEX "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"
# define DIG "0123456789"

// utils.c
int	ft_strlen(const char *s);
int	print_char(char c);
int	print_str(char *s);
int	putnbr_base(long long int nb, char *base);
int	print_pointer(uintptr_t ptr, char *base, int flag);
// printf
int	type_check(char format, va_list ap);
int	ft_printf(const char *str, ...);

#endif
