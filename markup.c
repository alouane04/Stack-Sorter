/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 21:17:16 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/13 13:09:28 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	markup_2(int big_head, t_struct *a, t_struct *tmp, int len)
{
	int	i;

	i = -1;
	a = a->next;
	if (!a)
		a = tmp;
	while (++i < len)
	{
		a->markup = 0;
		if (big_head < a->nb)
		{
			a->markup++;
			big_head = a->nb;
			a = a->next;
		}
		else
			a = a->next;
		if (!a)
			a = tmp;
	}
}

int	markup_1(int head, t_struct *a, t_struct *tmp, int len)
{
	int	i;
	int	markup;

	i = -1;
	markup = 1;
	a = a->next;
	if (!a)
		a = tmp;
	while (++i < len)
	{
		if (head < a->nb)
		{
			markup++;
			head = a->nb;
			a = a->next;
		}
		else
			a = a->next;
		if (!a)
			a = tmp;
	}
	return (markup);
}

void	markup_0(t_struct *a)
{
	t_struct	*tmp;
	t_struct	*tmp_2;
	int			head;
	int			big_head;

	big_head = 0;
	tmp = a;
	while (a)
	{
		head = markup_1(a->nb, a, tmp, ft_lstsize(tmp));
		if (big_head == head)
			if (tmp_2->index > a->index)
				tmp_2 = a;
		if (big_head < head)
		{
			big_head = head;
			tmp_2 = a;
		}
		a = a->next;
	}
	markup_2(tmp_2->nb, tmp_2, tmp, ft_lstsize(tmp));
	tmp_2->markup = 1;
}
