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

static void	read_map(t_env *e, int fd, char *line, char **tab)
{
	int		i;
	int		j;
	int		ret;

	e->map.tab = (int **)malloc(sizeof(int *) * e->map.height);
	i = -1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		(i >= e->map.height) ? error("wrong map") : 0;
		e->map.tab[++i] = (int *)malloc(sizeof(int) * e->map.width);
		tab = ft_strsplit(line, ' ');
		ft_strdel(&line);
		j = -1;
		while (tab[++j])
		{
			(j >= e->map.width) ? error("wrong map") : 0;
			e->map.tab[i][j] = ft_atoi(tab[j]);
			ft_strdel(&tab[j]);
		}
		(j != e->map.width) ? error("wrong map") : 0;
		free(tab);
	}
	(i + 1 != e->map.height) ? error("wrong map") : 0;
	(ret == -1) ? error("gnl") : 0;
}

static void	read_first_line(t_env *e, int fd, char *line, char **tab)
{
	int		i;
	int		cpt;

	if (get_next_line(fd, &line) < 1)
		error("file empty");
	tab = ft_strsplit(line, ' ');
	cpt = 0;
	while (tab[cpt])
		cpt++;
	if (cpt != 4)
		error("wrong first line (4 integers expected: width height posx posy)");
	ft_strdel(&line);
	e->map.width = ft_atoi(tab[0]);
	e->map.height = ft_atoi(tab[1]);
	e->player.pos.x = ft_atoi(tab[2]) - 0.5;
	e->player.pos.y = ft_atoi(tab[3]) - 0.5;
	(e->player.pos.x < 1) ? e->player.pos.x = 1 : 0;
	(e->player.pos.x > e->map.width) ? e->player.pos.x = e->map.width : 0;
	(e->player.pos.y < 1) ? e->player.pos.y = 1 : 0;
	(e->player.pos.y > e->map.height) ? e->player.pos.y = e->map.height : 0;
	printf("[%.0f][%.0f]\n", e->player.pos.x, e->player.pos.y);
	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	free(tab);
}

static void	read_lines(t_env *e, int fd)
{
	char	*line;
	char	**tab;

	line = NULL;
	tab = NULL;
	read_first_line(e, fd, line, tab);
	read_map(e, fd, line, tab);
	printf("[%d][%d]\n", (int)(e->player.pos.x - 0.5), (int)(e->player.pos.y
	- 0.5));
	if (e->map.tab[(int)(e->player.pos.y - 1.5)][(int)(e->player.pos.x - 1.5)]
		!= 0 && e->map.tab[(int)(e->player.pos.y - 0.5)][(int)(e->player.pos.x
			- 0.5)] != 0)
		error("player on a wall");
}

void		read_params(t_env *e)
{
	int		fd;

	if ((fd = open(e->input, O_RDONLY)) == -1)
		error("cannot open map");
	read_lines(e, fd);
	close(fd);
}
