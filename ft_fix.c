/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:48:46 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/13 12:17:00 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fix(t_struct **a)
{
	t_struct	*tmp;
	int			i;
	int			len;

	tmp = *a;
	i = 0;
	len = ft_lstsize(*a);
	while (i < len)
	{
		if (tmp->index == 0)
		{
			if (i <= len / 2)
				while (i-- > 0)
					ra(a, 1);
			else
				while (i++ < len)
					rra(a, 1);
			break ;
		}
		else
			tmp = tmp->next;
		i++;
	}
}
