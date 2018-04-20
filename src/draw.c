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

#include "wolf3d.h"

void			put_pxl(t_env *e, int x, int y, unsigned int c)
{
	int		i;

	i = (x * 4) + (y * e->mlx.s_line);
	e->mlx.pxl[i] = c;
	e->mlx.pxl[++i] = c >> 8;
	e->mlx.pxl[++i] = c >> 16;
}

// unsigned int	wall_orientation(t_env *e, int y, int *x, double tmp2, double a, double b)
// {
// 	static int	next_wall = 0;

// 	next_wall += 0;
// 	if (e->ray.hit_side == 1)
// 	{
// 		if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
// 			(e->ray.step.x == 1 && e->ray.step.y == -1))
// 		{
// 			if (next_wall != 1)
// 			{
// 				*x = 1;
// 				next_wall = 1;
// 			}
// 			return (e->text1.texture[(int)((*x) / tmp2) % 64][(int)((y - a)/ tmp2) % 64]);
// 		}	
// 		if ((e->ray.step.x == -1 && e->ray.step.y == 1) ||
// 			(e->ray.step.x == 1 && e->ray.step.y == 1))
// 		{
// 			if (next_wall != 2)
// 			{
// 				*x = 1;
// 				next_wall = 2;
// 			}
// 			return (e->text2.texture[(int)((*x) / tmp2) % 64][(int)((y + a) / tmp2) % 64]);
// 		}
// 	}
// 	if ((e->ray.step.x == -1 && e->ray.step.y == -1) ||
// 		(e->ray.step.x == -1 && e->ray.step.y == 1))
// 	{
// 		if (next_wall != 3)
// 		{
// 			*x = 1;
// 			next_wall = 3;
// 		}
// 		return (e->text3.texture[(int)((*x)/ tmp2) % 64][(int)((y - b) / tmp2) % 64]);
// 	}
// 	if (next_wall != 4)
// 	{
// 		*x = 1;
// 		next_wall = 4;
// 	}
// 	return (e->text4.texture[(int)((*x)/ tmp2) % 64][(int)((y + b) / tmp2) % 64]);
// 	b+=0;
// 	a+=0;
// }

void			draw_line(t_env *e, int x, int start, int end, double a, double b)
{
	int				i;
	int				tmpy;
	double			tmp2;

	i = -1;
	tmpy = 0;
	b+=0;
	a+=0;
	while (++i < start + e->player.z)
		put_pxl(e, x, i, e->texture.color_sky);
	i--;
	tmp2 = (end - start) / (double)64;
	while (++i <= end)
	{
		// printf("[%d]=>[", tmpy);
		put_pxl(e, x, i, e->texture.color_wall);
		// printf("%d]\n", tmpy);
		tmpy++;
	}
	i--;
	while (++i < HEIGHT)
		put_pxl(e, x, i, e->texture.color_ground);
}
