/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yenyilma <yyenerkaan1@student.42.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:17:03 by yenyilma          #+#    #+#             */
/*   Updated: 2024/12/13 01:17:05 by yenyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "get_next_line/get_next_line.h"

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

void		first(int ac, char **av, t_stack **a, t_stack **b);
int			ft_strcmp(char *s1, char *s2);
t_stack		*ft_stacknew(void);
bool		parse(t_stack *stack, int ac, char **av);
void		ft_stackclear(t_stack *stack, void (*del)(void *));
void		av_f_check(t_stack *a, t_stack *b);
bool		ft_lstsort(t_list *lst, bool (*cmp)(void *elmnt, void *elmnt1));
bool		swp_cmp(void *prev, void *next);
void		sorting(t_stack *a, t_stack *b);
size_t		ft_arrlen(char **arr);
void		ft_arrfree(char **arr);
void		ft_stackpush(t_stack *stack, void *data);
void		*ft_stackpop(t_stack *stack);
bool		av_check(char *str);
bool		double_check(t_stack *stack, long nbr);
bool		av_are_valid(t_stack *stack, char **av);
t_list		*transaction_max(t_stack *stack);
t_list		*transaction_min(t_stack *stack);
void		transaction_b(t_swap *val, t_stack *a);
void		transaction_a(t_swap *val, t_stack *b);
void		chpst_swap(t_swap *swap, t_swap **min);
void		op_a(t_stack *a, t_stack *b);
t_list		*find_max(t_stack *stack);
t_list		*find_min(t_stack *stack);
void		op_b(t_stack *a, t_stack *b);
void		prepare_or(t_stack *stack);
void		load_stack(t_stack *find, t_stack *target,
				void (*prcs)(t_swap *value, t_stack *target));
void		the_sort(t_stack *stack);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);

#endif
