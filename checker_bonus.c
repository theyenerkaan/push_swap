/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:35:00 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/15 18:13:31 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_exit(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	execute_action(char *action, t_stack *a, t_stack *b)
{
	if (ft_strncmp(action, "sa\n", 3) == 0)
		sa(a);
	else if (ft_strncmp(action, "sb\n", 3) == 0)
		sb(b);
	else if (ft_strncmp(action, "ss\n", 3) == 0)
		ss(a, b);
	else if (ft_strncmp(action, "rra\n", 4) == 0)
		rra(a);
	else if (ft_strncmp(action, "rrb\n", 4) == 0)
		rrb(b);
	else if (ft_strncmp(action, "rrr\n", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(action, "pa\n", 3) == 0)
		pa(b, a);
	else if (ft_strncmp(action, "pb\n", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(action, "ra\n", 3) == 0)
		ra(a);
	else if (ft_strncmp(action, "rb\n", 3) == 0)
		rb(b);
	else if (ft_strncmp(action, "rr\n", 3) == 0)
		rr(a, b);
	else
		error_exit();
}

void	read_actions(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		execute_action(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = ft_stacknew();
	b = ft_stacknew();
	if (parse(a, ac, av) || !a || !b)
		error_exit();
	read_actions(a, b);
	if (ft_lstsort(a->top, swp_cmp) && b->count == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stackclear(a, free);
	ft_stackclear(b, free);
	return (0);
}
