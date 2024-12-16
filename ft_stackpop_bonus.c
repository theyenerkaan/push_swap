/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpop_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:12:55 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/16 21:51:39 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	*ft_stackpop(t_stack *stack)
{
	void	*content;
	t_list	*tmp;

	if (stack->count == 0)
		return (ft_printf("You can't pop when stack is empty!!!"), NULL);
	content = stack->top->content;
	tmp = stack->top;
	stack->top = stack->top->next;
	ft_lstdelone(tmp, NULL);
	stack->count--;
	return (content);
}
