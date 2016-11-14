/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:01 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/14 14:33:22 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define OK 0

# define ERROR_OPTION "ft_ls : option non valide -- "

typedef char	t_bool;

# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <time.h>

/*
**	Structure
*/

typedef struct	s_flags
{
	t_bool		l;
	t_bool		R;
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

/*
**	Functions
*/

void		ft_sort_alpha(char ***tab);
void		ft_sort_revalpha(char ***tab);
void		ft_sort_time(char *name, char ***tab);
int			ft_isdir(const char *path);
int			ft_stat(const char *path);
int			ft_init_flags(t_flags **flags, int ac, char **av);
int			ft_dirORP(char *name, t_flags *flags, t_params *params);
char		*ft_setPATH(char *path, char *name);
char		*ft_getTime(char *path, char *name);

#endif
