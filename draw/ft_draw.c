/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:52:37 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/11 19:49:51 by rdel-olm         ###   ########.fr       */
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
 * @param t_point start				starting point.
 * @param t_point end				final point.
 * @param t_fdf *rol				rol instance created in fdf.c.
 * 
 * 
 * The function "ft_draw_line_params" xxx
 * 
 * @param t_point start				starting point.
 * @param t_point end				final point.
 * @param t_line_params *params		struct with data (delta, sign, error).
 * 
 * 
 */

// static void	ft_draw_line_params(t_point start, t_point end, \
// t_line_params *params)
// {
// 	params->delta[0] = abs(end.x - start.x);
// 	params->delta[1] = abs(end.y - start.y);
// 	if (start.x < end.x)
// 		params->sign[0] = 1;
// 	else
// 		params->sign[0] = -1;
// 	if (start.y < end.y)
// 		params->sign[1] = 1;
// 	else
// 		params->sign[1] = -1;
// 	params->error = params->delta[0] - params->delta[1];
// }

// void	ft_draw_line(t_point start, t_point end, t_fdf *rol)
// {
// 	t_line_params	params;
// 	int				start_int[2];

// 	ft_draw_line_params(start, end, &params);
// 	while (start.x != end.x || start.y != end.y)
// 	{
// 		if (start.x >= 0 && start.x < DEFAULT_WIDTH && start.y >= 0 \
// 		&& start.y < DEFAULT_HEIGHT)
// 			mlx_put_pixel(rol->img, start.x, start.y, 0xFFFFFF);
// 		start_int[0] = start.x;
// 		start_int[1] = start.y;
// 		ft_bresenham_step(start_int, &params.error, params.delta, params.sign);
// 		start.x = start_int[0];
// 		start.y = start_int[1];
// 	}
// 	if (start.x >= 0 && start.x < DEFAULT_WIDTH && start.y >= 0 \
// 	&& start.y < DEFAULT_HEIGHT)
// 		mlx_put_pixel(rol->img, start.x, start.y, 0xFFFFFF);
// }

// void	ft_draw_horizvert(int x, int y, t_map *map, t_fdf *rol)
// {
// 	t_point	p1;
// 	t_point	p2;

// 	p1 = ft_project_iso(x, y, map->superarray[y][x][0], rol);
// 	if (x + 1 < map->map_width)
// 	{
// 		p2 = ft_project_iso(x + 1, y, map->superarray[y][x + 1][0], rol);
// 		ft_draw_line(p1, p2, rol);
// 	}
// 	if (y + 1 < map->map_height)
// 	{
// 		p2 = ft_project_iso(x, y + 1, map->superarray[y + 1][x][0], rol);
// 		ft_draw_line(p1, p2, rol);
// 	}
// }

// void	ft_draw_grid(t_map *map, t_fdf *rol)
// {
// 	int		x;
// 	int		y;

// 	y = 0;
// 	while (y < map->map_height)
// 	{
// 		x = 0;
// 		while (x < map->map_width)
// 		{
// 			ft_draw_horizvert(x, y, map, rol);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	ft_draw(t_map *map, t_fdf *rol)
// {
// 	ft_printf(ORANGE "Starting " RESET GREEN "drawing process...\n");
// 	ft_draw_grid(map, rol);
// 	if (mlx_image_to_window(rol->mlx, rol->img, 0, 0) == -1)
// 	{
// 		ft_printf("Error updating image to window\n");
// 		mlx_terminate(rol->mlx);
// 		ft_manage_err(IMG_ERR);
// 	}
// 	ft_printf(ORANGE "Drawing completed. " RESET GREEN "Image updated to" \
// 	GREEN " window successfully.\n" RESET);
// }
static int	ft_ipart(float n)
{
	return ((int)n);
}

static float	ft_fpart(float n)
{
	if (n > 0.f)
		return (n - ft_ipart(n));
	return (n - (ft_ipart(n) + 1.f));
}

static float	ft_rfpart(float n)
{
	return (1.f - ft_fpart(n));
}

// static int	ft_min(int a, int b)
// {
// 	if (a < b)
// 		return (a);
// 	return (b);
// }


int	get_default_color(int z, t_map *map)
{
	double			percent;
	unsigned int	max;

	max = map->z_maximum - map->z_minimum;
	if (max == 0)
		return (0x432371);
	percent = ((double)(z - map->z_minimum) / max);
	if (percent < 0.2)
		return (0x432371);
	else if (percent < 0.4)
		return (0x714674);
	else if (percent < 0.6)
		return (0x9F6976);
	else if (percent < 0.8)
		return (0xCC8B79);
	else
		return (0xFAAE7B);
}

