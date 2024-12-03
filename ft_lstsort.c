/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 01:55:36 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/01 02:01:27 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_lstsort(t_list *lst, bool (*cmp)(void *elmnt, void *elmnt1))
{
	if (!lst || !lst->next)
		return (true);
	if (!cmp)
		return (false);
	while (lst->next)
	{
		if (!cmp(lst->content, lst->next->content))
			return (false);
		lst = lst->next;
	}
	return (true);
}