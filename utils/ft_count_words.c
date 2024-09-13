/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 23:19:43 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/05 19:53:12 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "" count the number of numbers that appear in the row.
 * 
 * @param char const *s     line from which we want to calculate the number 
 *                          of elements (columns).
 * @param char c            Separation character between row numbers.
 * 
 */

int32_t	ft_count_words(char *s, char c)
{
	int32_t	count;
	int32_t	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}