static void	ft_put_pixel(t_fdf *rol, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * rol->bpp / 8) + (y * rol->size_line);
		rol->data_addr[i] = color;
		rol->data_addr[++i] = color >> 8;
		rol->data_addr[++i] = color >> 16;
	}
}

static float	ft_abs1(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_lerp(int first, int second, double p)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * p));
}

static int	ft_get_color(int x, t_point s, t_point e, float factor)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = ft_abs1(x - s.x) / ft_abs1(e.x - s.x);
	if (s.reverse)
	{
		r = ft_lerp((e.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percent);
		g = ft_lerp((e.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percent);
		b = ft_lerp(e.color & 0xFF, s.color & 0xFF, percent);
	}
	else
	{
		r = ft_lerp((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
		g = ft_lerp((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
		b = ft_lerp(s.color & 0xFF, e.color & 0xFF, percent);
	}
	r *= factor;
	g *= factor;
	b *= factor;
	return ((r << 16) | (g << 8) | b);
}

static void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static void	ft_draw_line_loop(t_point s, t_point e, float gradient, t_fdf *rol)
{
	float	inter_y;
	int		x;

	inter_y = (float)s.y;
	x = s.x;
	while (x <= e.x)
	{
		if (rol->steep)
		{
			ft_put_pixel(rol, ft_ipart(inter_y), x,
				ft_get_color(x, s, e, ft_rfpart(inter_y)));
			ft_put_pixel(rol, ft_ipart(inter_y) + 1, x,
				ft_get_color(x, s, e, ft_fpart(inter_y)));
		}
		else
		{
			ft_put_pixel(rol, x, ft_ipart(inter_y),
				ft_get_color(x, s, e, ft_rfpart(inter_y)));
			ft_put_pixel(rol, x, ft_ipart(inter_y) + 1,
				ft_get_color(x, s, e, ft_fpart(inter_y)));
		}
		inter_y += gradient;
		x++;
	}
}

static void	ft_draw_line(t_point s, t_point e, t_fdf *rol)
{
	float	dy;
	float	dx;
	float	gradient;

	rol->steep = ft_abs1(e.y - s.y) > ft_abs1(e.x - s.x);
	if (rol->steep)
	{
		ft_swap(&s.x, &s.y);
		ft_swap(&e.x, &e.y);
	}
	if (s.x > e.x)
	{
		ft_swap(&s.x, &e.x);
		ft_swap(&s.y, &e.y);
		s.reverse = 1;
	}
	dx = (float)(e.x - s.x);
	dy = (float)(e.y - s.y);
	gradient = dy / dx;
	if (dx == 0.0f)
		gradient = 1.f;
	ft_draw_line_loop(s, e, gradient, rol);
}

// static void	ft_draw_instructions(t_fdf *rol)
// {
// 	mlx_string_put(rol->mlx, rol->win, 5, 0, 0xFFFFFF,
// 		"Left Click:   Pan");
// 	mlx_string_put(rol->mlx, rol->win, 5, 20, 0xFFFFFF,
// 		"Right Click:  Rotate x/y");
// 	mlx_string_put(rol->mlx, rol->win, 5, 40, 0xFFFFFF,
// 		"Middle Click: Rotate z");
// 	if (rol->cam->iso)
// 		mlx_string_put(rol->mlx, rol->win, 5, 60, 0xFFFFFF,
// 			"Space:        Toggle projection (Current: Isometric)");
// 	else
// 		mlx_string_put(rol->mlx, rol->win, 5, 60, 0xFFFFFF,
// 			"Space:        Toggle projection (Current: Parrallel)");
// 	mlx_string_put(rol->mlx, rol->win, 5, 80, 0xFFFFFF,
// 		"R:            Reset");
// 	mlx_string_put(rol->mlx, rol->win, 5, 100, 0xFFFFFF,
// 		"-/+:          Flatten");
// }

void	ft_draw(t_map *map, t_fdf *rol)
{
	int	x;
	int	y;

	//ft_bzero(rol->data_addr, WIDTH * HEIGHT * (rol->bpp / 8));
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
				ft_draw_line(project(x, y, rol), project(x + 1, y, rol), rol);
			if (y != map->map_height - 1)
				ft_draw_line(project(x, y, rol), project(x, y + 1, rol), rol);
			x += -2 * (rol->cam->y_ang > 0) + 1;
		}
		y += -2 * (rol->cam->x_ang > 0) + 1;
	}
	mlx_image_to_window(rol->mlx, rol->img, 0, 0);
//	ft_draw_instructions(rol);
}
