/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:45:16 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 16:38:10 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	find;

	i = 0;
	if (to_find[i] == '\0')
		return ((char*)str);
	while (str[i] && i < len)
	{
		find = 0;
		while (str[i + find] == to_find[find] && i + find < len)
		{
			find++;
			if (to_find[find] == '\0')
				return ((char*)&str[i]);
		}
		i++;
	}
	return (NULL);
}
