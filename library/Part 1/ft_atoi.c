/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:08:31 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/13 13:17:06 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int	nbr;
	int	n;
	int	neg;

	neg = 1;
	n = 0;
	nbr = 0;
	if (!str)
		return (0);
	while (str[n] == '\t' || str[n] == '\v' || str[n] == '\f' ||
			str[n] == '\r' || str[n] == '\n' || str[n] == ' ')
		n = n + 1;
	if (str[n] == '-')
		neg = -1;
	n = (str[n] == '-' || str[n] == '+') ? n + 1 : n;
	while (str[n] != '\0' && (str[n] >= '0' && str[n] <= '9'))
	{
		nbr = nbr * 10 + (str[n] - '0');
		n = n + 1;
	}
	nbr = nbr * neg;
	return (nbr);
}
