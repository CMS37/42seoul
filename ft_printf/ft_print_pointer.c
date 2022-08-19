/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:12:40 by min-cho           #+#    #+#             */
/*   Updated: 2022/07/28 20:12:40 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long long ap)
{
	int		result;

	result = 0;
	result += write(1, "0x", 2);
	if (ap >= 16)
	{
		result += ft_print_pointer(ap / 16);
		result += ft_print_pointer(ap % 16);
	}
	if ((ap <= 15) && (ap >= 0))
		result += ft_print_char("0123456789abcdef"[ap % 16]);
	return (result);
}
