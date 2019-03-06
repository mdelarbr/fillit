/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 17:50:26 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/16 17:50:29 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <time.h>
# include <stdio.h>

typedef struct			s_pos
{
	int		x;
	int		y;
}						t_pos;

typedef	struct			s_tetrominos
{
	t_pos					*p[4];
	t_pos					*result;
	char					c;
	struct s_tetrominos		*next;
	struct s_tetrominos		*last;
}						t_tetrominos;

int						ft_error(int error);
t_tetrominos			*put_tetro_list(int fd);
t_tetrominos			*put_single_node(int op, t_tetrominos *last
, char ***line);
t_pos					*ft_put_point(int x, int y);

void					ft_del_point(t_pos *pos);
void					ft_del_tetro(t_tetrominos **tetrominos);
void					ft_del_list(t_tetrominos **tetrominos);

t_tetrominos			*put_single_tetro(t_tetrominos *tetro
, char **single_tetro, char l_tetro);
void					align_tetro(t_tetrominos *tetro);
int						verif_coord(char **single_tetro, int nb_tetro, int i);
char					**create_result(int size);
int						btk(t_tetrominos *ptetri, char **result);
int						place_tetri(t_tetrominos *ptetri, char **result);
int						place_tetri_bis(t_tetrominos *ptetri, char **result);
char					**create_result(int size);
void					display(char **result);

#endif
