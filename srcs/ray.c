/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:47:04 by ojerroud          #+#    #+#             */
/*   Updated: 2018/03/22 16:47:05 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		ray_draw(t_env *e, int x, double a, double b)
{
	int		height;
	int		start;
	int		end;

	height = (int)(e->height / e->ray.dist);
	start = (e->height - height) * 0.5;
	if (start < 0)
		start = 0;
	end = height / 2 + e->height / 2;
	if (end >= e->height)
		end = e->height - 1;
	draw_line(e, x, start, end, a, b);
}

static void		ray_calc_dist(t_env *e)
{
	while (!e->map[e->ray.map.x][e->ray.map.y])
	{
		if (e->ray.side.x < e->ray.side.y)
		{
			e->ray.side.x += e->ray.delta.x;
			e->ray.map.x += e->ray.step.x;
			e->ray.hit_side = 0;
		}
		else
		{
			e->ray.side.y += e->ray.delta.y;
			e->ray.map.y += e->ray.step.y;
			e->ray.hit_side = 1;
		}
	}
	if (!e->ray.hit_side)
		e->ray.dist = (e->ray.map.x - e->player.pos.x + (1 - e->ray.step.x)
				/ 2) / e->ray.dir.x;
	else
		e->ray.dist = (e->ray.map.y - e->player.pos.y + (1 - e->ray.step.y)
				/ 2) / e->ray.dir.y;
}

static void		ray_calc_step_side(t_env *e)
{
	if (e->ray.dir.x < 0)
	{
		e->ray.step.x = -1;
		e->ray.side.x = (e->player.pos.x - (int)e->player.pos.x) * e->ray.delta.x;
	}
	else
	{
		e->ray.step.x = 1;
		e->ray.side.x = ((int)e->player.pos.x + 1 - e->player.pos.x) * e->ray.delta.x;
	}
	if (e->ray.dir.y < 0)
	{
		e->ray.step.y = -1;
		e->ray.side.y = (e->player.pos.y - (int)e->player.pos.y) * e->ray.delta.y;
	}
	else
	{
		e->ray.step.y = 1;
		e->ray.side.y = ((int)e->player.pos.y + 1 - e->player.pos.y) * e->ray.delta.y;
	}
}

static void		ray_init(t_env *e, int x)
{
	e->ray.map.x = (int)e->player.pos.x;
	e->ray.map.y = (int)e->player.pos.y;
	e->ray.cam = 2 * x / (double)e->width - 1;
	e->ray.dir.x = e->player.dir.x + e->player.plane.x * e->ray.cam;
	e->ray.dir.y = e->player.dir.y + e->player.plane.y * e->ray.cam;
	e->ray.delta.x = sqrt(1 + (e->ray.dir.y * e->ray.dir.y) /
			(e->ray.dir.x * e->ray.dir.x));
	e->ray.delta.y = sqrt(1 + (e->ray.dir.x * e->ray.dir.x) /
			(e->ray.dir.y * e->ray.dir.y));
	e->ray.hit = 0;
	e->ray.dist = -1;
	e->ray.hit_side = -1;
}

void			raycasting(t_env *e)
{
	int			x;
	double		a;
	double		b;

	x = -1;
	// printf("[%f][%f]\n", e->player.pos.x + e->ray.dist * e->ray.dir.x, e->player.pos.y +  e->ray.dist * e->ray.dir.y);
	while (++x < e->width)
	{
		ray_init(e, x);
		ray_calc_step_side(e);
		ray_calc_dist(e); 
		if (!x)
		{
			a = (e->player.pos.x + e->ray.dist * e->ray.dir.x) * 64;
			b = (e->player.pos.y + e->ray.dist * e->ray.dir.y) * 64;
			// printf("[%f][%f]\n", a / 64, b / 64);
		}
		// printf("[%f][%f]\n", a, b);
		ray_draw(e, x, a, b);
	}
}
