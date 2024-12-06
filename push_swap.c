/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:26:59 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/06 21:59:58 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first(int ac, char **av, t_stack **a, t_stack **b)
{
	if (ac == 1)
		return ;
	*a = ft_stacknew();
	if(parse(*a, ac, av))
	{
		ft_printf("Error\n");
		ft_stackclear(*a);
		return ;
	}
	*b = ft_stacknew(); 
}

void av_f_check(t_stack *a, t_stack *b)
{
	if (ft_lstsort(a->top, swp_cmp))
		return ;
	if (a->count > 3)
		pb(a, b);
	sorting(a, b);
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		t_stack	*a_stack;
		t_stack	*b_stack;		
		
		first(ac, av, &a_stack, &b_stack);
		av_f_check(a_stack, b_stack);
		ft_stackclear(a_stack);
		ft_stackclear(b_stack);	
	}
}