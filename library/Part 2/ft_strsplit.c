/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarra <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 09:04:45 by jcarra            #+#    #+#             */
/*   Updated: 2016/11/21 11:21:02 by jcarra           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_tab(char **tab)
{
	int		n;

	n = 0;
	while (tab[n])
	{
		free(tab[n]);
		tab[n++] = NULL;
	}
	free(tab);
	tab = NULL;
}

static int	count_word(char const *s, char c)
{
	int		n;
	int		word;

	n = 0;
	word = 0;
	while (s[n] == c && s[n])
		n = n + 1;
	while (s[n])
	{
		word = word + 1;
		while (s[n] && s[n] != c)
			n = n + 1;
		while (s[n] == c && s[n])
			n = n + 1;
	}
	return (word);
}

static int	size_word(char const *s, char c, int n)
{
	int		len;

	len = 0;
	while (s[n + len] && s[n + len] != c)
		len = len + 1;
	return (len);
}

static char	**complete_tab(char const *s, char c, char **tab)
{
	int		n;
	int		i;
	int		j;

	n = 0;
	i = 0;
	while (s[n] == c && s[n])
		n = n + 1;
	while (s[n])
	{
		if ((tab[i] = malloc(size_word(s, c, n) + 1)) == NULL)
			return (NULL);
		j = 0;
		while (s[n] && s[n] != c)
			tab[i][j++] = s[n++];
		tab[i++][j] = '\0';
		while (s[n] == c && s[n])
			n = n + 1;
	}
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	char	**sav;
	int		word;

	if (s == NULL)
		return (NULL);
	if ((word = count_word(s, c)) == 0)
		return (NULL);
	if ((tab = malloc(sizeof(char *) * (word + 1))) == NULL)
		return (NULL);
	while (word >= 0)
		tab[word--] = NULL;
	sav = tab;
	if ((tab = complete_tab(s, c, tab)) == NULL)
		ft_free_tab(sav);
	return (tab);
}
