/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:39:49 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/16 21:34:29 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_manage_hook" Configure hooks for keyboard, window closing 
 * and mouse.
 * 
 * @param t_fdf	*rol 		rol instance created in fdf.c.
 * 
 * 
 */

void	ft_manage_hook(t_fdf *rol)
{
	mlx_key_hook(rol->mlx, &ft_key_hook, rol);
	ft_printf(ORANGE "Hooks " RESET GREEN "initialized successfully...\n" \
	RESET);
}
