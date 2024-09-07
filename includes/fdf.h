/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 11:36:56 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/05 22:38:33 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// ============================================================================
// Libraries
// ============================================================================
# include <unistd.h>		// for write...
# include <stdlib.h>		// for typedef, malloc...
# include <math.h>			// for PI, etc.
# include <fcntl.h>			// for oprn, O_RDONLY, etc.
# include <stdio.h>			// for printf...
//# include <signal.h>		// for SIGNAL, SIGUSR1, SIGSEGV...
//# include <sys/types.h>	// for ssize_t, useconds_t...
//# include <limits.h>		// for INT_MAX, INT_MIN...
//# include <stdbool.h>		// for boolean...
//# include <stdint.h>		// for uint, SIZE_MAX...
//# include <stddef.h>		// for size_t...

// ============================================================================
// Access to my libraries
// ============================================================================
# include "colors.h"
# include "examft.h"
# include "ft_macros.h"
# include "ft_printf.h"
# include "get_next_line_bonus.h"
# include "get_next_line.h"
# include "libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

// ============================================================================
// Structures
// ============================================================================
typedef struct s_line_params
{
	int				delta[2];
	int				sign[2];
	int				error;
}					t_line_params;

typedef struct s_cam
{
	int				zoom;
	double			x_ang;
	double			y_ang;
	double			z_ang;
	float			z_height;
	int				x_offset;
	int				y_offset;
	int				prev_x;
	int				prev_y;
	int				iso;
}					t_cam;

typedef struct s_point
{
	int				x;
	int				y;
	int				z;
	unsigned long	color;
}					t_point;

typedef struct s_map
{
	int				map_width;
	int				map_height;
	int				***superarray;
	int				z_minimum;
	int				z_maximum;
}					t_map;

typedef struct s_fdf
{
	void			*mlx;
	void			*img;
	t_map			*map;
	t_cam			*cam;
	int				win_width;
	int				win_height;
}					t_fdf;

// ============================================================================
// Several controls
// ============================================================================
int		ft_check_commas(char *str, t_point *node);
int		ft_control_args(int argc, char **argv);
char	*ft_control_fd(char *argv);
void	ft_control_map(char **argv, t_map *map);
int		ft_ext_valid(char *map_name);

// ============================================================================
// Drawing functions
// ============================================================================
void	ft_bresenham_step(int *start, int *error, int delta[2], int sign[2]);
t_cam	*ft_cam_init(t_fdf	*rol);
void	ft_draw(t_map *map, t_fdf *rol);
void	ft_manage_hook(t_fdf *rol);
t_point	ft_project_iso(int x, int y, int z, t_fdf *rol);
double	ft_reset_angles(double angle);

// ============================================================================
// Management errors
// ============================================================================
void	ft_manage_err(const char *err);

// ============================================================================
// Initialization functions
// ============================================================================
t_map	*ft_init_map(char *argv);
t_fdf	*ft_init(const char *filepath);

// ============================================================================
// Several functions
// ============================================================================
void	ft_collect_z_minmax(t_map *map);
void	ft_complete_matrix(int **nb, char *line, int map_width);
int		ft_count_words(char *s, char c);
void	ft_free_fdf(t_fdf *rol);
void	ft_free_map(t_map *map);
int		ft_get_min(int nbr1, int nbr2);
int		ft_manage_columns(int map_columns, char *read_line, char *map_line);
int		ft_matrix_height(char *map_file);
int		ft_matrix_width(char *map_file);

#endif