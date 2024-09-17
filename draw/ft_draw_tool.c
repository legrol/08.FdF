/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-17 05:37:13 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-09-17 05:37:13 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_draw_instructions" displays the control instructions in 
 * the window, providing the user with key bindings and controls.
 * 
 * @param t_fdf *rol  				rol instance created in fdf.c.
 * 
 * 
 * The function "src_draw_y" draws a vertical line (y-direction) between 
 * two points.
 * 
 * @param int x						x coordinate of map
 * @param int y						y coordinate of map
 * @param t_fdf *rol				rol instance created in fdf.c.
 * 
 * 
 * The function "src_draw_x" draws a horizontal line (x-direction) between 
 * two points.
 * 
 * @param int x						x coordinate of map
 * @param int y						y coordinate of map
 * @param t_fdf *rol				rol instance created in fdf.c.
 *  
 * 
 */

void	ft_draw_instructions(t_fdf *rol)
{
	mlx_put_string(rol->mlx, "Controls", 5, 0);
	mlx_put_string(rol->mlx, "--------", 5, 20);
	mlx_put_string(rol->mlx, "", 5, 40);
	mlx_put_string(rol->mlx, "R:         Reset", 5, 60);
	mlx_put_string(rol->mlx, "-/+: 		    Flatten/Lift", 5, 80);
	mlx_put_string(rol->mlx, "Key Up: 	  Move Up", 5, 100);
	mlx_put_string(rol->mlx, "Key Down:	 Move Down", 5, 120);
	mlx_put_string(rol->mlx, "Key Right: Move Right", 5, 140);
	mlx_put_string(rol->mlx, "Key Left:	 Move Left", 5, 160);
	mlx_put_string(rol->mlx, "W:         Zoom in", 5, 180);
	mlx_put_string(rol->mlx, "S:         Zoom out", 5, 200);
}

void	ft_src_draw_x(int x, int y, t_fdf *rol)
{
	t_point	p1;
	t_point	p2;

	p1 = ft_project(x, y, rol);
	p2 = ft_project(x + 1, y, rol);
	ft_draw_line(p1, p2, rol);
}

void	ft_src_draw_y(int x, int y, t_fdf *rol)
{
	t_point	p1;
	t_point	p2;

	p1 = ft_project(x, y, rol);
	p2 = ft_project(x, y + 1, rol);
	ft_draw_line(p1, p2, rol);
}
