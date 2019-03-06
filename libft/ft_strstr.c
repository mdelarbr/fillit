/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 11:37:59 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 15:41:21 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(char *str, char *to_find)
{
	int i;
	int find;

	i = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		find = 0;
		while (str[i + find] == to_find[find])
		{
			find++;
			if (to_find[find] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
