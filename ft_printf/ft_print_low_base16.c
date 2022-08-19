/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_low_base16.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 02:54:41 by min-cho           #+#    #+#             */
/*   Updated: 2022/08/02 02:54:41 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_low_base16(unsigned int ap)
{
	int		result;

	result = 0;
	if (ap >= 16)
	{
		result += ft_print_low_base16(ap / 16);
		result += ft_print_low_base16(ap % 16);
	}
	if ((ap <= 15) && (ap >= 0))
		result += ft_print_char("0123456789abcdef"[ap % 16]);
	return (result);
}
