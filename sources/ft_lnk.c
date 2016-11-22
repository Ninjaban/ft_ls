/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:30:08 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/22 12:33:50 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void			ft_lnk(t_stat **stats, char *name, char *lnk, int ret)
{
	char		*tmp;

	lnk[ret] = '\0';
	tmp = ft_strjoin(name, " -> ");
	free(name);
	name = ft_strjoin(tmp, lnk);
	free(tmp);
	(*stats)->perms[0] = 'l';
	(*stats)->name = name;
}
