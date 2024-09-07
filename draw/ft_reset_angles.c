/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_angles.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-04 10:53:50 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-09-04 10:53:50 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_reset_angles" It is used to keep angles within a valid 
 * range, usually between 0 and 2π (or -π to π depending on context).
 * 
 * @param double angle Angle passed from ft_manage_hook.
 * 
 */

double	ft_reset_angles(double angle)
{
	double	two_pi;

	two_pi = 2.00 * M_PI;
	while (angle >= two_pi)
		angle -= two_pi;
	while (angle < 0)
		angle += two_pi;
	return (angle);
}
