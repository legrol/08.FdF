/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commas.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:22:08 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/05 17:09:04 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_check_commas" separates the decimal value and the 
 * hexadecimal value (if it exists).
 * 
 * @param char *str		String to evaluate, where the values ​​are.
 * @param t_point *node Node structure where the extracted values ​​will be 
 * 						stored.
 * 
 * The function static "ft_color_zcell" saves the hex value converted to dec 
 * in the treated node.
 * 
 * @param char *str		String to evaluate, where the values ​​are.
 * @param t_point *node Node structure where the extracted values ​​will be 
 * 						stored.
 * 
 * The function static "ft_htol" converts a hexadecimal number to long int.
 * 
 * @param char *str		String to evaluate, where the value is.
 * 
 */

static	unsigned int	ft_htol(const char *str)
{
	const char		*hex;
	unsigned long	res;
	const char		*ptr;

	hex = "0123456789abcdef";
	res = 0;
	if (str[0] == 48 && (str[1] == 'x' || str[1] == 'X'))
		str += 2;
	while (*str != '\0')
	{
		ptr = ft_strchr(hex, *str);
		if (ptr == NULL)
			break ;
		res = res * 16 + (ptr - hex);
		str++;
	}
	return (res);
}

static int	ft_color_zcell(char *str, t_point *node)
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
	node->color = ft_htol(&str[i]);
	return (z);
}

int	ft_check_commas(char *str, t_point *node)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (ft_color_zcell(str, node));
		node->color = 0;
		i++;
	}
	return (ft_atoi(str));
}
