/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 12:18:58 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 21:43:18 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	size;
	char			*new_str;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	i = ft_strlen(s);
	size = i;
	while (i-- && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		size--;
	if (!(new_str = ft_strnew(size)))
		return (NULL);
	new_str = ft_strncpy(new_str, s, size);
	new_str[size + 1] = 0;
	return (new_str);
}
