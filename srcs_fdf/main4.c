/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main4.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <lnieto@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 14:01:54 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 15:26:44 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/mlx.h"
#include "../libft/includes/libft.h"
#include <math.h>
#include <stdio.h>

typedef	struct	s_point
{
	int		x;
	int		y;
	int		z;
}				point;

typedef	struct	s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*map_name;
	char	*img_string;
	int		bits;
	int		size_line;
	int		endian;
	int		max_p;
	int		*x;
	int		*y;
	int		*z;
	int		img_pos_x;
	int		img_pos_y;
	int		index;
	int		co1;
	int		x1;
	int		y1;
	int		co2;
	int		x2;
	int		y2;
	int		len_line;
	int		zoom;
	int		high;
	int		k;
}				vars;

int		draw_image(vars *all);

int		false_args()
{
	printf("usage: ./FdF [Map.fdf]");
	return (-1);
}

int		red_cross(int key)
{
	exit(0);
	return (0);
}

int		make_windows(vars *all)
{
	int		x;
	int		y;

	y = 0;
	while (y <= 1250)
	{
		x = 0;
		while (x <= 1250)
		{
			if (y <= 150 || y >= 1200)
				mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, 0x525252);
			else if (x <= 20 || x >= 1230)
				mlx_pixel_put(all->mlx_ptr, all->win_ptr, x, y, 0x525252);
			x++;
		}
		y++;
	}
	mlx_string_put(all->mlx_ptr, all->win_ptr, 525, 60, 0xffffff, "FdF Lnieto/Vasalome");
	return (0);
}  

int		move_img(int dir, vars *all)
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
	//printf("x = %d\ny = %d\n\n", all->img_pos_x, all->img_pos_y);
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, all->img_pos_x, all->img_pos_y);
	make_windows(all);
	return (0);
}

int		get_key(int keycode, vars *all)
{
	static vars		*all2 = NULL;

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
	else if (keycode == 78 && all2->zoom > 1)
	{
		all2->zoom -= 1;
		draw_image(all2);
		move_img(0, all2);
	}
	else if (keycode == 69/* && all2->zoom < 15*/)
	{
		all2->zoom += 1;
		draw_image(all2);
		move_img(0, all2);
	}
	return (0);
}

int     *tab_zero(int *tab)
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	return (tab);
}

int		*split_bcl(char **split, int *tab, vars *all)
{
	while (split[tab[0]])
	{
		if (all->max_p != 0)
		{
			all->z[tab[3]] = -tab[0];
			all->x[tab[3]] = tab[1];
			all->y[tab[3]] = -ft_atoi(split[tab[0]]);
		}
		else
			tab[2] += 1;
		tab[0] += 1;
		tab[3] += 1;
	}
	if (all->len_line == 0)
		all->len_line = tab[3];
	tab[1] += 1;
	return (tab);
}

int		malloc_coord(vars *all)
{
	if (!(all->x = malloc(sizeof(int) * (all->max_p + 1))))
		return (-1);
	if (!(all->y = malloc(sizeof(int) * (all->max_p + 1))))
		return (-1);
	if (!(all->z = malloc(sizeof(int) * (all->max_p + 1))))
		return (-1);
	return (0);
}

int		read_map(vars *all)
{
	int		fd;
	char	*line;
	int		*tab;
	char	**split;

	if (!(tab = malloc(sizeof(int) * (4 + 1))))
		return (-1);
	tab = tab_zero(tab);
	if (all->max_p != 0)
		malloc_coord(all);
	fd = open(all->map_name, O_RDONLY);
	while (ft_get_next_line(fd, &line) > 0)
	{
		split = ft_strsplit(line, ' ');
		tab[0] = 0;
		tab = split_bcl(split, tab, all);
	}
	close(fd);
	if (all->max_p != 0)
		return (0);
	else
	{
		all->max_p = tab[2];
		return (read_map(all));
	}
}

