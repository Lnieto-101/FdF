#include "../includes_fdf/mlx.h"
#include "../libft/includes/libft.h"
#include "stdio.h"
#include "unistd.h"
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct  s_point
{
    int         x;
    int         y;
    int         z;
}               point;

point   set_point(int x, int y, int z, int w)
{
    point co;

    co.x = x;
    co.y = y;
    co.z = z;
    return (co);
}

int		put_pixel(void *mlx_ptr, void *win_ptr, int x, int y)
{
	static void	*mlx = (void *)-1;
	static void	*win = (void *)-1;

	if (mlx == (void *)-1 && win == (void *)-1)
	{
		mlx = mlx_ptr;
		win = win_ptr;
	}
	if (x >= 0 && y >= 0)
	{
		mlx_pixel_put(mlx, win, x, y, 0xffffff);
	}
	return (0);
}

int		print_pixel(int x1, int y1, int x2, int y2)
{
	int		dx;
	int		dy;
	int		e;

	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0)
		return (1);
	if (x1 >= x2 && y1 >= y2)
	{
		if (y1 - y2 >= x1 - x2)
		{
			e = y2 - y1;
			dx = e * 2;
			dy = (x2 - x1) * 2;
			while (y1 >= y2)
			{
				put_pixel((void *)-1, (void *)-1, x1, y1);
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
				put_pixel((void *)-1, (void *)-1, x1, y1);
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
				put_pixel((void *)-1, (void *)-1, x1, y1);
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
				put_pixel((void *)-1, (void *)-1, x1, y1);
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
				put_pixel((void *)-1, (void *)-1, x1, y1);
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
				put_pixel((void *)-1, (void *)-1, x1, y1);
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
				put_pixel((void *)-1, (void *)-1, x1, y1);
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
				put_pixel((void *)-1, (void *)-1, x1, y1);
				x1 = x1 + 1;
				if ((e = e - dy) >= 0)
				{
					y1 = y1 - 1;
					e = e + dx;
				}
			}
		}
	}
	return (0);
}

int		red_cross(int key)
{
	exit(0);
	return (0);
}

int    get_key(int keycode, void *mlx_ptr, void *win_ptr, void *img_ptr)
{
	static int	x = 0;
	static int	y = 0;
	static void *img = (void *)-1;
	static void *win = (void *)-1;
	static void *mlx = (void *)-1;

	if (mlx == (void *)-1)
		mlx = mlx_ptr;
	if (win == (void *)-1)
		win = win_ptr;
	if (img == (void *)-1)
		img = img_ptr;
	if (keycode == 124)
	{
		mlx_clear_window(mlx, win);
		x += 10;
		mlx_put_image_to_window(mlx, win, img, x, y);
	}
	else if (keycode == 123)
	{
		mlx_clear_window(mlx, win);
		x -= 10;
		mlx_put_image_to_window(mlx, win, img, x, y);
	}
	else if (keycode == 125)
	{
		mlx_clear_window(mlx, win);
		y += 10;
		mlx_put_image_to_window(mlx, win, img, x, y);
	}
	else if (keycode == 126)
	{
		mlx_clear_window(mlx, win);
		y -= 10;
		mlx_put_image_to_window(mlx, win, img, x, y);
	}
    if (keycode == 53)
        red_cross(53);
		printf("%d\n", keycode);
    return (0);
}

point         *read_map(char *map, int *j)
{
    int     fd;
    int     i;
    int     count;
    int     x;
    int     y;
    char    *line;
    char    **split;
    point	*co;

    i = 0;
    count = 0;
    x = 0;
    y = 0;
    if (*j != 0)
        if (!(co = malloc(sizeof(point) * *j + 1)))
            return (NULL);
    fd = open(map, O_RDONLY);
    while (ft_get_next_line(fd, &line) > 0)
    {
        split = ft_strsplit(line, ' ');
        x = 0;
        while (split[x])
        {
            if (*j != 0)
            {
                co[i].z = -x;
                co[i].x = y;
                co[i].y = -ft_atoi(split[x]);
               // printf("x = %d      y = %d      z = %d\n", co[i].x, co[i].y, co[i].z);
            }
            else
                count++;
            //printf("j = %d\n", *j);
            x++;
            i++;
        }
       // printf("\n");
        y++;
    }
    close(fd);
    if (*j != 0)
        return (co);
    else
	{
		*j = count;
        return (read_map(map, j));
	}
}

