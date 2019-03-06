/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 10:51:54 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 10:58:55 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int			ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char*)s1;
	ps2 = (unsigned char*)s2;
	i = 0;
	while (ps1[i] == ps2[i] && ps1[i] != '\0' && ps2[i] != '\0')
		i++;
	if (ps1[i] == ps2[i])
		return (0);
	else
		return (ps1[i] - ps2[i]);
}
