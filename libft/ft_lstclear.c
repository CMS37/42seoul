/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-cho <min-cho@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 23:05:21 by min-cho           #+#    #+#             */
/*   Updated: 2022/03/19 23:05:21 by min-cho          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*last;
	t_list	*next;

	last = *lst;
	while (last)
	{
		next = last->next;
		ft_lstdelone(last, del);
		last = next;
	}
	*lst = NULL;
}
