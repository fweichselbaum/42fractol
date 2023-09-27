/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichs@student.42vienna.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:19:07 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/27 12:42:27 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"

# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 1500
# define HEIGHT 1000
# define RATIO ((double) WIDTH / HEIGHT)

# define X_CENTER -0.5
# define Y_CENTER 0

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	*img;
}			t_mlx;

typedef struct s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

typedef struct s_range
{
	int	min;
	int	max;
}		t_range;

void	frac_mandelbrot(t_mlx *meta);
void	frac_julia(t_mlx *meta);

double	map(double v, t_range *in, t_range *out);
double	map_win(double v, int bound, double min, double max);

t_img	*img_create(t_mlx *meta);
void	img_pixel(t_img *img, int x, int y, int color);
void	img_render_free(t_mlx *meta, t_img *img);

#endif