/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/12 14:38:36 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/12 16:43:30 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (size == 0 || ptr)
	{
		if (!(new_ptr = (void*)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (new_ptr);
	}
	if (!(new_ptr = (void*)malloc(size)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, size);
		ft_memdel(&ptr);
	}
	return (new_ptr);
}
