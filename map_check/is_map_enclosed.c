/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_enclosed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:49:50 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/25 12:50:09 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_map_enclosed(char **lines_map)
{
	int	i;
	int	j;
	int	last_line;
	int	last;

	i = 0;
	j = 0;
	last = ft_strlen(lines_map[i]);
	last_line = get_amount_lines(lines_map) - 1;
	while (j < last)
	{
		if (lines_map[0][j] != '1' || lines_map[last_line][j] != '1')
			return (0);
		j++;
	}
	while (i < last_line)
	{
		if (lines_map[i][0] != '1' || lines_map[i][last - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
