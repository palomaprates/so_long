/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:53:23 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/25 12:53:32 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_image(t_image *canva, t_image *image, int x, int y)
{
	int	index_x;
	int	index_y;
	int	pixel;

	index_y = 0;
	while (index_y < image->height)
	{
		index_x = 0;
		while (index_x < image->width)
		{
			pixel = get_pixel_canva(image, index_x, index_y);
			if (pixel != -16777216 && pixel != 0)
				my_mlx_pixel_put(canva, (x + index_x), (y + index_y), pixel);
			index_x++;
		}
		index_y++;
	}
}
