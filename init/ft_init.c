/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:18:43 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/09 20:55:39 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/**
 * The function "ft_init" initializes the main FDF structure.
 * 
 * @param const char *filepath 	The path to the file containing the map data.
 *  
 *  
 * The function "*ft_allocate_rol" Manages dynamic memory reservation for rol.
 * 
 * @param void					Without parameters. 
 * 
 * 
 * The function "*ft_create_mapname" Extracts from argv[1] the name without 
 * extension to add it to the screen title.
 *   
 * @param const char *filepath	argv[1].
 * 
 * 
 * The function "ft_init_mlx" initializes the new instance of MLX42.
 * 
 * @param t_fdf *rol 			rol instance created in fdf.c.
 * @param char *mapname			map file name without extension. 
 * 
 * 
*/

void	ft_init_mlx(t_fdf *rol, char *mapname)
{
	rol->win_height = DEFAULT_HEIGHT;
	rol->win_width = DEFAULT_WIDTH;
	rol->mlx = mlx_init(DEFAULT_WIDTH, DEFAULT_HEIGHT, mapname, true);
	if (!rol->mlx)
	{
		ft_printf("Error initializing MLX\n");
		ft_manage_err(BDRED INIT_ERR YELLOW MLX_ERR RESET);
	}
	ft_printf(ORANGE "\nMLX " GREEN "initialized successfully...\n" RESET);
	rol->img = mlx_new_image(rol->mlx, DEFAULT_WIDTH, DEFAULT_HEIGHT);
	if (!rol->img)
	{
		mlx_close_window(rol->mlx);
		ft_printf("Error creating new image\n");
		ft_manage_err(BDRED INIT_ERR YELLOW IMG_ERR RESET);
	}
	ft_printf(ORANGE "Image " GREEN "created successfully...\n" RESET);
	if (mlx_image_to_window(rol->mlx, rol->img, 0, 0) == -1)
	{
		mlx_close_window(rol->mlx);
		ft_printf("Error adding image to window\n");
		ft_manage_err(BDRED INIT_ERR YELLOW IMG_ERR RESET);
	}
	ft_printf(ORANGE "Image " GREEN "added to window successfully...\n" RESET);
}

static t_fdf	*ft_allocate_rol(void)
{
	t_fdf	*rol;

	rol = (t_fdf *)malloc(sizeof(t_fdf));
	if (!rol)
	{
		ft_printf("Error allocating memory for rol\n");
		ft_free_fdf(rol);
		ft_manage_err(BDRED INIT_ERR YELLOW MALLOC_ERR RESET);
	}
	return (rol);
}

static char	*ft_create_mapname(const char *filepath)
{
	char	*filename;
	char	*mapname;

	filename = ft_substr(filepath, 0, (ft_strlen(filepath) - 4));
	if (!filename)
	{
		ft_printf("Error allocating memory for filename\n");
		free(filename);
		ft_manage_err(BDRED INIT_ERR YELLOW MALLOC_ERR RESET);
	}
	mapname = ft_strjoin("Fdf - ", filename);
	free(filename);
	if (!mapname)
	{
		ft_printf("Error allocating memory for mapname\n");
		ft_manage_err(BDRED INIT_ERR YELLOW MALLOC_ERR RESET);
	}
	return (mapname);
}

t_fdf	*ft_init(const char *filepath)
{
	t_fdf	*rol;
	char	*mapname;

	mapname = ft_create_mapname(filepath);
	rol = ft_allocate_rol();
	ft_init_mlx(rol, mapname);
	rol->map = NULL;
	rol->cam = NULL;
	// rol->mouse = (t_mouse *) malloc(sizeof(t_mouse));
	// if (!rol->mouse)
	// {
	// 	ft_printf("Error allocating memory for mouse\n");
	// 	ft_manage_err(BDRED INIT_ERR YELLOW MALLOC_ERR RESET);
	// }
	free(mapname);
	return (rol);
}
