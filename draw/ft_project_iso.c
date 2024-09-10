/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project_iso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-07 10:20:50 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-09-07 10:20:50 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * 
 * The function "ft_project_iso" Isometric projection to convert 3D coordinates
 * to 2D.
 * 
 * Angle_x and angle_y are angles for the isometric projection (examples).
 * Projected.x and projected.y They are used for the transformation of 3D 
 * 							   coordinates to 2D by applying the isometric 
 * 							   projection.
 * 
 * @param int x				x coordinate passed from ft_draw_horizvert.
 * @param int y				y coordinate passed from ft_draw_horizvert.
 * @param int z				z coordinate passed from ft_draw_horizvert.
 * @param t_fdf *rol		rol instance created in fdf.c.
 * 
 *  
 */

t_point	ft_project_iso(int x, int y, int z, t_fdf *rol)
{
	t_point	point;

	point.x = (x - y) * cos(0.523599);
	point.y = (x + y) * sin(0.523599) - z;
	// point.x = 50 * point.x + rol->cam->x_offset;
	// point.y = 50 * point.y + rol->cam->y_offset;
	point.x = point.x * rol->cam->zoom + rol->cam->x_offset;
	point.y = point.y * rol->cam->zoom + rol->cam->y_offset;
	return (point);
}
