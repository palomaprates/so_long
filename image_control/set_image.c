/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:08:47 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/24 19:09:34 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_image(t_image *image, void *mlx, char *source, int *endian)
{
	image->img = mlx_xpm_file_to_image(mlx,
			source, &image->width, &image->height);
	image->addr = mlx_get_data_addr(image->img,
			&image->bits_per_pixel, &image->line_length, endian);
}
