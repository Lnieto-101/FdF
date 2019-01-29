/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_windows.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <lnieto@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 16:38:56 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 12:26:47 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

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
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, \
			all->img_ptr, all->img_pos_x, all->img_pos_y);
	return (0);
}
