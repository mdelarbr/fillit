/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_tetrominos_2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 18:07:12 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 13:06:58 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that align the first tetro to be up right.
** Can have negative value.
*/

void			align_tetro(t_tetrominos *tetro)
{
	int		min[3];
	int		i;

	i = 0;
	min[0] = 4;
	min[1] = 4;
	while (i < 4)
	{
		if ((tetro)->p[i]->x < min[0])
			min[0] = (tetro)->p[i]->x;
		if ((tetro)->p[i]->y < min[1])
			min[1] = (tetro)->p[i]->y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(tetro)->p[i]->x -= min[0];
		if (i == 0)
			min[2] = (tetro)->p[i]->x;
		(tetro)->p[i]->x -= min[2];
		(tetro)->p[i]->y -= min[1];
		i++;
	}
}

/*
** Function that put the tetro in an tab of chain of caracter,
** witch get next line, check if the number of line is good.
** And if is there multiple tetros, check the line between the Tetros.
*/

int				get_str_tetro(int fd, char *all_tetro[26][4])
{
	int		nb_part;
	int		op;
	int		nb_tetro;
	char	*line;

	nb_part = -1;
	while (++nb_part <= 25)
	{
		nb_tetro = -1;
		while (++nb_tetro < 4)
		{
			if ((op = get_next_line(fd, &line)) == -1
					|| ft_strlen(line) != 4)
				return (0);
			all_tetro[nb_part][nb_tetro] = ft_strdup(line);
			free(line);
		}
		if ((op = get_next_line(fd, &line)) == 0)
			break ;
		if (ft_strcmp(line, "") || nb_part == 25)
			return (0);
		free(line);
	}
	all_tetro[++nb_part][0] = NULL;
	return (1);
}

/*
** Function that get the tetros, and put it in the chained list(t_tetrominos)
*/

t_tetrominos	*put_tetro_list(int fd)
{
	t_tetrominos	*tetro;
	t_tetrominos	*start;
	char			*all_tetro[26][4];
	int				i;
	char			l_tetro;

	l_tetro = 'A';
	if (get_str_tetro(fd, all_tetro) == 0)
		return (NULL);
	if ((start = put_single_tetro(NULL, all_tetro[0], l_tetro)) == NULL)
		return (NULL);
	i = 1;
	tetro = start;
	while (all_tetro[i][0] != NULL)
	{
		if ((tetro->next =
			put_single_tetro(tetro, all_tetro[i], ++l_tetro)) == NULL)
			return (NULL);
		tetro = tetro->next;
		i++;
	}
	return (start);
}
