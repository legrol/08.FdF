/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-03 10:01:04 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-09-03 10:01:04 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_get_min" returns the smallest of the two numbers passed as 
 * parameters.
 * 
 * @param int32_t nbr1 The first number to check.
 * @param int32_t nbr2 THe second number to check.
 * 
 */

int32_t	ft_get_min(int32_t nbr1, int32_t nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	return (nbr2);
}
