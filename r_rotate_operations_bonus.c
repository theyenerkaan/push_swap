/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_operations_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:11:46 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/16 17:51:41 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra(t_stack *a) {
	t_list	*tmp;

	if (a->count <= 1)
		return ;
	tmp = a->top;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = a->top;
	a->top = tmp->next;
	tmp->next = NULL;
}

void	rrb(t_stack *b) {
	t_list	*tmp;

	if (b->count <= 1)
		return ;
	tmp = b->top;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = b->top;
	b->top = tmp->next;
	tmp->next = NULL;
}

void	rrr(t_stack *a, t_stack *b) {
	t_list	*tmp;

	if (a->count <= 1)
		return ;
	tmp = a->top;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = a->top;
	a->top = tmp->next;
	tmp->next = NULL;
	if (b->count <= 1)
		return ;
	tmp = b->top;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = b->top;
	b->top = tmp->next;
	tmp->next = NULL;
}
