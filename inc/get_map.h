/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:15:20 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/16 10:24:31 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H
# define GET_MAP_H

# include "structs.h"

void	get_map(t_map *map, char *file);
int		count_rows(char *file);
int		count_cols(char *file);
char	***get_str_matrix(char *file, int rows);
void	get_map_2d_points(t_map *map);

#endif