int     main(int ac, char **av)
{
    point   *coord;
    void*   mlx_ptr;
    void*   win_ptr;
    int     k;
    int     o;
	int		dx;
	int		dy;
	int		dx2;
	int		dy2;
	int		half_width;
	int		half_height;
	int		x_screen;
	int		y_screen;
	int		x2_screen;
	int		dz;
	int		dz2;
	int		y2_screen;
	int		j;
	int		color;
	void	*img_ptr;
	char	*img_string;
	int		bits;
	int		size_line;
	int		endian;
	int		ok;

    k = 0;
    o = 0;
	ac = 0;
	j = 0;
    coord = read_map(av[1], &j);
    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1500, 1500, "Perspective test!");
	img_ptr = mlx_new_image(mlx_ptr, 2000, 2000);
	img_string = mlx_get_data_addr(img_ptr, &bits, &size_line, &endian);
    put_pixel(mlx_ptr, win_ptr, -1, -1);
	get_key(-1, mlx_ptr, win_ptr, img_ptr);
    while (k < j)
    {
		if (k < j - 1)
        	o = k + 1;
		else
			o = 0;
		dx = (coord[k].x / 1) * 1/sqrt(1);
		dy = (coord[k].y / 16) * 1/sqrt(1);
		dz = (coord[k].z / 1) * 1/sqrt(1);
		dx2 = (coord[o].x / 1) * 1/sqrt(1);
		dy2 = (coord[o].y / 16) * 1/sqrt(1);
		dz2 = (coord[o].z / 1) * 1/sqrt(1);
		half_width = 1500 / 2;
		half_height = 1500 / 2;

		/*x_screen = (((dx - (dz / sqrt(2)))));
		y_screen = (((dx + 2 * dy + dz) / sqrt(6) + half_height));
		x2_screen = (((dx2 - (dz2 / sqrt(2)))));
		y2_screen = (((dx2 + 2 * dy2 + dz2) / sqrt(6) + half_height));*/
		//printf("%d\n\n", coord[k].y);
		if (coord[k].y <= -300)
			color = 0xffffff;
		else if (coord[k].y <= -100)
			color = 0x303030;
		else if (coord[k].y >= -2)
			color = 0x0000ff;
		else
			color = 0x8b00;
		x_screen = (dx + (256 / (dz + 1)) + half_width);
		y_screen = (dy + (256 / (dz + 1)) + half_width);
		x2_screen = (dx2 + (256 / (dz2 + 1)) + half_width);
		y2_screen = (dy2 + (256 / (dz2 + 1)) + half_width);

		//printf("%d %d %d %d\n", x_screen, y_screen, x2_screen, y2_screen);
        //print_pixel(x_screen, y_screen, x2_screen, y2_screen);
		//mlx_pixel_put(mlx_ptr, win_ptr, x_screen, y_screen, color);
		ok = 0;
		while (ok != 3)
		{
			img_string[((0 + 4 * x_screen) + 4 * 2000 * y_screen) + ok] = (char)255;
			ok++;
		}
        k++;
    }
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
	k = 0;
	/*while (k < 5)
	{
		print_pixel(x_screen[k - 1], y_screen[k - 1], x_screen[k + 3], y_screen[k + 3]);
		k++;
	}*/
    mlx_key_hook(win_ptr, get_key, (void *)0);
    mlx_hook(win_ptr, 17, 0, red_cross, (void *)0);
    mlx_loop(mlx_ptr);
}
