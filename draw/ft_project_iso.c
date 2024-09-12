/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project_iso.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-12 09:53:35 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-09-12 09:53:35 by rdel-olm         ###   ########.fr       */
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

static void	ft_rotate_x(int *y, int *z, double x_angle)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(x_angle) + *z * sin(x_angle);
	*z = prev_y * -sin(x_angle) + *z * cos(x_angle);
}

static void	ft_rotate_y(int *x, int *z, double y_angle)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
	*z = prev_x * -sin(y_angle) + *z * cos(y_angle);
}

static void	ft_rotate_z(int *x, int *y, double z_angle)
{
	t_point	prev;

	prev.x = *x;
	prev.y = *y;
	*x = prev.x * cos(z_angle) - prev.y * sin(z_angle);
	*y = prev.x * sin(z_angle) + prev.y * cos(z_angle);
}

t_point	project(int x, int y, t_fdf *rol)
{
	t_point	point;

	point.z = rol->map->superarray[y][x][0];
	if (rol->map->superarray[y][x][1] >= 0)
		point.color = rol->map->superarray[y][x][1];
	else
		point.color = get_default_color(rol->map->superarray[y][x][0], \
		rol->map);
	point.x = x * rol->cam->zoom;
	point.y = y * rol->cam->zoom;
	point.z *= rol->cam->zoom / rol->cam->z_height;
	point.x -= (rol->map->map_width * rol->cam->zoom) / 2;
	point.y -= (rol->map->map_height * rol->cam->zoom) / 2;
	ft_rotate_x(&point.y, &point.z, rol->cam->x_ang);
	ft_rotate_y(&point.x, &point.z, rol->cam->y_ang);
	ft_rotate_z(&point.x, &point.y, rol->cam->z_ang);
	point.x += WIDTH / 2 + rol->cam->x_offset;
	point.y += (HEIGHT + rol->map->map_height / 2 * rol->cam->zoom) / 2
		+ rol->cam->y_offset;
	point.reverse = 0;
	return (point);
}