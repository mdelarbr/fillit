/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdelone.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/05 09:10:14 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/07 17:09:57 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstdelone(t_list **alts, void (*del)(void *, size_t))
{
	if (alts && *alts)
	{
		del((*alts)->content, (*alts)->content_size);
		free(*alts);
		*alts = NULL;
	}
}
