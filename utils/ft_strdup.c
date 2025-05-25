/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:01:06 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/25 13:01:09 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	new_str = malloc(sizeof(char) * i + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
