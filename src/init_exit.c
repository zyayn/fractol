/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchia <zchia@42.sg>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:15:09 by zchia             #+#    #+#             */
/*   Updated: 2024/07/16 22:28:43 by zchia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_exit(char *err_msg, t_fractal *f)
{
	if (f->palette)
		free(f->palette);
	if (f->buf)
		f->buf = NULL;
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

void	set_palette(int **palette, int shift)
{
	int	i;
	int	palette_size;
	int	colours[7];

	colours[0] = 0xFF0000;
	colours[1] = 0xFF7F00;
	colours[2] = 0xFFFF00;
	colours[3] = 0x00FF00;
	colours[4] = 0x0000FF;
	colours[5] = 0x4B0082;
	colours[6] = 0x8B00FF;
	palette_size = 7;
	if (*palette)
		free(*palette);
	*palette = ft_calloc(palette_size, sizeof(int));
	i = 0;
	while (i < palette_size)
	{
		(*palette)[i] = colours[(i + shift) % palette_size];
		i++;
	}
}

void	init_values(t_fractal *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->buf = NULL;
	f->palette = NULL;
	f->cindex = 0;
	f->detail = 1;
	f->type = 0;
	f->min_r = -4.0;
	f->max_r = 4.0;
	f->min_i = -4.0;
	f->max_i = 4;
	f->kr = 0.0;
	f->ki = 0.0;
	f->sx = 1.5;
}

void	init(t_fractal *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	init_values(f);
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit("Error initialising mlx.", f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract'ol by zchia");
	if (!f->win)
		clean_exit("Error initialising window.", f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		clean_exit("Error creating image.", f);
	buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	if (!buf)
		clean_exit("Error getting image data address.", f);
	set_palette(&f->palette, f->cindex);
	if (!f->palette)
		clean_exit("Error initialising colour palette.", f);
	f->buf = buf;
}
