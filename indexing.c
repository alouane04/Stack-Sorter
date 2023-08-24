/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:18:55 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/13 12:17:28 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	c;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				c = tab[i];
				tab[i] = tab[j];
				tab[j] = c;
			}
			j++;
		}
		i++;
	}
}

void	ft_indexing_2(int *array, t_struct *a, int len)
{
	t_struct	*tmp;
	int			i;

	tmp = a;
	i = 0;
	while (i < len)
	{
		a = tmp;
		while (a)
		{
			if (array[i] == a->nb)
			{
				a->index = i;
				break ;
			}
			else
				a = a->next;
		}
		i++;
	}
}

void	ft_indexing(t_struct *a)
{
	t_struct	*tmp;
	int			*array;
	int			len;
	int			i;

	i = -1;
	len = ft_lstsize(a);
	array = malloc(sizeof(int) * len);
	tmp = a;
	while (++i < len)
	{
		array[i] = a->nb;
		a = a->next;
	}
	ft_sort_int_tab(array, len);
	ft_indexing_2(array, tmp, len);
}
