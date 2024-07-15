/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchia <zchia@42.sg>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 01:20:08 by zchia             #+#    #+#             */
/*   Updated: 2024/07/07 01:20:08 by zchia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	end_fractol(t_fractal *mlx)
{
	clean_exit("Exit fract'ol...", mlx);
	return (0);
}

void	handle_events(t_fractal *f)
{
	mlx_hook(f->win, EVENT_CLOSE_BTN, 0, end_fractol, f);
	mlx_key_hook(f->win, key_event, f);
	mlx_mouse_hook(f->win, mouse_event, f);
	mlx_loop(f->mlx);
}

static void	handle_input(int argc, char **argv, t_fractal *f)
{
	if (!ft_strncmp(argv[1], "julia", 5))
	{
		if (argc != 4)
			print_instr2(f);
		else if (argc == 4 && (!ft_isdouble(argv[2]) || !ft_isdouble(argv[3])))
			print_instr2(f);
		else
		{
			f->kr = ft_atod(argv[2]);
			f->ki = ft_atod(argv[3]);
			f->type = 1;
		}
		if (f->kr > 2.0 || f->kr < -2.0 || f->ki >= 2.0 || f->ki <= -2.0)
			print_instr2(f);
	}
	else if (argc == 2 && !ft_strncmp(argv[1], "mandeblot", 9))
		f->type = 2;
	else if (argc == 2 && !ft_strncmp(argv[1], "sierpinski", 10))
		f->type = 3;
	else
		print_instr2(f);
}

int	main(int argc, char **argv)
{
	t_fractal	f;
	int			i;

	if (argc < 2 || !argv[1])
		print_instr2(&f);
	else
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				argv[1][i] = argv[1][i] + 32;
			i++;
		}
		init(&f);
		handle_input(argc, argv, &f);
		render(&f);
		print_instr1();
		argv[1][0] = ft_toupper(argv[1][0]);
		ft_printf("%s generated!\n", argv[1]);
		handle_events(&f);
	}
	return (0);
}
