/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_viewport.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:13:26 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/16 11:48:03 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_VIEWPORT_H
# define GET_VIEWPORT_H

# include "structs.h"

void	get_color(t_map *map);
void	get_map_zoom(t_map *map);
void	get_map_offsets(t_map *map);
void	get_map_screen_points(t_map *map);

#endif
