/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_clear_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:02:26 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/25 13:02:28 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	to_clear_buffer(char *s1)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * ft_strlen(s1));
	while (s1[i] && s1[i] != '\n')
		i++;
	if (s1[i] == '\n')
		i++;
	while (s1[i])
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	new[j] = '\0';
	i = -1;
	while (new[++i])
		s1[i] = new[i];
	s1[i] = '\0';
	free(new);
}
