/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchia <zchia@42.sg>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:15:09 by zchia             #+#    #+#             */
/*   Updated: 2024/07/15 17:15:09 by zchia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_exit(char *err_msg, t_fractal *f)
{
	if (!f)
		exit(1);
	if (f->palette)
		free(f->palette);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win && f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	ft_printf("%s\n", err_msg);
	exit(1);
}

static void	init_img(t_fractal *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	if (f->mlx && f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->palette)
		free(f->palette);
	if (f->buf)
		f->buf = NULL;
	set_palette(&f->palette, f->cindex);
	if (!(f->palette))
		clean_exit("Error initialising colour scheme.", f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->img))
		clean_exit("Error creating image.", f);
	buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	f->buf = buf;
}

void	clean_init(t_fractal *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->buf = NULL;
	f->type = 0;
	f->min_r = -4.0;
	f->max_r = 4.0;
	f->min_i = -4.0;
	f->max_i = 4;
	f->kr = 0;
	f->ki = 0;
	f->sx = 1.5;
	f->palette = NULL;
	f->cindex = 0;
	f->detail = 1;
}

void	init(t_fractal *f)
{
	clean_init(f);
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit("MLX: error connecting to mlx.", f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract'ol by zchia");
	if (!f->win)
		clean_exit("MLX: error creating window.", f);
	init_img(f);
}
