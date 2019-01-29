/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_last_circle.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <lnieto@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/01/07 13:08:36 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/07 13:09:23 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

int		e_circle(t_vars *all)
{
	int		dx;
	int		dy;
	int		e;

	e = all->y2 - all->y1;
	dx = e * 2;
	dy = (all->x1 - all->x2) * 2;
	while (all->y2 >= all->y1)
	{
		print_one_pixel(all);
		all->y1 += 1;
		if ((e = e - dy) <= 0)
		{
			all->x1 = all->x1 - 1;
			e = e + dx;
		}
	}
	return (0);
}

int		f_circle(t_vars *all)
{
	int		dx;
	int		dy;
	int		e;

	e = all->x1 - all->x2;
	dx = e * 2;
	dy = (all->y2 - all->y1) * 2;
	while (all->x1 >= all->x2)
	{
		print_one_pixel(all);
		all->x1 = all->x1 - 1;
		if ((e = e - dy) <= 0)
		{
			all->y1 = all->y1 + 1;
			e = e + dx;
		}
	}
	return (0);
}

int		g_circle(t_vars *all)
{
	int		dx;
	int		dy;
	int		e;

	e = all->y1 - all->y2;
	dx = e * 2;
	dy = (all->x2 - all->x1) * 2;
	while (all->y1 >= all->y2)
	{
		print_one_pixel(all);
		all->y1 -= 1;
		if ((e = e - dy) <= 0)
		{
			all->x1 = all->x1 + 1;
			e = e + dx;
		}
	}
	return (0);
}

int		h_circle(t_vars *all)
{
	int		dx;
	int		dy;
	int		e;

	e = all->x1 - all->x2;
	dx = e * 2;
	dy = (all->y2 - all->y1) * 2;
	while (all->x1 <= all->x2)
	{
		print_one_pixel(all);
		all->x1 = all->x1 + 1;
		if ((e = e - dy) >= 0)
		{
			all->y1 = all->y1 - 1;
			e = e + dx;
		}
	}
	return (0);
}
