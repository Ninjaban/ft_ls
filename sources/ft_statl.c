/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_statl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:12:28 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/14 16:26:31 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

t_stat		*ft_init_stat(char *name, struct stat *buf)
{
	t_stat	*stat;

	if ((stat = malloc(sizeof(t_stat))) == NULL)
		return (NULL);
	stat->name = ft_strdup(name);
	stat->user = ft_strdup(getpwuid(buf->st_uid)->pw_name);
	stat->group = ft_strdup(getgrgid(buf->st_gid)->gr_name);
	stat->links = buf->st_nlink;
	stat->octets = buf->st_size;
	return (stat);
}
