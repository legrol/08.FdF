/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:33:21 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/08 18:56:15 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The main function of FDF, starts the project in which we convert a file 
 * with a grid of height values into a 3d wireframe using a simple graphics 
 * library called MiniLibX (MLX42).
 * 
 * @param char **argv 	name of the file to open (passed as argument) 
 * 						containing the map to manage. 
 * 
 */

int	main(int argc, char **argv)
{
	t_fdf	*rol;
	t_map	*map;

	ft_control_args(argc, argv);
	rol = ft_init(argv[1]);
	map = ft_init_map(argv[1]);
	rol->map = map;
	ft_control_map(argv, rol->map);
	rol->cam = ft_cam_init(rol);
	ft_manage_hook(rol);
	ft_draw(rol->map, rol);
	mlx_loop(rol->mlx);
	mlx_terminate(rol->mlx);
	ft_free_map(map);
	ft_free_fdf(rol);
	//pdte
	return (0);
}
