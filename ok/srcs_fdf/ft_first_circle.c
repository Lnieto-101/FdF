/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_first_circle.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <lnieto@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 14:01:54 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 12:28:19 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

int		a_circle(t_vars *all)
{
	int		dx;
	int		dy;
	int		e;

	e = all->y2 - all->y1;
	dx = e * 2;
	dy = (all->x2 - all->x1) * 2;
	while (all->y1 >= all->y2)
	{
		print_one_pixel(all);
		all->y1 = all->y1 - 1;
		if ((e = e - dy) >= 0)
		{
			all->x1 = all->x1 - 1;
			e = e + dx;
		}
	}
	return (0);
}

int		b_circle(t_vars *all)
{
	int		dx;
	int		dy;
	int		e;

	e = all->x2 - all->x1;
	dx = e * 2;
	dy = (all->y2 - all->y1) * 2;
	while (all->x1 >= all->x2)
	{
		print_one_pixel(all);
		all->x1 = all->x1 - 1;
		if ((e = e - dy) >= 0)
		{
			all->y1 = all->y1 - 1;
			e = e + dx;
		}
	}
	return (0);
}

int		c_circle(t_vars *all)
{
	int		dx;
	int		dy;
	int		e;

	e = all->y2 - all->y1;
	dx = e * 2;
	dy = (all->x2 - all->x1) * 2;
	while (all->y1 <= all->y2)
	{
		print_one_pixel(all);
		all->y1 += 1;
		if ((e = e - dy) <= 0)
		{
			all->x1 = all->x1 + 1;
			e = e + dx;
		}
	}
	return (0);
}

int		d_circle(t_vars *all)
{
	int		dx;
	int		dy;
	int		e;

	e = all->x2 - all->x1;
	dx = e * 2;
	dy = (all->y2 - all->y1) * 2;
	while (all->x1 <= all->x2)
	{
		print_one_pixel(all);
		all->x1 += 1;
		if ((e = e - dy) <= 0)
		{
			all->y1 = all->y1 + 1;
			e = e + dx;
		}
	}
	return (0);
}
