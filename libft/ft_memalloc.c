/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 09:55:30 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/04 10:05:50 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	size_t	*ptr_new;
	int		i;

	if (!(ptr_new = malloc(size * sizeof(size_t))))
		return (NULL);
	i = 0;
	while (size--)
	{
		ptr_new[i] = 0;
		i++;
	}
	return ((void*)ptr_new);
}
