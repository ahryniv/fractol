/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 20:43:11 by ahryniv           #+#    #+#             */
/*   Updated: 2018/06/04 20:46:27 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fract.h"

void	put_pixel_ship(t_image **z_img, int x, int y, int n)
{
	int		ii;
	int		k;

	k = (n + (*z_img)->color_kof) % (*z_img)->colors_k;
	k = k < 0 ? k * (-1) : k;
	if (n == (*z_img)->depth)
	{
		ii = ((y * (*z_img)->width) + x) * 4;
		(*z_img)->image[ii] = 0;
		(*z_img)->image[ii + 1] = 0;
		(*z_img)->image[ii + 2] = 0;
	}
	else
	{
		ii = ((y * (*z_img)->width) + x) * 4;
		(*z_img)->image[ii] = (*z_img)->colors[k][0];
		(*z_img)->image[ii + 1] = (*z_img)->colors[k][1];
		(*z_img)->image[ii + 2] = (*z_img)->colors[k][2];
	}
}

void	make_magic_ship(t_image **z_img, int x, int y, double c_im)
{
	double	zx;
	double	zy;
	int		n;
	double	xtemp;

	zx = (*z_img)->min_re + x * (*z_img)->re_factor;
	zy = c_im;
	n = 0;
	while (n < (*z_img)->depth)
	{
		xtemp = zx * zx - zy * zy + (*z_img)->min_re + (double)x
			* (*z_img)->re_factor;
		zy = 2 * fabs(zx * zy) - c_im;
		zx = fabs(xtemp);
		if (zx * zx + zy * zy > 4)
			break ;
		n++;
	}
	put_pixel_ship(z_img, x, y, n);
}

void	draw_ship(t_image *z_img, int n)
{
	double	c_im;
	int		x;
	int		y;

	z_img->re_factor = (z_img->max_re - z_img->min_re) / (z_img->width - 1);
	z_img->im_factor = (z_img->max_im - z_img->min_im) / (z_img->height - 1);
	y = 0;
	while (y < z_img->height)
	{
		c_im = z_img->max_im - (double)y * z_img->im_factor;
		x = z_img->p_for_thread * n;
		while (x >= z_img->p_for_thread * n &&
				x < (z_img->p_for_thread * n) + z_img->p_for_thread)
		{
			make_magic_ship(&z_img, x, y, c_im);
			x++;
		}
		y++;
	}
}
