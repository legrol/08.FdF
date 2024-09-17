/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-09-13 09:15:26 by rdel-olm          #+#    #+#             */
/*   Updated: 2024-09-13 09:15:26 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_swap" exchanges the values ​​contained in variables a 
 * and b.
 * 
 * @param uint32_t *a   variable a, to be inserted into variable b.
 * @param uint32_t *b   variable b, to be inserted into variable a.
 * 
 */

void	ft_swapping(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
