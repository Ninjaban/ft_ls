/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:11:21 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/04 11:21:03 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char *src)
{
	char	*str;
	int		n;

	n = -1;
	if ((str = malloc(ft_strlen(src) + 1)) == NULL)
		return (NULL);
	while (src[++n])
		str[n] = src[n];
	str[n] = '\0';
	return (str);
}
