/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_fdf.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/18 17:11:34 by vasalome     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 17:16:23 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

int		main(int ac, char **av)
{
	vars	all;

	if (ac != 2)
		return (false_args());
	all.img_pos_x = 0;
	all.img_pos_y = 0;
	all.rotate = 0;
	all.proj = 1;
	all.zoom = 1;
	all.high = 1;
	all.map_name = av[1];
	all.mlx_ptr = mlx_init();
	all.win_ptr = mlx_new_window(all.mlx_ptr, 1250, 1250, "FdF Lnieto!");
	draw_image(&all);
	mlx_put_image_to_window(all.mlx_ptr, all.win_ptr, all.img_ptr, 0, 0);
	make_windows(&all);
	get_key(-1, &all);
	mlx_key_hook(all.win_ptr, get_key, (void *)0);
	mlx_hook(all.win_ptr, 17, 0, red_cross, (void *)0);
	mlx_loop(all.mlx_ptr);
	return (0);
}