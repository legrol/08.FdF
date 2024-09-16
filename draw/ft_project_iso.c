/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project_iso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:53:35 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/15 15:53:11 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * 
 * The function "ft_project_iso" Isometric projection to convert 3D coordinates
 * to 2D.
 * 
 * ang_x and ang_y are angs for the isometric projection (examples).
 * Projected.x and projected.y They are used for the transformation of 3D 
 * 							   coordinates to 2D by applying the isometric 
 * 							   projection.
 * 
 * @param int32_t x			x coordinate passed from ft_draw_horizvert.
 * @param int32_t y			y coordinate passed from ft_draw_horizvert.
 * @param int32_t z			z coordinate passed from ft_draw_horizvert.
 * @param t_fdf *rol		rol instance created in fdf.c.
 * 
 *  
 */

t_point	project(int x, int y, t_fdf *rol)
{
	t_point	point;
	int		z;
	int		x_new;
	int		y_new;
	// int		z1;

	z = rol->map->superarray[y][x][0];
	// z1 = rol->map->superarray[y][x][1];
	// printf("\n-- z = %d\n", z);
	// printf("-- z1 = %d\n", z1);
	point.x = (x - rol->map->map_width / 2) * rol->cam->zoom;
	point.y = (y - rol->map->map_height / 2) * rol->cam->zoom;
	z = z * rol->cam->z_height;
	// printf("++ z2 = %d\n", z);
	x_new = (point.x - point.y) * cos(0.523599);
	y_new = (point.x + point.y) * sin(0.523599) - z;
	point.x = x_new + rol->cam->x_offset;
	point.y = y_new + rol->cam->y_offset;
	// printf("** point.x = %d\n", point.x);
	// printf("** point.y  = %d\n", point.y);
	printf("z1 = %i\n", rol->map->superarray[y][x][1] );
	if (rol->map->superarray[y][x][1] != 16777215)
	{
		printf("Estoy en distinto de 16777215");
		point.color = rol->map->superarray[y][x][1];
	}
	else
	{
		printf("Estoy en igual a 16777215 y voy al color defecto");
		point.color = ft_get_default_color(rol->map->superarray[y][x][0], \
		rol->map);
		// printf("\nz = %d, color = 0x%x", z, ft_get_default_color(z, \
		// rol->map));
	}
	// printf("z = %d, color = 0x%lu\n", z, point.color);
	return (point);
}
