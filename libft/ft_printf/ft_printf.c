/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blankx <blankx@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:12:28 by brguicho          #+#    #+#             */
/*   Updated: 2023/12/30 00:46:48 by blankx           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_check_char(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p'
		|| c == 'i' || c == 'd' || c == 'x' || c == 'X' || c == 'u')
		return (1);
	return (0);
}

int	ft_print_pointer(va_list p)
{
	va_list	cpy;
	int		len;

	len = 0;
	va_copy(cpy, p);
	if (va_arg(cpy, unsigned long int) != 0)
	{
		len += ft_putstrlen("0x");
		len += ft_putnbr_basel(va_arg(p, unsigned long), "0123456789abcdef");
	}
	else
		len += ft_putstrlen("(nil)");
	va_end(cpy);
	return (len);
}

int	ft_check_flag(char c, va_list ptr)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putcharl(va_arg(ptr, int));
	else if (c == 's')
		len += ft_putstrlen(va_arg(ptr, char *));
	else if (c == 'p')
		len += ft_print_pointer(ptr);
	else if (c == 'i' || c == 'd')
		len += ft_putnbrl(va_arg(ptr, int));
	else if (c == 'u')
		len += ft_putunbrl(va_arg(ptr, unsigned int));
	else if (c == 'x')
		len += ft_putnbr_basel(va_arg(ptr, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len += ft_putnbr_basel(va_arg(ptr, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		len += ft_putcharl('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		index;
	int		len;
	char	c;

	index = 0;
	len = 0;
	va_start(ptr, format);
	while (format[index])
	{
		if (format[index] == '%' && ft_check_char(format[index + 1]))
		{
			c = format[index + 1];
			len += ft_check_flag(c, ptr);
			index++;
		}
		else
		{
			ft_putcharl(format[index]);
			len++;
		}
		index++;
	}
	va_end(ptr);
	return (len);
}
