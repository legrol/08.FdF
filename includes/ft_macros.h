/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-olm <rdel-olm@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 22:22:32 by rdel-olm          #+#    #+#             */
/*   Updated: 2024/09/05 18:53:23 by rdel-olm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MACROS_H
# define FT_MACROS_H

# define DEFAULT_WIDTH			1080
# define DEFAULT_HEIGHT			720
# define WIDTH					1920
# define HEIGHT					1080
# define DEFAULT_MENU_WIDTH		250
# define M_PI					3.14159265358979323846

# define INIT_ERR		"42FdF : ==> "
# define NUM_ARGV_ERR	BDRED "42FdF : ==> " YELLOW \
						"❗1️⃣ Incorrect number of arguments, expected \
						one." RESET
# define NAME_EXT_ERR	BDRED "42FdF : ==> " YELLOW \
						"🔣 Please enter a file that ends with [.fdf]" RESET
# define OPEN_ERR		BDRED "42FdF : ==> " YELLOW \
						"📖 Error opening source file!!!" RESET
# define CLOSED_ERR		BDRED "42FdF : ==> " YELLOW \
						"📚 Error closing source file!!!" RESET
# define FILE_READ_ERR	BDRED "42FdF : ==> " YELLOW \
						"📑 File read error!!!" RESET
# define SHORT_NAME_ERR	BDRED "42FdF : ==> " YELLOW \
						"🗺️ Map name is very short!!!" RESET
# define EXT_ERR		BDRED "42FdF : ==> " YELLOW \
						"❌ⓔⓧⓣ File extension error!!!" RESET
# define MALLOC_ERR		BDRED "42FdF : ==> " YELLOW \
						"❌Ⓜⓐⓛⓛⓞⓒ Error creating malloc!!!" RESET
# define MLX_ERR 		BDRED "42FdF : ==> " YELLOW \
						"4️⃣2️⃣📈📉 Error connecting to graphics server \
						MLX42!!!" RESET
# define IMG_ERR 		BDRED "42FdF : ==> " YELLOW \
						"❌4️⃣2️⃣🎞️ Error initializing image MLX42!!!" RESET
# define INIT_MAP_ERR	BDRED "42FdF : ==> " YELLOW \
						"🌎 Error initializing map!!!"	RESET
# define MATRIX1_ERR	BDRED "42FdF : ==> " YELLOW \
						"🔛 Wrong matrix line width!!!" RESET
# define MATRIX2_ERR	BDRED "42FdF : ==> " YELLOW \
						"❗🔛 FdF file has irregular width!!!" RESET
# define INIT_CAM_ERR	BDRED "42FdF : ==> " YELLOW \
						"📽️ Error initializing camera!!!" RESET
# define MLLC_CAM_ERR	BDRED "42FdF : ==> " YELLOW \
						"📽️ Error ailed to allocate memory for camera!!!" RESET
# define GET_NAME_ERR	BDRED "42FdF : ==> " YELLOW \
						"📽️ Error in the extraction and generation of the \
						name!!!" RESET

#endif