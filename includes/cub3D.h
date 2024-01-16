/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apereira <apereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:28:33 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/16 10:52:30 by apereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/GNL/get_next_line.h"
# include "../includes/mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "math.h"

# define WDW_WIDTH 800
# define WDW_HEIGHT 600
# define ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define INFINITY 1000000

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_wall
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_wall;

// pos_x & pos_y = exact player coordinates
// map->coord integer rounded player coordinates
typedef struct s_config
{
	void	*mlx;
	void	*wdw;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	distance;
	double	height;
	char	**map;
	char	**textures;

	char	*so;
	char	*no;
	char	*we;
	char	*ea;

	int		f[3];
	int		c[3];
	int		map_width;
	int		map_height;
	int		hit;
	int		step_x;
	int		step_y;
	int		*map_coord;
	int		side;

	t_img	img;
	t_wall	wall[4];
}	t_config;

// parser.c
int		parser(char *src);

// parser_utils.c
int		ft_contains_str(char *scfile_line, char *contained);

// extract.c
char	**extract(char *src);

// events.c
int		handle_keys(int key, t_config *config);

// utils.c
void	vars_init(t_config *config);
int		ft_exit_cub(t_config *config);

#endif