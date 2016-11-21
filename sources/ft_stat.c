/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 09:05:51 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/21 11:31:53 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void		ft_change(char **str, char *name, char *nb, int i)
{
	int			n;
	int			j;

	n = 0;
	while ((*str)[i++] == name[n++])
		;
	j = 0;
	if (name[n] == '\0')
	{
		while (nb[j])
			(*str)[i - n--] = nb[j++];
		while (n >= 0)
			(*str)[i - n--] = ' ';
	}
}

static void		ft_ctime_int(char **str)
{
	int			n;

	n = -1;
	if (!str || !(*str))
		return ;
	while ((*str)[++n] != ' ')
		(*str)[n] = (*str)[n + 20];
	(*str)[n] = (*str)[n + 20];
	n = n + 1;
	ft_change(&(*str), "Jan\0", "1", n);
	ft_change(&(*str), "Feb\0", "2", n);
	ft_change(&(*str), "Mar\0", "3", n);
	ft_change(&(*str), "Apr\0", "4", n);
	ft_change(&(*str), "May\0", "5", n);
	ft_change(&(*str), "Jun\0", "6", n);
	ft_change(&(*str), "Jul\0", "7", n);
	ft_change(&(*str), "Aug\0", "8", n);
	ft_change(&(*str), "Sep\0", "9", n);
	ft_change(&(*str), "Oct\0", "10", n);
	ft_change(&(*str), "Nov\0", "11", n);
	ft_change(&(*str), "Dec\0", "12", n);
}

char			*ft_gettime(char *path, char *name)
{
	struct stat	*buf;
	char		*tmp;

	if ((tmp = ft_setpath(path, name, FALSE)) == NULL)
		return (NULL);
	if ((buf = malloc(sizeof(struct stat))) == NULL)
		return (NULL);
	if (stat(tmp, buf) == -1)
		return (NULL);
	free(tmp);
	tmp = ctime(&buf->st_mtime);
	free(buf);
	ft_ctime_int(&tmp);
	return (tmp);
}

int				ft_isdir(const char *path)
{
	struct stat	*buf;

	if (!path)
		return (ERROR);
	if ((buf = malloc(sizeof(struct stat))) == NULL)
		return (ERROR);
	if (stat(path, buf) == -1)
	{
		free(buf);
		return (ERROR);
	}
	free((void *)path);
	if (S_ISDIR(buf->st_mode))
	{
		free(buf);
		return (TRUE);
	}
	free(buf);
	return (FALSE);
}

t_stat			*ft_stat(const char *path, char *name)
{
	struct stat	*buf;
	t_stat		*stats;
	int			ret;
	char		*lnk;

	if (!path)
		return (NULL);
	if ((buf = malloc(sizeof(struct stat))) == NULL)
		return (NULL);
	if ((lnk = malloc(1024)) == NULL)
		return (NULL);
	if (lstat(path, buf) == -1)
		return (NULL);
	stats = ft_init_stat(name, buf);
	if ((ret = readlink(path, lnk, 1023)) != -1)
	{
		stats->perms[0] = 'l';
		lnk[ret] = '\0';
		stats->name = ft_strjoin(stats->name, ft_strjoin(" -> ", lnk));
	}
	free(lnk);
	free(buf);
	free((void *)path);
	return (stats);
}
