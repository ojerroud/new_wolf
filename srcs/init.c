/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:45:32 by ojerroud          #+#    #+#             */
/*   Updated: 2018/03/22 16:45:34 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
	e->mlx.mlx = mlx_init();
	e->mlx.img = mlx_new_image(e->mlx.mlx, WIDTH, HEIGHT);
	e->mlx.pxl = mlx_get_data_addr(e->mlx.img, &(e->mlx.bpp), &(e->mlx.s_line),
			&(e->mlx.ed));
}

void			init_texture(void *mlx, t_text *text, char *xpm)
{
	int		bpp;
	int		size_l;
	int		end;
	int		i;
	int		j;
	int		k;

	text->img = mlx_xpm_file_to_image(mlx, xpm, &text->max.x, &text->max.y);
	text->data = (int *)mlx_get_data_addr(text->img, &bpp, &size_l, &end);
	i = -1;
	k = -1;
	while (++i < text->max.y)
	{
		j = -1;
		while (++j < text->max.x)
			text->texture[i][j] = text->data[++k];
	}
}

void			init_env(t_env *e)
{
	e->width = WIDTH;
	e->height = HEIGHT;
	init_player(e);
	init_mlx(e);
	e->color_wall = 0x87591A;
	e->color_sky = 0x00cdff;
	e->color_ground = 0x16B84E;
	init_texture(e->mlx.mlx, &e->text1, TEXTURE_WEST);
	init_texture(e->mlx.mlx, &e->text2, TEXTURE_EAST);
	init_texture(e->mlx.mlx, &e->text3, TEXTURE_NORTH);
	init_texture(e->mlx.mlx, &e->text4, TEXTURE_SOUTH);
}
