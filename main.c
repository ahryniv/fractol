/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahryniv <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 19:43:28 by ahryniv           #+#    #+#             */
/*   Updated: 2018/06/04 19:43:34 by ahryniv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_fract.h"

void	free_structure(t_image **z_img)
{
	int i;

	free((*z_img)->title);
	i = 0;
	while (i < 16)
	{
		free((*z_img)->colors[i]);
		i++;
	}
	free(*z_img);
}

int		main(int argc, char *argv[])
{
	t_image	*z_img;

	check_parameters(argc, argv);
	fill_structure(&z_img, argv[1]);
	draw_fractal(&z_img);
	mlx_put_image_to_window(z_img->mlx, z_img->win, z_img->img, 0, 0);
	mlx_key_hook(z_img->win, what_key, &z_img);
	mlx_mouse_hook(z_img->win, mouse_cather, &z_img);
	mlx_hook(z_img->win, 6, (1L << 6), mouse_move, &z_img);
	mlx_loop(z_img->mlx);
	free_structure(&z_img);
	return (0);
}
