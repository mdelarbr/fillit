/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 19:40:08 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 19:49:04 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t s;
	size_t len;

	i = 0;
	len = ft_strlen(dest);
	while (dest[i] != '\0')
		i++;
	s = 0;
	while (src[s] != '\0' && i < n - 1 && n)
	{
		dest[i] = src[s];
		s++;
		i++;
	}
	dest[i] = '\0';
	if (len < n)
		return (len + ft_strlen((char *)src));
	return (n + ft_strlen((char *)src));
}
