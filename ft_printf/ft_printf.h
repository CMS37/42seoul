/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:09:02 by min-cho           #+#    #+#             */
/*   Updated: 2022/07/28 20:09:02 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_print_char(char ap);
int	ft_print_string(char *ap);
int	ft_print_pointer(unsigned long long ap);
int	ft_print_nbr(int ap);
int	ft_print_unbr(unsigned int ap);
int	ft_print_low_base16(unsigned int ap);
int	ft_print_up_base16(unsigned int ap);
int	ft_printf(const char *format, ...);
void	ft_bzero(char *str, int n);
size_t	ft_strlen(char *s);

#endif