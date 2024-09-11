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

// typedef struct s_point1 {
// 	int x;
// 	int y;
// } t_point1;

// void plot_pixel(int x, int y)
// {
// 	// Esta función es un placeholder, aquí deberías colocar la lógica para
// 	// dibujar el píxel en la pantalla, por ejemplo usando MLX42.
// 	printf("Plot pixel at (%d, %d)\n", x, y);
// }

// void bresenham(t_point1 start, t_point1 end)
// {
// 	int dx;
// 	int dy;
// 	int sx;
// 	int sy;
// 	int err;
// 	int e2;

// 	dx = abs(end.x - start.x);
// 	dy = abs(end.y - start.y);
// 	// sx = start.x < end.x ? 1 : -1;
// 	// sy = start.y < end.y ? 1 : -1;
// 	if (start.x < end.x)
// 		sx = 1;
// 	else
// 		sx = -1;
// 	if (start.y < end.y)
// 		sy = 1;
// 	else
// 		sy = -1;
// 	err = dx - dy;
// 	while (1)
// 	{
// 		// Dibuja el pixel en la posición actual
// 		plot_pixel(start.x, start.y);
// 		// Si hemos llegado al final, terminamos
// 		if (start.x == end.x && start.y == end.y)
// 			break ;
// 		e2 = 2 * err; // Calculamos el error
// 		if (e2 > -dy) // Ajustamos la posición horizontal
// 		{
// 			err -= dy;
// 			start.x += sx;
// 		}
// 		if (e2 < dx) // Ajustamos la posición vertical
// 		{
// 			err += dx;
// 			start.y += sy;
// 		}
// 	}
// }

// int main()
// {
//     t_point start = {0, 0};    // Punto inicial
//     t_point end = {10, 5};     // Punto final

//     bresenham(start, end);

//     return 0;
// }