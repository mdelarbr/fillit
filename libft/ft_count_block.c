/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_block.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 14:39:28 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 14:41:04 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int			ft_count_block(char const *str, char c)
{
	int	i;
	int	block;

	if (str[0] == '\0')
		return (0);
	i = 0;
	block = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i] != '\0' &&
				(str[i + 1] == c || str[i + 1] == '\0'))
			block++;
		i++;
	}
	return (block);
}
