/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:35:46 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/19 18:35:46 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nbr_len;
	int		i;

	i = 0;
	nbr_len = ft_nbrlen(n);
	if (!(str = (char *)malloc(sizeof(char) * (nbr_len + 1))))
		return (NULL);
	if (n == -2147483648)
		return ("-2147483648\0");
	if (n == 0)
		return ("0\0");
	if (n < 0)
	{
		str[i] = '-';
		n *= -1;
		i++;
		nbr_len--;
	}
	while (nbr_len > 0)
	{
		str[nbr_len - 1] = (n % 10) + '0';
		n /= 10;
		i++;
		nbr_len--;
	}
	str[i] = '\0';
	return (str);
}
