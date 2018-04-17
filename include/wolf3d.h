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


typedef struct		s_player
{
	struct s_ixy	pos;
}					t_player;

typedef struct		s_ray
{
	struct s_ixy	map;
}					t_ray;

typedef struct 		s_map
{
	int				**tab;
	int				width;
	int				height;
}					t_map;

typedef struct 		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
}					t_mlx;
typedef struct		s_env
{
	t_mlx			mlx;
	t_player		player;
	t_ray			ray;
	char			*input;
	t_map			map;
}					t_env;

/*
**	read.c
*/

void	read_params(t_env *e);

/*
**	error.c
*/

void	error(char *str);

/*
**	test.c ============================== a supprimer
*/

void	print_table(t_env e);

#endif
