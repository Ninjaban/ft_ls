/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_statl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:12:28 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/15 12:16:38 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static void	ft_setperms(char **str, struct stat *buf)
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

static char	*ft_settime(char *str)
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
	t_stat			*stat;
	struct passwd	*user;
	struct group	*group;

	if ((stat = malloc(sizeof(t_stat))) == NULL)
		return (NULL);
	if (!(stat->name = ft_strdup(name)))
		return (NULL);
	if (!(stat->perms = ft_strdup("----------\0")))
		return (NULL);
	user = getpwuid(buf->st_uid);
	if (!(stat->user = (user) ? ft_strdup(user->pw_name) : ft_strdup("\0")))
		return (NULL);
	group = getgrgid(buf->st_gid);
	if (!(stat->group = (group) ? ft_strdup(group->gr_name) : ft_strdup("\0")))
		return (NULL);
	if (!(stat->time = ft_strdup(ctime(&buf->st_mtime))))
		return (NULL);
	stat->links = buf->st_nlink;
	stat->octets = buf->st_size;
	ft_setperms(&stat->perms, buf);
	stat->time = ft_settime(stat->time);
	stat->block = buf->st_blocks;
	return (stat);
}
