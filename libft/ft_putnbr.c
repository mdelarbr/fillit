/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/03 17:28:58 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/10/03 17:32:13 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	long nbl;

	nbl = n;
	if (nbl < 0)
	{
		ft_putchar('-');
		nbl = -nbl;
	}
	if (nbl < 10)
		ft_putchar(nbl + '0');
	else
	{
		ft_putnbr(nbl / 10);
		ft_putchar((nbl % 10) + '0');
	}
}
