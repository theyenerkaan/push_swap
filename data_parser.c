/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:35:00 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/18 05:25:17 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	av_check(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (false);
	while (str[i])
	{
		if (i == 0)
		{
			if (!(str[i] == '+' || str[i] == '-' || ft_isdigit(str[i])))
				return (false);
		}
		else if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if ((i == 1 && !ft_isdigit(str[i - 1])))
		return (false);
	else
		return (true);
}

int	double_check(t_stack *stack, long nbr)
{
	t_list	*temp;

	temp = stack->top;
	while (temp != NULL)
	{
		if (((t_swap *)temp->content)->nbr == nbr)
			return (true);
		temp = temp->next;
	}
	return (false);
}

long	av_are_valid(t_stack *stack, char **av)
{
	long	i;
	t_swap	*swap;

	i = ft_arrlen(av) - 1;
	while (i >= 0)
	{
		if (!av_check(av[i]))
			return (false);
		swap = malloc(sizeof (t_swap));
		if (swap == NULL)
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

int	parse(t_stack *stack, int ac, char **av)
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
