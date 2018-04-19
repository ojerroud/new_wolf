/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 16:54:17 by ojerroud          #+#    #+#             */
/*   Updated: 2017/09/26 17:16:41 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"

# define WIDTH		800
# define HEIGHT		600
# define WALL_SIZE	64

/*
**	keyboard keys ascii
*/

# define KEY_UP		13
# define KEY_LEFT	0
# define KEY_RIGHT	2
# define KEY_DOWN	1
# define KEY_ESC	53

/*
**	mask & key pressed
*/

# define RED_CROSS 		17
# define RED_CROSS_MASK (1L << 1)
# define KEY_PRESS 2
# define KEY_PRESS_MASK (1L << 0)

/*
**	texture names
*/

typedef enum		e_texture
{
	DEEP = 0,
	FLOOR = 1,
	WALL = 2,
	// SIGN = 3,
	// HOUSES = 4,
	// FENCE = 5,
	// WATER = 6,
	// COMPUTER = 7,
	// TABLE = 8,
	// BED = 9,
	// CONSOLE = 10,
	// TV = 11,
	// TREE = 12,
	TP = 13,
	// FURNITURE = 14,
	// CHAIR = 15,
	LAST
}					t_texture;

typedef struct		s_ixy
{
	int				x;
	int				y;
}					t_ixy;

typedef struct		s_dxy
{
	double			x;
	double			y;
}					t_dxy;

typedef struct		s_player
{
	t_ixy			pos;
	t_ixy			dir;
	t_dxy			plane;
	int				z;
	double			speed_turn;
	double			speed_move;
	double			move_up;
	double			move_down;
	double			move_right;
	double			move_left;
}					t_player;

typedef struct		s_ray
{
	t_ixy	map;
}					t_ray;

typedef struct		s_map
{
	int				**tab;
	int				width;
	int				height;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				*pxl;
}					t_mlx;

typedef struct 		s_text
{
	size_t			color_sky;
	size_t			color_wall;
	size_t			color_ground;
}					t_text;

typedef struct		s_env
{
	t_mlx			mlx;
	t_player		player;
	t_ray			ray;
	char			*input;
	t_map			map;
	t_text			texture;
}					t_env;

/*
**	read.c
*/

void				read_params(t_env *e);

/*
**	error.c
*/

void				error(char *str);

/*
**	init.c
*/

void				init_env(t_env *e);

/*
**	key.c
*/

int					red_cross(t_env *e);
int					key_press(int key, t_env *e);
int					key_hook(int key, t_env *e);
int					loop_hook(t_env *e);

/*
**	move.c
*/

void				move_up(t_env *e);
void				move_down(t_env *e);
void				move_right(t_env *e);
void				move_left(t_env *e);


/*
**	test.c ============================== a supprimer
*/

void				print_table(t_env e);

#endif
