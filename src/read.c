/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:48:19 by ojerroud          #+#    #+#             */
/*   Updated: 2018/04/17 16:48:21 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	read_map(t_env *e, int fd)
{
	char	*line;
	char	**tab;
	int		i;
	int		j;
	int		ret;

	e->map.tab = (int **)malloc(sizeof(int *) * e->map.height);
	i = -1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		e->map.tab[++i] = (int *)malloc(sizeof(int) * e->map.width);
		tab = ft_strsplit(line, ' ');
		ft_strdel(&line);
		j = -1;
		while (++j < e->map.width)
		{
			e->map.tab[i][j] = ft_atoi(tab[j]);
			ft_strdel(&tab[j]);
		}
		free(tab);
	}
	if (ret == -1)
		error("gnl");
}

static void	read_first_line(t_env *e, int fd)
{
	char	*line;
	char	**tab;
	int		i;

	if (get_next_line(fd, &line) < 1)
		error("file empty");
	tab = ft_strsplit(line, ' ');
	ft_strdel(&line);
	e->map.width = ft_atoi(tab[0]);
	e->map.height = ft_atoi(tab[1]);
	e->player.pos.x = ft_atoi(tab[2]);
	e->player.pos.y = ft_atoi(tab[3]);
	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	free(tab);
}

static void	read_lines(t_env *e, int fd)
{
	read_first_line(e, fd);
	read_map(e, fd);
}

void		read_params(t_env *e)
{
	int		fd;

	if ((fd = open(e->input, O_RDONLY)) == -1)
		error("cannot open map");
	read_lines(e, fd);
	close(fd);
}
