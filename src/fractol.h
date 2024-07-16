/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchia <zchia@42.sg>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:21:43 by zchia             #+#    #+#             */
/*   Updated: 2024/07/07 01:21:43 by zchia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define EVENT_CLOSE_BTN 17
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_I 105
# define KEY_O 111
# define KEY_C 99
# define KEY_R 114
# define KEY_L 108
# define KEY_M 109
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_SPACE 32
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

# define WIDTH 1000
# define HEIGHT 1000
# define ITERATIONS 50

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		*palette;
	int		cindex;
	int		detail;
	int		type;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	sx;
}	t_fractal;

void	print_instr1(void);
void	print_instr2(t_fractal *f);

void	init(t_fractal *f);
void	set_palette(int **palette, int shift);
void	clean_exit(char *err_msg, t_fractal *f);

void	render(t_fractal *f);
void	reset(t_fractal *f);

int		mouse_event(int keycode, int x, int y, t_fractal *f);
int		key_event(int keycode, t_fractal *f);

int		mandelbrot(t_fractal *f, double cr, double ci);
int		julia(t_fractal *f, double zr, double zi);
int		sierpinski(t_fractal *f, double cr, double ci);

#endif
