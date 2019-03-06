/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 12:33:00 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 15:39:24 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		i;

	i = 0;
	if (src > dest)
		return (ft_memcpy(dest, src, len));
	while (len--)
		((unsigned char*)dest)[len] = ((unsigned char*)src)[len];
	return (dest);
}
