/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:37:49 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/13 12:37:50 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_line(t_fractl *list, double x[2], double y[2], int color)
{
	float	x_step;
	float	y_step;
	int		max;
	int		*img;

	img = (int*)list->data_ptr;
	x_step = x[END] - x[START];
	y_step = y[END] - y[START];
	max = ft_maxf(ft_absf(x_step), ft_absf(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x[START] - x[END]) || (int)(y[START] - y[END]))
	{
		if (x[START] > 0 && x[START] < WIDTH && y[START] > 0 &&
			y[START] < HEIGHT)
			*(img + (int)x[START] + (int)y[START] * WIDTH) = color;
		x[START] += x_step;
		y[START] += y_step;
	}
}

int			color_tree(t_fractl *list, int len)
{
	int		color;

	if (list->color_mod == 1)
		color = (len >= 20) ? 0xdeb887 : ((len * 16) << 16) + ((len * 150)
				<< 8) + (len * 100);
	if (list->color_mod == 2)
		color = (len >= 20) ? 0xffffff : ((len * 250) << 16) + ((len * 50)
				<< 8) + (len * 100);
	if (list->color_mod == 3)
		color = (len >= 20) ? 0x555555 : ((len * 15) << 16) + ((len * 45)
				<< 8) + (len * 28);
	return (color);
}

void		get_color_fern(int i, t_fractl *list, int x, int y)
{
	int			*img;
	int			index;
	static int	color[6] = {0xffaa00, 0x00ff00, 0x33ff33,
						0x6a5acd, 0x4682b4, 0x6495ed};

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		img = (int*)list->data_ptr;
		if (list->color_mod == 2)
			*(img + x + y * WIDTH) = 0xffffff;
		if (list->color_mod == 1 || list->color_mod == 3)
		{
			index = (list->color_mod == 1) ? 0 : 3;
			if (!*(img + x + y * WIDTH))
			{
				if (i <= 50000)
					*(img + x + y * WIDTH) = color[index];
				if (i > 50000 && i <= 300000)
					*(img + x + y * WIDTH) = color[index + 1];
				if (i > 300000)
					*(img + x + y * WIDTH) = color[index + 2];
			}
		}
	}
}

void		get_color_newtn(int i, t_fractl *list, int x, int y)
{
	double	t;
	int		*img;

	t = i / (double)list->iter;
	img = (int*)list->data_ptr;
	if (list->color_mod == 1)
		*(img + x + y * WIDTH) = ((i * 100 << 16) + (i * 50 << 8) + i * 80);
	if (list->color_mod == 2)
		*(img + x + y * WIDTH) = ((i * 150 << 16) + (i * 150 << 8) + i * 150);
	if (list->color_mod == 3)
		*(img + x + y * WIDTH) = t * (15.0 - t) * 0xFFFFFF;
}

void		get_color(double i, t_fractl *list, int x, int y)
{
	double	t;
	int		*img;
	int		color;

	t = i / (double)list->iter;
	img = (int*)list->data_ptr;
	if (list->color_mod == 1)
		*(img + x + y * WIDTH) = ((int)(i * 90) << 16) + ((int)(i * 50) << 8) +
				(int)(i * 80);
	if (list->color_mod == 2)
		*(img + x + y * WIDTH) = ((int)(i * 5) << 16) + ((int)(i * 5) << 8) +
				(int)(i * 5);
	if (list->color_mod == 3)
	{
		color = (int)(15 * (1 - t) * (1 - t) * t * t * 255) << 16;
		color |= (int)(9 * (1 - t) * t * t * t * 255) << 8;
		color |= (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		*(img + x + y * WIDTH) = color;
	}
}
