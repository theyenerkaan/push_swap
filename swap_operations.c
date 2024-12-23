/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:11:36 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/16 21:56:53 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	*tmp;
	int	*tmp1;

	ft_printf("sa\n");
	if (a->count <= 1)
		return ;
	tmp = ft_stackpop(a);
	tmp1 = ft_stackpop(a);
	ft_stackpush(a, tmp);
	ft_stackpush(a, tmp1);
}

void	sb(t_stack *b)
{
	int	*tmp;
	int	*tmp1;

	ft_printf("sb\n");
	if (b->count <= 1)
		return ;
	tmp = ft_stackpop(b);
	tmp1 = ft_stackpop(b);
	ft_stackpush(b, tmp);
	ft_stackpush(b, tmp1);
}

void	ss(t_stack *a, t_stack *b)
{
	int	*tmp;
	int	*tmp1;

	ft_printf("ss\n");
	if (a->count > 1)
	{
		tmp = ft_stackpop(a);
		tmp1 = ft_stackpop(a);
		ft_stackpush(a, tmp);
		ft_stackpush(a, tmp1);
	}
	if (b->count > 1)
	{
		tmp = ft_stackpop(b);
		tmp1 = ft_stackpop(b);
		ft_stackpush(b, tmp);
		ft_stackpush(b, tmp1);
	}
}
