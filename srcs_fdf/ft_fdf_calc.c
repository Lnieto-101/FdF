/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_calc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 17:17:35 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 18:24:48 by vasalome    ###    #+. /#+    ###.fr     */
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

	dx = x;
	dz = z;
	if (dz <= 0 && all->proj != 1)
		dz = 1;
	if (all->proj != 1)
	{
		x1 = (64 + ((dx * 64) / (dz + 2.5))) * all->zoom;
	}
	else
	{
		x1 = (dx - (dz / sqrt(2))) * all->zoom;
	}
	return (x1);
}

int		calc_y(int y, int z, int x, t_vars *all)
{
	int		dy;
	int		dz;
	int		dx;
	int		y1;

	dx = x;
	dy = y / all->high;
	dz = z;
	if (dz <= 0 && all->proj != 1)
		dz = 1;
	if (all->proj != 1)
	{
		dx = ((cos(all->rotate) * y) - (sin(all->rotate) * z));
		dz = (-(sin(all->rotate) * y) + (cos(all->rotate) * z));
		y1 = (64 + ((dy * 64) / (dz + 2.5))) * all->zoom;
	}
	else
	{
		y1 = ((dx + 2 * dy + dz) / sqrt(6)) * all->zoom;
	}
	return (y1 + 625);
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
	{
		all->x2 = calc_x(all->x[all->index + 1], all->z[all->index + 1], \
				all->y[all->index + 1], all);
		all->y2 = calc_y(all->y[all->index + 1], all->z[all->index + 1], \
				all->x[all->index + 1], all);
		print_pixel(all);
	}
	if (all->index + all->len_line <= all->max_p)
	{
		all->x1 = x1;
		all->y1 = y1;
		all->x2 = calc_x(all->x[all->index + all->len_line], all->z[all->index \
				+ all->len_line], all->y[all->index + all->len_line], all);
		all->y2 = calc_y(all->y[all->index + all->len_line], all->z[all->index \
				+ all->len_line], all->x[all->index + all->len_line], all);
		print_pixel(all);
	}
	if (all->index >= all->k - 1)
	{
		all->k += all->len_line;
	}
	return (0);
}
