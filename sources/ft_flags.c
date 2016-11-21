/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:51:45 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/21 11:14:47 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static int	ft_find_flags(t_flags **flags, char *str, int n)
{
	if (str[0] != '-' || str[1] == '-')
		return (OK);
	while (str[++n])
	{
		if (str[n] == 'l')
			(*flags)->l = TRUE;
		else if (str[n] == 'R')
			(*flags)->rec = TRUE;
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
			ft_putendl(ERROR_USAGE);
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
	(*flags)->rec = FALSE;
	(*flags)->a = FALSE;
	(*flags)->r = FALSE;
	(*flags)->t = FALSE;
	while (++n < ac)
		if (ft_find_flags(&(*flags), av[n], 0) == ERROR)
			return (ERROR);
	return (OK);
}
