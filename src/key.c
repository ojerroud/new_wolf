/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 19:08:03 by ojerroud          #+#    #+#             */
/*   Updated: 2018/04/19 19:08:05 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			red_cross(t_env *e)
{
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	exit(0);
}

static void	key_move(int key, t_env *e)
{
	if (key == KEY_UP)
		e->player.move_up = !e->player.move_up;
	if (key == KEY_DOWN)
		e->player.move_down = !e->player.move_down;
	if (key == KEY_LEFT)
		e->player.move_left = !e->player.move_left;
	if (key == KEY_RIGHT)
		e->player.move_right = !e->player.move_right;
	if (key == KEY_ESC)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
}

int			key_press(int key, t_env *e)
{
	key_move(key, e);
	return (0);
}

int			key_hook(int key, t_env *e)
{
	key_move(key, e);
	return (0);
}

int			loop_hook(t_env *e)
{
	if (e->player.move_up)
		move_up(e);
	if (e->player.move_down)
		move_down(e);
	if (e->player.move_right)
		move_right(e);
	if (e->player.move_left)
		move_left(e);
	raycasting(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	return (0);
}
