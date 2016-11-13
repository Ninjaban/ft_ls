/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:01 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/13 17:24:32 by jcarra           ###   ########.fr       */
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
# include <dirent.h>

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

/*
**	Functions
*/

int			ft_init_flags(t_flags **flags, int ac, char **av);
int			ft_dirORP(char *name, t_flags *flags);

#endif
