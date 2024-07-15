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
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

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
	int		type;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
	double	sx;
	int		*palette;
	int		cindex;
	int		detail;
}	t_fractal;

void	print_instr1(void);
void	print_instr2(t_fractal *f);

void	init(t_fractal *f);
void	clean_exit(char *err_msg, t_fractal *f);

void	render(t_fractal *f);
void	reset(t_fractal *f);
void	set_palette(int **palette, int shift);

int		mouse_event(int keycode, int x, int y, t_fractal *mlx);
int		key_event(int keycode, t_fractal *mlx);

int		mandelbrot(t_fractal *f, double cr, double ci);
int		julia(t_fractal *f, double zr, double zi);
int		sierpinski(t_fractal *f, double cr, double ci);
/*

void	render(t_fractal *f);
int		julia_shift(int x, int y, t_fractal *f);


void	colour_shift(t_fractal *f);
void	set_colour_mono(t_fractal *f, int colour);
void	set_colour_multiple(t_fractal *f, int colours[4], int n);
void	set_colour_zebra(t_fractal *f, int colour);
void	set_colour_triad(t_fractal *f, int colour);
void	set_colour_tetra(t_fractal *f, int colour);
void	set_colour_opposites(t_fractal *f, int colour);
void	set_colour_contrasted(t_fractal *f, int colour);
void	set_colour_graphic(t_fractal *f, int colour);
int		get_percent_colour(int colour, double percent);


int		key_event(int keycode, t_fractal *mlx);
int		mouse_event(int keycode, int x, int y, t_fractal *mlx);


void	clean_init(t_fractal *f);
void	reinit_img(t_fractal *f);
void	init(t_fractal *f);
void	get_complex_layout(t_fractal *f);
void	get_colour(t_fractal *f, int ac, char **av);
double	ft_atof(char *str);


int		end_fractol(t_fractal *mlx);
void	clean_exit(int error_code, t_fractal *f);
int		msg(char *str1, char *str2, int errno);
void	help_msg(t_fractal *f);
void	print_controls(void);
*/
#endif
