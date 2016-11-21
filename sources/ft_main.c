/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:19 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/21 11:13:49 by jcarra           ###   ########.fr       */
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
	(*params)->base_nb = (*params)->nb;
	return (OK);
}

static void		ft_launch(int ac, char **av, t_flags *flags, t_params *params)
{
	char		*str;
	int			n;

	if (ac == 1 || params->nb == 0)
		ft_dirorp(ft_strjoin(".", ""), flags, params);
	else
	{
		n = 0;
		while (++n < ac)
			if (av[n][0] != '-')
			{
				str = ft_strdup(av[n]);
				ft_dirorp(ft_setpath("./", str, TRUE), flags, params);
				params->nb++;
			}
	}
}

int				main(int ac, char **av)
{
	t_flags		*flags;
	t_params	*params;

	if ((flags = malloc(sizeof(t_flags))) == NULL)
		return (1);
	if ((params = malloc(sizeof(t_params))) == NULL)
		return (1);
	if (ft_init_flags(&flags, ac, av) == ERROR)
	{
		free(flags);
		free(params);
		return (1);
	}
	if (ft_init_params(&params, ac, av) == ERROR)
	{
		free(flags);
		free(params);
		return (1);
	}
	ft_launch(ac, av, flags, params);
	ft_putchar('\n');
	free(flags);
	free(params);
	return (0);
}
