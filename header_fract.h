/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_fract.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 20:55:28 by ahryniv           #+#    #+#             */
/*   Updated: 2018/06/04 20:58:07 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_HEADER_FRACT_H
# define FRACT_OL_HEADER_FRACT_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "libft/libft.h"
# include <pthread.h>
# include <math.h>

typedef struct	s_image
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*title;
	int			b_p_p;
	int			s_l;
	int			en;
	char		*image;
	int			width;
	int			height;
	int			depth;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		re_factor;
	double		im_factor;
	int			*colors[16];
	int			p_for_thread;
	double		c_im;
	double		c_re;
	int			change_julia;
	int			color_kof;
	int			colors_k;
}				t_image;

typedef struct	s_thread
{
	int			n;
	void		*mlx_struct;
}				t_thread;

void			free_structure(t_image **z_img);
int				*set_color(int red, int green, int blue);
void			set_colors(t_image **z_img);
void			fill_structure(t_image **z_img, char *title);
void			print_usage(void);
void			draw_fractal(t_image **z_img);
void			*router(void *thread_data);
void			make_zoom_plus(t_image **z_img, int x, int y);
void			make_zoom_minus(t_image **z_img, int x, int y);
void			check_parameters(int argc, char **argv);
void			what_key_colors(int keycode, t_image **z_img);
void			what_key_move(int keycode, t_image **z_img);
int				what_key(int keycode, t_image **z_img);
int				mouse_cather(int button, int x, int y, t_image **z_img);
int				mouse_move(int x, int y, t_image **z_img);
void			put_pixel(t_image **z_img, int x, int y, int n);
void			make_magic(t_image **z_img, int x, int y, double c_im);
void			draw_mandelbrot(t_image *z_img, int n);
void			make_magic_julia(t_image **z_img, int x, int y, double c_im);
void			draw_julia(t_image *z_img, int n);
void			put_pixel_ship(t_image **z_img, int x, int y, int n);
void			make_magic_ship(t_image **z_img, int x, int y, double c_im);
void			draw_ship(t_image *z_img, int n);

#endif
