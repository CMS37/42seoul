/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 02:55:44 by min-cho           #+#    #+#             */
/*   Updated: 2022/08/02 02:55:44 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(va_list ap, char format)
{
	int	result;

	result = 0;
	if (format == 'c')
		result = ft_print_char(va_arg(ap, int));
	else if (format == 's')
		result = ft_print_string(va_arg(ap, char *));
	else if (format == 'p')
		result = ft_print_pointer(va_arg(ap, unsigned long long));
	else if (format == 'd' || format == 'i')
		result = ft_print_nbr(va_arg(ap, int));
	else if (format == 'u')
		result = ft_print_unbr(va_arg(ap, unsigned int));
	else if (format == 'x')
		result = ft_print_low_base16(va_arg(ap, unsigned int));
	else if (format == 'X')
		result = ft_print_up_base16(va_arg(ap, unsigned int));
	else if (format == '%')
		result = ft_print_char('%');
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		result;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	result = 0;
	while (format[i])
	{
		if (format[i] == '\0')
			return (0);
		if (format[i] == '%')
		{
			result += ft_check(ap, format[i + 1]);
			// if (format[i + 1] != '%')
			// 	va_arg(ap, int);
			i++;
		}
		else
			result += ft_print_char(format[i]);
		i++;
	}
	va_end(ap);
	return (result);
}
