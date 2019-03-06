/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <husahuc@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/18 18:06:39 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/19 13:21:43 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

/*
** Function that display the error message
*/

int		ft_error(int error)
{
	if (error == 1)
		ft_putendl("usage: fillit source_file");
	else
		ft_putendl("error");
	return (0);
}

/*
**  Function that display the result of the smallest square.
*/

void	display(char **result)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	size = ft_strlen(result[1]);
	while (i < size - 1)
	{
		j = 1;
		while (j < size - 1)
		{
			ft_putchar(result[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

/*
** Function that solve to find the smallest square of all tetros.
** infinite loop with check the result, and if false increase the size of the
** square.
*/

int		solver(char **result, int size, t_tetrominos *lst_tetrominos)
{
	int			done;

	done = 1;
	while (done)
	{
		if (!(btk(lst_tetrominos, result)))
		{
			lst_tetrominos->result->x = 1;
			lst_tetrominos->result->y = 1;
			ft_strdel_2(result, size + 2);
			size++;
			result = create_result(size);
		}
		else
		{
			done = 0;
			display(result);
			ft_strdel_2(result, size + 2);
		}
	}
	return (0);
}

/*
** Function that verify the entry given and resolve the tetros.
*/

int		main(int argc, char **argv)
{
	int				op;
	char			**result;
	int				size;
	t_tetrominos	*lst_tetrominos;
	t_tetrominos	*start;

	size = 2;
	if (argc != 2)
		return (ft_error(1));
	if ((op = open(argv[1], O_RDONLY)) == -1)
		return (ft_error(0));
	if ((lst_tetrominos = put_tetro_list(op)) == NULL)
		return (ft_error(0));
	start = lst_tetrominos;
	result = create_result(size);
	solver(result, size, lst_tetrominos);
	ft_del_list(&start);
	return (0);
}
