/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichse@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:59:58 by fweichse          #+#    #+#             */
/*   Updated: 2023/10/24 17:49:55 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int findMandelbrot (double cr, double ci)
{
	int max_iterations = 100;
	int i = 0;
	double zr = 0.0, zi = 0.0;
	double zr2 = 0.0, zi2 = 0.0;
	double temp;
	while (i < max_iterations && zr2 + zi2 < 4.0)
	{
		temp = zr2 - zi2 + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		zr2 = zr * zr;
		zi2 = zi * zi;
		++i;
	}
	return(i - 1);
}

int mandel(double cr, double ci)
{
	int max_iterations = 100;
	int i = 0;
	double zr = 0.0, zi = 0.0;
	double temp;
	while (i < max_iterations && zr * zr + zi * zi < 16.0)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		++i;
	}
	return i;
}

void	frac_mandelbrot(t_mlx *meta)
{
	int max_iter = 100;
	int brightness;
	int x = 0;
	int y = 0;
	int n;
	t_complex	v;
	t_complex	v_clone;
	t_complex	v_new;

	printf("center(%lf %lf)\n",
		meta->params->x_center,
		meta->params->y_center);
	fflush(0);

	meta->img = img_create(meta);
	if (!meta->img)
		return ;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{		
			v.real = map_win(x, WIDTH,
				meta->params->x_center - meta->params->zoom * ((double) WIDTH / HEIGHT),
				meta->params->x_center + meta->params->zoom * ((double) WIDTH / HEIGHT));
			v.imaginary = map_win(y, HEIGHT,
				meta->params->y_center - meta->params->zoom,
				meta->params->y_center + meta->params->zoom);
			v_clone.real = v.real;
			v_clone.imaginary = v.imaginary;
			n = 0;
			while (n < max_iter)
			{
				v_new.real = v.real * v.real - v.imaginary * v.imaginary;
				v_new.imaginary = 2 * v.real * v.imaginary;
				v.real = v_new.real + v_clone.real;
				v.imaginary = v_new.imaginary + v_clone.imaginary;
				if (v.real * v.real + v.imaginary * v.imaginary > 16)
					break ;
				n++;
			}
			if (n == max_iter)
			{
				y++;
				continue ;
			}
			brightness = sqrt(((double) n) / max_iter) * 0xff;


			// brightness = sqrt(mandel(v.real, v.imaginary) / (double) 100) * 0xff;

			img_pixel(meta->img, x, y, brightness << 16 | brightness << 8 | brightness);
			y++;
		}
		x++;
	}
	img_render_free(meta, meta->img);
}
