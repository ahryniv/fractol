/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:39:47 by ahryniv           #+#    #+#             */
/*   Updated: 2018/06/05 17:39:58 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fract.h"
#include <stdio.h>

void	what_key_colors(int keycode, t_image **z_img)
{
	if (keycode == 65433)
	{
		(*z_img)->color_kof += 1;
	}
	if (keycode == 65436)
	{
		(*z_img)->color_kof -= 1;
	}
	if (keycode == 65451)
	{
		(*z_img)->colors_k = (*z_img)->colors_k < 16 ? (*z_img)->colors_k + 1
			: (*z_img)->colors_k;
	}
	if (keycode == 65453)
	{
		(*z_img)->colors_k = (*z_img)->colors_k > 1 ? (*z_img)->colors_k - 1
			: (*z_img)->colors_k;
	}
	if (keycode == 65455)
	{
		(*z_img)->depth = (*z_img)->depth - 10 > 0 ? (*z_img)->depth - 10
			: (*z_img)->depth;
	}
}

void	what_key_move(int keycode, t_image **z_img)
{
	if (keycode == 65362)
	{
		(*z_img)->min_im = (*z_img)->min_im + ((*z_img)->max_im
				- (*z_img)->min_im) * 0.05;
		(*z_img)->max_im = (*z_img)->max_im + ((*z_img)->max_im
				- (*z_img)->min_im) * 0.05;
	}
	if (keycode == 65363)
	{
		(*z_img)->min_re = (*z_img)->min_re + ((*z_img)->max_re
				- (*z_img)->min_re) * 0.05;
		(*z_img)->max_re = (*z_img)->max_re + ((*z_img)->max_re
				- (*z_img)->min_re) * 0.05;
	}
	if (keycode == 65364)
	{
		(*z_img)->min_im = (*z_img)->min_im - ((*z_img)->max_im
				- (*z_img)->min_im) * 0.05;
		(*z_img)->max_im = (*z_img)->max_im - ((*z_img)->max_im
				- (*z_img)->min_im) * 0.05;
	}
	if (keycode == 65450)
	{
		(*z_img)->depth += 10;
	}
}

int		what_key(int keycode, t_image **z_img)
{
	if (keycode == 65307)
	{
		free_structure(z_img);
		exit(0);
	}
	if (keycode == 32)
	{
		(*z_img)->change_julia = (*z_img)->change_julia == 1 ? 0 : 1;
		return (0);
	}
	if (keycode == 65361)
	{
		(*z_img)->min_re = (*z_img)->min_re - ((*z_img)->max_re
				- (*z_img)->min_re) * 0.05;
		(*z_img)->max_re = (*z_img)->max_re - ((*z_img)->max_re
				- (*z_img)->min_re) * 0.05;
	}
	what_key_move(keycode, z_img);
	what_key_colors(keycode, z_img);
	draw_fractal(z_img);
	mlx_put_image_to_window((*z_img)->mlx, (*z_img)->win, (*z_img)->img, 0, 0);
	return (0);
}

int		mouse_cather(int button, int x, int y, t_image **z_img)
{
	if (button == 1)
	{
		make_zoom_plus(z_img, x, y);
	}
	else if (button == 3)
	{
		make_zoom_minus(z_img, x, y);
	}
	draw_fractal(z_img);
	mlx_put_image_to_window((*z_img)->mlx, (*z_img)->win, (*z_img)->img, 0, 0);
	return (0);
}

int		mouse_move(int x, int y, t_image **z_img)
{
	if ((*z_img)->change_julia == 1 && !ft_strcmp((*z_img)->title, "julia"))
	{
		(*z_img)->c_re = 1.0 / (double)(*z_img)->width * x;
		(*z_img)->c_im = 1.0 / (double)(*z_img)->height * y;
		draw_fractal(z_img);
		mlx_put_image_to_window((*z_img)->mlx, (*z_img)->win,
				(*z_img)->img, 0, 0);
	}
	return (0);
}
