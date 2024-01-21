/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:28:33 by ratavare          #+#    #+#             */
/*   Updated: 2024/01/21 17:38:31 by ratavare         ###   ########.fr       */
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
# define INFINITE 1000000

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
	char	letter;

	int		f[3];
	int		c[3];
	int		map_width;
	int		map_height;
	int		hit;
	int		*colors;
	int		step_x;
	int		step_y;
	int		*map_coord;
	int		side;
	int		start;
	int		end;

	t_img	img;
	t_wall	wall[4];
}	t_config;

// parser.c
int				parser(char *src, t_config *config);

// parser_utils.c
int				ft_longest_line_size(char	**ptp);
int				ft_contains_str(char *scfile_line, char *contained);
void			ft_add_textures(char *scfile_line, int *count, \
					t_config *config, int id);
void			ft_add_colors(char *scfile_line, int *count, \
					t_config *config, int id);
void			get_player_pos(char **map, int *pos);

// Extract.c
int				count_lines(char *src);
char			**extract(char *src);

// Events.c
int				keyboard_handle(int key, t_config *config);

// Utils.c
void			vars_init_helper(t_config *config);
void			vars_init(t_config *config);
int				ft_free_exit_cub(t_config *config);


// map.c
char			**get_map(char **scfile_text);
int				check_map(char **map);


// Distance.c
double			*calculate_dist(t_config *config, double *ray);
double			*dist_1(double *ray);
double			*dist_2(t_config *config, double *ray, double *dist);

// Math.c
double			*calculate_ray(t_config *config, double x);
void			ft_calculations_helper(t_config *config, double *dist);
void			ft_calculations(t_config *config);

// Drawing.c
void			get_image_vars(t_config *config, int side, double *dist);
unsigned int	get_pixel_texture(t_config *config, int y, double *ray);
void			draw_img(int x, t_config *config, double *dist, double *ray);

// Drawing_aux.c
void			ft_mlx_pixel_put(t_config *config, int x, int y, int color);
int				get_i(t_config *config, double *ray);

// free.c
void			free_ptp(char	**ptp);
void			free_textures(t_config *config);

// error.c
int				parsing_error(t_config *config, char *msg, int err_nbr);

#endif