/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:53:55 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/13 13:24:09 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					ft_putnbr(int nbr)
{
	unsigned long int	rev;
	char				c;

	if ((long)nbr == -2147483648LL)
		ft_putstr("-2147483648");
	else
	{
		if (nbr < 0)
			ft_putchar('-');
		rev = ABS(nbr);
		rev = ft_revnbr(rev);
		while (rev != 1)
		{
			c = rev % 10 + '0';
			rev = rev / 10;
			ft_putchar(c);
		}
	}
}
