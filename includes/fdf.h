/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 09:54:33 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/16 21:14:39 by rdel-olm         ###   ########.fr       */
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
# include <fcntl.h>			// for open, O_RDONLY, etc.
# include <stdio.h>			// for printf...

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
	int32_t			delta[2];
	int32_t			sign[2];
	int32_t			error;
}					t_line_params;

typedef struct s_cam
{
	int32_t			zoom;
	double			x_ang;
	double			y_ang;
	double			z_ang;
	float			z_height;
	int32_t			x_offset;
	int32_t			y_offset;
	int32_t			prev_x;
	int32_t			prev_y;
	int32_t			iso;
}					t_cam;

typedef struct s_mouse
{
	int32_t			button;
	int32_t			x;
	int32_t			y;
	int32_t			current_x;
	int32_t			current_y;
	int32_t			prev_x;
	int32_t			prev_y;
}					t_mouse;

typedef struct s_point
{
	int32_t			x;
	int32_t			y;
	int32_t			z;
	int32_t			reverse;
	unsigned long	color;
}					t_point;

typedef struct s_map
{
	int32_t			map_width;
	int32_t			map_height;
	int32_t			***superarray;
	int32_t			z_minimum;
	int32_t			z_maximum;
}					t_map;

typedef struct s_fdf
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_map			*map;
	t_cam			*cam;
	t_mouse			*mouse;
	int32_t			steep;
	int32_t			win_width;
	int32_t			win_height;
}					t_fdf;

// ============================================================================
// Several controls
// ============================================================================
int			ft_check_commas(char *str, t_map *map, int row, int j);
int32_t		ft_control_args(int32_t argc, char **argv);
char		*ft_control_fd(char *argv);
void		ft_control_map(char **argv, t_map *map);
int32_t		ft_ext_valid(char *map_name);

// ============================================================================
// Drawing functions
// ============================================================================

t_cam		*ft_cam_init(t_fdf	*rol);
void		ft_draw(t_map *map, t_fdf *rol);
void		ft_draw_instructions(t_fdf *rol);
void		ft_draw_line(t_point start, t_point end, t_fdf *rol);
int			ft_get_color(int x, t_point s, t_point e, float factor);
int			ft_get_default_color(int z, t_map *map);
void		ft_manage_hook(t_fdf *rol);
t_point		ft_project(int32_t x, int32_t y, t_fdf *rol);
void		ft_put_pixel(t_fdf *rol, int x, int y, int color);
double		ft_reset_angles(double *angle);
void		ft_src_draw_x(int x, int y, t_fdf *rol);
void		ft_src_draw_y(int x, int y, t_fdf *rol);

// ============================================================================
// Management errors
// ============================================================================
void		ft_manage_err(const char *err);

// ============================================================================
// Functions to release
// ============================================================================
void		ft_cleanup(t_map *map, char *line, char **split_line, int32_t row);
void		ft_free_fdf(t_fdf *rol);
void		ft_free_inner(int32_t **array, int32_t length);
void		ft_free_map(t_map *map);
void		ft_free_split(char **split);
void		ft_free_superarray(t_map *map, int32_t rows);

// ============================================================================
// Initialization functions
// ============================================================================
t_map		*ft_init_map(char *argv);
t_fdf		*ft_init(const char *filepath);

// ============================================================================
// Peripherals
// ============================================================================
void		ft_key_hook(mlx_key_data_t keydata, void *param);
void		ft_toggle_projection(t_fdf *rol);

// ============================================================================
// Several functions
// ============================================================================
float		ft_absolute(float n);
void		ft_collect_z_minmax(t_map *map);
void		ft_complete_matrix(int32_t **nb, char *line, int32_t map_width);
int32_t		ft_count_words(char *s, char c);
int32_t		ft_get_min(int32_t nbr1, int32_t nbr2);
int			ft_intpart(float n);
float		ft_fracpart(float n);
float		ft_revfracpart(float n);
int32_t		ft_matrix_height(char *map_file);
int32_t		ft_matrix_width(char *map_file);
void		ft_swapping(int *a, int *b);


#endif