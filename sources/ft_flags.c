/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:51:45 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/13 14:29:22 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void	ft_find_flags(t_flags **flags, char *str)
{

}

t_flags		ft_init_flags(t_flags **flags, int ac, char **av)
{
	int	n;

	n = 0;
	if ((*flags = malloc(sizeof(t_flags))) == NULL)
		return (ERROR);
	(*flags)->l = FALSE;
	(*flags)->R = FALSE;
	(*flags)->a = FALSE;
	(*flags)->r = FALSE;
	(*flags)->t = FALSE;
	while (++n < ac)
		ft_find_flags(&(*flags), av[n]);
	return (OK);
}
