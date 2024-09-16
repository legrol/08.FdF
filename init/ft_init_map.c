/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 20:50:57 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/15 21:13:22 by rdel-olm         ###   ########.fr       */
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
 * The function "ft_allocate_row" To allocate memory for a row of the 
 * superarray.
 * 
 * @param t_map *map		map to read.
 * @param int i				The current index of the row being processed and 
 * 							allocated in the 'superarray'. This index is used 
 * 							to access and manage the correct row in the 
 * 							'superarray'.
 * @param char *line		The current line of text that was being processed
 *                          which may need to be freed if not NULL.
 * 
 * 
 * The function "ft_fill_row"	To fill a row of the super array with the 
 * values ​​obtained from the split of the read line.
 * 
 * @param t_map *map		map to read.
 * @param char **split_line	an array of string segments derived from 'line'
 *                          which should be freed to prevent memory leaks.
 * @param int row			The index up to which rows in the superarray 
 *                          have been allocated and may need cleaning. 
 *                          This allows the function to free all rows up 
 *                          to 'row' to handle partial constructions of 
 *                          the superarray.
 * 
 * 
 * The function "ft_read_map_dimensions" reads the map dimensions (width and 
 * height) and assigns them to map->map_width and map->map_height.
 * 
 * @param t_map *map		map to read.
 * @param int fd			fd of the file passed to get_next_line to read it. 
 * 
 * 
 * Note: lseek(fd, 0, SEEK_SET); => Restart the file to read it again.
 * 
 */

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

static void	ft_fill_row(t_map *map, char **split_line, int row)
{
	int	j;

	j = 0;
	while (j < map->map_width && split_line[j] != NULL)
	{
		map->superarray[row][j] = (int *)malloc(2 * sizeof(int));
		if (!map->superarray[row][j])
		{
			ft_free_inner(map->superarray[row], j);
			return ;
		}
		map->superarray[row][j][0] = ft_atoi(split_line[j]);
		ft_check_commas(split_line[j], map, row, j);		
		j++;
	}
}

static int	ft_allocate_row(t_map *map, int i, char *line)
{
	char	**split_line;

	map->superarray[i] = (int **)malloc(map->map_width * sizeof(int *));
	if (!map->superarray[i])
		return (0);
	split_line = ft_split(line, ' ');
	if (!split_line)
	{
		free(map->superarray[i]);
		return (0);
	}
	ft_fill_row(map, split_line, i);
	ft_free_split(split_line);
	return (1);
}

static void	ft_fill_superarray(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line && i < map->map_height)
	{
		ft_printf(CYAN "Line read: " RESET YELLOW "%s" RESET, line);
		if (!ft_allocate_row(map, i, line))
		{
			ft_cleanup(map, line, NULL, i);
			return ;
		}
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
	{
		ft_free_map(map);
		ft_manage_err(BDRED INIT_ERR YELLOW MALLOC_ERR RESET);
	}
	ft_fill_superarray(map, fd);
	ft_collect_z_minmax(map);
	close(fd);
	return (map);
}
