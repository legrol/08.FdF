/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ext_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:23:11 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/08/31 15:14:31 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_ext_valid" check the name of the map and map name 
 * extension.
 * 
 * @param char *map_name The name of map passed by argv[1].
 * 
 */

int	ft_ext_valid(char *map_name)
{
	int	size;

	size = ft_strlen(map_name);
	if (size < 4)
	{
		ft_manage_err(BDRED INIT_ERR YELLOW SHORT_NAME_ERR RESET);
		return (0);
	}
	if ((ft_strncmp(map_name + size - 4, ".fdf", 4) != 0))
	{
		ft_manage_err(BDRED INIT_ERR YELLOW EXT_ERR RESET);
		return (0);
	}
	return (1);
}
