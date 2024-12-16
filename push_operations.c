/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:11:41 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/16 21:53:49 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *b, t_stack *a)
{
	if (b->count == 0)
		return ;
	ft_stackpush(a, ft_stackpop(b));
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->count == 0)
		return ;
	ft_stackpush(b, ft_stackpop(a));
	ft_printf("pb\n");
}
