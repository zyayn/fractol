/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchia <zchia@42.sg>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 00:07:11 by zchia             #+#    #+#             */
/*   Updated: 2024/07/16 00:07:11 by zchia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_pixel_colour(t_fractal *f, int x, int y, int colour)
{
	f->buf[x * 4 + y * WIDTH * 4] = colour;
	f->buf[x * 4 + y * WIDTH * 4 + 1] = colour >> 8;
	f->buf[x * 4 + y * WIDTH * 4 + 2] = colour >> 16;
	f->buf[x * 4 + y * WIDTH * 4 + 3] = colour >> 24;
}

int	get_iter(t_fractal *f, double pr, double pi)
{
	int	iter;

	iter = 0;
	if (f->type == 1)
		iter = julia(f, pr, pi);
	else if (f->type == 2)
		iter = mandelbrot(f, pr, pi);
	else if (f->type == 3)
		iter = sierpinski(f, pr, pi);
	return (iter);
}

void	render(t_fractal *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;
	int		iter;

	mlx_clear_window(f->mlx, f->win);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->max_i + (double)y * (f->min_i - f->max_i) / HEIGHT;
			iter = get_iter(f, pr, pi);
			set_pixel_colour(f, x, y, f->palette[iter % 7]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_string_put(f->mlx, f->win, 20, 20, 0x000000, "Fract'ol by zchia");
}

void	reset(t_fractal *f)
{
	f->cindex = 0;
	f->detail = 1;
	f->min_r = -4.0;
	f->max_r = 4.0;
	f->min_i = -4.0;
	f->max_i = 4.0;
	f->sx = 1.5;
}
