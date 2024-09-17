/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:52:12 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/16 23:12:01 by rdel-olm         ###   ########.fr       */
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
 * The function "ft_draw_line" sets up the drawing of a line between two 
 * points, calculating the gradient and handling steepness and coordinate 
 * swapping.
 *
 * @param t_point s					start point.
 * @param t_point e					end point.
 * @param t_fdf *rol				rol instance created in fdf.c.
 *
 * 
 * The function "ft_check_and_adjust_points" ft_draw_line extension, to 
 * perform the tasks indicated in it, and comply with the rule of 25 lines 
 * per function.
 * 
 * @param t_point s					start point.
 * @param t_point e					end point.
 * @param t_fdf *rol				rol instance created in fdf.c.
 * 
 * 
 * The function "ft_draw_line_loop" handles drawing the line pixel by pixel
 * along the x-axis between two points (s and e) with anti-aliasing.
 *
 * @param t_point s  				start point.
 * @param t_point e  				end point.
 * @param float gradient  			Slope of the line (dy/dx).
 * @param t_fdf *rol  				rol instance created in fdf.c.
 * 
 * 
 * 
 * ================================================
 * ft_intpart function integer part
 * ft_fracpart function fractional part
 * ft_revfracpart function reverse fractional part
 * ================================================
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

static int	ft_check_and_adjust_points(t_point *s, t_point *e, t_fdf *rol)
{
	if ((s->x < 0 || s->x >= rol->win_width || s->y < 0 || s->y >= \
	rol->win_height) && \
	(e->x < 0 || e->x >= rol->win_width || e->y < 0 || e->y >= \
		rol->win_height))
		return (0);

	rol->steep = ft_absolute(e->y - s->y) > ft_absolute(e->x - s->x);
	if (rol->steep)
	{
		ft_swapping(&s->x, &s->y);
		ft_swapping(&e->x, &e->y);
	}
	if (s->x > e->x)
	{
		ft_swapping(&s->x, &e->x);
		ft_swapping(&s->y, &e->y);
		s->reverse = 1;
	}
	return (1);
}

void	ft_draw_line(t_point s, t_point e, t_fdf *rol)
{
	float	dy;
	float	dx;
	float	gradient;

	if (!ft_check_and_adjust_points(&s, &e, rol))
		return ;
	dx = (float)(e.x - s.x);
	dy = (float)(e.y - s.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	ft_draw_line_loop(s, e, gradient, rol);
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
				ft_src_draw_x(x, y, rol);
			if (y != map->map_height - 1)
				ft_src_draw_y(x, y, rol);
			x += -2 * (rol->cam->y_ang > 0) + 1;
		}
		y += -2 * (rol->cam->x_ang > 0) + 1;
	}
	mlx_image_to_window(rol->mlx, rol->img, 0, 0);
	ft_draw_instructions(rol);
}
