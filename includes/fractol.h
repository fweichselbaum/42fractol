/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichse@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:19:07 by fweichse          #+#    #+#             */
/*   Updated: 2023/10/04 18:44:06 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <X11/X.h>

# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 1500
# define HEIGHT 1000

# define L_ARROW 65361
# define U_ARROW 65362
# define R_ARROW 65363
# define D_ARROW 65364

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_param
{
	double	x_center;
	double	y_center;
	double	zoom;
}			t_param;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	*img;
	t_param	*params;
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