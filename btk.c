/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   btk.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 18:06:17 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 11:49:02 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that verify then place the Tetros in the square
*/

int		place_tetri_bis(t_tetrominos *ptetri, char **result)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (result[ptetri->result->y +
		ptetri->p[i]->y][ptetri->result->x + ptetri->p[i]->x] != '.')
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		result[ptetri->result->y + ptetri->p[i]->y][ptetri->result->x +
			ptetri->p[i]->x] = ptetri->c;
		i++;
	}
	return (1);
}

/*
** Function that remove the tetros in the square.
*/

void	remove_tetri_bis(t_tetrominos *ptetri, char **result)
{
	int x;
	int y;

	x = 1;
	y = 1;
	while (result[y][1] != '&')
	{
		while (result[y][x] != '&')
		{
			if (result[y][x] == ptetri->c)
				result[y][x] = '.';
			x++;
		}
		x = 1;
		y++;
	}
}

/*
** Function that try to place the tetrominos in the square.
** Check on all the position avariable.
*/

int		place_tetri(t_tetrominos *ptetri, char **result)
{
	while (result[ptetri->result->y][1] != '&')
	{
		while (result[(ptetri)->result->y][(ptetri)->result->x] != '&')
		{
			if (result[(ptetri)->result->y][(ptetri)->result->x] == '.')
				if (place_tetri_bis(ptetri, result))
				{
					ptetri->result->x++;
					return (1);
				}
			(ptetri)->result->x++;
		}
		(ptetri)->result->x = 1;
		(ptetri)->result->y++;
	}
	(ptetri)->result->y = 1;
	return (0);
}

/*
** Function that create the square of char (result), malloc and put other
** symbols (&) in the outline.
*/

char	**create_result(int size)
{
	char	**result;
	int		x;
	int		y;

	y = 0;
	if (!(result = malloc(sizeof(char*) * (size + 2))))
		return (NULL);
	while (y < size + 2)
	{
		if (!(result[y] = ft_strnew(size + 2)))
			return (NULL);
		y++;
	}
	y = 0;
	while (y < (size + 2))
	{
		x = -1;
		while (++x < (size + 2))
			result[y][x] = (y == 0 || x == 0 || y == (size + 1)
			|| x == (size + 1)) ? '&' : '.';
		y++;
	}
	return (result);
}

/*
** Function that try to place the chained list in the square, return 0 if it
** do not have result in the square of this size.
*/

int		btk(t_tetrominos *ptetri, char **result)
{
	remove_tetri_bis(ptetri, result);
	while (ptetri != NULL)
	{
		remove_tetri_bis(ptetri, result);
		if (place_tetri(ptetri, result) == 1)
		{
			if (ptetri->next == NULL)
				return (1);
			else
				ptetri = ptetri->next;
		}
		else
		{
			if (ptetri->last == NULL)
				return (0);
			ptetri = ptetri->last;
		}
	}
	return (0);
}
