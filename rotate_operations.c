/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:53:07 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/16 21:55:12 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	t_list	*tmp;

	ft_printf("ra\n");
	if (a->count <= 1)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	tmp->next = NULL;
	ft_lstlast(a->top)->next = tmp;
}

void	rb(t_stack *b)
{
	t_list	*tmp;

	ft_printf("rb\n");
	if (b->count <= 1)
		return ;
	tmp = b->top;
	b->top = tmp->next;
	tmp->next = NULL;
	ft_lstlast(b->top)->next = tmp;
}

void	rr(t_stack *a, t_stack *b)
{
	t_list	*tmp;

	ft_printf("rr\n");
	if (a->count <= 1)
		return ;
	tmp = a->top;
	a->top = tmp->next;
	tmp->next = NULL;
	ft_lstlast(a->top)->next = tmp;
	if (b->count <= 1)
		return ;
	tmp = b->top;
	b->top = tmp->next;
	tmp->next = NULL;
	ft_lstlast(b->top)->next = tmp;
}
