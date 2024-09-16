/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_z_minmax.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:41:53 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/01 23:49:53 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_collect_z_minmax" Find in the matrix generated from the 
 * map, the maximum z and the minimum z.
 * 
 * @param t_map *map map structure in which to evaluate the max and min.
 * 
 */

void	ft_collect_z_minmax(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map->z_maximum = map->superarray[i][j][0];
	map->z_minimum = map->superarray[i][j][0];
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (map->superarray[i][j][0] < map->z_minimum)
				map->z_minimum = map->superarray[i][j][0];
			if (map->superarray[i][j][0] > map->z_maximum)
				map->z_maximum = map->superarray[i][j][0];
			j++;
		}
		i++;
	}
}
