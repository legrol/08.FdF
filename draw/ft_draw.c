/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:52:12 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/14 10:15:38 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/fdf.h"

/**
 * The function "ft_draw" draw the map on the screen, managing the drawing
 * process and updating the window.
 *
 * @param t_map *map 				map to read.
 * @param t_fdf *rol 				rol instance created in fdf.c.
 *
 *
 * Thew function "ft_draw_grid" Loop through the map coordinates and call
 * ft_draw_horizvert to draw the lines.
 *
 * @param t_map *map 				map to read.
 * @param t_fdf *rol 				rol instance created in fdf.c.
 *
 * The function "ft_draw_horizvert" They handle the logic of drawing horizontal
 * and vertical lines.
 *
 * @param int x						x coordinate passed from ft_draw_grid.
 * @param int y						y coordinate passed from ft_draw_grid.
 * @param t_map *map				map to read.
 * @param t_fdf *rol				rol instance created in fdf.c.
 *
 *
 * The function "ft_draw_line" draw a line between two points.
 *
 * @param t_point s				sing point.
 * @param t_point e				final point.
 * @param t_fdf *rol				rol instance created in fdf.c.
 *
 *
 * The function "ft_draw_line_params" xxx
 *
 * @param t_point s				sing point.
 * @param t_point e				final point.
 * @param t_line_params *params		struct with data (delta, sign, error).
 *
 *
 * 
 * ft_intpart function integer part
 * ft_fracpart function fractional part
 * ft_revfracpart function reverse fractional part
 * 
 */

static void	ft_draw_line_loop(t_point s, t_point e, float gradient, \
t_fdf *rol)
{
	float	inter_y;
	int		x;

	inter_y = (float)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (rol->steep)
		{
			ft_put_pixel(rol, ft_intpart(inter_y), x, \
				ft_get_color(x, s, e, ft_revfracpart(inter_y)));
			ft_put_pixel(rol, ft_intpart(inter_y) + 1, x, \
				ft_get_color(x, s, e, ft_fracpart(inter_y)));
		}
		else
		{
			ft_put_pixel(rol, x, ft_intpart(inter_y), \
				ft_get_color(x, s, e, ft_revfracpart(inter_y)));
			ft_put_pixel(rol, x, ft_intpart(inter_y) + 1, \
				ft_get_color(x, s, e, ft_fracpart(inter_y)));
		}
		inter_y += gradient;
		x++;
	}
}

void	ft_draw_line(t_point s, t_point e, t_fdf *rol)
{
	float	dy;
	float	dx;
	float	gradient;

	if ((s.x < 0 || s.x >= rol->win_width || s.y < 0 || \
	s.y >= rol->win_height) && \
	(e.x < 0 || e.x >= rol->win_width || e.y < 0 || e.y >= rol->win_height))
		return ;
	rol->steep = ft_absolute(e.y - s.y) > ft_absolute(e.x - s.x);
	if (rol->steep)
	{
		ft_swapping(&s.x, &s.y);
		ft_swapping(&e.x, &e.y);
	}
	if (s.x > e.x)
	{
		ft_swapping(&s.x, &e.x);
		ft_swapping(&s.y, &e.y);
		s.reverse = 1;
	}
	dx = (float)(e.x - s.x);
	dy = (float)(e.y - s.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	ft_draw_line_loop(s, e, gradient, rol);
}

// static void ft_draw_instructions(t_fdf *rol)
// {
// 	// Colocar las instrucciones en la ventana
// 	mlx_put_string(rol->mlx, "Left Click:   Pan", 5, 0);
// 	mlx_put_string(rol->mlx, "Right Click:  Rotate x/y", 5, 20);
// 	mlx_put_string(rol->mlx, "Middle Click: Rotate z", 5, 40);
	
// 	// Mostrar la proyección actual
// 	if (rol->cam->iso)
// 		mlx_put_string(rol->mlx, "Space:        Toggle projection (Current: Isometric)", 5, 60);
// 	else
// 		mlx_put_string(rol->mlx, "Space:        Toggle projection (Current: Parallel)", 5, 60);

// 	// Mostrar otras instrucciones
// 	mlx_put_string(rol->mlx, "R:            Reset", 5, 80);
// 	mlx_put_string(rol->mlx, "-/+:          Flatten", 5, 100);
// }

static void	src_draw_x(int x, int y, t_fdf *fdf)
{
	t_point	p1;
	t_point	p2;

	p1 = project(x, y, fdf);
	p2 = project(x + 1, y, fdf);
	ft_draw_line(p1, p2, fdf);
}

static void	src_draw_y(int x, int y, t_fdf *fdf)
{
	t_point	p1;
	t_point	p2;

	p1 = project(x, y, fdf);
	p2 = project(x, y + 1, fdf);
	ft_draw_line(p1, p2, fdf);
}

void	ft_draw(t_map *map, t_fdf *rol)
{
	int	x;
	int	y;

	mlx_delete_image(rol->mlx, rol->img);
	rol->img = mlx_new_image(rol->mlx, rol->win_width, rol->win_height);
	y = 0;
	if (rol->cam->x_ang > 0)
		y = map->map_height - 1;
	while (y < map->map_height && y >= 0)
	{
		x = 0;
		if (rol->cam->y_ang > 0)
			x = map->map_width - 1;
		while (x < map->map_width && x >= 0)
		{
			if (x != map->map_width - 1)
				src_draw_x(x, y, rol);
			if (y != map->map_height - 1)
				src_draw_y(x, y, rol);
			x += -2 * (rol->cam->y_ang > 0) + 1;
		}
		y += -2 * (rol->cam->x_ang > 0) + 1;
	}
	mlx_image_to_window(rol->mlx, rol->img, 0, 0);
	// ft_draw_instructions(rol);
}