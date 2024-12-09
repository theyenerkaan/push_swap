/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:26:59 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/10 20:04:33 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first(int ac, char **av, t_stack **a, t_stack **b)
{
	if (ac == 1)
		exit(0);
	*a = ft_stacknew();
	if (!*a)
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (parse(*a, ac, av))
	{
		ft_printf("Error\n");
		ft_stackclear(*a, free);
		exit(1);
	}
	*b = ft_stacknew();
	if (!*b)
	{
		ft_printf("Error\n");
		ft_stackclear(*a, free);
		exit(1);
	}
}

void	av_first_check(t_stack *a, t_stack *b)
{
	if (ft_lstsort(a->top, swp_cmp))
		return ;
	if (a->count > 3)
		pb(a, b);
	if (a->count > 3)
		pb(a, b);
	sorting(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	first(ac, av, &a, &b);
	av_first_check(a, b);
	ft_stackclear(a, free);
	ft_stackclear(b, free);
	return (0);
}
