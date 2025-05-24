/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:05:16 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/24 19:06:24 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_images(t_data *data)
{
	data->canva.img = mlx_new_image(data->mlx, \
	data->width_win, data->height_win);
	data->canva.addr = mlx_get_data_addr(data->canva.img, \
	&data->canva.bits_per_pixel, &data->canva.line_length, &data->canva.endian);
	set_image(&data->background, data->mlx, \
	"./images/background.xpm", &data->background.endian);
	set_image(&data->player.image, data->mlx, \
	"./images/peach.xpm", &data->player.image.endian);
	set_image(&data->wall, data->mlx, \
	"./images/walls.xpm", &data->wall.endian);
	set_image(&data->coins, data->mlx, \
	"./images/coins.xpm", &data->coins.endian);
	set_image(&data->exit.image, data->mlx, \
	"./images/mario.xpm", &data->exit.image.endian);
}
