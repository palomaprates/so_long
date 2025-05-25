/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:50:57 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/25 12:50:57 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	parsing_map(t_data data)
{
	if (!is_retangular_map(data.map))
		return (ft_printf("map is not retangular\n"), 0);
	if (!*data.map)
		return (0);
	if (!is_map_enclosed(data.map))
		return (ft_printf("map is not enclosed\n"), 0);
	if (number_of_elements(data.map, 'E') != 1)
		return (ft_printf("must be one exit\n"), 0);
	if (number_of_elements(data.map, 'P') != 1)
		return (ft_printf("there are more than one initial position\n"), 0);
	if (number_of_elements(data.map, 'C') < 1)
		return (ft_printf("there are not collectibles"), 0);
	return (1);
}
