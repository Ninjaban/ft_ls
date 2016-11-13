/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:51:45 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/13 16:30:59 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static int	ft_find_flags(t_flags **flags, char *str)
{
	int		n;

	n = 0;
	if (str[0] != '-' || str[1] == '-')
		return (OK);
	while (str[++n])
	{
		if (str[n] == 'l')
			(*flags)->l = TRUE;
		else if (str[n] == 'R')
			(*flags)->R = TRUE;
		else if (str[n] == 'a')
			(*flags)->a = TRUE;
		else if (str[n] == 'r')
			(*flags)->r = TRUE;
		else if (str[n] == 't')
			(*flags)->t = TRUE;
		else
		{
			ft_putstr(ERROR_OPTION);
			ft_putendl(&str[n]);
			return (ERROR);
		}
	}
	return (OK);
}

int			ft_init_flags(t_flags **flags, int ac, char **av)
{
	int	n;

	n = 0;
	(*flags)->l = FALSE;
	(*flags)->R = FALSE;
	(*flags)->a = FALSE;
	(*flags)->r = FALSE;
	(*flags)->t = FALSE;
	while (++n < ac)
		if (ft_find_flags(&(*flags), av[n]) == ERROR)
			return (ERROR);
	return (OK);
}
