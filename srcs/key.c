/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:45:40 by ojerroud          #+#    #+#             */
/*   Updated: 2018/03/22 16:45:41 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		loop_hook(t_env *e)
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
	// mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->test, 0, 0);
	return (0);
}

int		red_cross(int i)
{
	exit(i);
}

void	key_move(int k, t_env *e)
{
	if (k == KEY_UP)
		e->player.move_up = !e->player.move_up;
	if (k == KEY_DOWN)
		e->player.move_down = !e->player.move_down;
	if (k == KEY_LEFT)
		e->player.move_left = !e->player.move_left;
	if (k == KEY_RIGHT)
		e->player.move_right = !e->player.move_right;
	if (k == KEY_ESC)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
}

int		key_press(int k, t_env *e)
{
	key_move(k, e);
	return (0);
}

int		key_hook(int k, t_env *e)
{
	key_move(k, e);
	return (0);
}
