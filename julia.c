/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 20:39:58 by ahryniv           #+#    #+#             */
/*   Updated: 2018/06/04 20:42:37 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fract.h"

void	make_magic_julia(t_image **z_img, int x, int y, double c_im)
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
		z_im = 2 * z_re * z_im + (*z_img)->c_im;
		z_re = z_re2 - z_im2 + (*z_img)->c_re;
		n++;
	}
	put_pixel(z_img, x, y, n);
}

void	draw_julia(t_image *z_img, int n)
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
			make_magic_julia(&z_img, x, y, c_im);
			x++;
		}
		y++;
	}
}
