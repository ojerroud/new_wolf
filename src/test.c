/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:54:15 by ojerroud          #+#    #+#             */
/*   Updated: 2018/04/17 18:54:16 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	print_table(t_env e)
{
	int i;
	int j;

	i = -1;
	printf("[%f][%f]\n", e.player.pos.x, e.player.pos.y);
	while (++i < e.map.height)
	{
		j = -1;
		while (++j < e.map.width)
		{
			if (i == e.player.pos.y - 0.5 && j == e.player.pos.x - 0.5)
				printf("P ");
			else
				printf("%d ", e.map.tab[i][j]);
		}
		printf("\n");
	}
}
