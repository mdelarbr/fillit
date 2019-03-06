/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_tetrominos_bis.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 18:07:33 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 13:24:07 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that verify the number of edge of the part
** where is not an other part (egual to 8 or 10)
*/

int				verif_coord(char **single_tetro, int nb_tetro, int i)
{
	int nb;

	nb = 0;
	if (nb_tetro > 0 && single_tetro[nb_tetro - 1][i] == '#')
		nb++;
	if (nb_tetro < 3 && single_tetro[nb_tetro + 1][i] == '#')
		nb++;
	if (i > 0 && single_tetro[nb_tetro][i - 1] == '#')
		nb++;
	if (i < 3 && single_tetro[nb_tetro][i + 1] == '#')
		nb++;
	return (4 - nb);
}

/*
** function that will create and verify an tetro.
** uses the edge of the part where is not an other
** block must be equal to 8 (cubes) or 10. ALWAYS WORK.
*/

int				put_single_tetro_bis(char **single_tetro,
		t_tetrominos *tetro, int test)
{
	int	i;
	int	j;
	int k;

	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (single_tetro[i][j] == '#')
			{
				test += verif_coord(single_tetro, i, j);
				tetro->p[k++] = ft_put_point(j, i);
			}
			else if (single_tetro[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	if (k != 4)
		return (0);
	return (test);
}

/*
** Function that create an new element of type t_tetrominos, put the char, next
** and last
*/

t_tetrominos	*put_single_tetro(t_tetrominos *last,
	char *single_tetro[4], char l_tetro)
{
	int				test;
	t_tetrominos	*tetro;
	int				i;

	test = 0;
	if (!(tetro = malloc(sizeof(t_tetrominos))))
		return (NULL);
	if ((test = put_single_tetro_bis(single_tetro, tetro, test)) == 0)
		return (NULL);
	i = -1;
	while (++i < 4)
		free(single_tetro[i]);
	if ((test != 8 && test != 10))
		return (NULL);
	align_tetro(tetro);
	tetro->result = ft_put_point(1, 1);
	tetro->c = l_tetro;
	tetro->last = last;
	tetro->next = NULL;
	return (tetro);
}
