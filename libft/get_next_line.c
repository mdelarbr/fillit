/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 20:03:03 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/14 20:03:06 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int			get_str(const int fd, t_gnl_list **new_ptr)
{
	int			len;
	char		*buf;
	char		*temp;

	if (!(buf = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (1);
	if (!(*new_ptr = malloc(sizeof(t_gnl_list))))
		return (1);
	(*new_ptr)->str = ft_strnew(0);
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[len] = '\0';
		temp = (*new_ptr)->str;
		if (!((*new_ptr)->str = ft_strjoin((*new_ptr)->str, buf)))
			return (0);
		free(temp);
	}
	free(buf);
	(*new_ptr)->fd = fd;
	(*new_ptr)->next = 0;
	return (0);
}

static int			line_with_n(t_gnl_list **ptr_list, int i)
{
	char	*tmp;

	tmp = (*ptr_list)->str;
	(*ptr_list)->str = ft_strsub((*ptr_list)->str, i + 1,
			ft_strlen((*ptr_list)->str) - i);
	free(tmp);
	if (ft_strlen((*ptr_list)->str) == 0)
	{
		tmp = (*ptr_list)->str;
		(*ptr_list)->str = NULL;
		free(tmp);
	}
	return (1);
}

static int			find_line(char **line, t_gnl_list **ptr_list)
{
	int		i;

	i = 0;
	if ((*ptr_list)->str == NULL)
		return (0);
	while ((*ptr_list)->str[i] != '\n' && (*ptr_list)->str[i] != '\0')
		i++;
	*line = ft_strsub((*ptr_list)->str, 0, i);
	if ((*ptr_list)->str[i] == '\0' && ft_strlen((*ptr_list)->str) > 0)
	{
		(*ptr_list)->str = NULL;
		return (1);
	}
	else if ((*ptr_list)->str[i] == '\n')
		return (line_with_n(ptr_list, i));
	return (0);
}

static t_gnl_list	*get_lst_fd(int fd, t_gnl_list *ptr_list)
{
	t_gnl_list	*tmp;

	tmp = ptr_list;
	while (ptr_list != NULL)
	{
		if (ptr_list->fd == fd)
			return (ptr_list);
		ptr_list = ptr_list->next;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl_list	*ptr_list;
	t_gnl_list			*ptr_next;
	char				buf[0];

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buf, 0) == -1)
		return (-1);
	if (ptr_list == NULL)
	{
		if (get_str(fd, &ptr_list) == 1)
			return (-1);
		ptr_next = ptr_list;
	}
	else
	{
		ptr_next = get_lst_fd(fd, ptr_list);
		if (fd == ptr_next->fd)
			return (find_line(line, &ptr_next));
		if (get_str(fd, &ptr_next->next) == 1)
			return (-1);
		ptr_next = ptr_next->next;
	}
	return (find_line(line, &ptr_next));
}
