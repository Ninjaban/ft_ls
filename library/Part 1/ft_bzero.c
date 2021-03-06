/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:04:35 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/13 13:14:55 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero(void *str, size_t n)
{
	char	*dst;

	if (str)
	{
		dst = str;
		while (n != 0)
		{
			*dst++ = 0;
			n--;
		}
	}
}
