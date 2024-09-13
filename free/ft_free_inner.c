/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_inner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:00:41 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/08 23:36:46 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_free_inner" xxx
 * 
 * @param int32_t **array   The array of integer pointers to be freed. This 
 * 							array represents a single row within a 2D array 
 * 							structure typically used for storing integer data.
 *                      	Each element of this array points to an int that 
 * 							has been dynamically allocated.
 * @param int32_t length    The number of elements (integer pointers) in the 
 * 							array.
 *                      	This parameter is crucial to ensure that the 
 * 							correct number of dynamically allocated integers 
 * 							are freed, preventing memory leaks.
 * 
 */

void	ft_free_inner(int32_t **array, int32_t length)
{
	int32_t	i;

	i = 0;
	while (i < length)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
