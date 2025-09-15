/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:47:50 by sgaspari          #+#    #+#             */
/*   Updated: 2025/07/16 15:10:11 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "structs.h"

int		handle_keypress(int keysym, t_data *data);
void	handle_projection(int keysym, t_data *data);
int		handle_mouse_scroll(int button, int x, int y, void *data);
int		close_window(t_data *data);

#endif
