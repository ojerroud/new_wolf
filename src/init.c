/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:59:15 by ojerroud          #+#    #+#             */
/*   Updated: 2018/04/19 15:42:45 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init_player(t_env *e)
{
	e->player.dir.x = -1;
	e->player.dir.y = 0;
	e->player.z = 0;
	e->player.plane.x = 0;
	e->player.plane.y = 0.66;
	e->player.speed_turn = 0.05;
	e->player.speed_move = 0.1;
	e->player.move_up = 0;
	e->player.move_down = 0;
	e->player.move_right = 0;
	e->player.move_left = 0;
}

static void		init_mlx(t_env *e)
{
	int tmp;

	e->mlx.mlx = mlx_init();
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT, "wolfy");
	e->mlx.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->mlx.pxl = (int *)mlx_get_data_addr(e->mlx.img, &tmp, &tmp, &tmp);
}

void			init_env(t_env *e)
{
	init_player(e);
	init_mlx(e);
	e->texture.color_wall = 0x87591A;
	e->texture.color_sky = 0x00cdff;
	e->texture.color_ground = 0x16B84E;
}
