/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:18:05 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/16 21:32:34 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_get_color" xxx
 *
 * @param int x         x coordinate of start point.
 * @param t_point s     start point.
 * @param t_point e     end point.
 * @param float factor  management of fractional part of y coordinate.
 *
 *
 * ft_lin_itp = function linear interpolation
 *
 */

static int	ft_lin_itp(int first, int second, double percent)
{
	if (first == second)
		return (first);
	return ((int)((double)first + (second - first) * percent));
}

int	ft_get_color(int x, t_point s, t_point e, float factor)
{
	int		r;
	int		g;
	int		b;
	float	percent;

	percent = ft_absolute(x - s.x) / ft_absolute(e.x - s.x);
	if (s.reverse)
	{
		r = ft_lin_itp((e.color >> 24) & 0xFF, (s.color >> 24) & 0xFF, percent);
		g = ft_lin_itp((e.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percent);
		b = ft_lin_itp((e.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percent);
	}
	else
	{
		r = ft_lin_itp((s.color >> 16) & 0xFF, (e.color >> 16) & 0xFF, percent);
		g = ft_lin_itp((s.color >> 8) & 0xFF, (e.color >> 8) & 0xFF, percent);
		b = ft_lin_itp(s.color & 0xFF, e.color & 0xFF, percent);
	}
	r *= fabs(factor);
	g *= fabs(factor);
	b *= fabs(factor);
	return (0xFF | (r << 24) | (g << 16) | (b << 8));
}
