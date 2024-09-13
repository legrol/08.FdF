/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:43:30 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/01 22:33:03 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/***
 * The function "ft_complete_matrix" This function reads the integers passed in
 * the line it receives as arguments and stores them in the array nb. If the 
 * number has two parameters (value, hexadecimal) it stores them in the pointer
 * to int pointer. If there is only value, the second item is set to -1.
 * 
 * @param int32_t **nb		matrix where the integers read in each position of 
 * 								the line will be stored.
 * @param char *line		line read from the map.
 * @param int32_t width		map width.
 * 
 */

void	ft_complete_matrix(int32_t **nb, char *line, int32_t map_width)
{
	char		**number;
	int32_t		i;
	int32_t		j;

	number = ft_split(line, 32);
	i = 0;
	while (number[i] && i < map_width)
	{
		nb[i] = malloc(sizeof(int) * 2);
		if (!nb[i])
			ft_manage_err(BDRED INIT_ERR YELLOW MALLOC_ERR RESET);
		nb[i][0] = ft_atoi(number[i]);
		j = 0;
		while (number[i][j] && number[i][j] != ',')
			j++;
		if (number[i][j] == ',')
			nb[i][1] = ft_atoi_base(&number[i][++j], 16);
		else
			nb[i][1] = -1;
		free(number[i]);
		i++;
	}
	if (i != map_width || number[i])
		ft_manage_err(BDRED INIT_ERR YELLOW MATRIX2_ERR RESET);
	free(number);
}
