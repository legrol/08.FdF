/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:18:05 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/15 20:02:23 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_get_color" xxx
 *
 * @param int x         xxx
 * @param t_point s     xxx
 * @param t_point e     xxx
 * @param float factor  xxx
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
		r = ft_lin_itp((e.color >> 16) & 0xFF, (s.color >> 16) & 0xFF, percent);
		g = ft_lin_itp((e.color >> 8) & 0xFF, (s.color >> 8) & 0xFF, percent);
		b = ft_lin_itp(e.color & 0xFF, s.color & 0xFF, percent);
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
	return ((r << 16) | (g << 8) | b);
}
