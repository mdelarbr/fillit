/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/02 18:19:31 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 15:08:33 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char *buf1;
	unsigned char *buf2;

	buf1 = (unsigned char*)str1;
	buf2 = (unsigned char*)str2;
	while (n-- > 0)
	{
		*buf1++ = (unsigned char)*buf2++;
	}
	return (str1);
}
