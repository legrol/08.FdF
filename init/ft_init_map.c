/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:50:57 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/05 19:14:45 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_init_map" initializes all parameters of the map structure.
 * 
 * @param char *argv		argv[1].
 * 
 * 
 * The function "ft_fill_superarray" fills the superaray with the values ​​read
 * from the file, converting the strings to integers.
 * 
 * @param t_map *map		map to read.
 * @param int fd			fd of the file passed to get_next_line to read it. 
 * 
 * 
 * The function "ft_read_map_dimensions" reads the map dimensions (width and 
 * height) and assigns them to map->map_width and map->map_height.
 * 
 * @param t_map *map		map to read.
 * @param int fd			fd of the file passed to get_next_line to read it. 
 * 
 * 
 * The function "ft_free_split" free double pointer string with split.
 * 
 * @param char **split 		String to free.
 * 
 * Note: lseek(fd, 0, SEEK_SET); => Restart the file to read it again.
 * 
 */

static void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	ft_read_map_dimensions(t_map *map, int fd)
{
	char	*line;
	char	**split_line;

	line = get_next_line(fd);
	while (line)
	{
		if (map->map_height == 0)
		{
			split_line = ft_split(line, 32);
			while (split_line[map->map_width])
				map->map_width++;
			ft_free_split(split_line);
		}
		map->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	lseek(fd, 0, SEEK_SET);
}

static void	ft_fill_superarray(t_map *map, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**split_line;

	i = 0;
	line = get_next_line(fd);
	while (line && i < map->map_height)
	{
		ft_printf(CYAN "Line read: " RESET YELLOW "%s" RESET, line);
		map->superarray[i] = (int **)malloc(map->map_width * sizeof(int *));
		split_line = ft_split(line, 32);
		j = 0;
		while (j < map->map_width)
		{
			map->superarray[i][j] = (int *)malloc(sizeof(int));
			map->superarray[i][j][0] = ft_atoi(split_line[j]);
			j++;
		}
		ft_free_split(split_line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

t_map	*ft_init_map(char *argv)
{
	t_map	*map;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_manage_err(BDRED INIT_ERR YELLOW OPEN_ERR RESET);
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_manage_err(BDRED INIT_ERR YELLOW INIT_MAP_ERR RESET);
	map->map_height = 0;
	map->map_width = 0;
	ft_read_map_dimensions(map, fd);
	map->superarray = (int ***)malloc(map->map_height * sizeof(int **));
	if (!map->superarray)
		ft_manage_err(BDRED INIT_ERR YELLOW MALLOC_ERR RESET);
	ft_fill_superarray(map, fd);
	map->z_maximum = 0;
	map->z_minimum = 0;
	close(fd);
	return (map);
}
