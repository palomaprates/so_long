/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:50:32 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/25 12:50:43 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	number_of_elements(char **lines_map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (lines_map[i])
	{
		j = 0;
		while (lines_map[i][j])
		{
			if (lines_map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
