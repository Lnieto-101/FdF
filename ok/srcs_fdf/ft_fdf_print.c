/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_print.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <lnieto@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 14:01:54 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 12:51:42 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

int		print_one_pixel(t_vars *all)
{
	int		ok;

	ok = 0;
	while (ok != 4 && (4 * all->x1) < 20000 && \
			(all->y1 * 20000) > 0 && (all->y1 * 20000) < 100000000)
	{
		if (ok < 2)
			all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) \
				+ ok++] = (char)(all->y[all->index] % 255) + 255;
		else
			all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) +\
				ok++] = (char)0;
	}
	return (0);
}

int		print_pixel(t_vars *all)
{
	if (all->x1 < 0 || y1 < 0 || all->x2 < 0 || all->y2 < 0)
		return (1);
	if (all->x1 >= all->x2 && all->y1 >= all->y2)
		if (all->y1 - all->y2 >= all->x1 - all->x2)
			a_circle(all);
		else
			b_circle(all);
	else if (all->x1 <= all->x2 && all->y1 <= all->y2)
		if (all->y2 - all->y1 >= all->x2 - all->x1)
			c_circle(all);
		else
			d_circle(all);
	else if (all->x1 >= all->x2 && all->y1 <= all->y2)
		if (all->y2 - all->y1 >= all->x1 - all->x2)
			e_circle(all);
		else
			f_circle(all);
	else if (all->x1 <= all->x2 && all->y1 >= all->y2)
	{
		if (all->y1 - all->y2 >= all->x2 - all->x1)
			g_circle(all);
		else
			h_circle(all);
	}
	return (0);
}
