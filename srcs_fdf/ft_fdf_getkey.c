/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_getkey.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 14:01:54 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 18:25:32 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

int		get_key(int keycode, t_vars *all)
{
	static t_vars		*all2 = NULL;

	if (all2 == NULL)
		all2 = all;
	if (keycode >= 123 && keycode <= 126)
		move_img(keycode, all2);
	if (keycode == 53)
	{
		red_cross(0);
	}
	else if (keycode == 67)
	{
		all2->high += 1;
		draw_image(all2);
		move_img(0, all2);
	}
	else if (keycode == 75 && all2->high > 1)
	{
		all2->high -= 1;
		draw_image(all2);
		move_img(0, all2);
	}
	else if (keycode == 78)
	{
		all2->zoom -= 1;
		draw_image(all2);
		move_img(0, all2);
	}
	else if (keycode == 69)
	{
		all2->zoom += 1;
		draw_image(all2);
		move_img(0, all2);
	}
	else if (keycode == 35)
	{
		all2->zoom = 1;
		if (all2->proj == 1)
			all2->proj = 2;
		else
			all2->proj = 1;
		draw_image(all2);
		move_img(0, all2);
	}
	else if (keycode == 4)
	{
		all2->rotate += 2;
		draw_image(all2);
		move_img(0, all2);
	}
	else if (keycode == 5)
	{
		all2->rotate -= 2;
		draw_image(all2);
		move_img(0, all2);
	}
	printf("key = %d\n", keycode);
	return (0);
}
