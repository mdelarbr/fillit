/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 13:56:19 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 21:36:13 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_split(char const *str, char c,
		char **tab, unsigned int nb_block)
{
	unsigned int		block;
	unsigned int		f;
	unsigned int		i;
	unsigned int		len_word;

	block = 0;
	i = 0;
	while (block < nb_block)
	{
		f = 0;
		len_word = 0;
		while (str[i] == c)
			i++;
		if (!(tab[block] = (char*)malloc((ft_count_word(str, c, i) + 1)
						* sizeof(char))))
			return (NULL);
		while (str[i] != '\0' && str[i] != c)
			tab[block][f++] = str[i++];
		tab[block][f] = '\0';
		block++;
	}
	tab[block] = 0;
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	nb_block;

	if (!s)
		return (NULL);
	nb_block = ft_count_block(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (nb_block + 1))))
		return (NULL);
	tab = ft_split(s, c, tab, nb_block);
	return (tab);
}
