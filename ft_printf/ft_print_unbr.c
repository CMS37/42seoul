/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:53:27 by min-cho           #+#    #+#             */
/*   Updated: 2022/07/28 20:53:27 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unbr(unsigned int ap)
{
	unsigned int	nbr;
	int			result;

	nbr = ap;
	result = 0;
	if	(nbr >= 10)
	{
		result += ft_print_nbr(nbr / 10);
		result += ft_print_nbr(nbr % 10);
	}
	if ((nbr >= 0) && (nbr <= 9))
		result += ft_print_char(nbr + '0');
	return(result);
}
