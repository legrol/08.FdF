/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:58:20 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/05 19:57:02 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_matrix_height" calculate the number of rows in the matrix.
 * 
 * @param char 	*map_file 	map passed by argv[1] to read.
 * 
 * 
 * The function "ft_check_fd" check that fd is not null
 * 
 * @param int fd 		fd generated in ft_matrix_height.
 * 
 * 
 * The function "ft_close_fd" check that the fd can be closed correctly.
 * 
 * @param int fd 		fd generated in ft_matrix_height.
 * 
 * 
 */

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

int	ft_matrix_height(char *map_file)
{
	int		height;
	int		fd;
	char	*line;

	if (map_file == NULL)
	{
		perror("Nombre de archivo no válido");
		ft_manage_err(BDRED INIT_ERR YELLOW OPEN_ERR RESET);
	}
	fd = open(map_file, O_RDONLY);
	ft_check_fd(fd);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		height++;
		free(line);
	}
	ft_close_fd(fd);
	close(fd);
	return (height);
}
