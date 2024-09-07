/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:39:49 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/05 17:17:04 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_manage_hook" Configure hooks for keyboard, window closing 
 * and mouse.
 * 
 * @param t_fdf	*rol 				rol instance created in fdf.c.
 * 
 * 
 * The function "ft_mouse_hook" mouse event handling.
 * 
 * -action- handles all mouse events
 * 
 * @param mouse_key_t button		identifies which mouse button has been 
 * 									pressed.
 * @param action_t action			Describes the action that has taken place,
 * 									similar to what happens with the keyboard.
 * 									Values ​​can be MLX_PRESS (button pressed) 
 * 									or MLX_RELEASE (button released).
 * @param modifier_key_t mods		Represents the keyboard modifiers that were
 * 									active when the mouse event occurred, such 
 * 									as Shift, Ctrl, etc. This parameter can be 
 * 									used to detect if modifier keys were being 
 * 									pressed when the mouse was clicked.
 * @param void *param				It is used to pass a pointer to the t_fdf 
 * 									structure. It is cast to be able to access 
 * 									the elements of the rol structure and 
 * 									update the camera or redraw the scene.
 * 
 * 
 * The function "ft_close_hook" window close event management.
 * 
 * Note. "mlx_close_window" closes the window when the X is closed.
 * 
 * @param void *param				It is cast to be able to close the window 
 * 									using mlx_close_window(role->mlx).
 * 
 * 
 * The function "ft_key_hook" keyboard event management.
 * 
 * Inside the if statement relative to action, you can add more keyboard 
 * controls like moving the camera, rotating, etc.
 * 
 * @param mlx_key_data_t keydata	Contains information about the keyboard 
 * 									event that has occurred.
 * @param void *param				This pointer is cast to a pointer of type
 * 									t_fdf to access the elements of the rol 
 * 									structure.
 * 
 */

static void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_fdf	*rol;

	rol = (t_fdf *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(rol->mlx);
		}
	}
}

static void	ft_close_hook(void *param)
{
	t_fdf	*rol;

	rol = (t_fdf *)param;
	mlx_close_window(rol->mlx);
}

static void	ft_mouse_hook(mouse_key_t button, action_t action, \
modifier_key_t mods, void *param)
{
	t_fdf	*rol;

	(void)mods;
	rol = (t_fdf *)param;
	if (action == MLX_PRESS)
	{
		if (button == MLX_MOUSE_BUTTON_LEFT)
		{
			rol->cam->x_ang += (rol->cam->prev_y - rol->cam->y_offset) * 0.002;
			rol->cam->y_ang += (rol->cam->prev_x - rol->cam->x_offset) * 0.002;
			rol->cam->x_ang = ft_reset_angles(rol->cam->x_ang);
			rol->cam->y_ang = ft_reset_angles(rol->cam->y_ang);
			rol->cam->prev_x = rol->cam->x_offset;
			rol->cam->prev_y = rol->cam->y_offset;
			ft_draw(rol->map, rol);
		}
		else if (button == MLX_MOUSE_BUTTON_RIGHT)
		{
			rol->cam->x_offset += (rol->cam->prev_x - rol->cam->x_offset);
			rol->cam->y_offset += (rol->cam->prev_y - rol->cam->y_offset);
			rol->cam->prev_x = rol->cam->x_offset;
			rol->cam->prev_y = rol->cam->y_offset;
			ft_draw(rol->map, rol);
		}
	}
}

void	ft_manage_hook(t_fdf *rol)
{
	mlx_key_hook(rol->mlx, &ft_key_hook, rol);
	mlx_close_hook(rol->mlx, &ft_close_hook, rol);
	mlx_mouse_hook(rol->mlx, &ft_mouse_hook, rol);
	ft_printf(ORANGE "Hooks " RESET \
	GREEN "initialized succesfully...\n" RESET);
}
