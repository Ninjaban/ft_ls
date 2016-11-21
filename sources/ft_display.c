/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 08:55:57 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/21 18:50:28 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static	size_t		ft_tablen(char **tab)
{
	size_t			n;

	n = 0;
	while (tab[n])
		n = n + 1;
	return (n);
}

static void			ft_print_stat(t_stat **stats, int n)
{
	while (stats[++n])
	{
		if (n != 0)
			ft_putchar('\n');
		ft_putstr(stats[n]->perms);
		ft_print_char(' ', ft_max_int(stats, 1) -
					ft_getnbdigit(stats[n]->links) + 2);
		ft_putnbr(stats[n]->links);
		ft_print_char(' ', ft_max_length(stats, 1) -
					ft_strlen(stats[n]->user) + 1);
		ft_putstr(stats[n]->user);
		ft_print_char(' ', ft_max_length(stats, 2) -
					ft_strlen(stats[n]->group) + 2);
		ft_putstr(stats[n]->group);
		ft_print_char(' ', ft_max_int(stats, 2) -
					ft_getnbdigit(stats[n]->octets) + 2);
		ft_putnbr(stats[n]->octets);
		ft_putstr(" ");
		ft_putstr(stats[n]->time);
		ft_putstr(" ");
		ft_putstr(stats[n]->name);
	}
}

static void			ft_print_stat_init(char *name, char **tab, size_t total)
{
	t_stat			**stats;
	int				n;

	n = -1;
	if ((stats = malloc(sizeof(t_stat) * ft_tablen(tab) + 1)) == NULL)
		return ;
	while ((size_t)++n <= ft_tablen(tab))
		stats[n] = NULL;
	n = -1;
	while (tab[++n])
		if ((stats[n] = ft_stat(ft_setpath(name, tab[n], FALSE),
								tab[n])) == NULL)
			return ;
	n = -1;
	while (stats[++n])
		total = total + stats[n]->block;
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
	ft_print_stat(stats, -1);
	n = -1;
	while (stats[++n])
		ft_free_stat(stats[n]);
	free(stats);
}

static void			ft_print_aff(char *name, char **tab,
								t_flags *flags, t_params *params)
{
	int				n;

	n = -1;
	if (flags->l == TRUE)
		ft_print_stat_init(name, tab, 0);
	else
		while (tab[++n])
		{
			ft_putstr(tab[n]);
			if (tab[n + 1])
				ft_putchar('\n');
		}
	n = -1;
	while (tab[++n])
		if (flags->rec == TRUE &&
			ft_isdir(ft_setpath(name, tab[n], FALSE)) == TRUE &&
			ft_strcmp(".", tab[n]) != 0 && ft_strcmp("..", tab[n]) != 0)
		{
			params->nb++;
			ft_dirorp(ft_setpath(name, tab[n], FALSE), flags, params);
		}
	n = 0;
	while (tab[n])
	{
		ft_putendl(tab[n]);
		free(tab[n++]);
	}
	free(tab);
//	ft_free_tab(tab);
}

void				ft_print_init(char *name, char *str,
								t_flags *flags, t_params *params)
{
	char			**tab;

	if (params->nb != params->base_nb)
		ft_putstr("\n\n");
	if (params->nb > 1)
	{
		ft_putstr(name);
		ft_putendl(":");
	}
	if ((tab = ft_strsplit(str, '|')) == NULL)
		return ;
	free(str);
	if (flags->t == FALSE)
		ft_sort_alpha(&tab);
	if (flags->t == TRUE)
		ft_sort_time(name, &tab);
	if (flags->r == TRUE)
		ft_sort_revalpha(&tab);
	ft_print_aff(name, tab, flags, params);
}
