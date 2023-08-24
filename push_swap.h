/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:59:01 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/13 12:18:56 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_swap
{
	int				nb;
	int				index;
	int				markup;
	int				t_index;
	struct s_swap	*next;
}	t_struct;

///////////////////////////////////////////////////////////LST_UTILES
t_struct	*ft_lstnew(int nb);
void		ft_lstclear(t_struct **a);
void		ft_lstadd_back(t_struct **a, t_struct *new);
int			ft_lstsize(t_struct *a);
void		free_line(int fd);
///////////////////////////////////////////////////////////CHECKING
void		error(t_struct *a);
bool		ft_checking(t_struct *a, char *str);
bool		ft_is_exist(t_struct *a, int num);
t_struct	*ft_initialize(t_struct *a, int ac, char *av[]);
///////////////////////////////////////////////////////////RULES
void		sa(t_struct *a);
void		sb(t_struct *b);
void		ss(t_struct *a, t_struct*b);
void		pa(t_struct **a, t_struct **b);
void		pb(t_struct **a, t_struct **b);
void		ra(t_struct **a, int yes);
void		rb(t_struct **b, int yes);
void		rr(t_struct **a, t_struct **b);
void		rra(t_struct **a, int yes);
void		rrb(t_struct **b, int yes);
void		rrr(t_struct **a, t_struct **b);
//////////////////////////////////////////////////////////INDEXING
void		ft_sort_int_tab(int *tab, int size);
void		ft_indexing_2(int *array, t_struct *a, int len);
void		ft_indexing(t_struct *a);
//////////////////////////////////////////////////////////MARKUP
void		markup_0(t_struct *a);
int			markup_1(int head, t_struct *tmp, t_struct *a, int len);
void		markup_2(int big_head, t_struct *a, t_struct *tmp, int len);
void		t_indexing(t_struct *a);
int			find_markup(t_struct *a, t_struct *tmp);
void		ft_send_to_b(t_struct **a, t_struct **b);
//////////////////////////////////////////////////////////ALGO
t_struct	*ft_a_count(t_struct *a, t_struct *b);
t_struct	*ft_algo(t_struct *a, t_struct *b);
int			ft_mv_count(t_struct *tmp, t_struct *b, t_struct *a, int len_b);
int			find_pos(t_struct *a, t_struct *tmp);
void		ft_send(t_struct **a, t_struct **b);
void		ft_fix(t_struct **a);
int			ft_is_sorted(t_struct *a);
void		ft_send_2(t_struct **a, t_struct **b,
				t_struct *tmp_a, t_struct *tmp_b);

#endif