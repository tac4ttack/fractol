/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:48:39 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/12 20:36:34 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			render(t_env *e)
{
	if (e->select == 0)
		multibrot(e);
	else if (e->select == 1)
		tricornpow(e);
	else if (e->select == 2)
		juliapow(e);
	else if (e->select == 3)
		burning_ship(e);
	else if (e->select == 4)
		celtic(e);
	else if (e->select == 5)
		mandeldrop(e);
	else
		error("\x1b[2;31mUnknown fractal parameter given, exiting :/\x1b[0m");
	(e->guides > 0 ? mid_guides(e) : 0);
}

void			refresh(t_env *e)
{
	ft_bzero(e->sce->img, (e->m_w * e->m_h));
	if (e->refresh == 1 || e->select == 2)
	{
		render(e);
		e->refresh = 0;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->sce->p_img, e->s_x, e->s_y);
	hud(e);
}
