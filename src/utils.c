/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:11:57 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/25 15:48:31 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <mlx.h>
#include "libft.h"
#include "structs.h"
#include "macros.h"
#include "utils.h"
#include "get_next_line.h"

uint32_t	str_to_color(char *s)
{
	uint32_t	color;
	int			val;
	int			i;

	if (!s)
		return (WHITE);
	i = 2;
	color = BLACK;
	while (s[i])
	{
		val = hex_char_to_int(s[i]);
		if (val == -1)
			break ;
		color = (color << 4) | val;
		i++;
	}
	return (color);
}

int	hex_char_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (10 + (c - 'A'));
	if (c >= 'a' && c <= 'f')
		return (10 + (c - 'a'));
	return (-1);
}

void	clean_all(t_data *data)
{
	clean_map(data->map);
	if (data->img.img)
	{
		mlx_destroy_image(data->mlx, data->img.img);
		data->img.img = NULL;
	}
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

void	clean_map(t_map map)
{
	int	i;
	int	j;

	if (map.points_matrix)
	{
		i = 0;
		while (i < map.rows)
			free(map.points_matrix[i++]);
		free(map.points_matrix);
		map.points_matrix = NULL;
	}
	if (map.str_matrix)
	{
		i = 0;
		while (i < map.rows)
		{
			j = 0;
			while (j < map.cols)
				free(map.str_matrix[i][j++]);
			free(map.str_matrix[i++]);
		}
		free(map.str_matrix);
		map.str_matrix = NULL;
	}
}

void	reset_fd(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		free(line);
		line = NULL;
		if (!line)
			break ;
	}
}
