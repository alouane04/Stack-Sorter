/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 17:58:02 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/12 17:21:40 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_struct	*ft_lstnew(int nb)
{
	t_struct	*new_e;

	new_e = malloc(sizeof(t_struct));
	if (!new_e)
		return (NULL);
	new_e->nb = nb;
	new_e->next = NULL;
	return (new_e);
}

void	ft_lstclear(t_struct **a)
{
	t_struct	*tmp;

	if (!a)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free((*a));
		*a = tmp;
	}
	*a = NULL;
}

void	ft_lstadd_back(t_struct **a, t_struct *new)
{
	t_struct	*ptr;

	if (*a)
	{
		ptr = *a;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	else
		*a = new;
}

int	ft_lstsize(t_struct *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	free_line(int fd)
{
	char	line[1];

	ft_bzero(line, 1);
	while (read(fd, line, 1) > 0)
		continue ;
}
