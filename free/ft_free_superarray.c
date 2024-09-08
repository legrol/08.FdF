/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_superarray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 22:17:53 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/08 23:33:17 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_free_superarray" to release triple pointer superray.
 * 
 * @param t_map *map    map to read.
 * @param int rows      The index up to which rows in the superarray have been 
 * 						allocated and may need cleaning. 
 *                      This allows the function to free all rows up to 'row' 
 * 						to handle partial constructions of the superarray.
 * 
 */

void	ft_free_superarray(t_map *map, int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < map->map_width; j++)
			free(map->superarray[i][j]);
		free(map->superarray[i]);
	}
	free(map->superarray);
}
