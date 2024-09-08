/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:12:21 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/08 23:51:51 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_free_map" release the map structure.
 * 
 * @param t_map *map 		structure to be released.
 * 
 */

void ft_free_map(t_map *map) {
	if (map != NULL && map->superarray != NULL) {
		int i = 0;
		while (i < map->map_height) {
			int j = 0;
			if (map->superarray[i] != NULL) {
				while (j < map->map_width) {
					free(map->superarray[i][j]);
					map->superarray[i][j] = NULL;
					j++;
				}
				free(map->superarray[i]);
				map->superarray[i] = NULL;
			}
			i++;
		}
		free(map->superarray);
		map->superarray = NULL;
	}
}
