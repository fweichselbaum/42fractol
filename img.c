/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichs@student.42vienna.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:18:52 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/27 11:58:41 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_img *img_create(t_mlx *meta)
{
	t_img *img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->ptr = mlx_new_image(meta->mlx, WIDTH, HEIGHT);
	img->data = mlx_get_data_addr(img->ptr,
		&img->bits_per_pixel,
		&img->line_length,
		&img->endian);
	return (img);
}

void	img_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	// endian
	// printf("%d %d -> %x\n", x, y, color);
	dst = img->data + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	img_render_free(t_mlx *meta, t_img *img)
{
	mlx_put_image_to_window(meta->mlx, meta->win, img->ptr, 0, 0);
	mlx_destroy_image(meta->mlx, img->ptr);
	free(img);
}