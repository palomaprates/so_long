/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 18:57:45 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/24 18:57:46 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	game_images(t_data *param)
{
	char	*next_pos;

	print_element(&param->canva, param->map, BACKGROUND, &param->background);
	print_element(&param->canva, param->map, EXIT, &param->background);
	print_element(&param->canva, param->map, PLAYER, &param->background);
	print_element(&param->canva, param->map, COINS, &param->background);
	print_element(&param->canva, param->map, COINS, &param->coins);
	next_pos = touch_element(param->player.x, param->player.y, param->map);
	if (*next_pos == COINS)
		*next_pos = BACKGROUND;
	print_exit(param);
	print_avatar(&param->canva, param->player);
	print_element(&param->canva, param->map, WALL, &param->wall);
	if (*next_pos == EXIT && !number_of_elements(param->map, COINS))
		cleanup_and_exit(param);
	mlx_put_image_to_window(param->mlx, param->mlx_win, param->canva.img, 0, 0);
}
