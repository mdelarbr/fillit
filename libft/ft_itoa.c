/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 16:22:20 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/05 18:12:34 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int nb)
{
	int len;

	len = 0;
	if (nb > 0)
	{
		while (nb > 0)
		{
			len++;
			nb = nb / 10;
		}
	}
	else
		return (count_len(-nb) + 1);
	return (len);
}

char		*ft_itoa(int n)
{
	char	*new_nb;
	int		i;
	int		ng;

	ng = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(new_nb = ft_strnew(count_len(n))))
		return (NULL);
	i = count_len(n) - 1;
	if (n < 0)
	{
		new_nb[0] = '-';
		n = -n;
		ng = 1;
	}
	while (i >= ng)
	{
		new_nb[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (new_nb);
}
