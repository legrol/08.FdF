/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:26:23 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/15 01:57:55 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_put_pixel" xxx
 * 
 * @param t_fdf *rol    xxx
 * @param int x         xxx
 * @param int y         xxx
 * @param int color     xxx
 * 
 */

void	ft_put_pixel(t_fdf *rol, int x, int y, int color)
{
	if (x >= 0 && x < rol->win_width && y >= 0 && y < rol->win_height)
	{
		mlx_put_pixel(rol->img, x, y, color);
	}
}