/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lnk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:30:08 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/21 18:30:29 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

char			*ft_lnk(char *name, char *lnk, int ret)
{
	char		*tmp;

	lnk[ret] = '\0';
	tmp = ft_strjoin(name, " -> ");
	free(name);
	name = ft_strjoin(tmp, lnk);
	free(tmp);
	return (name);
}
