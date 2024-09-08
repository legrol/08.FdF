/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:13:15 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/05 22:13:29 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_free_fdf" releases the generated fdf instance for the 
 * project.
 * 
 * @param t_fdf *rol 			fdf instance to release
 * 
 */

void	ft_free_fdf(t_fdf *rol)
{
	if (!rol)
		return ;
	if (rol->map)
		ft_free_map(rol->map);
	if (rol->cam)
		free(rol->cam);
	if (rol->img)
		mlx_delete_image(rol->mlx, rol->img);
	if (rol->mlx)
		mlx_terminate(rol->mlx);
	free(rol);
}
