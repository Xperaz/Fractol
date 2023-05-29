/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:31:09 by aouhadou          #+#    #+#             */
/*   Updated: 2022/01/15 12:32:49 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"


void move(int keycode, t_data *mlx)
{
	float dx;
	float dy;

	dx = (mlx->xmax - mlx->xmin);
	dy = (mlx->ymax - mlx->ymin);
	if (keycode == 53)
		exit(0);
	if (keycode == 123 || keycode == 124)
	{
		if (keycode == 124)
			dx *= -1;
		mlx->xmin += dx / 5;
		mlx->xmax += dx / 5;
	}
	if (keycode == 126 || keycode == 125)
	{
		if (keycode == 126)
			dy *= -1;
		mlx->ymin += dy / 5;
		mlx->ymax += dy / 5;
	}
}

int keys(int keycode, t_data *mlx)
{
	if (keycode == 53 || keycode == 123 || keycode == 124 || keycode == 126 || keycode == 125)
		move(keycode, mlx);
	if (keycode == 8)
		mlx->color += 0x0d0d0d;
	if (keycode == 1)
		mlx->juliay += 0.2;
	if (keycode == 13)
		mlx->juliay -= 0.2;
	if (keycode == 0)
		mlx->juliax -= 0.2;
	if (keycode == 2)
		mlx->juliax += 0.2;
	render(mlx, 1);
	return (0);
}
