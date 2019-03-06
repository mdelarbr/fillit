/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 10:17:36 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/10 13:43:12 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*ptr_new;
	size_t	i;

	if (!(ptr_new = (char*)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (size-- > 0)
	{
		ptr_new[i++] = '\0';
	}
	ptr_new[i] = '\0';
	return (ptr_new);
}
