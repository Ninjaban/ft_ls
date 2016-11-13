/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 12:32:01 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/13 14:29:39 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define OK 0

typedef char	t_bool;

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

t_flags		ft_init_flags(t_flags **flags, int ac, char **av);


#endif
