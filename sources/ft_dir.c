/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:43:59 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/13 17:33:35 by jcarra           ###   ########.fr       */
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
	if ((save = ft_strjoin(str, " ")) == NULL)
		return (NULL);
	free(str);
	str = save;
	return (str);
}

int					ft_dirORP(char *name, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*files;
	char			*str;

	if ((str = malloc(1)) == NULL)
		return (ERROR);
	str[0] = '\0';
	if ((dir = opendir(name)) == NULL)
	{
		perror("ft_ls");
		return (ERROR);
	}
	while ((files = readdir(dir)) != NULL)
	{
		/* Voir ici pour stat */
		if (files->d_name[0] != '.' || flags->a == TRUE)
			if ((str = ft_savename(str, files)) == NULL)
				return (ERROR);
	}
	ft_putendl(ft_strtrim(str));
	return (OK);
}
