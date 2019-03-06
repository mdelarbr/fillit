/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 20:02:10 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 20:02:13 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 3

typedef struct			s_gnl_list
{
	char				*str;
	int					fd;
	struct s_gnl_list	*next;
}						t_gnl_list;

int						get_next_line(const int fd, char **line);

#endif
