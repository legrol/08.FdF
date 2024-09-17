/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-17 06:20:08 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-09-17 06:20:08 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_toggle_projection" Switch between the two available 
 * projection modes: isometric and a standard flat view. Adjust the rotation
 * angles depending on the projection mode.
 * 
 * @param t_fdf *rol				rol instance created in fdf.c.
 * 
 * 
 */

void	ft_toggle_projection(t_fdf *rol)
{
	if (rol->cam->iso)
	{
		rol->cam->x_ang = -0.523599;
		rol->cam->y_ang = -0.261799;
		rol->cam->z_ang = 0;
	}
	else
	{
		rol->cam->x_ang = -0.615472907;
		rol->cam->y_ang = -0.523599;
		rol->cam->z_ang = 0.615472907;
	}
	rol->cam->iso = !rol->cam->iso;
}
