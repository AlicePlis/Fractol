/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:37:49 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/13 12:37:50 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fractl *list, int x, int y)
{
	double	c[2];
	double	z[2];
	double	tmp;
	int		i;
	double	sn;

	i = -1;
	c[RE] = (list->min_x + x * list->corrct_x) - list->move_x / (WIDTH);
	c[IM] = (list->max_y - y * list->corrct_y) - list->move_y / (HEIGHT);
	z[RE] = c[RE];
	z[IM] = c[IM];
	while (++i < list->iter)
	{
		tmp = (z[RE] * z[RE] - z[IM] * z[IM]) + c[RE];
		z[IM] = 2.0 * z[RE] * z[IM] + c[IM];
		z[RE] = tmp;
		if (z[RE] * z[RE] + z[IM] * z[IM] > 16)
			break ;
	}
	if (i == list->iter)
		sn = 0;
	else
		sn = (double)i - log(log(z[RE] * z[RE] + z[IM] * z[IM])) / log(2) + 4.0;
	get_color(sn, list, x, y);
}

void	julia(t_fractl *list, int x, int y)
{
	double	c[2];
	double	z[2];
	double	tmp;
	double	sn;
	int		i;

	i = -1;
	c[RE] = list->tmp_x;
	c[IM] = list->tmp_y;
	z[RE] = (list->min_x + x * list->corrct_x) - list->move_x / (WIDTH);
	z[IM] = (list->max_y - y * list->corrct_y) - list->move_y / (HEIGHT);
	while (++i < list->iter)
	{
		tmp = (z[RE] * z[RE] - z[IM] * z[IM]) + c[RE];
		z[IM] = 2.0 * z[RE] * z[IM] + c[IM];
		z[RE] = tmp;
		if (z[RE] * z[RE] + z[IM] * z[IM] > 16)
			break ;
	}
	sn = (double)i - (log(log(z[RE] * z[RE] + z[IM] * z[IM])) / log(2)) + 4.0;
	get_color(sn, list, x, y);
}

void	newton(t_fractl *list, int x, int y)
{
	double	z[2];
	double	old_z[2];
	double	tmp;
	int		i;

	i = -1;
	z[RE] = ((list->min_x + x * list->corrct_x) - list->move_x / WIDTH);
	z[IM] = ((list->max_y - y * list->corrct_y) - list->move_y / HEIGHT);
	while (++i < list->iter - 90)
	{
		old_z[RE] = z[RE];
		old_z[IM] = z[IM];
		tmp = (z[RE] * z[RE] + z[IM] * z[IM]) * (z[RE] * z[RE] + z[IM] * z[IM]);
		z[RE] = (2.0 * z[RE] * tmp + (z[RE] * z[RE] - z[IM] * z[IM])) /
				(3 * tmp);
		z[IM] = (2.0 * z[IM] * (tmp - old_z[RE])) / (3 * tmp);
		if (((z[RE] - old_z[RE]) * (z[RE] - old_z[RE]) +
			(z[IM] - old_z[IM]) * (z[IM] - old_z[IM])) < 0.0001)
			break ;
	}
	if (list->color_mod == 2)
		get_color(i * 2, list, x, y);
	else
		get_color_newtn(i, list, x, y);
}

void	flowey(t_fractl *list, int x, int y)
{
	double	z[2];
	double	old_z[2];
	double	tmp;
	int		i;

	i = -1;
	z[RE] = ((list->min_x + x * list->corrct_x) - list->move_x / WIDTH);
	z[IM] = ((list->max_y - y * list->corrct_y) - list->move_y / HEIGHT);
	while (++i < list->iter - 90)
	{
		old_z[RE] = z[RE];
		old_z[IM] = z[IM];
		tmp = (z[RE] * z[RE] + z[IM] * z[IM]) * (z[RE] * z[RE] + z[IM] * z[IM]);
		z[RE] = (2.0 * z[RE] * tmp + (z[RE] * z[RE] - z[IM] * z[IM])) /
				(2 * tmp);
		z[IM] = (2.0 * z[IM] * (tmp - old_z[RE])) / (2 * tmp);
		if (((z[RE] - old_z[RE]) * (z[RE] - old_z[RE]) +
			(z[IM] - old_z[IM]) * (z[IM] - old_z[IM])) < 0.001)
			break ;
	}
	if (list->color_mod == 2)
		get_color(i * 2, list, x, y);
	else
		get_color_newtn(i, list, x, y);
}

void	spider(t_fractl *list, int x, int y)
{
	double	c[2];
	double	z[2];
	double	tmp;
	int		i;

	i = -1;
	c[RE] = (list->min_x + x * list->corrct_x) - list->move_x / (WIDTH);
	c[IM] = (list->max_y - y * list->corrct_y) - list->move_y / (HEIGHT);
	z[RE] = c[RE];
	z[IM] = c[IM];
	while (++i < list->iter)
	{
		tmp = (z[RE] * z[RE] - z[IM] * z[IM]) + c[RE];
		z[IM] = 2.0 * z[RE] * z[IM] + c[IM];
		z[RE] = (list->color_mod == 2) ? -tmp : tmp;
		c[RE] = c[RE] * 0.5 + z[RE];
		c[IM] = c[IM] * 0.5 + z[IM];
		if (z[RE] * z[RE] + z[IM] * z[IM] > 25)
			break ;
	}
	get_color(i, list, x, y);
}
