/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 09:12:01 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/15 11:51:40 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

size_t		ft_getnbdigit(size_t nbr)
{
	size_t	nb;
	size_t	tmp;

	tmp = nbr;
	nb = 0;
	while (tmp != 0)
	{
		nb = nb + 1;
		tmp = tmp / 10;
	}
	return (nb);
}

size_t		ft_max_int(t_stat **stats, int in)
{
	size_t	nb;
	int		n;

	n = 0;
	if (in == 1)
	{
		nb = ft_getnbdigit(stats[0]->links);
		while (stats[++n])
			if (ft_getnbdigit(stats[n]->links) > nb)
				nb = ft_getnbdigit(stats[n]->links);
	}
	else
	{
		nb = ft_getnbdigit(stats[0]->octets);
		while (stats[++n])
			if (ft_getnbdigit(stats[n]->octets) > nb)
				nb = ft_getnbdigit(stats[n]->octets);
	}
	return (nb);
}

size_t		ft_max_length(t_stat **stats, int in)
{
	size_t	len;
	int		n;

	n = 0;
	if (in == 1)
	{
		len = ft_strlen(stats[n]->user);
		while (stats[++n])
			if (ft_strlen(stats[n]->user) > len)
				len = ft_strlen(stats[n]->user);
	}
	else
	{
		len = ft_strlen(stats[n]->group);
		while (stats[++n])
			if (ft_strlen(stats[n]->group) > len)
				len = ft_strlen(stats[n]->group);
	}
	return (len);
}

void		ft_print_char(char c, size_t n)
{
	while (n--)
		ft_putchar(c);
}
