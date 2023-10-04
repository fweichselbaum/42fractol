/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichse@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:59:58 by fweichse          #+#    #+#             */
/*   Updated: 2023/10/04 18:37:14 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	frac_julia(t_mlx *meta)
// {
// 	int max_iter = 100;
// 	int brightness;

// 	int x = 0;
// 	int y = 0;
// 	int n;
// 	t_complex	v;
// 	t_complex	v_clone;
// 	t_complex	v_new;
// 	int	zoom = 1;

// 	while (x < WIDTH)
// 	{
// 		y = 0;
// 		while (y < HEIGHT)
// 		{
// 			v.real = map_win(x, WIDTH, X_CENTER - zoom * RATIO, X_CENTER + zoom * RATIO);
// 			v.imaginary = map_win(y, HEIGHT, Y_CENTER - zoom, Y_CENTER + zoom);
// 			// printf("%lf %lf\n", v.real, v.imaginary);
// 			v_clone.real = v.real;
// 			v_clone.imaginary = v.imaginary;
// 			n = 0;
// 			while (n < max_iter)
// 			{
// 				// printf("iter [%lf + %lfi]\n", v.real, v.imaginary);
// 				v_new.real = v.real * v.real - v.imaginary * v.imaginary;
// 				v_new.imaginary = 2 * v.real * v.imaginary;
// 				v.real = v_new.real + v_clone.real;
// 				v.imaginary = v_new.imaginary + v_clone.imaginary;
// 				if (v.real * v.real + v.imaginary * v.imaginary > 16)
// 					break ;
// 				n++;
// 			}
// 			if (n == max_iter)
// 			{
// 				y++;
// 				continue ;
// 			}
// 			brightness = ((double) n) / max_iter * 0xff;
// 			// brightness = sqrt(brightness) * 255;
// 			img_pixel(meta->img, x, y, brightness << 16 | brightness << 8 | brightness);
// 			y++;
// 		}
// 		x++;
// 	}
// 	img_render_free(meta, meta->img);
// }
