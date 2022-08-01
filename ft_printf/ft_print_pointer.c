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
	char	*str;
	int		i;
	int		result;
	
	result = 0;
//	result += write(1, "0x", 2);
	i = 16;
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	str[i] = '\0';
	i--;
	while (ap >= 16)
	{
		str[i] = "0123456789abcdef"[ap % 16];
		ap = ap / 16;
		i--;
	}
	str[i] = "0123456789abcdef"[ap];
	i--;
	if (i > 0)
		ft_bzero(str, i);
	result += ft_print_string(str);
	free(str);
	return (result);
}
