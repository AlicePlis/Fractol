/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:37:49 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/13 12:37:50 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		draw_r_angle(int x0, int y0, int r, t_fractl *list)
{
	float		x;
	float		y;
	float		p;
	static int	sign[8] = {1, 1, -1, 1, 1, -1, -1, -1};
	int			i;

	i = -1;
	while (++i < 6)
	{
		p = 10;
		while (p <= 90)
		{
			x = x0 + r * pow(sin(p * 3.14 / 180), 0.3) * sign[i];
			y = y0 + 15 * pow(cos(p * 3.14 / 180), 0.5) * sign[i + 1];
			mlx_pixel_put(list->mlx, list->win, (int)x, (int)y, list->type);
			p += 0.5;
		}
	}
}

void			button_on(int y, t_fractl *list)
{
	if (y <= 34 && y >= 5)
		init_structure(list, MAND);
	if (y <= 69 && y >= 40)
		init_structure(list, JULIA);
	if (y <= 104 && y >= 75)
		init_structure(list, SPIDR);
	if (y <= 139 && y >= 110)
		init_structure(list, NEWTN);
	if (y <= 174 && y >= 145)
		init_structure(list, FLOWY);
	if (y <= 209 && y >= 180)
		init_structure(list, FERN);
	if (y <= 244 && y >= 215)
		init_structure(list, TREE);
	if (y <= 279 && y >= 250)
		init_structure(list, LEVY);
}

static void		draw_button(t_fractl *list)
{
	if (list->type == MAND)
		draw_r_angle(937, 20, 60, list);
	if (list->type == JULIA)
		draw_r_angle(937, 55, 60, list);
	if (list->type == SPIDR)
		draw_r_angle(937, 90, 60, list);
	if (list->type == NEWTN)
		draw_r_angle(937, 125, 60, list);
	if (list->type == FLOWY)
		draw_r_angle(937, 160, 60, list);
	if (list->type == FERN)
		draw_r_angle(937, 195, 60, list);
	if (list->type == TREE)
		draw_r_angle(937, 230, 60, list);
	if (list->type == LEVY)
		draw_r_angle(937, 265, 60, list);
}

static void		info_menu(t_fractl *list, int color, int color2, int color3)
{
	mlx_string_put(list->mlx, list->win, 32, 36, color2, "Move          wasd");
	mlx_string_put(list->mlx, list->win, 32, 56, color2, "Zoom in/out   +|-");
	mlx_string_put(list->mlx, list->win, 32, 76, color2, "Change color  c");
	mlx_string_put(list->mlx, list->win, 32, 96, color2, "Block Julia   Space");
	mlx_string_put(list->mlx, list->win, 32, 116, color2, "Iteration     *|/");
	mlx_string_put(list->mlx, list->win, 30, 136, color2,
			"Reset         Enter");
	mlx_string_put(list->mlx, list->win, 32, 156, color2, "Exit          Esc");
	mlx_string_put(list->mlx, list->win, 32, 176, color2, "Hide menu     i");
	mlx_string_put(list->mlx, list->win, 90, 10, color, "Control");
	mlx_string_put(list->mlx, list->win, 30, 35, color, "Move          wasd");
	mlx_string_put(list->mlx, list->win, 30, 55, color, "Zoom in/out   +|-");
	mlx_string_put(list->mlx, list->win, 30, 75, color, "Change color  c");
	mlx_string_put(list->mlx, list->win, 30, 95, color, "Block Julia   Space");
	mlx_string_put(list->mlx, list->win, 30, 115, color, "Iteration     *|/");
	mlx_string_put(list->mlx, list->win, 30, 135, color,
			"Reset         Enter");
	mlx_string_put(list->mlx, list->win, 30, 155, color, "Exit          Esc");
	mlx_string_put(list->mlx, list->win, 30, 175, color, "Hide menu     i");
	if (list->type == TREE || list->type == LEVY || list->type == FERN)
	{
		mlx_string_put(list->mlx, list->win, 30, 205, color3, "*Few commands");
		mlx_string_put(list->mlx, list->win, 160, 205, color3, " may not");
		mlx_string_put(list->mlx, list->win, 30, 219, color3, "work correctly");
	}
}

void			menu(t_fractl *list)
{
	if (list->info)
		info_menu(list, list->type, 0x222222, list->type / 1.5);
	else
		mlx_string_put(list->mlx, list->win, 10, 10, list->type,
				"|i| for Control information");
	draw_button(list);
	mlx_string_put(list->mlx, list->win, 887, 10, 0x004444, "Mandelbrot");
	mlx_string_put(list->mlx, list->win, 885, 8, MAND, "Mandelbrot");
	mlx_string_put(list->mlx, list->win, 910, 45, 0x442200, "Julia");
	mlx_string_put(list->mlx, list->win, 908, 43, JULIA, "Julia");
	mlx_string_put(list->mlx, list->win, 908, 80, 0x444400, "Spider");
	mlx_string_put(list->mlx, list->win, 906, 78, SPIDR, "Spider");
	mlx_string_put(list->mlx, list->win, 908, 115, 0x004433, "Newton");
	mlx_string_put(list->mlx, list->win, 906, 113, NEWTN, "Newton");
	mlx_string_put(list->mlx, list->win, 908, 150, 0x330011, "Flowey");
	mlx_string_put(list->mlx, list->win, 906, 148, FLOWY, "Flowey");
	mlx_string_put(list->mlx, list->win, 920, 185, 0x114411, "Fern");
	mlx_string_put(list->mlx, list->win, 918, 183, FERN, "Fern");
	mlx_string_put(list->mlx, list->win, 920, 220, 0x003300, "Tree");
	mlx_string_put(list->mlx, list->win, 918, 218, TREE, "Tree");
	mlx_string_put(list->mlx, list->win, 920, 255, 0x330000, "Levy");
	mlx_string_put(list->mlx, list->win, 918, 253, LEVY, "Levy");
}
