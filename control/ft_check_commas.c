/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:22:08 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/16 21:25:02 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_check_commas" separates the decimal value and the 
 * hexadecimal value (if it exists).
 * 
 * @param char *str		String to evaluate, where the values ​​are.
 * @param t_map *map	map to read.
 * @param int row		value of the row to examine.
 * @param int j			value of position j of the row to be examined.
 * 
 * 
 * The function static "ft_color_zcell" saves the hex value converted to dec 
 * in the treated node.
 * 
 * @param char *str		String to evaluate, where the values ​​are.
 * @param t_map *map	map to read.
 * @param int row		value of the row to examine.
 * @param int j			value of position j of the row to be examined.
 * 
 * The function static "ft_htol" converts a hexadecimal number to long int.
 * 
 * @param char *str		String to evaluate, where the value is.
 * 
 */

static	unsigned int	ft_htol(char *str)
{
	char			*hex_lower;
	char			*hex_upper;
	unsigned long	res;
	char			*ptr;

	hex_lower = "0123456789abcdef";
	hex_upper = "0123456789ABCDEF";
	res = 0;
	if (str[0] == 48 && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str != '\0')
	{
		ptr = ft_strchr(hex_lower, *str);
		if (ptr == NULL)
			ptr = ft_strchr(hex_upper, *str);
		if (ptr == NULL)
			break ;
		if (ft_strchr(hex_lower, *str))
			res = res * 16 + (ptr - hex_lower);
		else
			res = res * 16 + (ptr - hex_upper);
		str++;
	}
	return (res);
}

static int	ft_color_zcell(char *str, t_map *map, int row, int j)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (str[i] != ',' && str[i] != '\0')
	{
		z = (z * 10) + (str[i] - 48);
		i++;
	}
	if (str[i] == ',')
		i++;
	map->superarray[row][j][1] = ft_htol(&str[i]);
	return (z);
}

int	ft_check_commas(char *str, t_map *map, int row, int j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (ft_color_zcell(str, map, row, j));
		map->superarray[row][j][1] = 0xffffff;
		i++;
	}
	return (ft_atoi(str));
}
