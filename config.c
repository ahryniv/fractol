/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 19:45:02 by ahryniv           #+#    #+#             */
/*   Updated: 2018/06/04 20:58:48 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fract.h"

int		*set_color(int red, int green, int blue)
{
	int *rgb;

	rgb = malloc(sizeof(int) * 3);
	rgb[0] = red;
	rgb[1] = green;
	rgb[2] = blue;
	return (rgb);
}

void	set_colors(t_image **z_img)
{
	(*z_img)->colors[0] = set_color(66, 30, 15);
	(*z_img)->colors[1] = set_color(25, 7, 26);
	(*z_img)->colors[2] = set_color(9, 1, 47);
	(*z_img)->colors[3] = set_color(4, 4, 73);
	(*z_img)->colors[4] = set_color(0, 7, 100);
	(*z_img)->colors[5] = set_color(12, 44, 138);
	(*z_img)->colors[6] = set_color(24, 82, 177);
	(*z_img)->colors[7] = set_color(57, 125, 209);
	(*z_img)->colors[8] = set_color(134, 181, 229);
	(*z_img)->colors[9] = set_color(211, 236, 248);
	(*z_img)->colors[10] = set_color(241, 233, 191);
	(*z_img)->colors[11] = set_color(248, 201, 95);
	(*z_img)->colors[12] = set_color(255, 170, 0);
	(*z_img)->colors[13] = set_color(204, 128, 0);
	(*z_img)->colors[14] = set_color(153, 87, 0);
	(*z_img)->colors[15] = set_color(106, 52, 3);
}

void	fill_structure(t_image **z_img, char *title)
{
	*z_img = malloc(sizeof(t_image));
	(*z_img)->mlx = mlx_init();
	(*z_img)->width = !ft_strcmp(title, "julia") ? 600 : 900;
	(*z_img)->height = 600;
	(*z_img)->depth = 100;
	(*z_img)->win = mlx_new_window((*z_img)->mlx, (*z_img)->width,
			(*z_img)->height, title);
	(*z_img)->img = mlx_new_image((*z_img)->mlx, (*z_img)->width,
			(*z_img)->height);
	(*z_img)->image = mlx_get_data_addr((*z_img)->img,
			&((*z_img)->b_p_p), &((*z_img)->s_l), &((*z_img)->en));
	(*z_img)->title = ft_strdup(title);
	(*z_img)->min_re = !ft_strcmp(title, "ship") ? -3.0 : -2.0;
	(*z_img)->max_re = !ft_strcmp(title, "julia") ? 2.0 : 1.0;
	(*z_img)->max_re = !ft_strcmp(title, "ship") ? 1.5 : (*z_img)->max_re;
	(*z_img)->min_im = !ft_strcmp(title, "julia") ? -2.0 : -1.0;
	(*z_img)->max_im = (*z_img)->min_im + ((*z_img)->max_re - (*z_img)->min_re)
		* (*z_img)->height / (*z_img)->width;
	(*z_img)->p_for_thread = (*z_img)->width / 4;
	(*z_img)->c_im = 0.288;
	(*z_img)->c_re = 0.353;
	(*z_img)->change_julia = 1;
	(*z_img)->color_kof = !ft_strcmp(title, "ship") ? 14 : -17;
	(*z_img)->colors_k = !ft_strcmp(title, "ship") ? 13 : 16;
	set_colors(z_img);
}

void	print_usage(void)
{
	ft_putstr("usage : fractol [fractals]\n");
	ft_putstr("fractals :\n");
	ft_putstr("--> mandelbrot\n");
	ft_putstr("--> julia\n");
	ft_putstr("--> ship\n");
}
