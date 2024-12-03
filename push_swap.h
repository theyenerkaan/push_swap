/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 02:26:59 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/03 03:20:30 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int		count;
	t_list	*top;
}			t_stack;

typedef struct s_swap
{
	long	nbr;
	long	index;
	long	cost;
	bool	is_cheapest;
	bool	is_above_median;
	t_list	*target;
}			t_swap;

void	first(int ac, char **av, t_stack *a, t_stack *b);
size_t ft_arrlen(char **arr);
void ft_arrfree(char **arr);
void	ft_stackpush(t_stack *stack, int data);
void	ft_stackpop(t_stack *stack);
t_stack	*ft_stacknew(void);
bool av_check(char *str);
bool double_check(t_stack *stack, long nbr);
bool av_are_valid(t_stack *stack, char **av);
bool parse(t_stack *stack, int ac, char **av);
void	ft_stackclear(t_stack *stack);
bool	ft_lstsort(t_list *lst, bool (*cmp)(void *elmnt, void *elmnt1));
bool swp_cmp(void *prev, void *next);
t_list	*transaction_max(t_stack *stack);
t_list	*transaction_min(t_stack *stack);
void	transaction_b(t_swap *val, t_stack *a);
void	transaction_a(t_swap *val, t_stack *b);
void	sorting(t_stack *a, t_stack *b);

#endif
