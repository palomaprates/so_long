/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pprates- <pprates-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 12:53:08 by pprates-          #+#    #+#             */
/*   Updated: 2025/05/25 12:53:09 by pprates-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_exit(t_data *param)
{
	if (!number_of_elements(param->map, COINS))
		print_element(&param->canva, param->map, EXIT, &param->exit.image);
}
