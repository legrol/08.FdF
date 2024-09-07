/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:13:13 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/05 22:06:26 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_control_map" It manages the reading of the map, extracts 
 * the dimensions, allocates dynamic memory to the three-dimensional array, 
 * obtains the max and min z, and fills the matrix with the data obtained from
 * the map. All this by reading the map line by line (.fdf).
 * 
 * @param char **argv	name of the file to read, passed as arg[1].
 * @param t_map *map	map to read.
 * 
 * In the function "ft_process_lines" complements the main function to 
 * maintain the guideline of 25 lines per function.
 * 
 * @param int fd		fd of the file to read. 
 * @param t_map *map	map to read.
 * 
 */

void	ft_control_map(char **argv, t_map *map)
{
	(void) argv;
	if (!map || !map->superarray)
	{
		printf("Map or superarray is NULL\n");
		ft_manage_err(OPEN_ERR);
	}
	ft_printf(ORANGE "Map dimensions: " RESET GREEN "Width " RESET "%d, " \
	GREEN"Height " RESET "%d\n", map->map_width, map->map_height);
}
