/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_draw.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <lnieto@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 17:16:14 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 14:02:25 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

int		draw_line(t_vars *all)
{
	int		ok;

	ok = 0;
	all->co1 = 0;
	calc_point(all);
	all->index += 1;
	return (0);
}

int		draw_image(t_vars *all)
{
	int		k;

	k = 0;
	mlx_clear_window(all->mlx_ptr, all->win_ptr);
	ft_strdel(&all->img_string);
	all->img_ptr = mlx_new_image(all->mlx_ptr, 5000, 5000);
	all->max_p = 0;
	all->len_line = 0;
	all->index = 0;
	all->x1 = 0;
	all->y1 = 0;
	all->x2 = 0;
	all->y2 = 0;
	all->k = all->len_line;
	if (read_map(all) == -1)
	{
		false_map();
		return (-1);
	}
	all->img_string = mlx_get_data_addr(all->img_ptr, &all->bits, \
			&all->size_line, &all->endian);
	while (k++ < all->max_p)
		draw_line(all);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	make_help(all);
	return (0);
}
