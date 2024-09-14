/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:52:10 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/14 10:53:22 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * 
 * 
 * 
 * 
 */

static void	ft_translate_img(int key, t_fdf *rol)
{
	if (key == MLX_KEY_LEFT)
		rol->cam->x_offset -= 10;
	else if (key == MLX_KEY_RIGHT)
		rol->cam->x_offset += 10;
	else if (key == MLX_KEY_DOWN)
		rol->cam->y_offset += 10;
	else if (key == MLX_KEY_UP)
		rol->cam->y_offset -= 10;
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*rol;

	rol = (t_fdf *)param;
	if (rol->mlx && keydata.action == MLX_PRESS && keydata.key == \
	MLX_KEY_ESCAPE)
		mlx_close_window(rol->mlx);
	else if (rol->mlx && keydata.action == MLX_PRESS && \
	(keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_LEFT \
	|| keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_UP))
		ft_translate_img(keydata.key, rol);
}
