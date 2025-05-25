/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_canva.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:28:43 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/25 12:29:33 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_pixel_canva(t_image *image, int x, int y)
{
	return (*(unsigned int *)(image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8))));
}
