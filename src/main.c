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
	print_table(e);
	return (0);
}
