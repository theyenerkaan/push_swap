/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:12:55 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/01 00:14:04 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackpop(t_stack *stack)
{
	t_list	*temp;

	if (!stack->top)
		return ;
	temp = stack->top;
	stack->top = stack->top->next;
	free(temp);
	stack->count--;
}
