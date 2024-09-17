/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_part.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-13 11:07:48 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-09-13 11:07:48 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_intpart" returns the integer part of a floating-point 
 * number.
 * 
 * @param float n	The float number whose integer part is to be obtained.
 * 
 * 
 * The function "ft_fracpart" returns the fractional part of a floating-point
 * number.
 * 
 * @param float n	The float number whose integer part is to be obtained.
 * 
 * 
 * The function "ft_revfracpart" returns the inverse fractional part of a 
 * number.
 * That is, how much further the number is from reaching the next integer.
 * 
 * @param float n	The float number whose integer part is to be obtained.
 * 
 * 
 * 
 * ft_intpart function integer part
 * ft_fracpart function fractional part
 * ft_revfracpart function reverse fractional part
 * 
 */

int	ft_intpart(float n)
{
	return ((int)n);
}

float	ft_fracpart(float n)
{
	if (n > 0.f)
		return (n - ft_intpart(n));
	return (n - (ft_intpart(n) + 1.f));
}

float	ft_revfracpart(float n)
{
	return (1.f - ft_fracpart(n));
}
