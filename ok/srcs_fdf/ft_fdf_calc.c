/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_calc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <lnieto@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 17:17:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 13:39:56 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

int		calc_x(int x, int z, int y, t_vars *all)
{
	int		dx;
	int		dz;
	int		dy;
	int		x1;

	dx = (x * cos(all->rotatez) - y * sin(all->rotatez)) + \
		(z * sin(all->rotatey) + x * cos(all->rotatey));
	dz = (z * cos(all->rotatex) + y * sin(all->rotatex)) + \
		(z * cos(all->rotatey) - x * sin(all->rotatey));
	if (dz <= 0 && all->proj != 1)
		dz = 1;
	if (all->proj != 1)
		x1 = (128 + ((dx * 2) / (dz + 2))) * all->zoom;
	else
		x1 = (dx - (dz / sqrt(2))) * all->zoom;
	return (x1);
}

int		calc_y(int y, int z, int x, t_vars *all)
{
	int		dy;
	int		dz;
	int		dx;
	int		y1;

	dx = (x * cos(all->rotatez) - y * sin(all->rotatez)) + \
		(z * sin(all->rotatey) + x * cos(all->rotatey));
	dy = (y * cos(all->rotatex) - z * sin(all->rotatex)) + \
		(x * sin(all->rotatez) + y * cos(all->rotatez)) / all->high;
	dz = (z * cos(all->rotatex) + y * sin(all->rotatex)) + \
		(z * cos(all->rotatey) - x * sin(all->rotatey));
	if (dz <= 0 && all->proj != 1)
		dz = 1;
	if (all->proj != 1)
		y1 = (128 + ((dy * 2) / (dz + 2))) * all->zoom;
	else
		y1 = ((dx + 2 * dy + dz) / sqrt(6)) * all->zoom;
	return (y1 + 625);
}

int		calc_extend(t_vars *all, int x1, int y1, int ret)
{
	if (ret == 1)
	{
		all->x2 = calc_x(all->x[all->index + 1], all->z[all->index + 1], \
				all->y[all->index + 1], all);
		all->y2 = calc_y(all->y[all->index + 1], all->z[all->index + 1], \
				all->x[all->index + 1], all);
		print_pixel(all);
	}
	if (ret == 2)
	{
		all->x1 = x1;
		all->y1 = y1;
		all->x2 = calc_x(all->x[all->index + all->len_line], all->z[all->index \
				+ all->len_line], all->y[all->index + all->len_line], all);
		all->y2 = calc_y(all->y[all->index + all->len_line], all->z[all->index \
				+ all->len_line], all->x[all->index + all->len_line], all);
		print_pixel(all);
	}
	return (0);
}

int		calc_point(t_vars *all)
{
	int		x1;
	int		y1;

	if (all->index >= all->max_p)
		return (0);
	all->x1 = calc_x(all->x[all->index], all->z[all->index], \
			all->y[all->index], all);
	all->y1 = calc_y(all->y[all->index], all->z[all->index], \
			all->x[all->index], all);
	x1 = all->x1;
	y1 = all->y1;
	if (all->index < (all->k - 1) || all->index < all->len_line - 1)
		calc_extend(all, x1, y1, 1);
	if (all->index + all->len_line <= all->max_p)
		calc_extend(all, x1, y1, 2);
	if (all->index >= all->k - 1)
		all->k += all->len_line;
	return (0);
}
