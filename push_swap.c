/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:26:59 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/18 09:02:28 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static void	first(int ac, char **av, t_stack **a, t_stack **b)
{
	if (ac == 1)
		exit(0);
	*a = ft_stacknew();
	if (!*a)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (parse(*a, ac, av))
	{
		write(2, "Error\n", 6);
		ft_stackclear(*a, free);
		exit(1);
	}
	*b = ft_stacknew();
	if (!*b)
	{
		write(2, "Error\n", 6);
		ft_stackclear(*a, free);
		exit(1);
	}
}

static void	av_first_check(t_stack *a, t_stack *b)
{
	if (ft_lstsort(a->top, swp_cmp))
		return ;
	if (a->count > 3)
		pb(a, b);
	if (a->count > 3)
		pb(a, b);
	if (a->count == 3)
		sort_three(a);
	sorting(a, b);
}

static void	space_error(char **str)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] >= '0' && str[i][j] <= '9')
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (flag == 0)
			error_exit();
		flag = 0;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	space_error(av);
	first(ac, av, &a, &b);
	av_first_check(a, b);
	ft_stackclear(a, free);
	ft_stackclear(b, free);
	return (0);
}
