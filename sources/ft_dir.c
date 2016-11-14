/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:43:59 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/14 15:49:49 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static char			*ft_savename(char *str, struct dirent *files)
{
	char			*save;

	if ((save = ft_strjoin(str, files->d_name)) == NULL)
		return (NULL);
	free(str);
	str = save;
	if ((save = ft_strjoin(str, "|")) == NULL)
		return (NULL);
	free(str);
	str = save;
	return (str);
}

char			*ft_setPATH(char *path, char *name)
{
	char			*new;
	int				n;
	int				i;

	n = 0;
	i = 0;
	if ((ft_strcmp("./", name) == 0 || ft_strcmp(".", name) == 0) || name[0] == '/')
		return (name);
	if ((new = malloc(ft_strlen(path) + ft_strlen(name) + 2)) == NULL)
		return (NULL);
	while (path[n])
		new[i++] = path[n++];
	n = 0;
	if (new[i - 1] != '/')
		new[i++] = '/';
	while (name[n])
		new[i++] = name[n++];
	new[i] = '\0';
	return (new);
}

static void			ft_print_aff(char *name, char **tab, t_flags *flags, t_params *params)
{
	int				n;

	n = 0;
	while (tab[n])
	{
		ft_putstr(tab[n++]);
		if (tab[n])
			ft_putchar(' ');
	}
	n = 0;
	while (tab[n])
	{
		if (flags->R == TRUE && ft_isdir(ft_setPATH(name, tab[n])) == TRUE &&
			ft_strcmp(".", tab[n]) != 0 && ft_strcmp("..", tab[n]) != 0)
		{
			params->nb++;
			ft_dirORP(ft_setPATH(name, tab[n]), flags, params);
		}
		if (flags->l == TRUE)
			if (ft_stat(ft_setPATH(name, tab[n])) == ERROR)
				return ;
		n = n + 1;
	}
}

static void			ft_print_init(char *name, char *str, t_flags *flags, t_params *params)
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
	if (flags->t == FALSE)
		ft_sort_alpha(&tab);
	if (flags->t == TRUE)
		ft_sort_time(name, &tab);
	if (flags->r == TRUE)
		ft_sort_revalpha(&tab);
	ft_print_aff(name, tab, flags, params);
}

int					ft_dirORP(char *name, t_flags *flags, t_params *params)
{
	DIR				*dir;
	struct dirent	*files;
	char			*str;

	if (!name)
		return (ERROR);
	if ((str = malloc(1)) == NULL)
		return (ERROR);
	str[0] = '\0';
	if ((dir = opendir(name)) == NULL)
	{
		perror("ft_ls");
		return (ERROR);
	}
	while ((files = readdir(dir)) != NULL)
		if (files->d_name[0] != '.' || flags->a == TRUE)
			if ((str = ft_savename(str, files)) == NULL)
				return (ERROR);
	closedir(dir);
	ft_print_init(name, str, flags, params);
	return (OK);
}
