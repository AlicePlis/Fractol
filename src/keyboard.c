/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:16:57 by jsonja            #+#    #+#             */
/*   Updated: 2020/02/17 17:16:58 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			f_zoom(int button, int x, int y, t_fractl *list)
{
	float		shift;

	shift = 18;
	if (button == 5)
	{
		list->zoom *= 1.05;
		list->max_x *= 0.95;
		list->min_x *= 0.95;
		list->min_y *= 0.95;
		list->max_y *= 0.95;
		list->move_y += (y - HEIGHT / 2) * (list->max_y - list->min_y) / shift;
		list->move_x -= (x - WIDTH / 2) * (list->max_x - list->min_x) / shift;
	}
	if (button == 4)
	{
		list->zoom *= 0.95;
		list->max_x *= 1.1;
		list->min_x *= 1.1;
		list->min_y *= 1.1;
		list->max_y *= 1.1;
	}
	list->corrct_x = (list->max_x - list->min_x) / WIDTH;
	list->corrct_y = (list->max_y - list->min_y) / HEIGHT;
}

static void		move_zoom_key(int key, t_fractl *list)
{
	if (key == 36)
		default_settings(list);
	if (key == 49)
		list->julia_block = (list->julia_block) ? OFF : ON;
	if (key == 69)
		f_zoom(5, list->m->x0, list->m->y0, list);
	if (key == 78)
		f_zoom(4, list->m->x, list->m->y, list);
	if (key == 1)
		list->move_y -= (list->max_y - list->min_y) / 0.1;
	if (key == 13)
		list->move_y += (list->max_y - list->min_y) / 0.1;
	if (key == 0)
		list->move_x -= (list->max_x - list->min_x) / 0.1;
	if (key == 2)
		list->move_x += (list->max_x - list->min_x) / 0.1;
	get_thrd(list);
}

static void		set_key(int key, t_fractl *list)
{
	if (key == 67)
	{
		if (list->type == LEVY)
			list->len += (list->len == 30) ? 0 : 2;
		else
			list->iter += 1;
	}
	if (key == 75)
	{
		if (list->type == LEVY)
			list->len -= (list->len == 1) ? 0 : 2;
		else
			list->iter -= 1;
	}
	if (key == 82)
	{
		if (list->type == FLOWY || list->type == NEWTN)
			list->iter = 90;
		else if (list->type == LEVY)
			list->len = 0;
		else
			list->iter = 0;
	}
	get_thrd(list);
}

static void		color_key(int key, t_fractl *list)
{
	if (key == 34)
		list->info = (list->info) ? OFF : ON;
	if (key == 8)
	{
		if (list->color_mod == 1)
			list->color_mod = 2;
		else if (list->color_mod == 2)
			list->color_mod = 3;
		else if (list->color_mod == 3)
			list->color_mod = 1;
	}
	get_thrd(list);
}

int				opt_key(int key, t_fractl *list)
{
	if (key == 53)
		exit(0);
	if (key == 8 || key == 34)
		color_key(key, list);
	if (key == 67 || key == 75 || key == 82)
		set_key(key, list);
	if (key == 36 || key == 49 || key == 69 || key == 78 ||
	key == 13 || key == 1 || key == 0 || key == 2)
		move_zoom_key(key, list);
	return (0);
}
