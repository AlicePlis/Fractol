/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:16:57 by jsonja            #+#    #+#             */
/*   Updated: 2020/02/17 17:16:58 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		mouse_press(int button, int x, int y, t_fractl *list)
{
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		if (button == 1 && x <= 965 && x >= 905)
			button_on(y, list);
		if (button == 2)
		{
			list->m->button2 = ON;
			list->m->x0 = x;
			list->m->y0 = y;
		}
		if (button == 5 || button == 4)
		{
			f_zoom(button, x, y, list);
			get_thrd(list);
		}
	}
	return (0);
}

static int		mouse_release(int button, int x, int y, t_fractl *list)
{
	(void)x;
	(void)y;
	if (button == 1)
		list->m->button1 = OFF;
	if (button == 2)
		list->m->button2 = OFF;
	return (0);
}

static int		mouse_move(int x, int y, t_fractl *list)
{
	if (x <= WIDTH && x >= 0 && y <= HEIGHT && y >= 0)
	{
		if (list->type == JULIA && list->julia_block == OFF)
		{
			list->tmp_x = ((double)x - list->corrct_x) / WIDTH * 1.5;
			list->tmp_y = ((double)y - list->corrct_y) / HEIGHT * 1.5;
			get_thrd(list);
		}
		list->m->x = x - list->m->x0;
		list->m->y = y - list->m->y0;
		list->m->x0 = x;
		list->m->y0 = y;
		if (list->m->button2 == ON)
		{
			list->move_x += (list->m->x * 4) / list->zoom;
			list->move_y -= (list->m->y * 4) / list->zoom;
			get_thrd(list);
		}
	}
	return (0);
}

static int		f_close(t_fractl *list)
{
	(void)list;
	exit(0);
}

void			mouse_hook(t_fractl *list)
{
	if (list->type == FERN || list->type == TREE || list->type == LEVY)
		mouse_hook_gr(list);
	else
	{
		mlx_hook(list->win, 4, 0, mouse_press, list);
		mlx_hook(list->win, 5, 0, mouse_release, list);
		mlx_hook(list->win, 6, 0, mouse_move, list);
		mlx_hook(list->win, 17, 0, f_close, list);
	}
}
