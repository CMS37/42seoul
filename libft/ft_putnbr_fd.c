/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:01:35 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/15 20:01:35 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ftprint(int n, int fd)
{
	int	arr[10];
	int	i;

	i = 9;
	while (n > 0)
	{
		arr[i] = (n % 10 + '0');
		n /= 10;
		i--;
	}
	while (i < 10)
	{
		ft_putchar_fd(arr[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	else if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	ftprint(n, fd);
}