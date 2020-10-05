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
	list->m->x0 = x;
	list->m->y0 = y;
	if (button == 1)
	{
		if (x <= 965 && x >= 905)
			button_on(y, list);
		if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
			list->m->button1 = ON;
	}
	if (button == 2)
		list->m->button2 = ON;
	if (button == 4 || button == 5)
	{
		list->zoom *= (button == 5) ? 1.1 : 0.9;
		get_thrd(list);
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
	if (list->m->button1 == ON)
	{
		list->m->x = x - list->m->x0;
		list->m->y = y - list->m->y0;
		list->m->x0 = x;
		list->m->y0 = y;
		if (list->m->button2 == ON)
		{
			list->move_x += list->m->x;
			list->move_y += list->m->y;
		}
		else
		{
			list->ang_y += list->m->x / (WIDTH / 2);
			if (list->ang_y >= 6.28319 || list->ang_y <= -6.28319)
				list->ang_y = 0;
			list->ang_x -= list->m->y / (HEIGHT / 2);
			if (list->ang_x >= 6.28319 || list->ang_x <= -6.28319)
				list->ang_x = 0;
		}
		get_thrd(list);
	}
	return (0);
}

static int		f_close(t_fractl *list)
{
	(void)list;
	exit(0);
}

void			mouse_hook_gr(t_fractl *list)
{
	t_mouse	*a;

	a = (t_mouse*)malloc(sizeof(t_mouse));
	list->m = a;
	mlx_hook(list->win, 4, 0, mouse_press, list);
	mlx_hook(list->win, 6, 0, mouse_move, list);
	mlx_hook(list->win, 5, 0, mouse_release, list);
	mlx_hook(list->win, 17, 0, f_close, list);
}
