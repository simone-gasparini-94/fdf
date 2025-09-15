/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:08:16 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/25 16:44:59 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <mlx.h>
#include "structs.h"
#include "macros.h"
#include "render.h"
#include "utils.h"

int	render(t_data *data)
{
	if (!data->win)
		return (1);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bpp,
			&data->img.line_l, &data->img.endian);
	render_model(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

void	render_model(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < data->map.rows)
	{
		j = 0;
		while (j < data->map.cols)
		{
			put_pixel(&data->img,
				data->map.points_matrix[i][j].screen_x,
				data->map.points_matrix[i][j].screen_y,
				data->map.points_matrix[i][j].color);
			if (i + 1 < data->map.rows)
				draw_line(&data->img, &data->map.points_matrix[i][j],
					&data->map.points_matrix[i + 1][j]);
			if (j + 1 < data->map.cols)
				draw_line(&data->img, &data->map.points_matrix[i][j],
					&data->map.points_matrix[i][j + 1]);
			j++;
		}
		i++;
	}
}

void	draw_line(t_img *img, t_point *point1, t_point *point2)
{
	t_line		line;

	get_line_data(&line, point1, point2);
	while (1)
	{
		put_pixel(img, line.x0, line.y0, line.color);
		line.e2 = 2 * line.err;
		if (line.e2 >= line.dy)
		{
			if (line.x0 == line.x1)
				break ;
			line.err += line.dy;
			line.x0 += line.sx;
		}
		if (line.e2 <= line.dx)
		{
			if (line.y0 == line.y1)
				break ;
			line.err += line.dx;
			line.y0 += line.sy;
		}
	}
}

void	get_line_data(t_line *line, t_point *point1, t_point *point2)
{
	line->x0 = point1->screen_x;
	line->x1 = point2->screen_x;
	line->y0 = point1->screen_y;
	line->y1 = point2->screen_y;
	line->dx = abs(line->x1 - line->x0);
	line->dy = -abs(line->y1 - line->y0);
	if (line->x0 < line->x1)
		line->sx = 1;
	else
		line->sx = -1;
	if (line->y0 < line->y1)
		line->sy = 1;
	else
		line->sy = -1;
	line->err = line->dx + line->dy;
	line->color = point1->color;
}

int	put_pixel(t_img *img, int x, int y, uint32_t color)
{
	char		*px;

	if (x >= 0 && x < WINDOW_WIDTH && y >= 0 && y < WINDOW_HEIGHT)
		px = img->addr + (y * img->line_l + x * (img->bpp / 8));
	else
		return (1);
	*(uint32_t *)px = color;
	return (0);
}
