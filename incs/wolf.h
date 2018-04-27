/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:48:13 by ojerroud          #+#    #+#             */
/*   Updated: 2018/03/22 16:48:14 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define WIDTH			800
# define HEIGHT			600

# define KEY_UP			13
# define KEY_LEFT		0
# define KEY_RIGHT		2
# define KEY_DOWN		1
# define KEY_ESC		53

# define RED_CROSS 		17
# define RED_CROSS_MASK (1L << 1)
# define KEY_PRESS		2
# define KEY_PRESS_MASK (1L << 0)

# define T_PARAMS		4
# define NONE			0

# define TEXTURE_WEST		"texture/wall1h.xpm"
# define TEXTURE_EAST		"texture/wall1h.xpm"
# define TEXTURE_NORTH		"texture/wall2h.xpm"
# define TEXTURE_SOUTH		"texture/wall2h.xpm"

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

typedef struct		s_texture_color
{
	char			id;
	int				color;
}					t_texture_color;

typedef struct		s_player
{
	struct s_dxy	pos;
	struct s_dxy	dir;
	struct s_dxy	plane;
	double			speed_turn;
	double			speed_move;
	int				z;
	int				move_left;
	int				move_right;
	int				move_up;
	int				move_down;
}					t_player;

typedef struct		s_ray
{
	struct s_dxy	dir;
	struct s_ixy	map;
	struct s_dxy	side;
	struct s_dxy	delta;
	struct s_ixy	step;
	double			dist;
	double			cam;
	int				hit;
	int				hit_side;
}					t_ray;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*pxl;
	int				bpp;
	int				s_line;
	int				ed;
}					t_mlx;

typedef struct		s_text
{
	struct s_ixy	max;
	struct s_ixy	cur;
	void			*img;
	int				*data;
	int				texture[64][64];
}					t_text;

typedef struct		s_env
{
	struct s_mlx	mlx;
	struct s_player	player;
	struct s_ray	ray;
	int				height;
	int				width;
	int				**map;
	int				i;
	int				map_width;
	int				map_height;
	unsigned int	*texture_wall;
	unsigned int	*texture_ground;
	unsigned int	color_wall;
	unsigned int	color_sky;
	unsigned int	color_ground;
	char			**xpm_data;
	int				width2;
	int				height2;
	void			*test;
	char			*input;
	t_text			text1;
	t_text			text2;
	t_text			text3;
	t_text			text4;
}					t_env;

void				read_params(t_env *e, char *input);
int					loop_hook(t_env *e);
int					open_file(t_env *e, char *f);
int					key_hook(int k, t_env *e);
int					key_press(int k, t_env *e);
int					key_release(int k, t_env *e);
void				init_env(t_env	*e);
void				draw_line(t_env *e, int x, int start, int end, double a, double b);
void				raycasting(t_env *e);
void				move_left(t_env *e);
void				move_right(t_env *e);
void				move_up(t_env *e);
void				move_down(t_env *e);
void				error(char *str);
int					red_cross(int i);
int					next_color(t_env *e, int texture_code);
#endif
