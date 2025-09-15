/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:21:26 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/21 14:24:52 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include <stdint.h>
# include "structs.h"

int		render(t_data *data);
void	render_model(t_data *data);
void	draw_line(t_img *img, t_point *point1, t_point *point2);
void	get_line_data(t_line *line, t_point *point1, t_point *point2);
int		put_pixel(t_img *img, int x, int y, uint32_t color);

#endif
