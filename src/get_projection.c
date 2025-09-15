/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:40:21 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/21 14:49:52 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_projection.h"

void	get_projection(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			map->points_matrix[i][j].iso_x = map->points_matrix[i][j].x
				- map->points_matrix[i][j].y;
			map->points_matrix[i][j].iso_y = ((map->points_matrix[i][j].x
						+ map->points_matrix[i][j].y)
					/ map->projection)
				- map->points_matrix[i][j].z;
			j++;
		}
		i++;
	}
}
