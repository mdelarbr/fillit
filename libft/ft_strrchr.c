/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 14:44:53 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 14:52:10 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	int len;

	len = ft_strlen(str);
	while (len > 0)
	{
		if (str[len] == (const char)c)
			return ((char*)&str[len]);
		len--;
	}
	if (str[len] == (const char)c)
		return ((char*)&str[len]);
	return (NULL);
}
