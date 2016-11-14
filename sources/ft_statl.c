/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_statl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:12:28 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/14 21:09:34 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void	ft_setPerms(char **str, struct stat *buf)
{
	if (S_ISDIR(buf->st_mode))
		(*str)[0] = 'd';
	if (S_ISLNK(buf->st_mode))
		(*str)[0] = 'l';
	(*str)[1] = (buf->st_mode & S_IRUSR) ? 'r' : '-';
	(*str)[2] = (buf->st_mode & S_IWUSR) ? 'w' : '-';
	(*str)[3] = (buf->st_mode & S_IXUSR) ? 'x' : '-';
	(*str)[4] = (buf->st_mode & S_IRGRP) ? 'r' : '-';
	(*str)[5] = (buf->st_mode & S_IWGRP) ? 'w' : '-';
	(*str)[6] = (buf->st_mode & S_IXGRP) ? 'x' : '-';
	(*str)[7] = (buf->st_mode & S_IROTH) ? 'r' : '-';
	(*str)[8] = (buf->st_mode & S_IWOTH) ? 'w' : '-';
	(*str)[9] = (buf->st_mode & S_IXOTH) ? 'x' : '-';
}

static char	*ft_setTime(char *str)
{
	int		n;
	char	*dst;

	n = 0;
	while (str[n] != ' ')
		str[n++] = ' ';
	while (str[n] != ':')
		n = n + 1;
	n = n + 1;
	while (str[n] != ':')
		n = n + 1;
	while (str[n])
		str[n++] = ' ';
	dst = ft_strtrim(str);
	free(str);
	return (dst);
}

void		ft_free_stat(t_stat *stats)
{
	if (!stats)
		return ;
	free(stats->name);
	free(stats->perms);
	free(stats->user);
	free(stats->group);
	free(stats->time);
	free(stats);
}

t_stat		*ft_init_stat(char *name, struct stat *buf)
{
	t_stat	*stat;

	if ((stat = malloc(sizeof(t_stat))) == NULL)
		return (NULL);
	stat->name = ft_strdup(name);
	stat->perms = ft_strdup("----------\0");
	stat->user = ft_strdup(getpwuid(buf->st_uid)->pw_name);
	stat->group = ft_strdup(getgrgid(buf->st_gid)->gr_name);
	stat->time = ft_strdup(ctime(&buf->st_mtime));
	stat->links = buf->st_nlink;
	stat->octets = buf->st_size;
	ft_setPerms(&stat->perms, buf);
	stat->time = ft_setTime(stat->time);
	ft_putstr(stat->perms);
	ft_putnbr(stat->links);
	ft_putstr(stat->user);
	ft_putstr(stat->group);
	ft_putnbr(stat->octets);
	ft_putstr(stat->time);
	ft_putendl(stat->name);
	return (stat);
}
