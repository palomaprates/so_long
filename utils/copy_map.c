/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:53:46 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/25 13:00:27 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_map	copy_map(t_data data)
{
	t_map	new_map;
	int		i;

	new_map.map = NULL;
	new_map.collectibles = 0;
	new_map.flag = 0;
	new_map.map = malloc(sizeof(char *) * (get_amount_lines(data.map) + 1));
	if (!new_map.map)
		return (new_map);
	i = 0;
	while (data.map[i])
	{
		new_map.map[i] = ft_strdup(data.map[i]);
		if (!new_map.map[i])
		{
			while (--i >= 0)
				free(new_map.map[i]);
			free(new_map.map);
			return (new_map);
		}
		i++;
	}
	return (new_map.map[i] = NULL, \
	new_map.collectibles = data.collectibles, new_map.flag = 0, new_map);
}
