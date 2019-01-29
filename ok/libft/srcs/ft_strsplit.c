/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 14:52:06 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/01 15:51:53 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		count_letters(char *str, int i, char c)
{
	int		nb;

	nb = 0;
	while ((str[i] != c) && str[i])
	{
		nb++;
		i++;
	}
	return (nb);
}

static int		count_words(char *str, char c)
{
	int		i;
	int		word;
	int		space;
	int		nb;

	i = 0;
	word = 0;
	space = 1;
	nb = 0;
	while (str[i])
	{
		if ((str[i] != c) && !word)
		{
			word = 1;
			space = 0;
			nb++;
		}
		if ((str[i] == c) && !space)
		{
			space = 1;
			word = 0;
		}
		i++;
	}
	return (nb);
}

static char		**ft_whitespaces(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	tab = NULL;
	j = 0;
	i = 0;
	if (!(tab = malloc(sizeof(char *) * (count_words((char *)s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			k = 0;
			tab[j] = malloc(sizeof(char) * count_letters((char *)s, i, c) + 1);
			while (s[i] != c && s[i])
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	if (s)
		return (ft_whitespaces(s, c));
	return (NULL);
}
