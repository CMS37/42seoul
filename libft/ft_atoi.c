/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:30:14 by min-cho           #+#    #+#             */
/*   Updated: 2022/01/15 00:30:14 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	white_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || \
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	nbr;
	int		m;
	int		i;

	nbr = 0;
	i = 0;
	m = 1;
	while (white_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
		m *= -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		nbr = (nbr * 10) + (nptr[i] - '0');
		if (nbr > 2147483647 && m == 1)
			return (-1);
		if (nbr > 2147483648 && m == -1)
			return (0);
		i++;
		if (nptr[i] < '0' || nptr[i] > '9')
			break ;
	}
	return (nbr * m);
}
