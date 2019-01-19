/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 20:11:58 by ahryniv           #+#    #+#             */
/*   Updated: 2018/06/04 21:02:36 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fract.h"

void	draw_fractal(t_image **z_img)
{
	pthread_t	*threads;
	t_thread	*thread_data;
	int			i;

	thread_data = (t_thread*)malloc(4 * sizeof(t_thread));
	threads = (pthread_t*)malloc(4 * sizeof(pthread_t));
	i = 0;
	while (i < 4)
	{
		thread_data[i].n = i;
		thread_data[i].mlx_struct = *z_img;
		pthread_create(&(threads[i]), NULL, router, &thread_data[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
	free(thread_data);
}

void	*router(void *thread_data)
{
	t_thread	*data;
	t_image		*z_img;

	data = (t_thread*)thread_data;
	z_img = (t_image*)data->mlx_struct;
	if (!ft_strcmp("mandelbrot", z_img->title))
	{
		draw_mandelbrot(z_img, data->n);
	}
	else if (!ft_strcmp(z_img->title, "julia"))
	{
		draw_julia(z_img, data->n);
	}
	else if (!ft_strcmp(z_img->title, "ship"))
	{
		draw_ship(z_img, data->n);
	}
	return (NULL);
}

void	make_zoom_plus(t_image **z_img, int x, int y)
{
	double step;
	double first_part;
	double position_f;
	double ch_f_f;
	double ch_f_s;

	step = ((*z_img)->max_re - (*z_img)->min_re) / (*z_img)->width;
	first_part = (double)x / (*z_img)->width;
	position_f = (*z_img)->min_re + (double)x * step;
	ch_f_f = ((*z_img)->max_re - (*z_img)->min_re) / 2 * first_part;
	ch_f_s = ((*z_img)->max_re - (*z_img)->min_re) / 2 * (1 - first_part);
	(*z_img)->min_re = position_f - ch_f_f;
	(*z_img)->max_re = position_f + ch_f_s;
	step = ((*z_img)->max_im - (*z_img)->min_im) / (*z_img)->height;
	first_part = (double)y / (*z_img)->height;
	position_f = (*z_img)->max_im - (double)y * step;
	ch_f_f = ((*z_img)->max_im - (*z_img)->min_im) / 2 * first_part;
	ch_f_s = ((*z_img)->max_im - (*z_img)->min_im) / 2 * (1 - first_part);
	(*z_img)->max_im = position_f + ch_f_f;
	(*z_img)->min_im = position_f - ch_f_s;
}

void	make_zoom_minus(t_image **z_img, int x, int y)
{
	double step;
	double first_part;
	double position_f;
	double ch_f_f;
	double ch_f_s;

	step = ((*z_img)->max_re - (*z_img)->min_re) / (*z_img)->width;
	first_part = (double)x / (*z_img)->width;
	position_f = (*z_img)->min_re + (double)x * step;
	ch_f_f = ((*z_img)->max_re - (*z_img)->min_re) * 2 * first_part;
	ch_f_s = ((*z_img)->max_re - (*z_img)->min_re) * 2 * (1 - first_part);
	(*z_img)->min_re = position_f - ch_f_f;
	(*z_img)->max_re = position_f + ch_f_s;
	step = ((*z_img)->max_im - (*z_img)->min_im) / (*z_img)->height;
	first_part = (double)y / (*z_img)->height;
	position_f = (*z_img)->max_im - (double)y * step;
	ch_f_f = ((*z_img)->max_im - (*z_img)->min_im) * 2 * first_part;
	ch_f_s = ((*z_img)->max_im - (*z_img)->min_im) * 2 * (1 - first_part);
	(*z_img)->max_im = position_f + ch_f_f;
	(*z_img)->min_im = position_f - ch_f_s;
}

void	check_parameters(int argc, char **argv)
{
	if (argc != 2)
	{
		print_usage();
		exit(0);
	}
	else if (ft_strcmp(argv[1], "mandelbrot") &&
			ft_strcmp(argv[1], "julia") &&
			ft_strcmp(argv[1], "ship"))
	{
		print_usage();
		exit(0);
	}
}
