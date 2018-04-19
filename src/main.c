/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:37:11 by ojerroud          #+#    #+#             */
/*   Updated: 2018/04/17 16:37:12 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
	{
		ft_putendl("usage: ./wolf3d <map>.");
		return (0);
	}
	e.input = av[1];
	read_params(&e);
	init_env(&e);
	e.mlx.win = mlx_new_window(e.mlx.mlx, WIDTH, HEIGHT, "wolfy");
	print_table(e);
	mlx_do_key_autorepeatoff(e.mlx.mlx);
	mlx_loop_hook(e.mlx.mlx, loop_hook, &e);
	mlx_hook(e.mlx.win, RED_CROSS, RED_CROSS_MASK, red_cross, &e);
	mlx_hook(e.mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_press, &e);
	mlx_key_hook(e.mlx.win, key_hook, &e);
	mlx_loop(e.mlx.mlx);
	return (0);
}
