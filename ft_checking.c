/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariahi <ariahi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 18:02:12 by ariahi            #+#    #+#             */
/*   Updated: 2022/04/13 12:03:44 by ariahi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_struct *a)
{
	ft_lstclear(&a);
	write(2, "Error\n", 7);
	exit (0);
}

bool	ft_checking(t_struct *a, char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && str[1])
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || errno != 0)
			error(a);
		i++;
	}
	return (1);
}

bool	ft_is_exist(t_struct *a, int num)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->nb == num)
			return (0);
		a = a->next;
	}	
	return (1);
}

t_struct	*ft_initialize(t_struct *a, int ac, char *av[])
{
	int			i;
	int			j;
	int			num;
	char		**str;

	i = 0;
	while (ac > ++i)
	{
		j = -1;
		str = ft_split(av[i], ' ');
		while (str[++j])
		{
			if (ft_checking(a, str[j]))
			{
				errno = 0;
				num = ft_atoi(str[j]);
				if (errno != 0 || !ft_is_exist(a, num))
					error(a);
			}
			ft_lstadd_back(&a, ft_lstnew(num));
		}
		ft_free(str);
	}
	return (a);
}
