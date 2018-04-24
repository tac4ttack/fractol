/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 09:39:21 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/12 16:21:56 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx_mouse_events(int btn, int x, int y, t_env *e)
{
	e->mouse_x = x;
	e->mouse_y = y;
	(btn ? e->refresh = 1 : 0);
	(btn == 1 ? mouse_zoom_in(e, x, y) : 0);
	(btn == 2 ? mouse_zoom_out(e, x, y) : 0);
	(btn == 4 ? mouse_zoom_in(e, x, y) : 0);
	(btn == 5 ? mouse_zoom_out(e, x, y) : 0);
	return (0);
}
