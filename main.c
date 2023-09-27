/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichs@student.42vienna.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:30:39 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/27 12:20:50 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	terminate_program(void *param)
{
	t_mlx	*meta;

	meta = (t_mlx *)param;
	mlx_destroy_window(meta->mlx, meta->win);
	mlx_destroy_display(meta->mlx);
	free(meta->mlx);
	puts("exit");
	exit(0);
}

int main()
{
	t_mlx	meta;

	meta.mlx = mlx_init(); // error handling
	meta.win = mlx_new_window(meta.mlx, WIDTH, HEIGHT, "oasch");
	meta.img = img_create(&meta);

	mlx_hook(meta.win, 17, 0, terminate_program, &meta);

	frac_mandelbrot(&meta);

	mlx_loop(meta.mlx);
}
