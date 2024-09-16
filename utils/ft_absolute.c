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
 * The function "ft_absolute" xxx
 * 
 * @param float n   xxx
 * 
 */

float	ft_absolute(float n)
{
	if (n < 0)
		return (-n);
	return (n);
}
