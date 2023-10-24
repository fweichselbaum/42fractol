/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichse@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:30:39 by fweichse          #+#    #+#             */
/*   Updated: 2023/10/24 18:03:19 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <X11/X.h>
#include <stdio.h>

int	terminate_program(t_mlx *meta)
{
	mlx_destroy_window(meta->mlx, meta->win);
	mlx_destroy_display(meta->mlx);
	free(meta->mlx);
	exit(0);
}

int	mouse_event(int button, int x, int y, t_mlx *meta)
{
	double	factor;
	double	dx;
	double	dy;
	printf("mouse -> %d %d\n", x, y);

	if (button == Button4)
		factor = 0.5;
	else if (button == Button5)
		factor = 2;
	else
		return (0);

	printf("topleft(%lf %lf)\n",
		meta->params->x_center * WIDTH,
		meta->params->y_center * HEIGHT);
	dx = map_win(x, WIDTH,
		meta->params->x_center - meta->params->zoom * ((double) WIDTH / HEIGHT),
		meta->params->x_center + meta->params->zoom * ((double) WIDTH / HEIGHT));
	dy = map_win(y, HEIGHT,
		meta->params->y_center - meta->params->zoom,
		meta->params->y_center + meta->params->zoom);
	if(button == Button5)
	{
		dx = -dx;
		dy = -dy;
	}
	meta->params->zoom *= factor;
	meta->params->x_center += dx * meta->params->zoom;
	meta->params->y_center += dy * meta->params->zoom;

	printf("delta(%lf %lf)\n",
		dx,
		dy);

	frac_mandelbrot(meta);
	return (0);
}

int	key_event(int key, t_mlx *meta)
{
	double	step;

	step = 0.1 * meta->params->zoom;
	if (key == 'r' || key == 'R')
	{
		meta->params->x_center = 0;//-0.5;
		meta->params->y_center = 0;
		meta->params->zoom = 1;
	}
	else if (key == U_ARROW)
		meta->params->y_center -= step;
	else if (key == D_ARROW)
		meta->params->y_center += step;
	else if (key == L_ARROW)
		meta->params->x_center -= step;
	else if (key == R_ARROW)
		meta->params->x_center += step;
	else
		return (0);
	frac_mandelbrot(meta);
	return (0);
}

int main()
{
	t_mlx	meta;
	t_param	params;

	meta.mlx = mlx_init(); // error handling
	meta.win = mlx_new_window(meta.mlx, WIDTH, HEIGHT, "Fractol");
	meta.img = NULL;
	meta.params = &params;
	meta.params->x_center = 0; //-0.5;
	meta.params->y_center = 0;
	meta.params->zoom = 1;

	mlx_mouse_hook(meta.win, mouse_event, &meta);
	mlx_key_hook(meta.win, key_event, &meta);
	mlx_hook(meta.win, 17, 0, terminate_program, &meta);

	frac_mandelbrot(&meta);

	mlx_loop(meta.mlx);
}
