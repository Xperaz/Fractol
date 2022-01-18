/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:37:55 by aouhadou          #+#    #+#             */
/*   Updated: 2022/01/15 13:05:42 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_set(double x, double y, t_data *mlx)
{
	int		i;
	double	xx;
	double	yy;
	double	temp;

	xx = x;
	yy = y;
	i = 1;
	while (i < ITERATION)
	{
		temp = xx;
		xx = ((xx * xx) - (yy * yy)) + 1 + mlx->juliax;
		yy = (2 * temp * yy) + 1 + mlx->juliay;
		if ((xx * xx) + (yy * yy) > 4)
		{
			img_pix_put(mlx, mlx->loopx, mlx->loopy,
				(mlx->color) + 0x0d0d0d * i);
			return (0);
		}
		i++;
	}
	img_pix_put(mlx, mlx->loopx, mlx->loopy, 0);
	return (0);
}

int	julia(t_data *mlx)
{
	double	x;
	double	y;

	mlx->loopx = 0;
	mlx->loopy = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (mlx->loopy < SIZEY)
	{
		while (mlx->loopx < SIZEX)
		{
			x = mlx->xmin + (mlx->loopx * ((mlx->xmax - mlx->xmin) / SIZEX));
			y = mlx->ymax - (mlx->loopy * ((mlx->ymax - mlx->ymin) / SIZEY));
			julia_set(x, y, mlx);
			mlx->loopx++;
		}
		mlx->loopy++;
		mlx->loopx = 0;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->mlx_img, 0, 0);
	return (0);
}

int	render_julia(void)
{
	t_data	*mlx;

	mlx = malloc(sizeof(t_data));
	init(mlx);
	mlx->xmin = MINX;
	mlx->xmax = MAXX;
	mlx->ymin = MINY;
	mlx->ymax = MAXY;
	mlx->color = 0;
	mlx->fractol = 2;
	mlx->max_it = 40;
	julia(mlx);
	mlx_key_hook(mlx->win, keys, mlx);
	mlx_hook(mlx->win, 17, 2, ft_exit, (void *)0);
	mlx_mouse_hook(mlx->win, zoom, mlx);
	mlx_string_put(mlx->mlx, mlx->win, 15, 10, 0xe74c3c,
		"Julia");
	mlx_string_put(mlx->mlx, mlx->win, 480, 550, 0xe74c3c,
		"By Aouhadou");
	mlx_loop(mlx->mlx);
	return (0);
}
