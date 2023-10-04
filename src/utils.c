/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fweichse <fweichs@student.42vienna.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 08:57:24 by fweichse          #+#    #+#             */
/*   Updated: 2023/09/27 12:15:58 by fweichse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double v, t_range *in, t_range *out)
{
	return (
		(v - in->min)
		/ (in->max - in->min)
		* (out->max - out->min)
		+ out->min);
}

double map_win(double v, int bound, double min, double max)
{
	return (v / bound * (max - min) + min);
}
