/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:19 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/14 13:35:40 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static int		ft_init_params(t_params **params, int ac, char **av)
{
	int			n;

	n = 1;
	(*params)->av = av;
	(*params)->nb = 0;
	while (n < ac)
	{
		if (av[n][0] != '-')
			(*params)->nb++;
		n = n + 1;
	}
	if ((*params)->nb == 0)
		(*params)->nb = 1;
	(*params)->base_nb = (*params)->nb;
	return (OK);
}

int				main(int ac, char **av)
{
	t_flags		*flags;
	t_params	*params;
	int			n;

	n = 1;
	if ((flags = malloc(sizeof(t_flags))) == NULL)
		return (1);
	if ((params = malloc(sizeof(t_params))) == NULL)
		return (1);
	if (ft_init_flags(&flags, ac, av) == ERROR)
		return (1);
	if (ft_init_params(&params, ac, av) == ERROR)
		return (1);
	if (ac == 1 || params->nb == 1)
		ft_dirORP(ft_strjoin(".", ""), flags, params);
	else
	{
		n = 0;
		while (++n < ac)
			if (av[n][0] != '-')
			{
				ft_dirORP(ft_setPATH("./", av[n]), flags, params);
				params->nb++;
			}
	}
	ft_putchar('\n');
	free(flags);
	free(params);
	return (0);
}
