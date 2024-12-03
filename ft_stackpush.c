/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:14:23 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/01 00:14:30 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackpush(t_stack *stack, int data)
{
	t_list	*new;

	new = ft_lstnew(data);
	if (!new)
		return ;
	new->next = stack->top;
	stack->top = new;
	stack->count++;
}
