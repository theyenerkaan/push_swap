/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:07:25 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/18 05:49:54 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(void)
{
	t_stack	*stack;

	stack = ft_calloc(sizeof(t_stack), sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->count = 0;
	return (stack);
}
