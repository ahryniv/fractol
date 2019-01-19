/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 20:34:31 by ahryniv           #+#    #+#             */
/*   Updated: 2018/06/04 20:39:21 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fract.h"

void	put_pixel(t_image **z_img, int x, int y, int n)
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

void	make_magic(t_image **z_img, int x, int y, double c_im)
{
	double	z_re;
	double	z_im;
	int		n;
	double	z_re2;
	double	z_im2;

	z_re = (*z_img)->min_re + x * (*z_img)->re_factor;
	z_im = c_im;
	n = 0;
	while (n < (*z_img)->depth)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4)
			break ;
		z_im = 2 * z_re * z_im + c_im;
		z_re = z_re2 - z_im2 + (*z_img)->min_re + x * (*z_img)->re_factor;
		n++;
	}
	put_pixel(z_img, x, y, n);
}

void	draw_mandelbrot(t_image *z_img, int n)
{
	double	c_im;
	int		x;
	int		y;

	z_img->re_factor = (z_img->max_re - z_img->min_re) / (z_img->width - 1);
	z_img->im_factor = (z_img->max_im - z_img->min_im) / (z_img->height - 1);
	y = 0;
	while (y < z_img->height)
	{
		c_im = z_img->max_im - y * z_img->im_factor;
		x = z_img->p_for_thread * n;
		while (x >= z_img->p_for_thread * n &&
			x < (z_img->p_for_thread * n) + z_img->p_for_thread)
		{
			make_magic(&z_img, x, y, c_im);
			x++;
		}
		y++;
	}
}
