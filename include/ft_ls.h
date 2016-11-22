/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:01 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/22 12:33:24 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define OK 0

# define ERROR_OPTION "ft_ls : illegal option -- "
# define ERROR_USAGE "usage: ft_ls [-Ralrt] [file ...]"

# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

typedef char	t_bool;

/*
**	Structure
*/

typedef struct	s_flags
{
	t_bool		l;
	t_bool		rec;
	t_bool		a;
	t_bool		r;
	t_bool		t;
}				t_flags;

typedef struct	s_params
{
	char		**av;
	size_t		nb;
	size_t		base_nb;
}				t_params;

typedef struct	s_stat
{
	char		*name;
	char		*perms;
	char		*user;
	char		*group;
	char		*time;
	size_t		links;
	size_t		octets;
	size_t		block;
}				t_stat;

/*
**	Functions
*/

void			ft_sort_alpha(char ***tab);
void			ft_sort_revalpha(char ***tab);
void			ft_sort_time(char *name, char ***tab);
void			ft_free_stat(t_stat *stats);
void			ft_print_init(char *name, char *str,
							t_flags *flags, t_params *params);
void			ft_print_char(char c, size_t n);
void			ft_lnk(t_stat **stats, char *name, char *lnk, int ret);
int				ft_isdir(const char *path);
int				ft_init_flags(t_flags **flags, int ac, char **av);
int				ft_dirorp(char *name, t_flags *flags, t_params *params);
size_t			ft_getnbdigit(size_t nbr);
size_t			ft_max_int(t_stat **stats, int in);
size_t			ft_max_length(t_stat **stats, int in);
char			*ft_setpath(char *path, char *name, int clean);
char			*ft_gettime(char *path, char *name);
t_stat			*ft_init_stat(char *name, struct stat *buf);
t_stat			*ft_stat(char *path, char *name);

#endif
