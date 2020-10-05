/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:37:49 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/13 12:37:50 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			rotate(t_fractl *list, float *x, float *y, int i)
{
	float	tmp_y;
	float	tmp_x;

	tmp_x = *x - WIDTH / 2;
	tmp_y = *y - HEIGHT / 2;
	*x = (cos(list->ang_y) * tmp_x + sin(list->ang_y)) + WIDTH / 2;
	*y = (cos(list->ang_x) * tmp_y - sin(list->ang_x)) + HEIGHT / 2;
	get_color_fern(i, list, (int)*x, (int)*y);
}

static void			fern(t_fractl *list, float x, float y, int i)
{
	static float	factor[20] = {0, 0, 0, 0.16, 0, 0.85, 0.04, -0.04, 0.85,
							1.6, 0.2, -0.26, 0.23, 0.22, 1.6, -0.15, 0.28, 0.26,
							0.24, 0.44};
	int				r;
	int				j;

	while (++i < 500000 + list->iter)
	{
		r = rand();
		if (r < RAND_MAX * 0.01)
			j = 0;
		else if (r < RAND_MAX * 0.85)
			j = 5;
		else if (r < 0.93 * RAND_MAX)
			j = 10;
		else
			j = 15;
		list->tmp_x = (factor[j] * x) + (factor[j + 1] * y);
		list->tmp_y = (factor[j + 2] * x) + (factor[j + 3] * y) + factor[j + 4];
		x = (WIDTH / 2 + list->tmp_x * list->zoom) + list->move_x;
		y = (HEIGHT / 2 - list->tmp_y * list->zoom) + list->move_y;
		rotate(list, &x, &y, i);
		x = list->tmp_x;
		y = list->tmp_y;
	}
}

static void			tree(t_fractl *list, double crd[2], int len, float ang)
{
	static float	inc_ang[4] = {0.7, -0.7, 0.35, -0.35};
	double			x[2];
	double			y[2];
	int				i;

	i = -1;
	x[START] = crd[X];
	y[START] = crd[Y];
	if (len > 1)
	{
		len *= 0.7;
		x[END] = (int)(x[START] + len * cos(ang) * list->zoom);
		y[END] = (int)(y[START] - len * sin(ang) * list->zoom);
		draw_line(list, x, y, color_tree(list, len));
		while (++i <= 3)
		{
			crd[X] = x[END];
			crd[Y] = y[END];
			tree(list, crd, len, ang + inc_ang[i] - list->ang_y);
		}
	}
}

static void			levy(t_fractl *list, double crd[2], double crd1[2], int len)
{
	static int		color[3] = {0xfa5acd, 0xffffff, 0x00ffaa};
	double			crd2[2];
	double			x[2];
	double			y[2];

	if (len <= 1)
	{
		x[START] = crd[X] + list->move_x;
		x[END] = crd1[X] + list->move_x;
		y[START] = HEIGHT - crd[Y] + list->move_y;
		y[END] = HEIGHT - crd1[Y] + list->move_y;
		draw_line(list, x, y, color[list->color_mod - 1]);
	}
	else
	{
		crd2[X] = (crd[X] + crd1[X]) / 2 - (crd1[Y] - crd[Y]) / 2;
		crd2[Y] = (crd[Y] + crd1[Y]) / 2 + (crd1[X] - crd[X]) / 2;
		levy(list, crd, crd2, len - 2);
		levy(list, crd2, crd1, len - 2);
	}
}

void				gr_fractol(t_fractl *list)
{
	double	crd[2];
	double	crd1[2];

	crd[X] = (list->type == LEVY) ? 300 : 500;
	crd[Y] = (list->type == LEVY) ? 400 : 700;
	crd1[X] = 600 + 100 * list->zoom;
	crd1[Y] = 400;
	if (list->type == FERN)
		fern(list, 0, 0, 0);
	if (list->type == TREE)
		tree(list, crd, 100, 1.57);
	if (list->type == LEVY)
		levy(list, crd, crd1, list->len);
}
