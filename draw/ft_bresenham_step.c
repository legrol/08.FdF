/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham_step.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-07 09:03:30 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-09-07 09:03:30 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_bresenham_step" Advances the start point in Bresenham's 
 * algorithm to draw a line between two points.
 * This function implements a step of Bresenham's algorithm to
 * decide which direction to move the start point. The algorithm evaluates the
 * accumulated error and adjusts the coordinates of the start point based on 
 * the delta and the direction of the step (sign). The algorithm is used to
 * draw straight lines between two points on a pixel grid.
 * 
 * @param int *start        An array of two integers representing the current
 *                          coordinates (x, y) of the start point.
 * @param int *error        A pointer to an integer storing the value of the 
 *                          error accumulated in Bresenham's algorithm.
 * @param int delta[2]      An array of two integers representing the absolute
 *                          differences in x and y (delta_x, delta_y) between 
 *                          the two points on the line.
 * @param int sign[2]       An array of two integers determining the direction 
 *                          of the step in x and y (positive or negative).
 * 
 */

void	ft_bresenham_step(int *start, int *error, int delta[2], int sign[2])
{
	int	error2;

	error2 = 2 * *error;
	if (error2 > -delta[1])
	{
		*error -= delta[1];
		start[0] += sign[0];
	}
	if (error2 < delta[0])
	{
		*error += delta[0];
		start[1] += sign[1];
	}
}
