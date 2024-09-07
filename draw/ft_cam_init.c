/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cam_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:25:24 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/05 22:32:29 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_cam_init" initializes the camera values.
 * 
 * @param t_fdf	*rol rol instance created in fdf.c.
 * 
 */

// 	cam->zoom = ft_get_min(WIDTH / rol->map->map_height / 2, \
// 	HEIGHT / rol->map->map_width / 2);
// 	cam->x_ang = -0.61547297;
// 	cam->y_ang = -0.523599;
// 	cam->z_ang = 0.61547297;
// 	cam->x_offset = 0;
// 	cam->y_offset = 0;

//cam->zoom = 20;
// cam->x_ang = 0.0;
// cam->y_ang = 0.0;
// cam->z_ang = 0.0;

t_cam	*ft_cam_init(t_fdf *rol)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (!cam)
		ft_manage_err(BDRED INIT_ERR YELLOW MLLC_CAM_ERR RESET);
	cam->zoom = ft_get_min(WIDTH / rol->map->map_height / 2, \
	HEIGHT / rol->map->map_width / 2);
	cam->x_offset = rol->win_width / 2;
	cam->y_offset = rol->win_height / 2;
	cam->z_height = 1;
	cam->x_ang = -0.61547297;
	cam->y_ang = -0.523599;
	cam->z_ang = 0.61547297;
	cam->prev_x = 0;
	cam->prev_y = 0;
	cam->iso = 1;
	ft_printf(ORANGE "Cam " RESET GREEN "initialized successfully...\n" RESET);
	return (cam);
}