int		print_pixel(vars *all)
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
				while (ok != 2 && (4 * all->x1) < 20000)
					all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
				// mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 0xffffff);
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
				while (ok != 2 && (4 * all->x1) < 20000)
					all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
				//mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 0xffffff);
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
				while (ok != 2 && (4 * all->x1) < 20000 && all->y1 * 20000 < 100000000)
					all->img_string[((0 + 4 * all->x1) + (4 * 5000) * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
				mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 0xffffff);
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
				while (ok != 2 && (4 * all->x1) < 20000 && all->y1 * 20000 < 100000000)
					all->img_string[((0 + 4 * all->x1) + (4 * 5000) * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
				mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 0xffffff);
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
				while (ok != 2 && (4 * all->x1) < 20000)
					all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
				//mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 0xffffff);
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
				while (ok != 2 && (4 * all->x1) < 20000)
					all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
				//mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 0xffffff);
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
				while (ok != 2 && (4 * all->x1) < 20000)
					all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
				//mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 0xffffff);
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
				while (ok != 2 && (4 * all->x1) < 20000)
					all->img_string[((0 + 4 * all->x1) + 4 * 5000 * all->y1) + ok++] = (char)(255 - all->y[all->index] * 2);
				//mlx_pixel_put(all->mlx_ptr, all->win_ptr, all->x1, all->y1, 0xffffff);
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

int		calc_x(int x, int z, int zoom)
{
	int		dx;
	int		dz;
	int		x1;

	dx = x;
	dz = z;
	x1 = (dx - (dz / sqrt(2))) * zoom;
	return (x1 + 625);
}

int		calc_y(int y, int z, int x, int zoom, int high)
{
	int		dy;
	int		dz;
	int		dx;
	int		y1;

	dx = x;
	dy = y / high;
	dz = z;
	y1 = ((dx + 2 * dy + dz) / sqrt(6)) * zoom;
	return (y1 + 625);
}

int		calc_point(vars *all)
{
	int		x1;
	int		y1;

	if (all->index >= all->max_p)
		return (0);
	all->x1 = calc_x(all->x[all->index], all->z[all->index], all->zoom);
	all->y1 = calc_y(all->y[all->index], all->z[all->index], all->x[all->index], all->zoom, all->high);
	x1 = all->x1;
	y1 = all->y1;
	//printf("%d %d\n\n", all->x1, all->y1);
	if (all->index < (all->k - 1) || all->index < all->len_line - 1)
	{
		all->x2 = calc_x(all->x[all->index + 1], all->z[all->index + 1], all->zoom);
		all->y2 = calc_y(all->y[all->index + 1], all->z[all->index + 1], all->x[all->index + 1], all->zoom, all->high);
		print_pixel(all);
	} 
	if (all->index + all->len_line <= all->max_p)
	{
		all->x1 = x1;
		all->y1 = y1;
		all->x2 = calc_x(all->x[all->index + all->len_line], all->z[all->index + all->len_line], all->zoom);
		all->y2 = calc_y(all->y[all->index + all->len_line], all->z[all->index + all->len_line], all->x[all->index + all->len_line], all->zoom, all->high);
		print_pixel(all);
	}
	if (all->index >= all->k - 1)
	{
		all->k += all->len_line;
	}
	return (0);
}

int		draw_line(vars *all)
{
	int		ok;

	ok = 0;
	all->co1 = 0;
	calc_point(all);
	/*while (ok != 3)
	  all->img_string[all->co1 + ok++] = (char)255;*/
	//draw_x_line(all);
	//draw_y_line(all);
	all->index += 1;
	return (0);
}

int		draw_image(vars *all)
{
	int		k;

	k = 0;
	mlx_clear_window(all->mlx_ptr, all->win_ptr);
	/*if (all->img_ptr)
		mlx_destroy_image(all->mlx_ptr, all->img_ptr);*/
	all->img_ptr = mlx_new_image(all->mlx_ptr, 5000, 5000);
	all->max_p = 0;
	all->len_line = 0;
	all->index = 0;
	all->x1 = 0;
	all->y1 = 0;
	all->x2 = 0;
	all->y2 = 0;
	all->k = all->len_line;
	read_map(all);
	all->img_string = mlx_get_data_addr(all->img_ptr, &all->bits, &all->size_line, &all->endian);
	while (k++ < all->max_p)
	{
		//printf("k = %d\n max_p = %d\n\n", k, all->max_p);
		draw_line(all);
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_ptr, all->img_ptr, 0, 0);
	make_windows(all);
	return (0);
}

int		main(int ac, char **av)
{
	vars	all;

	if (ac != 2)
		return (false_args());
	all.img_pos_x = 0;
	all.img_pos_y = 0;
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
