/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratavare <ratavare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 22:24:56 by ratavare          #+#    #+#             */
/*   Updated: 2024/02/14 15:47:01 by ratavare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	parsing_error(t_config *config, char *msg, int err_nbr)
{
	if (err_nbr == 1)
	{
		free(config->map_coord);
		free(config->textures);
		free(config->colors);
	}
	if (err_nbr == 2 || err_nbr == 3)
	{
		free(config->map_coord);
		free_textures(config);
		free(config->colors);
	}
	if (err_nbr == 4)
	{
		free_ptp(config->textures);
		free_ptp(config->map);
		free(config->colors);
		free(config->map_coord);
	}
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	return (1);
}

int	xpm_error(t_config *config)
{
	int	i;

	i = 0;
	parsing_error(config, "Invalid texture path.\n", 4);
	if (config->img.mlx_img)
		mlx_destroy_image(config->mlx, config->img.mlx_img);
	while (config->wall[i].img)
		if (config->wall[i].img)
			mlx_destroy_image(config->mlx, config->wall[i++].img);
	if (config->wdw && config->mlx)
		mlx_destroy_window(config->mlx, config->wdw);
	if (config->mlx)
		mlx_destroy_display(config->mlx);
	free(config->mlx);
	exit(1);
}
