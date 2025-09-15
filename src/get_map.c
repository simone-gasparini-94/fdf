/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:11:00 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/25 16:23:56 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"
#include "get_map.h"
#include "get_projection.h"
#include "get_viewport.h"
#include "structs.h"
#include "macros.h"
#include "utils.h"

void	get_map(t_map *map, char *file)
{
	file = ft_strjoin("assets/", file);
	map->cell_size = DEFAULT_CELL_SIZE;
	map->rows = count_rows(file);
	map->cols = count_cols(file);
	map->projection = 1;
	map->zoom = DEFAULT_ZOOM;
	map->str_matrix = get_str_matrix(file, map->rows);
	free(file);
	get_map_2d_points(map);
	get_projection(map);
	get_color(map);
	get_map_zoom(map);
	get_map_offsets(map);
	get_map_screen_points(map);
}

int	count_rows(char *file)
{
	char	*line;
	int		fd;
	int		rows;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (1);
	rows = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rows++;
		free(line);
	}
	close(fd);
	return (rows);
}

int	count_cols(char *file)
{
	char	**arr;
	char	*line;
	int		fd;
	int		cols;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (1);
	line = get_next_line(fd);
	arr = ft_split(line, ' ');
	free(line);
	cols = 0;
	while (arr[cols] != NULL)
		cols++;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	reset_fd(fd);
	close(fd);
	return (cols);
}

char	***get_str_matrix(char *file, int rows)
{
	char	***matrix;
	char	*line;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit (1);
	matrix = (char ***)malloc(sizeof(char **) * rows);
	if (!matrix)
		return (NULL);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		matrix[i] = ft_split(line, ' ');
		free(line);
		i++;
	}
	close(fd);
	return (matrix);
}

void	get_map_2d_points(t_map *map)
{
	int	i;
	int	j;

	map->points_matrix = (t_point **)malloc(sizeof(t_point *) * (map->rows));
	if (!map->points_matrix)
		return ;
	i = 0;
	while (i < map->rows)
	{
		map->points_matrix[i] = (t_point *)
			malloc(sizeof(t_point) * (map->cols));
		if (!map->points_matrix[i])
			return ;
		j = 0;
		while (j < map->cols)
		{
			map->points_matrix[i][j].x = j * map->cell_size;
			map->points_matrix[i][j].y = i * map->cell_size;
			map->points_matrix[i][j].z = ft_atoi(map->str_matrix[i][j]);
			j++;
		}
		i++;
	}
}
