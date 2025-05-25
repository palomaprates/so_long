/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:01:52 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/25 13:01:53 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	if (dest_size > 0)
	{
		while (src[i] && i < dest_size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[src_len])
		src_len++;
	return (src_len);
}
