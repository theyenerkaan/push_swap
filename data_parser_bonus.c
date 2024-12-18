/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:35:00 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/18 06:41:49 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

bool	av_check(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (false);
	while (str[i])
	{
		if (i == 0 && !(str[i] == '-' || str[i] == '+' || ft_isdigit(str[i])))
			return (false);
		if (!ft_isdigit(str[i]) && i != 0)
			return (false);
		i++;
	}
	if (i == 1 && !ft_isdigit(str[0]))
		return (false);
	return (true);
}

bool	double_check(t_stack *stack, long nbr)
{
	t_list	*temp;

	temp = stack->top;
	while (temp)
	{
		if (((t_swap *)temp->content)->nbr == nbr)
			return (true);
		temp = temp->next;
	}
	return (false);
}

bool	av_are_valid(t_stack *stack, char **av)
{
	long	i;
	t_swap	*swap;

	i = ft_arrlen(av) - 1;
	while (i >= 0)
	{
		if (!av_check(av[i]))
			return (false);
		swap = malloc(sizeof(t_swap));
		if (!swap)
			return (false);
		swap->nbr = ft_atol(av[i]);
		if (double_check(stack, swap->nbr))
		{
			free(swap);
			return (false);
		}
		ft_stackpush(stack, swap);
		i--;
	}
	return (true);
}

bool	parse(t_stack *stack, int ac, char **av)
{
	char	**split;
	int		i;

	i = ac - 1;
	while (i > 0)
	{
		split = ft_split(av[i], ' ');
		if (!av_are_valid(stack, split))
		{
			ft_arrfree(split);
			return (true);
		}
		ft_arrfree(split);
		i--;
	}
	return (false);
}
