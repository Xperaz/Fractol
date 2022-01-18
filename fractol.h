/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:09:28 by aouhadou          #+#    #+#             */
/*   Updated: 2022/01/15 13:10:48 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define ITERATION	40
# define MINX -2
# define  MINY -2
# define MAXX 2
# define MAXY 2
# define SIZEX 600
# define SIZEY 600
# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	double	ymin;
	double	xmax;
	double	ymax;
	double	juliax;
	double	xmin;
	double	juliay;
	int		max_it;
	int		loopx;
	int		loopy;
	int		color;
	int		fractol;
	char	kernel;
	t_img	*img;
}	t_data;

void	render(t_data *mlx, int flag);
int		init(t_data *mlx);
int		render_mandelbrot(void);
int		mandelbrot(t_data *mlx);
int		mandelbrot_set(double row, double col, t_data *mlx);
int		render_julia(void);
int		julia(t_data *mlx);
int		julia_set(double x, double y, t_data *mlx);
int		render_burning(void);
int		burning(t_data *mlx);
int		burning_set(double x, double y, t_data *mlx);
int		keys(int keycode, t_data *vars);
int		zoom(int keycode, int x, int y, t_data *mlx);
int		ft_strcmp(char *s1, char *s2);
int		ft_exit(void);
void	img_pix_put(t_data *mlx, int x, int y, int color);

#endif
