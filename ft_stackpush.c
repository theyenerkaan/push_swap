/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 00:14:23 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/16 17:43:34 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackpush(t_stack *stack, void *data) {
	t_list	*lst_content;

	lst_content = ft_lstnew(data);
	if (lst_content == NULL)
		return ;
	ft_lstadd_front(&stack->top, lst_content);
	stack->count++;
}
