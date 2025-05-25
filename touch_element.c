/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:12:31 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/25 13:13:19 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*touch_element(int player_x, int player_y, char **map)
{
	int	lines;
	int	len;

	lines = ((player_y + PLAYER_MARGIN)) / SQUARE_SIZE;
	len = (player_x + PLAYER_MARGIN) / SQUARE_SIZE;
	return (&map[lines][len]);
}
