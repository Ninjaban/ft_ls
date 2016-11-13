/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 11:02:40 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/13 13:17:47 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *str, int c, size_t n)
{
	const unsigned char	*dst;
	size_t				i;

	dst = str;
	i = 0;
	while (i < n && (*dst != (unsigned char)c) && *dst != '\0')
	{
		i = i + 1;
		dst++;
	}
	if (*dst == (unsigned char)c)
		return ((void *)dst);
	else
		return (NULL);
}
