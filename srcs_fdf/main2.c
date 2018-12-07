/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 14:01:54 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 18:01:10 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include <stdio.h>

int		to_white(void *win_ptr, void *mlx_ptr, int ym, int xm, int ym2, int xm2, int color)
{
	int		y;
	int		x;
	int		y2;
	int		x2;

	if (ym < ym2)
	{
		y = ym;
		y2 = ym2;
	}
	else
	{
		y = ym2;
		y2 = ym;
	}
	if (xm == 0 && ym == 0)
		return (to_white(win_ptr, mlx_ptr, 1000, 1500, 0, 0, color));
	while (y <= y2)
	{
		if (xm < xm2)
		{
			x = xm;
			x2 = xm2;
		}
		else
		{
			x = xm2;
			x2 = xm;
		}
		while (x <= x2)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}

int		put_pixel(void *mlx_ptr, void *win_ptr, int x, int y, int x2, int y2, int keycode)
{
	static void	*mlx = (void *)-1;
	static void	*win = (void *)-1;
	static int	color = 0xcd;
	static int	xm = 0;
	static int	ym = 0;	
	static int	xm2 = 0;
	static int	ym2 = 0;

	if (ym == 0 && y > 0)
		ym = y;
	if (ym2 == 0 && y2 > 0)
		ym2 = y2;
	if (xm == 0 && x > 0)
		xm = x;
	if (xm2 == 0 && x2 > 0)
		xm2 = x2;
	if (keycode == 83)
		color = 0xcd;
	if (keycode == 82)
		color = 0xffffff;
	if (keycode == 84)
		color = 0x8b0000;
	if (keycode == 4)
		mlx_string_put(mlx, win, xm2, ym2, 0, "NUMPAD 0 = BLUE NUMPAD 1 = BLUE NUMPAD 2 = RED NUMPAD 3 = CLEAR SQUARE DOUBLETAP NUMPAD 3 = CLEAR WINDOW H = HELP ESC = QUIT");
	if (keycode == 85)
	{
		to_white(win, mlx, ym, xm, ym2, xm2, color);
		ym = 0;
		xm = 0;
		xm2 = 0;
		ym2 = 0;
	}
	else if (keycode == 53)
		exit(0);
	if (mlx == (void *)-1 && win == (void *)-1)
	{
		mlx = mlx_ptr;
		win = win_ptr;
	}
	if (x >= 0 && y >= 0)
	{
		mlx_pixel_put(mlx, win, x, y, color);
	}
	return (0);
}

int 	get_key(int keycode)
{
	put_pixel((void *)-1, (void *)-1, -1, -1, -1, -1, keycode);
	return (0);
}

int		print_pixel(int button, int x, int y)
{
	static int	x1;
	static int	x2;
	static int	y1;
	static int	y2;
	int		dx;
	int		dy;
	int		e;

	if (x < 0 || y < 0)
		return (1);
	if (button == 1)
	{
		x1 = x;
		y1 = y;
	}
	else if (button == 2)
	{
		x2 = x;
		y2 = y;
		return (1);
	}
	if (x1 >= x2 && y1 >= y2)
	{
		if (y1 - y2 >= x1 - x2)
		{
			e = y2 - y1;
			dx = e * 2;
			dy = (x2 - x1) * 2;
			while (y1 >= y2)
			{
				put_pixel((void *)-1, (void *)-1, x1, y1, x2, y2, -1);
				y1 = y1 - 1;
				if ((e = e - dy) >= 0)
				{
					x1 = x1 - 1;
					e = e + dx;
				}
			}
		}
		else
		{
			e = x2 - x1;
			dx = e * 2;
			dy = (y2 - y1) * 2;
			while (x1 >= x2)
			{
				put_pixel((void *)-1, (void *)-1, x1, y1, x2, y2, -1);
				x1 = x1 - 1;
				if ((e = e - dy) >= 0)
				{
					y1 = y1 - 1;
					e = e + dx;
				}
			}
		}
	}
	else if (x1 <= x2 && y1 <= y2)
	{
		if (y2 - y1 >= x2 - x1)
		{
			e = y2 - y1;
			dx = e * 2;
			dy = (x2 - x1) * 2;
			while (y1 <= y2)
			{
				put_pixel((void *)-1, (void *)-1, x1, y1, x2, y2, -1);
				y1 = y1 + 1;
				if ((e = e - dy) <= 0)
				{
					x1 = x1 + 1;
					e = e + dx;
				}
			}
		}
		else
		{
			e = x2 - x1;
			dx = e * 2;
			dy = (y2 - y1) * 2;
			while (x1 <= x2)
			{
				put_pixel((void *)-1, (void *)-1, x1, y1, x2, y2, -1);
				x1 = x1 + 1;
				if ((e = e - dy) <= 0)
				{
					y1 = y1 + 1;
					e = e + dx;
				}
			}
		}
	}
	else if (x1 >= x2 && y1 <= y2)
	{
		if (y2 - y1 >= x1 - x2)
		{
			e = y2 - y1;
			dx = e * 2;
			dy = (x1 - x2) * 2;
			while (y2 >= y1)
			{
				put_pixel((void *)-1, (void *)-1, x1, y1, x2, y2, -1);
				y1 = y1 + 1;
				if ((e = e - dy) <= 0)
				{
					x1 = x1 - 1;
					e = e + dx;
				}
			}
		}
		else
		{
			e = x1 - x2;
			dx = e * 2;
			dy = (y2 - y1) * 2;
			while (x1 >= x2)
			{
				put_pixel((void *)-1, (void *)-1, x1, y1, x2, y2, -1);
				x1 = x1 - 1;
				if ((e = e - dy) <= 0)
				{
					y1 = y1 + 1;
					e = e + dx;
				}
			}
		}
	}
	else if (x1 <= x2 && y1 >= y2)
	{
		if (y1 - y2 >= x2 - x1)
		{
			e = y1 - y2;
			dx = e * 2;
			dy = (x2 - x1) * 2;
			while (y1 >= y2)
			{
				put_pixel((void *)-1, (void *)-1, x1, y1, x2, y2, -1);
				y1 = y1 - 1;
				if ((e = e - dy) <= 0)
				{
					x1 = x1 + 1;
					e = e + dx;
				}
			}
		}
		else
		{
			e = x1 - x2;
			dx = e * 2;
			dy = (y2 - y1) * 2;
			while (x1 <= x2)
			{
				put_pixel((void *)-1, (void *)-1, x1, y1, x2, y2, -1);
				x1 = x1 + 1;
				if ((e = e - dy) >= 0)
				{
					y1 = y1 - 1;
					e = e + dx;
				}
			}
		}
	}
	x1 = x;
	y1 = y;
	return (0);
}

int		red_cross(int key)
{
	exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*win_ptr;

	ac = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1500, 1000, "FdF test");
	put_pixel(mlx_ptr, win_ptr, -1, -1, -1, -1, -1);
	to_white(win_ptr, mlx_ptr, 1000, 1500, 0, 0, 0xffffff);
	mlx_mouse_hook(win_ptr, print_pixel, (void *)0);
	mlx_key_hook(win_ptr, get_key, (void *)0);
	mlx_hook(win_ptr, 17, 0, red_cross, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
