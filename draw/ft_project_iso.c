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

	z = rol->map->superarray[y][x][0];
	point.x = (x - rol->map->map_width / 2) * rol->cam->zoom;
	point.y = (y - rol->map->map_height / 2) * rol->cam->zoom;
	z = z * rol->cam->z_height;
	x_new = (point.x - point.y) * cos(0.523599);
	y_new = (point.x + point.y) * sin(0.523599) - z;
	point.x = x_new + rol->cam->x_offset;
	point.y = y_new + rol->cam->y_offset;
	if (rol->map->superarray[y][x][1] != 16777215)
		point.color = rol->map->superarray[y][x][1];
	else
	{
		point.color = ft_get_default_color(rol->map->superarray[y][x][0], \
		rol->map);
	}
	return (point);
}
