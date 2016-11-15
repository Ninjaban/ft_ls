/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:43:59 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/15 12:00:06 by jcarra           ###   ########.fr       */
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

char				*ft_setpath(char *path, char *name, int clean)
{
	char			*new;
	int				n;
	int				i;

	n = 0;
	i = 0;
	if ((ft_strcmp("./", name) == 0 || ft_strcmp(".", name) == 0)
		|| name[0] == '/')
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
	if (clean == TRUE)
		free(name);
	return (new);
}

int					ft_dirorp(char *name, t_flags *flags, t_params *params)
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
	free(name);
	return (OK);
}
