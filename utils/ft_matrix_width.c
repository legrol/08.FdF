/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:00:06 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/05 19:13:37 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_matrix_width" calculate the number of columns in the 
 * 									matrix.
 * 
 * @param char *map_file 	map passed by argv[1] to read.
 * 
 * 
 * The function "ft_manage_width" handles errors when the line read is of a
 * different size than the previous one
 * 
 * @param char *line 		last line read with get_next_line.
 * 
 * 
 * The function "ft_check_fd" check that fd is not null
 * 
 * @param int fd 		fd generated in ft_matrix_height.
 * 
 * 
 * The function "ft_close_fd" check that the fd can be closed correctly.
 * 
 * @param int fd 			fd generated in ft_matrix_height.
 * 
 * 
 * 
 */

static void	ft_manage_width(char *line)
{
	free(line);
	ft_manage_err(BDRED INIT_ERR YELLOW MATRIX1_ERR RESET);
}

static void	ft_check_fd(int fd)
{
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		ft_manage_err(BDRED INIT_ERR YELLOW OPEN_ERR RESET);
	}
}

static void	ft_close_fd(int fd)
{
	if (close(fd) < 0)
	{
		perror("Error al cerrar el archivo");
		ft_manage_err(BDRED INIT_ERR YELLOW CLOSED_ERR RESET);
	}
}

int	ft_matrix_width(char *map_file)
{
	int		width;
	int		fd;
	char	*line;
	int		next_width;

	fd = open(map_file, O_RDONLY, 0);
	ft_check_fd(fd);
	line = get_next_line(fd);
	if (!line)
		ft_manage_err(BDRED INIT_ERR YELLOW OPEN_ERR RESET);
	width = ft_count_words(line, 32);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		next_width = ft_count_words(line, 32);
		if (next_width != width)
			ft_manage_width(line);
		free(line);
	}
	ft_close_fd(fd);
	close(fd);
	return (width);
}
