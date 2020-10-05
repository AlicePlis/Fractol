/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsonja <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:34:52 by jsonja            #+#    #+#             */
/*   Updated: 2020/01/13 12:34:54 by jsonja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <pthread.h>
# define WIDTH 1000
# define HEIGHT 800
# define OFF 0
# define ON 1
# define MAND 0x00fffa
# define JULIA 0xff8800
# define SPIDR 0xffff00
# define NEWTN 0x22ff99
# define FLOWY 0xdd0099
# define FERN 0xaaff33
# define TREE 0x00ff00
# define LEVY 0xff0000
# define IM 1
# define RE 0
# define START 0
# define END 1
# define X 0
# define Y 1

typedef	struct	s_mouse
{
	int					x0;
	int					y0;
	float				x;
	float				y;
	float				button1;
	float				button2;
}				t_mouse;

typedef struct	s_fractl
{
	t_mouse				*m;
	double				tmp_x;
	double				tmp_y;
	double				corrct_x;
	double				corrct_y;
	double				max_x;
	double				min_x;
	double				max_y;
	double				min_y;
	double				move_x;
	double				move_y;
	double				zoom;
	void				*mlx;
	void				*win;
	void				*img_ptr;
	char				*data_ptr;
	int					bpp;
	int					sl;
	int					end;
	int					color_mod;
	int					type;
	int					iter;
	int					y;
	int					y_end;
	int					julia_block;
	int					info;
	int					len;
	float				ang_y;
	float				ang_x;
}				t_fractl;

void			init_structure(t_fractl *list, int type);
void			default_settings(t_fractl *list);
void			get_thrd(t_fractl *list);
void			draw(t_fractl *list);
void			menu(t_fractl *list);
void			button_on(int y, t_fractl *d);
void			mandelbrot(t_fractl *list, int x, int y);
void			julia(t_fractl *list, int x, int y);
void			newton(t_fractl *list, int x, int y);
void			flowey(t_fractl *list, int x, int y);
void			spider(t_fractl *list, int x, int y);
void			gr_fractol(t_fractl *list);
void			get_color(double i, t_fractl *list, int x, int y);
void			get_color_newtn(int i, t_fractl *list, int x, int y);
void			get_color_fern(int i, t_fractl *list, int x, int y);
int				color_tree(t_fractl *list, int len);
void			draw_line(t_fractl *list, double x[2], double y[2], int color);
int				opt_key(int key, t_fractl *list);
void			f_zoom(int button, int x, int y, t_fractl *list);
void			mouse_hook(t_fractl *data);
void			mouse_hook_gr(t_fractl *data);

#endif
