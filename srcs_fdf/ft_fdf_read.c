/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_read.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vasalome <vasalome@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 14:01:54 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2018/12/18 18:36:18 by vasalome    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

int		*tab_zero(int *tab)
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	return (tab);
}

int		*split_bcl(char **split, int *tab, t_vars *all)
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

int		malloc_coord(t_vars *all)
{
	if (!(all->x = malloc(sizeof(int) * (all->max_p + 1))))
		return (-1);
	if (!(all->y = malloc(sizeof(int) * (all->max_p + 1))))
		return (-1);
	if (!(all->z = malloc(sizeof(int) * (all->max_p + 1))))
		return (-1);
	return (0);
}

int		read_map(t_vars *all)
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
