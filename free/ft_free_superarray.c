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
 * @param int32_t rows The index up to which rows in the superarray have been 
 * 						allocated and may need cleaning. 
 *                      This allows the function to free all rows up to 'row' 
 * 						to handle partial constructions of the superarray.
 * 
 */

void	ft_free_superarray(t_map *map, int32_t rows)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < map->map_width)
		{
			free(map->superarray[i][j]);
			j++;
		}
		free(map->superarray[i]);
		i++;
	}
	free(map->superarray);
}
