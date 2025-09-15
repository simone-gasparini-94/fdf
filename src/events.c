/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:44:17 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/25 16:41:59 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <X11/keysym.h>
#include "structs.h"
#include "utils.h"
#include "events.h"
#include "render.h"
#include "get_projection.h"
#include "get_viewport.h"
#include "macros.h"

int	handle_keypress(int keysym, t_data *data)
{
	int	move_amount;

	move_amount = DEFAULT_MOVE_AMOUNT;
	if (keysym == XK_1 || keysym == XK_2)
		handle_projection(keysym, data);
	if (keysym == XK_Up)
		data->map.offset_y += move_amount;
	if (keysym == XK_Down)
		data->map.offset_y -= move_amount;
	if (keysym == XK_Left)
		data->map.offset_x += move_amount;
	if (keysym == XK_Right)
		data->map.offset_x -= move_amount;
	if (keysym == XK_Escape)
	{
		clean_all(data);
		exit (0);
	}
	mlx_clear_window(data->mlx, data->win);
	get_map_screen_points(&data->map);
	render(data);
	return (0);
}

void	handle_projection(int keysym, t_data *data)
{
	if (keysym == XK_1)
		data->map.projection = PROJECTION_1;
	if (keysym == XK_2)
		data->map.projection = PROJECTION_2;
	get_projection(&data->map);
	get_map_offsets(&data->map);
}

int	handle_mouse_scroll(int button, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (button == 4)
	{
		data->map.zoom *= 2;
		if (data->map.zoom >= MAX_ZOOM)
			data->map.zoom = MAX_ZOOM;
	}
	if (button == 5)
	{
		data->map.zoom /= 2;
		if (data->map.zoom <= MIN_ZOOM)
			data->map.zoom = MIN_ZOOM;
	}
	mlx_clear_window(data->mlx, data->win);
	get_projection(&data->map);
	get_map_zoom(&data->map);
	get_map_offsets(&data->map);
	get_map_screen_points(&data->map);
	render(data);
	return (0);
}

int	close_window(t_data *data)
{
	clean_all(data);
	exit (0);
}
