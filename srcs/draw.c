/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:45:16 by ojerroud          #+#    #+#             */
/*   Updated: 2018/03/22 16:45:17 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h>

void			put_pxl(t_env *e, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * e->mlx.s_line);
	e->mlx.pxl[i] = c;
	e->mlx.pxl[++i] = c >> 8;
	e->mlx.pxl[++i] = c >> 16;
}

unsigned int	wall_orientation(t_env *e, int y, int x, double responsif, double a, double b)
{
	static int	next_wall = 0;

	next_wall += 0;
	if (e->ray.hit_side == 1)
	{
		if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
			(e->ray.step.x == 1 && e->ray.step.y == -1))
			return (e->text1.texture[(int)((x) / responsif) % 64][(int)((y + a)/ responsif) % 64]);	
		if ((e->ray.step.x == -1 && e->ray.step.y == 1) ||
			(e->ray.step.x == 1 && e->ray.step.y == 1))
				return (e->text2.texture[(int)((x) / responsif) % 64][(int)((y - a)/ responsif) % 64]);
	}
	if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
		(e->ray.step.x == -1 && e->ray.step.y == 1))
		return (e->text3.texture[(int)((x) / responsif) % 64][(int)((y - b)/ responsif) % 64]);
	return (e->text4.texture[(int)((x) / responsif) % 64][(int)((y)/ responsif) % 64]);
	b += 0;
	a += 0;
}

void			draw_line(t_env *e, int x, int start, int end, double a, double b)
{
	int				i;
	int				tmpy;
	double			responsif;

	i = -1;
	tmpy = -1;
	b+=0;
	a+=0;
	while (++i < start + e->player.z)
		put_pxl(e, x, i, e->color_sky);
	i--;
	responsif = (end - start) / (double)64;
	while (++i <= end)
		put_pxl(e, x, i, wall_orientation(e, x, ++tmpy, responsif, a , b));
	i--;
	while (++i < e->height)
		put_pxl(e, x, i, e->color_ground);
}
