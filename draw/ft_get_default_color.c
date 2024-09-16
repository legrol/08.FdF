/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_default_color.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:17:33 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/16 21:09:26 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_get_default_color" containing the value of the height.
 * 
 * @param int z			z coordinate value.
 * @param t_map *map	map to read.
 * 
 */

int	ft_get_default_color(int z, t_map *map)
{
	double			percent;
	unsigned int	max;

	max = map->z_maximum - map->z_minimum;
	if (max == 0)
		return (0xFFFFFF);
	percent = ((double)(z - map->z_minimum) / max);
	if (percent < 0.2)
		return (0x3366FF);
	else if (percent < 0.4)
		return (0x33CCFF);
	else if (percent < 0.6)
		return (0x33FF66);
	else if (percent < 0.8)
		return (0xFFFF66);
	else
		return (0xFF3333);
}
