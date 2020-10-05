/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:34:16 by jsonja            #+#    #+#             */
/*   Updated: 2020/02/12 18:21:40 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		default_settings(t_fractl *list)
{
	list->julia_block = OFF;
	list->move_x = (list->type == MAND) ? 400 : 0;
	list->move_y = (list->type == FERN) ? 200 : 0;
	list->iter = 150;
	list->color_mod = 3;
	list->max_x = 2.0;
	list->min_x = -2.0;
	list->min_y = -1.5;
	list->max_y = 1.5;
	list->corrct_x = (list->max_x - list->min_x) / WIDTH;
	list->corrct_y = (list->max_y - list->min_y) / HEIGHT;
	list->tmp_x = (300 - list->corrct_x) / WIDTH;
	list->tmp_y = (475 - list->corrct_y) / HEIGHT;
	list->zoom = (list->type == FERN) ? 50 : 1.0;
	list->info = OFF;
	list->ang_x = 0;
	list->ang_y = 0;
	list->len = 30;
}

void		draw(t_fractl *list)
{
	int		x;
	int		y;
	int		*img;

	img = (int*)list->data_ptr;
	y = list->y - 1;
	while (++y < list->y_end)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (list->type == MAND)
				mandelbrot(list, x, y);
			if (list->type == JULIA)
				julia(list, x, y);
			if (list->type == NEWTN)
				newton(list, x, y);
			if (list->type == SPIDR)
				spider(list, x, y);
			if (list->type == FLOWY)
				flowey(list, x, y);
		}
	}
}

void		get_thrd(t_fractl *list)
{
	pthread_t	threads[10];
	t_fractl	fractl[10];
	int			i;

	i = -1;
	mlx_clear_window(list->mlx, list->win);
	ft_bzero(list->data_ptr, WIDTH * HEIGHT * 4);
	if (list->type == FERN || list->type == TREE || list->type == LEVY)
		gr_fractol(list);
	else
	{
		while (++i < 10)
		{
			fractl[i] = *list;
			fractl[i].y = i * (HEIGHT / 10);
			fractl[i].y_end = (i + 1) * (HEIGHT / 10);
			pthread_create(&threads[i], NULL, (void*(*)(void*))draw,
					(void*)&fractl[i]);
		}
		while (--i >= 0)
			pthread_join(threads[i], NULL);
	}
	mlx_put_image_to_window(list->mlx, list->win, list->img_ptr, 0, 0);
	menu(list);
}

void		init_structure(t_fractl *list, int type)
{
	list->type = type;
	default_settings(list);
	menu(list);
	get_thrd(list);
	mlx_key_hook(list->win, opt_key, list);
	mouse_hook(list);
	mlx_loop(list->mlx);
}
