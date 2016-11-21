/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:32:23 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/21 11:13:12 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void	ft_swap(char **a, char **b)
{
	void	*c;

	c = *a;
	*a = *b;
	*b = c;
}

void		ft_sort_alpha(char ***tab)
{
	int		n;

	n = -1;
	while ((*tab)[++n])
		if ((*tab)[n + 1] && ft_strcmp((*tab)[n], (*tab)[n + 1]) > 0)
		{
			ft_swap(&((*tab)[n]), &((*tab)[n + 1]));
			n = -1;
		}
}

void		ft_sort_revalpha(char ***tab)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while ((*tab)[n])
		n = n + 1;
	n = n - 1;
	while (n > i)
		ft_swap(&((*tab)[n--]), &((*tab)[i++]));
}

void		ft_sort_time(char *name, char ***tab)
{
	int		n;
	char	*tmp1;
	char	*tmp2;

	n = -1;
	while ((*tab)[++n])
	{
		tmp1 = ft_strdup(ft_gettime(name, (*tab)[n]));
		tmp2 = ft_gettime(name, (*tab)[n + 1]);
		if ((*tab)[n + 1] && ft_strcmp(tmp1, tmp2) < 0)
		{
			ft_swap(&((*tab)[n]), &((*tab)[n + 1]));
			n = -1;
		}
		if (tmp1)
			free(tmp1);
	}
}
