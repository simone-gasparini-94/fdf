/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:41:56 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/25 16:43:48 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <X11/X.h>
#include "macros.h"
#include "structs.h"
#include "get_map.h"
#include "events.h"
#include "render.h"
#include "utils.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (1);
	get_map(&data.map, argv[1]);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, argv[1]);
	if (!data.win)
		return (1);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_mouse_hook(data.win, &handle_mouse_scroll, &data);
	mlx_hook(data.win, DestroyNotify, 0, &close_window, &data);
	data.img.img = NULL;
	render(&data);
	mlx_loop(data.mlx);
	clean_all(&data);
	return (0);
}
