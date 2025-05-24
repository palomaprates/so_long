/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:03:10 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/24 19:05:06 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_images(t_data *data)
{
	mlx_destroy_image(data->mlx, data->background.img);
	mlx_destroy_image(data->mlx, data->wall.img);
	mlx_destroy_image(data->mlx, data->canva.img);
	mlx_destroy_image(data->mlx, data->coins.img);
	mlx_destroy_image(data->mlx, data->player.image.img);
	mlx_destroy_image(data->mlx, data->exit.image.img);
}
