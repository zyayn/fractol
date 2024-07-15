/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchia <zchia@42.sg>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:06:43 by zchia             #+#    #+#             */
/*   Updated: 2024/07/15 17:06:43 by zchia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_header(void)
{
	ft_printf("  ====================================\n");
	ft_printf("  ____ ____ ____ ____ ___ . ____ _    \n");
	ft_printf("  |___ |__/ |__| |     |  ' |  | |    \n");
	ft_printf("  |    |  | |  | |___  |    |__| |___ \n");
	ft_printf("  ___  _   _    ___  ____ _  _ _ ____ \n");
	ft_printf("  |__]  |_/       /  |    |__| | |__| \n");
	ft_printf("  |__]   |       /__ |___ |  | | |  | \n");
}

void	print_instr2(t_fractal *f)
{
	print_header();
	ft_printf("  ============Instructions============\n\n");
	ft_printf("  Use only the following commands to generate fractal:\n");
	ft_printf("  (arguement 1 is not case sensitive)\n\n");
	ft_printf("  Mandatory:\n");
	ft_printf("    ./fractol julia -0.7 0.27015\n");
	ft_printf("    ./fractol julia 0.355 0.355\n");
	ft_printf("    ./fractol julia -0.123 0.745\n");
	ft_printf("    ./fractol julia -0.835 -0.2321\n");
	ft_printf("    ./fractol julia -0.39054 -0.58679\n");
	ft_printf("    ./fractol mandeblot\n\n");
	ft_printf("  Bonus:\n");
	ft_printf("    ./fractol sierpinski\n\n");
	if (!f)
		clean_exit("Try again...", f);
}

void	print_instr1(void)
{
	print_header();
	ft_printf("  ============Instructions============\n\n");
	ft_printf("  Movement:\n");
	ft_printf("    - Use arrow keys or key W A S D to navigate\n\n");
	ft_printf("  Zoom:\n");
	ft_printf("    - Use mouse scroll or key I/+ and O/- to zoom in/out\n\n");
	ft_printf("  Colour Adjustments:\n");
	ft_printf("    - Use key C to cycle through color schemes\n\n");
	ft_printf("  Other Controls:\n");
	ft_printf("    - Use key M to increase detail level\n");
	ft_printf("    - Key Esc to exit the program\n\n");
}
