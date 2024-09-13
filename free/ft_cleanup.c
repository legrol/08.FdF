/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 23:11:02 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/08 23:32:38 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_cleanup" to clean up on error, ensuring that all 
 * previous allocations are properly freed.
 * 
 * @param t_map *map            map to read.
 * @param char *line            The current line of text that was being 
 *                              processed which may need to be freed if not 
 *                              NULL.
 * @param char **split_line     an array of string segments derived from 'line'
 *                              which should be freed to prevent memory leaks.
 * @param int32_t row           The index up to which rows in the superarray 
 *                              have been allocated and may need cleaning. 
 *                              This allows the function to free all rows up 
 *                              to 'row' to handle partial constructions of 
 *                              the superarray.  
 * 
 */

void	ft_cleanup(t_map *map, char *line, char **split_line, int32_t row)
{
	if (split_line)
		ft_free_split(split_line);
	if (line)
		free(line);
	ft_free_superarray(map, row);
}
