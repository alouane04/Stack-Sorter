/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:51:44 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/12 17:48:17 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*ft_a_count(t_struct *a, t_struct *b)
{
	t_struct	*tmp;

	tmp = NULL;
	while (a)
	{
		if (a->nb > b->nb && (!tmp || a->nb < tmp->nb))
				tmp = a;
		a = a->next;
	}
	return (tmp);
}

int	ft_mv_count(t_struct *tmp_b, t_struct *b, t_struct *a, int len_b)
{
	t_struct	*tmp_a;
	int			mv_b;
	int			mv_a;
	int			i;
	int			len_a;

	len_a = ft_lstsize(a);
	tmp_a = ft_a_count(a, tmp_b);
	i = 0;
	if (find_pos(b, tmp_b) <= len_b / 2)
		mv_b = find_pos(b, tmp_b);
	else
		mv_b = len_b - find_pos(b, tmp_b);
	if (find_pos(a, tmp_a) <= len_a / 2)
		mv_a = find_pos(a, tmp_a);
	else
		mv_a = len_a - find_pos(a, tmp_a);
	if (find_pos(b, tmp_b) <= len_b / 2 && find_pos(a, tmp_a) <= len_a / 2)
		while (mv_a && mv_b && mv_a-- && mv_b--)
			i++;
	else if (find_pos(b, tmp_b) > len_b / 2 && find_pos(a, tmp_a) > len_a / 2)
		while (mv_a && mv_b && mv_a-- && mv_b--)
			i++;
	return (mv_b + mv_a + i);
}

t_struct	*ft_algo(t_struct *a, t_struct *b)
{
	t_struct	*tmp;
	t_struct	*tmp_b;
	int			n;
	int			n_min;

	tmp = b;
	n_min = ft_mv_count(b, tmp, a, ft_lstsize(tmp));
	while (b)
	{
		n = ft_mv_count(b, tmp, a, ft_lstsize(tmp));
		if (n_min >= n)
		{
			n_min = n;
			tmp_b = b;
		}
		b = b->next;
	}
	return (tmp_b);
}

void	ft_send_2(t_struct **a, t_struct **b, t_struct *tmp_a, t_struct *tmp_b)
{
	if (find_pos(*b, tmp_b) <= ft_lstsize(*b) / 2)
		while (*b != tmp_b)
			rb(b, 1);
	else if (find_pos(*b, tmp_b) > ft_lstsize(*b) / 2)
		while (*b != tmp_b)
			rrb(b, 1);
	if (find_pos(*a, tmp_a) <= ft_lstsize(*a) / 2)
		while (*a != tmp_a)
			ra(a, 1);
	else if (find_pos(*a, tmp_a) > ft_lstsize(*a) / 2)
		while (*a != tmp_a)
			rra(a, 1);
	pa(a, b);
}

void	ft_send(t_struct **a, t_struct **b)
{
	t_struct	*tmp_a;
	t_struct	*tmp_b;
	int			i;

	i = 0;
	while (*b)
	{
		tmp_b = ft_algo(*a, *b);
		tmp_a = ft_a_count(*a, tmp_b);
		if (find_pos(*b, tmp_b) <= ft_lstsize(*b) / 2
			&& find_pos(*a, tmp_a) <= ft_lstsize(*a) / 2)
			while (*a != tmp_a && *b != tmp_b)
				rr(a, b);
		else if (find_pos(*b, tmp_b) > ft_lstsize(*b) / 2
			&& find_pos(*a, tmp_a) > ft_lstsize(*a) / 2)
			while (*a != tmp_a && *b != tmp_b)
				rrr(a, b);
		ft_send_2(a, b, tmp_a, tmp_b);
	}
}
