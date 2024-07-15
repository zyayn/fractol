/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchia <zchia@42.sg>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 23:52:34 by zchia             #+#    #+#             */
/*   Updated: 2024/07/15 23:52:34 by zchia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractal *f, double zoom)
{
	double	centre_r;
	double	centre_i;
	double	range_r;
	double	range_i;

	centre_r = (f->max_r + f->min_r) / 2;
	centre_i = (f->max_i + f->min_i) / 2;
	range_r = (f->max_r - f->min_r) * zoom / 2;
	range_i = (f->max_i - f->min_i) * zoom / 2;
	f->min_r = centre_r - range_r;
	f->max_r = centre_r + range_r;
	f->min_i = centre_i - range_i;
	f->max_i = centre_i + range_i;
}

static void	move(t_fractal *f, double distance, char direction)
{
	double	centre_r;
	double	centre_i;

	centre_r = f->max_r - f->min_r;
	centre_i = f->max_i - f->min_i;
	if (direction == '<')
	{
		f->min_r -= centre_r * distance;
		f->max_r -= centre_r * distance;
	}
	else if (direction == '>')
	{
		f->min_r += centre_r * distance;
		f->max_r += centre_r * distance;
	}
	else if (direction == '^')
	{
		f->min_i += centre_i * distance;
		f->max_i += centre_i * distance;
	}
	else if (direction == 'v')
	{
		f->min_i -= centre_i * distance;
		f->max_i -= centre_i * distance;
	}
}

int	mouse_event(int keycode, int x, int y, t_fractal *mlx)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(mlx, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(mlx, (double)x * -1 / WIDTH, '<');
		else if (x > 0)
			move(mlx, (double)x / WIDTH, '>');
		if (y < 0)
			move(mlx, (double)y * -1 / HEIGHT, '^');
		else if (y > 0)
			move (mlx, (double)y / HEIGHT, 'v');
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(mlx, 2);
	else
		return (0);
	render(mlx);
	return (1);
}

int	key_event(int keycode, t_fractal *mlx)
{
	if (keycode == KEY_ESC)
		clean_exit("Exit fract'ol...", mlx);
	else if (keycode == KEY_PLUS || keycode == KEY_I)
		zoom(mlx, 0.5);
	else if (keycode == KEY_MINUS || keycode == KEY_O)
		zoom(mlx, 2);
	else if (keycode == KEY_UP || keycode == KEY_W)
		move(mlx, 0.2, '^');
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		move(mlx, 0.2, 'v');
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		move(mlx, 0.2, '<');
	else if (keycode == KEY_RIGHT || keycode == KEY_D)
		move(mlx, 0.2, '>');
	else if (keycode == KEY_R)
		reset(mlx);
	else if (keycode == KEY_M)
		mlx->detail += 1;
	else if (keycode == KEY_L)
	{
		if (mlx->detail > 1)
			mlx->detail -= 1;
	}
	else if (keycode == KEY_C)
	{
		mlx->cindex = (mlx->cindex + 1) % 7;
		set_palette(&mlx->palette, mlx->cindex);
	}
	render(mlx);
	return (1);
}
