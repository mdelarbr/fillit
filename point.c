/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   point.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 18:06:55 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/18 18:06:57 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that put the point in t_pos.
*/

t_pos			*ft_put_point(int x, int y)
{
	t_pos	*pos;

	if (!(pos = malloc(sizeof(t_pos))))
		return (NULL);
	pos->x = x;
	pos->y = y;
	return (pos);
}

/*
** Function that remove the point t_pos
*/

void			ft_del_point(t_pos *pos)
{
	free(pos);
	pos = NULL;
}

/*
** Function that remove the tetro, and the point inside it.
*/

void			ft_del_tetro(t_tetrominos **tetromino)
{
	int i;

	if (tetromino && *tetromino)
	{
		i = -1;
		while (++i < 4)
			ft_del_point((*tetromino)->p[i]);
		ft_del_point((*tetromino)->result);
		free(*tetromino);
		*tetromino = NULL;
	}
}

/*
** Function that delete the chained list of t_tetrominos.
*/

void			ft_del_list(t_tetrominos **tetromino)
{
	if ((*tetromino)->next)
		ft_del_list(&(*tetromino)->next);
	ft_del_tetro(tetromino);
}
