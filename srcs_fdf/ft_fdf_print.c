/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_print.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 14:01:54 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 18:26:20 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

int		print_pixel(t_vars *all)
{
	int		dx;
	int		dy;
	int		e;
	int		ok;

	ok = 0;
	if (all->x1 < 0 || y1 < 0 || all->x2 < 0 || all->y2 < 0)
		return (1);
	if (all->x1 >= all->x2 && all->y1 >= all->y2)
	{
		if (all->y1 - all->y2 >= all->x1 - all->x2)
		{
			e = all->y2 - all->y1;
			dx = e * 2;
			dy = (all->x2 - all->x1) * 2;
			while (all->y1 >= all->y2)
			{
				ok = 0;
				while (ok != 4 && (4 * all->x1) < 20000 && (all->y1 * 20000) > 0 && (all->y1 * 20000) < 100000000)
				{
					if (ok < 2)
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
					else
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)0;
				}
				all->y1 = all->y1 - 1;
				if ((e = e - dy) >= 0)
				{
					all->x1 = all->x1 - 1;
					e = e + dx;
				}
			}
		}
		else
		{
			e = all->x2 - all->x1;
			dx = e * 2;
			dy = (all->y2 - all->y1) * 2;
			while (all->x1 >= all->x2)
			{
				ok = 0;
				while (ok != 4 && (4 * all->x1) < 20000 && (all->y1 * 20000) > 0 && (all->y1 * 20000) < 100000000)
				{
					if (ok < 2)
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
					else
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)0;
				}
				all->x1 = all->x1 - 1;
				if ((e = e - dy) >= 0)
				{
					all->y1 = all->y1 - 1;
					e = e + dx;
				}
			}
		}
	}
	if (all->x1 <= all->x2 && all->y1 <= all->y2)
	{
		if (all->y2 - all->y1 >= all->x2 - all->x1)
		{
			e = all->y2 - all->y1;
			dx = e * 2;
			dy = (all->x2 - all->x1) * 2;
			while (all->y1 <= all->y2)
			{
				ok = 0;
				while (ok != 4 && (4 * all->x1) < 20000 && (all->y1 * 20000) > 0 && (all->y1 * 20000) < 100000000)
				{
					if (ok < 2)
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
					else
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)0;
				}
				all->y1 += 1;
				if ((e = e - dy) <= 0)
				{
					all->x1 = all->x1 + 1;
					e = e + dx;
				}
			}
		}
		else
		{
			e = all->x2 - all->x1;
			dx = e * 2;
			dy = (all->y2 - all->y1) * 2;
			while (all->x1 <= all->x2)
			{
				ok = 0;
				while (ok != 4 && (4 * all->x1) < 20000 && (all->y1 * 20000) > 0 && (all->y1 * 20000) < 100000000)
				{
					if (ok < 2)
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
					else
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)0;
				}
				all->x1 += 1;
				if ((e = e - dy) <= 0)
				{
					all->y1 = all->y1 + 1;
					e = e + dx;
				}
			}
		}
	}
	if (all->x1 >= all->x2 && all->y1 <= all->y2)
	{
		if (all->y2 - all->y1 >= all->x1 - all->x2)
		{
			e = all->y2 - all->y1;
			dx = e * 2;
			dy = (all->x1 - all->x2) * 2;
			while (all->y2 >= all->y1)
			{
				ok = 0;
				while (ok != 4 && (4 * all->x1) < 20000 && (all->y1 * 20000) > 0 && (all->y1 * 20000) < 100000000)
				{
					if (ok < 2)
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
					else
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)0;
				}
				all->y1 += 1;
				if ((e = e - dy) <= 0)
				{
					all->x1 = all->x1 - 1;
					e = e + dx;
				}
			}
		}
		else
		{
			e = all->x1 - all->x2;
			dx = e * 2;
			dy = (all->y2 - all->y1) * 2;
			while (all->x1 >= all->x2)
			{
				ok = 0;
				while (ok != 4 && (4 * all->x1) < 20000 && (all->y1 * 20000) > 0 && (all->y1 * 20000) < 100000000)
				{
					if (ok < 2)
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
					else
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)0;
				}
				all->x1 = all->x1 - 1;
				if ((e = e - dy) <= 0)
				{
					all->y1 = all->y1 + 1;
					e = e + dx;
				}
			}
		}
	}
	if (all->x1 <= all->x2 && all->y1 >= all->y2)
	{
		if (all->y1 - all->y2 >= all->x2 - all->x1)
		{
			e = all->y1 - all->y2;
			dx = e * 2;
			dy = (all->x2 - all->x1) * 2;
			while (all->y1 >= all->y2)
			{
				ok = 0;
				while (ok != 4 && (4 * all->x1) < 20000 && (all->y1 * 20000) > 0 && (all->y1 * 20000) < 100000000)
				{
					if (ok < 2)
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
					else
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)0;
				}
				all->y1 -= 1;
				if ((e = e - dy) <= 0)
				{
					all->x1 = all->x1 + 1;
					e = e + dx;
				}
			}
		}
		else
		{
			e = all->x1 - all->x2;
			dx = e * 2;
			dy = (all->y2 - all->y1) * 2;
			while (all->x1 <= all->x2)
			{
				ok = 0;
				while (ok != 4 && (4 * all->x1) < 20000 && (all->y1 * 20000) > 0 && (all->y1 * 20000) < 100000000)
				{
					if (ok < 2)
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
					else
						all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)0;
				}
				mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 0xffffff);
				all->x1 = all->x1 + 1;
				if ((e = e - dy) >= 0)
				{
					all->y1 = all->y1 - 1;
					e = e + dx;
				}
			}
		}
	}
	return (0);
}
