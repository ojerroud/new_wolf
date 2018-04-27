/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:45:48 by ojerroud          #+#    #+#             */
/*   Updated: 2018/03/22 16:45:49 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
	{
		ft_putendl("usage: ./wolf3d <map>.");
		return (0);
	}
	init_env(&e);
	read_params(&e, av[1]);
	e.mlx.win = mlx_new_window(e.mlx.mlx, WIDTH, HEIGHT, "Wolf3d");
	mlx_do_key_autorepeatoff(e.mlx.mlx);
	mlx_loop_hook(e.mlx.mlx, loop_hook, &e);
	mlx_hook(e.mlx.win, 17, (1L << 1), red_cross, 0);
	mlx_hook(e.mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_press, &e);
	mlx_key_hook(e.mlx.win, key_hook, &e);
	mlx_loop(e.mlx.mlx);
	return (0);
}
