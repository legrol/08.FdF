/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absolute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-13 09:27:14 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-09-13 09:27:14 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_absolute" gets the absolute value of the parameter.
 * 
 * @param float n   floating point number that must be processed to obtain its
 * absolute value.
 * 
 */

float	ft_absolute(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}
