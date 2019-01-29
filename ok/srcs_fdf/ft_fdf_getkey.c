/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_getkey.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <lnieto@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 14:01:54 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 12:27:26 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

int		change_proj(t_vars *all2)
{
	all2->zoom = 1;
	if (all2->proj == 1)
		all2->proj = 2;
	else
		all2->proj = 1;
	ft_strdel(&all2->img_string);
	draw_image(all2);
	move_img(0, all2);
	return (0);
}

int		zoom(int zoom, t_vars *all2)
{
	all2->zoom += zoom;
	ft_strdel(&all2->img_string);
	draw_image(all2);
	move_img(0, all2);
	return (0);
}

int		high(int high, t_vars *all2)
{
	all2->high += high;
	ft_strdel(&all2->img_string);
	draw_image(all2);
	move_img(0, all2);
	return (0);
}

int		rotate_xyz(int keycode, t_vars *all2)
{
	if (keycode == 7)
		all2->rotatex += 0.1;
	else if (keycode == 1)
		all2->rotatex -= 0.1;
	else if (keycode == 16)
		all2->rotatey += 0.1;
	else if (keycode == 32)
		all2->rotatey -= 0.1;
	else if (keycode == 6)
		all2->rotatez += 0.1;
	else if (keycode == 0)
		all2->rotatez -= 0.1;
	ft_strdel(&all2->img_string);
	draw_image(all2);
	move_img(0, all2);
	return (0);
}

int		get_key(int keycode, t_vars *all)
{
	static t_vars		*all2 = NULL;

	if (all2 == NULL)
		all2 = all;
	if (keycode >= 123 && keycode <= 126)
		move_img(keycode, all2);
	if (keycode == 53)
		red_cross(0);
	else if (keycode == 67)
		high(1, all2);
	else if (keycode == 75 && all2->high > 1)
		high(-1, all2);
	else if (keycode == 4)
		zoom(-1, all2);
	else if (keycode == 5)
		zoom(1, all2);
	else if (keycode == 35)
		change_proj(all2);
	else
		rotate_xyz(keycode, all2);
	return (0);
}
