/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_fdf_read.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lnieto <lnieto@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 14:01:54 by lnieto       #+#   ##    ##    #+#       */
/*   Updated: 2019/01/29 14:30:31 by lnieto      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes_fdf/fdf.h"

int		tab_zero(t_vars *all)
{
	all->tab[0] = 0;
	all->tab[1] = 0;
	all->tab[2] = 0;
	all->tab[3] = 0;
	return (0);
}

int		split_bcl(char **split, t_vars *all)
{
	static int	tmp = 0;

	while (split[all->tab[0]])
	{
		if (all->max_p != 0)
		{
			all->z[all->tab[3]] = -all->tab[0];
			all->x[all->tab[3]] = all->tab[1];
			all->y[all->tab[3]] = -ft_atoi(split[all->tab[0]]);
		}
		else
			all->tab[2] += 1;
		all->tab[0] += 1;
		all->tab[3] += 1;
	}
	if (all->len_line == 0)
		all->len_line = all->tab[3];
	all->tab[1] += 1;
	if (tmp == 0)
		tmp = all->tab[0];
	if (tmp != all->tab[0])
		all->tab[0] = -1;
	else
		all->tab[0] = 0;
	return (0);
}

int		read_map(t_vars *all)
{
	int		fd;
	char	*line;
	char	**split;
	int		ret;

	tab_zero(all);
	if (!(fd = open(all->map_name, O_RDONLY)))
		return (-1);
	while ((ret = ft_get_next_line(fd, &line)) > 0 && all->tab[0] != -1)
	{
		split = ft_strsplit(line, ' ');
		split_bcl(split, all);
		ft_strdel(&line);
	}
	close(fd);
	if (ret == -1 || all->tab[0] == -1)
		return (-1);
	if (all->max_p != 0)
		return (0);
	all->max_p = all->tab[2] - 1;
	return (read_map(all));
}
