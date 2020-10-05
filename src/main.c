/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:34:16 by jsonja            #+#    #+#             */
/*   Updated: 2020/02/12 18:21:40 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		init_mlx(t_fractl *list)
{
	if (!(list->mlx = mlx_init()))
		ft_exit("mlx_init ERROR");
	if (!(list->win = mlx_new_window(list->mlx, WIDTH, HEIGHT, "Fractol")))
		ft_exit("mlx_new_window ERROR");
	if (!(list->img_ptr = mlx_new_image(list->mlx, WIDTH, HEIGHT)))
		ft_exit("mlx_new_image ERROR");
	if (!(list->data_ptr = mlx_get_data_addr(list->img_ptr, &list->bpp,
			&list->sl, &list->end)))
		ft_exit("mlx_get_data_addr ERROR");
}

static int		check_arg(char *argv)
{
	if (!ft_strcmp(argv, "mandelbrot") || !ft_strcmp(argv, "1"))
		return (MAND);
	if (!ft_strcmp(argv, "julia") || !ft_strcmp(argv, "2"))
		return (JULIA);
	if (!ft_strcmp(argv, "spider") || !ft_strcmp(argv, "3"))
		return (SPIDR);
	if (!ft_strcmp(argv, "newton") || !ft_strcmp(argv, "4"))
		return (NEWTN);
	if (!ft_strcmp(argv, "flowey") || !ft_strcmp(argv, "5"))
		return (FLOWY);
	if (!ft_strcmp(argv, "fern") || !ft_strcmp(argv, "6"))
		return (FERN);
	if (!ft_strcmp(argv, "tree") || !ft_strcmp(argv, "7"))
		return (TREE);
	if (!ft_strcmp(argv, "levy") || !ft_strcmp(argv, "8"))
		return (LEVY);
	return (0);
}

int				main(int argc, char **argv)
{
	t_fractl *list;

	if (argc == 2)
	{
		if (!(list = (t_fractl*)malloc(sizeof(t_fractl))) ||
		!(list->m = (t_mouse*)malloc(sizeof(t_mouse))))
			ft_exit("malloc ERROR");
		list->type = check_arg(argv[1]);
		if (list->type)
		{
			init_mlx(list);
			init_structure(list, list->type);
			exit(0);
		}
	}
	ft_putstr("1 : mandelbrot\n2 : julia\n3 : spider\n4 : newton\n");
	ft_exit("5 : flowey\n6 : fern\n7 : tree\n8 : levy");
}
