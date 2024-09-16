/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 10:52:10 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/16 21:35:01 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_key_hook" keyboard event management.
 * 
 * Inside the if statement relative to action, you can add more keyboard 
 * controls like moving the cam, rotating, etc.
 * 
 * @param mlx_key_data_t keydata	Contains information about the keyboard 
 * 									event that has occurred.
 * @param void *param				This pointer is cast to a pointer of type
 * 									t_fdf to access the elements of the rol 
 * 									structure.
 * 
 */

static void	ft_move_zoom(mlx_key_data_t keydata, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_W)
		fdf->cam->zoom += 1;
	else if (keydata.action == MLX_PRESS && keydata.key == MLX_KEY_S \
	&& fdf->cam->zoom > 1)
		fdf->cam->zoom -= 1;
}

static void	ft_reset(t_fdf *rol)
{
	rol->cam->x_offset = rol->win_width / 2;
	rol->cam->y_offset = rol->win_height / 2;
	if (rol->cam->iso)
	{
		rol->cam->x_ang = -0.61547297;
		rol->cam->y_ang = -0.523599;
		rol->cam->z_ang = 0.61547297;
		rol->cam->prev_x = 0;
		rol->cam->prev_y = 0;
	}
	else
	{
		rol->cam->x_ang = -0.523599;
		rol->cam->y_ang = -0.261799;
		rol->cam->z_ang = 0;
	}
	rol->cam->z_height = 1.0;
	rol->cam->zoom = ft_get_min(DEFAULT_WIDTH / rol->map->map_width / 2,
			DEFAULT_HEIGHT / rol->map->map_height / 2);
}

static void	ft_toggle_projection(t_fdf *rol)
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

static void	ft_mod_height(int key, t_fdf *rol)
{
	if (key == MLX_KEY_KP_SUBTRACT)
		rol->cam->z_height -= 0.1;
	else if (key == MLX_KEY_KP_ADD)
		rol->cam->z_height += 0.1;
	if (rol->cam->z_height < 0.1)
		rol->cam->z_height = 0.1;
	else if (rol->cam->z_height > 10)
		rol->cam->z_height = 10;
}

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
	else if (rol->mlx && keydata.action == MLX_PRESS && \
	(keydata.key == MLX_KEY_KP_SUBTRACT || keydata.key == MLX_KEY_KP_ADD))
		ft_mod_height(keydata.key, rol);
	else if (rol->mlx && keydata.action == MLX_PRESS && \
	keydata.key == MLX_KEY_SPACE)
		ft_toggle_projection(rol);
	else if (rol->mlx && keydata.action == MLX_PRESS && \
	keydata.key == MLX_KEY_R)
		ft_reset(rol);
	else if (rol->mlx && keydata.action == MLX_PRESS && \
	(keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_S))
		ft_move_zoom(keydata, rol);
	ft_draw(rol->map, rol);
}
