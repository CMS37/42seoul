/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:33:21 by min-cho           #+#    #+#             */
/*   Updated: 2022/07/28 20:33:21 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int ap)
{
	long long	nbr;
	int			result;

	nbr = (long long)ap;
	result = 0;
	if (nbr < 0)
	{
		result += ft_print_char('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		result += ft_print_nbr(nbr / 10);
		result += ft_print_nbr(nbr % 10);
	}
	if ((nbr >= 0) && (nbr <= 9))
		result += ft_print_char(nbr + '0');
	return (result);
}
