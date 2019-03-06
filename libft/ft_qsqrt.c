/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_qsqrt.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: husahuc <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/27 16:21:49 by husahuc      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/03 18:23:51 by husahuc     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

/*
** this is a reproduction of the fast inverse square root used in the code of
** Quake, based on this video . https://www.youtube.com/watch?v=4nShTeUEJIQ
*/

float	ft_qsqrt(float number)
{
	long		i;
	float		x2;
	float		y;
	float		th;

	th = 1.5F;
	x2 = number * 0.5F;
	y = number;
	i = *(long*)&y;
	i = 0x5f3759df - (i >> 1);
	y = *(float*)&i;
	y = y * (th - (x2 * y * y));
	y = y * (th - (x2 * y * y));
	return (1 / y);
}
