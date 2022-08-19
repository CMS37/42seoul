/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:11:55 by min-cho           #+#    #+#             */
/*   Updated: 2022/07/28 20:11:55 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *ap)
{
	int	i;

	i = 0;
	if (ap == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (ap[i])
	{
		write(1, &ap[i], 1);
		i++;
	}
	return (ft_strlen(ap));
}
