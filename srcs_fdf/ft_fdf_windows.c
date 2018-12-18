/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_windows.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 16:38:56 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 18:36:35 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

void	make_bg2(t_vars *all)
{
	int		y;
	int		x;

	y = 0;
	while (y <= 1250)
	{
		x = 0;
		while (x <= 1250)
		{
			mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, 0xbababa);
			x++;
		}
		y++;
	}
}

void	make_bg(t_vars *all)
{
	int		y;

	y = 0;
	while (y < 100000000)
	{
		all->img_string[y] = (char)255;
		y++;
	}
}

int		make_windows(t_vars *all)
{
	int		x;
	int		y;

	y = 0;
	while (y <= 1250)
	{
		x = 0;
		while (x <= 1250)
		{
			if (y <= 120)
				mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, 0x940202);
			else if (y <= 122)
				mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, 0x810000);
			x++;
		}
		y++;
	}
	make_help(all);
	mlx_string_put(all->mlx_ptr, all->win_ptr, \
			525, 50, 0xffffff, "FdF Lnieto/Vasalome");
	return (0);
}

int		move_img(int dir, t_vars *all)
{
	mlx_clear_window(all->mlx_ptr, all->win_ptr);
	if (dir == 123)
		all->img_pos_x += 10;
	else if (dir == 124)
		all->img_pos_x -= 10;
	else if (dir == 125)
		all->img_pos_y -= 10;
	else if (dir == 126)
		all->img_pos_y += 10;
	make_bg2(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
			all->img_ptr, all->img_pos_x, all->img_pos_y);
	make_windows(all);
	return (0);
}
