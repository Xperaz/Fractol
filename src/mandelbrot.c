/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:05:58 by aouhadou          #+#    #+#             */
/*   Updated: 2022/01/15 13:08:38 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


int mandelbrot_set(double x, double y, t_data *mlx)
{
	int i;
	double xx;
	double yy;
	double temp;

	xx = 0;
	yy = 0;
	i = 1;
	while (i < mlx->max_it)
	{
		temp = xx;
		xx = (xx * xx) - (yy * yy) + x;
		yy = (2 * temp * yy) + y;
		if ((xx * xx) + (yy * yy) > 4)
		{
			img_pix_put(mlx, mlx->loopx, mlx->loopy,
						(mlx->color) + 0x0d0d0d * i);
			return (0);
		}
		i++;
	}
	img_pix_put(mlx, mlx->loopx, mlx->loopy, 0x000000);
	return (0);
}

int mandelbrot(t_data *mlx)
{
	double x;
	double y;

	mlx->loopx = 0;
	mlx->loopy = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (mlx->loopy < SIZEY)
	{
		while (mlx->loopx < SIZEX)
		{
			x = mlx->xmin + (mlx->loopx * ((mlx->xmax - mlx->xmin) / SIZEX));
			y = mlx->ymax - (mlx->loopy * ((mlx->ymax - mlx->ymin) / SIZEY));
			mandelbrot_set(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->mlx_img, 0, 0);
	return (1);
}

int render_mandelbrot(void)
{
	t_data *mlx;

	mlx = malloc(sizeof(t_data));
	init(mlx);
	mlx->xmin = MINX;
	mlx->xmax = MAXX;
	mlx->ymin = MINY;
	mlx->ymax = MAXY;
	mlx->color = 0;
	mlx->fractol = 1;
	mlx->max_it = 40;
	mandelbrot(mlx);
	mlx_key_hook(mlx->win, keys, mlx);
	mlx_hook(mlx->win, 17, 2, ft_exit, (void *)0);
	mlx_mouse_hook(mlx->win, zoom, mlx);
	mlx_string_put(mlx->mlx, mlx->win, 15, 10, 0xe74c3c,
				   "Mandelbrot");
	mlx_string_put(mlx->mlx, mlx->win, 480, 550, 0xe74c3c,
				   "By Aouhadou");
	mlx_loop(mlx->mlx);
	return (0);
}
