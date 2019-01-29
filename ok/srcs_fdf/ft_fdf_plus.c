/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_plus.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <lnieto@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 16:34:05 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/28 10:01:09 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

int		false_args(void)
{
	ft_putendl("usage: ./FdF [Map.fdf]");
	return (-1);
}

int		false_map(void)
{
	ft_putendl("Map error");
	return (-1);
}

int		red_cross(int key)
{
	exit(0);
	return (0);
}

void	make_help(t_vars *all)
{
	int		y;
	int		x;

	y = 0;
	while (y <= 1250)
	{
		x = 0;
		while (x <= 1250)
		{
			if (y >= 1075 && x <= 400)
				mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, 0x8d8d8d);
			x++;
		}
		y++;
	}
	mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 1100, 0xffffff, \
			"press arrow to move camera");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 1150, 0xffffff, \
			"press '+' or '-' for zoom");
	mlx_string_put(all->mlx_ptr, all->win_ptr, 10, 1200, 0xffffff, \
			"press '*' or '/' for change Z value");
}
