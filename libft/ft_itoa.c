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
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
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
	size_t	nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nbr_len = ft_nbrlen(n);
	str = (char *)malloc(sizeof(char) * (nbr_len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	str[nbr_len] = '\0';
	nbr_len--;
	while (nbr_len >= 0)
	{
		str[nbr_len] = (nbr % 10) + '0';
		nbr /= 10;
		nbr_len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main ()
{
  int i;
  char *str;

  i = -12421424;

  str = ft_itoa(i);
  printf ("%s\n",str);
  free(str);
  return 0;
}
*/