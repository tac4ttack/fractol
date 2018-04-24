/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 00:46:33 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/09 23:02:30 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		usage(void)
{
	ft_putchar('\n');
	ft_putendl("\x1b[1;4;31mUsage:\x1b[0m ./fractol \x1b[1;32m[type]\x1b[0m\n");
	ft_putendl("\x1b[1;4;31mAvailable fractal types:\x1b[0m");
	ft_putendl("\x1b[1;32mmandelbrot\x1b[0m -> the Mandelbrot set");
	ft_putendl("\x1b[1;32mtricorn\x1b[0m -> the Tricorn set aka Mandelbar");
	ft_putendl("\x1b[1;32mjulia\x1b[0m -> the Julia set");
	ft_putendl("\x1b[1;32mburning\x1b[0m -> the Burning Ship set");
	ft_putendl("\x1b[1;32mceltic\x1b[0m -> the Celtic set");
	ft_putendl("\x1b[1;32mmandeldrop\x1b[0m -> the Mandeldrop set");
	ft_putendl("You can launch multiple fractals separating them with a space");
	exit(EXIT_FAILURE);
}

void	error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

int		quit(t_env *e)
{
	mlx_destroy_image(e->mlx, e->sce->p_img);
	mlx_destroy_window(e->mlx, e->win);
	free(e->title);
	free(e->fractal);
	free(e);
	ft_putendl_fd("Exiting", 2);
	exit(EXIT_SUCCESS);
	return (0);
}

char	*get_fractal(t_env *e)
{
	if (e->select == 0)
		return ("Powered Mandelbrot");
	else if (e->select == 1)
		return ("Powered Tricorn");
	else if (e->select == 2)
		return ("Powered Julia");
	else if (e->select == 3)
		return ("Burning Ship");
	else if (e->select == 4)
		return ("Celtic");
	else if (e->select == 5)
		return ("Powered Mandeldrop");
	else
		return ("ERROR");
}
