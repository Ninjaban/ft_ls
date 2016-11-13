/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:19 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/13 17:42:38 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int			main(int ac, char **av)
{
	t_flags	*flags;
	int		n;

	n = 1;
	if ((flags = malloc(sizeof(t_flags))) == NULL)
		return (ERROR);
	if (ft_init_flags(&flags, ac, av) == ERROR)
		return (1);
	while (n < ac && av[n][0] == '-')
		n = n + 1;
	if (ac == 1 || n == ac)
		ft_dirORP(".", flags);
	else
	{
		n = 0;
		while (++n < ac)
			if (av[n][0] != '-')
				ft_dirORP(av[n], flags);
	}
	free(flags);
	return (0);
}
