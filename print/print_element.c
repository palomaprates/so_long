/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:52:08 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/25 12:53:01 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_element(t_image *canva, char **map, char c, t_image *img)
{
	int	line;
	int	length;

	line = 0;
	while (map[line])
	{
		length = 0;
		while (map[line][length])
		{
			if (map[line][length] == c)
				print_image(canva, img, (length * SIZE), (line * SIZE));
			length++;
		}
		line++;
	}
}
