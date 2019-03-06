/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 12:44:05 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/02 15:12:35 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (INFINITE)
	{
		if (str[i] == '\0')
			return (i);
		if (str[i + 1] == '\0')
			return (i + 1);
		if (str[i + 2] == '\0')
			return (i + 2);
		if (str[i + 3] == '\0')
			return (i + 3);
		if (str[i + 4] == '\0')
			return (i + 4);
		if (str[i + 5] == '\0')
			return (i + 5);
		if (str[i + 6] == '\0')
			return (i + 6);
		if (str[i + 7] == '\0')
			return (i + 7);
		i += 8;
	}
}
