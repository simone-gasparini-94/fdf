/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:44:45 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/21 15:38:13 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>

typedef struct s_line
{
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	uint32_t	color;
}	t_line;

typedef struct s_point
{
	int			x;
	int			y;
	int			z;
	int			iso_x;
	int			iso_y;
	int			screen_y;
	int			screen_x;
	uint32_t	color;
}	t_point;

typedef struct s_map
{
	t_point	**points_matrix;
	char	***str_matrix;
	int		rows;
	int		cols;
	int		offset_x;
	int		offset_y;
	int		padding_x;
	int		padding_y;
	int		cell_size;
	int		projection;
	int		zoom;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
}	t_data;

#endif
