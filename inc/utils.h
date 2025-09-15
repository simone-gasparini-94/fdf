/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 14:13:53 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/23 12:37:19 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"
# include <stdint.h>

uint32_t	str_to_color(char *s);
int			hex_char_to_int(char c);
void		clean_all(t_data *data);
void		clean_map(t_map map);
void		reset_fd(int fd);

#endif
