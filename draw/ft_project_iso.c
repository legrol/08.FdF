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

// static void	ft_rotate_x(int *y, int *z, double x_angle)
// {
// 	int	prev_y;

// 	prev_y = *y;
// 	*y = prev_y * cos(x_angle) + *z * sin(x_angle);
// 	*z = prev_y * -sin(x_angle) + *z * cos(x_angle);
// }

// static void	ft_rotate_y(int *x, int *z, double y_angle)
// {
// 	int	prev_x;

// 	prev_x = *x;
// 	*x = prev_x * cos(y_angle) + *z * sin(y_angle);
// 	*z = prev_x * -sin(y_angle) + *z * cos(y_angle);
// }

// static void	ft_rotate_z(int *x, int *y, double z_angle)
// {
// 	t_point	prev;

// 	prev.x = *x;
// 	prev.y = *y;
// 	*x = prev.x * cos(z_angle) - prev.y * sin(z_angle);
// 	*y = prev.x * sin(z_angle) + prev.y * cos(z_angle);
// }

// t_point	project(int x, int y, t_fdf *rol)
// {
// 	t_point	point;

// 	point.z = rol->map->superarray[y][x][0];
// 	// if (rol->map->superarray[y][x][1] >= 0)
// 	// 	point.color = rol->map->superarray[y][x][1];
// 	// else
// 	// 	point.color = get_default_color(rol->map->superarray[y][x][0], \
// 	// 	rol->map);
// 	if (rol->map->superarray[y][x][1] >= 0)
// 		point.color = 0xFFFFFFFF;
// 	else
// 		point.color = 0xFFFFFFFF;
// 	point.x = x * rol->cam->zoom;
// 	point.y = y * rol->cam->zoom;
// 	point.z *= rol->cam->zoom / rol->cam->z_height;
// 	point.x -= (rol->map->map_width * rol->cam->zoom) / 2;
// 	point.y -= (rol->map->map_height * rol->cam->zoom) / 2;
// 	printf("x: %d, y: %d, z: %d\n", point.x, point.y, point.z);
// 	ft_rotate_x(&point.y, &point.z, rol->cam->x_ang);
// 	ft_rotate_y(&point.x, &point.z, rol->cam->y_ang);
// 	ft_rotate_z(&point.x, &point.y, rol->cam->z_ang);
// 	point.x += WIDTH / 2 + rol->cam->x_offset;
// 	point.y += (HEIGHT + rol->map->map_height / 2 * rol->cam->zoom) / 2
// 		+ rol->cam->y_offset;
// 	point.reverse = 0;
// 	return (point);
// }

// static void	src_draw_x(int x, int y, t_fdf *fdf)
// {
// 	t_point	p1;
// 	t_point	p2;

// 	p1 = project(x, y, fdf);
// 	p2 = project(x + 1, y, fdf);
// 	ft_draw_line(p1, p2, fdf);
// }

// static void	src_draw_y(int x, int y, t_fdf *fdf)
// {
// 	t_point	p1;
// 	t_point	p2;

// 	p1 = project(x, y, fdf);
// 	p2 = project(x, y + 1, fdf);
// 	ft_draw_line(p1, p2, fdf);
// }

// void	ft_draw(t_map *map, t_fdf *rol)
// {
// 	int	x;
// 	int	y;

// 	mlx_delete_img(rol->mlx, rol->img);
// 	rol->img = mlx_new_img(rol->mlx, rol->win_width, rol->win_height);
// 	y = 0;
// 	if (rol->cam->x_ang > 0)
// 		y = map->map_height - 1;
// 	while (y < map->map_height && y >= 0)
// 	{
// 		x = 0;
// 		if (rol->cam->y_ang > 0)
// 			x = map->map_width - 1;
// 		while (x < map->map_width && x >= 0)
// 		{
// 			if (x != map->map_width - 1)
// 				src_draw_x(x, y, rol);
// 			if (y != map->map_height - 1)
// 				src_draw_y(x, y, rol);
// 			x += -2 * (rol->cam->y_ang > 0) + 1;
// 		}
// 		y += -2 * (rol->cam->x_ang > 0) + 1;
// 	}
// 	mlx_img_to_window(rol->mlx, rol->img, 0, 0);
// }

t_point	project(int x, int y, t_fdf *rol)
{
	t_point	point;
	int		z;
	float	x_new;
	float	y_new;

	z = rol->map->superarray[y][x][0];
	point.x = (x - rol->map->map_width / 2) * rol->cam->zoom;
	point.y = (y - rol->map->map_height / 2) * rol->cam->zoom;
	point.z = z * rol->cam->z_height;
	x_new = point.x * cos(rol->cam->x_ang) - point.y * sin(rol->cam->x_ang);
	y_new = point.x * sin(rol->cam->x_ang) + point.y * cos(rol->cam->x_ang);
	point.x = x_new + rol->cam->x_offset;
	point.y = y_new + rol->cam->y_offset;
	point.color = 0xffffff;

	return (point);
}
