/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_viewport.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:04:16 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/25 16:43:17 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "structs.h"
#include "macros.h"
#include "get_viewport.h"
#include "libft.h"
#include "utils.h"

void	get_color(t_map *map)
{
	char		**matrix;
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			matrix = ft_split(map->str_matrix[i][j], ',');
			if (matrix[1])
				map->points_matrix[i][j].color = str_to_color(matrix[1]);
			else
				map->points_matrix[i][j].color = WHITE;
			k = 0;
			while (matrix[k])
				free(matrix[k++]);
			free(matrix);
			j++;
		}
		i++;
	}
}

void	get_map_zoom(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			map->points_matrix[i][j].iso_x *= map->zoom;
			map->points_matrix[i][j].iso_y *= map->zoom;
			j++;
		}
		i++;
	}
}

void	get_map_offsets(t_map *map)
{
	int		i;
	int		j;

	map->offset_x = 0;
	map->offset_y = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->points_matrix[i][j].iso_x < map->offset_x)
				map->offset_x = map->points_matrix[i][j].iso_x;
			if (map->points_matrix[i][j].iso_y < map->offset_y)
				map->offset_y = map->points_matrix[i][j].iso_y;
			j++;
		}
		i++;
	}
	map->offset_x *= -1;
	map->offset_y *= -1;
	map->padding_x = (WINDOW_WIDTH
			- map->points_matrix[0][map->cols - 1].iso_x) / 2;
	map->padding_y = (WINDOW_HEIGHT
			- map->points_matrix[map->rows - 1][map->cols - 1].iso_y) / 2;
}

void	get_map_screen_points(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			map->points_matrix[i][j].screen_x = (map->offset_x / 2)
				+ map->padding_x
				+ map->points_matrix[i][j].iso_x;
			map->points_matrix[i][j].screen_y = (map->offset_y / 2)
				+ map->padding_y
				+ map->points_matrix[i][j].iso_y;
			j++;
		}
		i++;
	}
}
