/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:39:49 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/14 11:33:29 by rdel-olm         ###   ########.fr       */
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
 * 									update the cam or redraw the scene.
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
 * controls like moving the cam, rotating, etc.
 * 
 * @param mlx_key_data_t keydata	Contains information about the keyboard 
 * 									event that has occurred.
 * @param void *param				This pointer is cast to a pointer of type
 * 									t_fdf to access the elements of the rol 
 * 									structure.
 * 
 */

// static void	ft_free_resources(t_fdf *rol)
// {
// 	if (!rol)
// 		return ;
// 	if (rol->map)
// 	{
// 		ft_free_map(rol->map);
// 		rol->map = NULL;
// 	}
// 	if (rol->cam)
// 	{
// 		free(rol->cam);
// 		rol->cam = NULL;
// 	}
// 	if (rol->img)
// 	{
// 		mlx_delete_image(rol->mlx, rol->img);
// 		rol->img = NULL;
// 	}
// }

// static void	ft_handle_mouse_move(int x, int y, t_fdf *rol)
// {
// 	if (rol->mouse->button == MOUSE_CLICK_RIGHT)
// 	{
// 		rol->cam->x_ang += (y - rol->mouse->prev_y) * 0.002;
// 		rol->cam->y_ang += (x - rol->mouse->prev_x) * 0.002;
// 		ft_reset_angles(&rol->cam->x_ang);
// 		ft_reset_angles(&rol->cam->y_ang);
// 		rol->mouse->prev_x = x;
// 		rol->mouse->prev_y = y;
// 		ft_draw(rol->map, rol);
// 	}
// 	else if (rol->mouse->button == MOUSE_CLICK_LEFT)
// 	{
// 		rol->cam->x_offset += (x - rol->mouse->prev_x);
// 		rol->cam->y_offset += (y - rol->mouse->prev_y);
// 		rol->mouse->prev_x = x;
// 		rol->mouse->prev_y = y;
// 		ft_draw(rol->map, rol);
// 	}
// 	// if (mlx_is_key_down(rol->mlx, MLX_KEY_ESCAPE) || \
// 	// mlx_is_window_closed(rol->mlx))
// 	// {
// 	// 	mlx_close_window(rol->mlx);
// 	// }
// }

// static void	ft_close_hook(void *param)
// {
// 	t_fdf	*rol;

// 	rol = (t_fdf *)param;
// 	if (rol)
// 	{
// 		if (rol->mlx)
// 		{
// 			mlx_close_window(rol->mlx);
// 			rol->mlx = NULL;
// 		}
// 		ft_free_resources(rol);
// 		free(rol);
// 		rol = NULL;
// 	}
// }

// static void ft_mouse_hook(mouse_key_t button, action_t action, modifier_key_t \
// mods, void *param)
// {
// 	t_fdf	*rol;
// 	int		x;
// 	int		y;

// 	(void) mods;
// 	rol = (t_fdf *)param;
// 	x = rol->mouse->current_x;
// 	y = rol->mouse->current_y;

// 	if (action == MLX_PRESS && (button == 4 || button == 5))
// 		ft_zoom(button, rol);
// 	else if (action == MLX_PRESS || action == MLX_RELEASE)
// 	{
// 		if (button >= MLX_MOUSE_BUTTON_LEFT && button <= \
// 		MLX_MOUSE_BUTTON_MIDDLE)
// 		{
// 			if (action == MLX_PRESS)
// 			{
// 				rol->mouse->button = button;
// 				rol->mouse->prev_x = x;
// 				rol->mouse->prev_y = y;
// 			}
// 			else if (action == MLX_RELEASE)
// 				rol->mouse->button = 0;
// 		}
// 	}
// 	else if (action == MLX_MOTION && rol->mouse->button != 0)
// 		ft_handle_mouse_move(x, y, rol);
// }

void	ft_manage_hook(t_fdf *rol)
{
	mlx_key_hook(rol->mlx, &ft_key_hook, rol);
	// mlx_close_hook(rol->mlx, &ft_close_hook, rol);
	// mlx_mouse_hook(rol->mlx, &ft_mouse_hook, rol);
	ft_printf(ORANGE "Hooks " RESET GREEN "initialized successfully...\n" \
	RESET);
}
