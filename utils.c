/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:11:50 by aouhadou          #+#    #+#             */
/*   Updated: 2022/01/15 13:21:37 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init(t_data *mlx)
{
	if (!mlx)
		return (0);
	mlx->img = malloc(sizeof(t_img));
	if (!mlx->img)
	{
		free(mlx->img);
		return (0);
	}
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, SIZEX, SIZEY, "Fract'ol");
	if (!(mlx->win))
	{
		free(mlx->win);
		return (0);
	}
	mlx->img->mlx_img = mlx_new_image(mlx, SIZEX, SIZEY);
	if (!mlx->img->mlx_img)
		return (0);
	mlx->img->addr = mlx_get_data_addr(mlx->img->mlx_img, &mlx->img->bpp,
			&mlx->img->line_len, &mlx->img->endian);
	if (!mlx->img->addr)
		return (0);
	return (1);
}

void	img_pix_put(t_data *mlx, int x, int y, int color)
{
	char	*pixel;

	pixel = mlx->img->addr + (y * mlx->img->line_len + x * (mlx->img->bpp / 8));
	*(int *)pixel = color;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' || s2[j] != '\0')
	{
		if (s1[i] > s2[j])
			return (s1[i] - s2[j]);
		else if (s1[i] < s2[j])
			return ((s1[i] - s2[j]));
		i++;
		j++;
	}
	return (0);
}

int	zoom(int keycode, int x, int y, t_data *mlx)
{
	float	fx;
	float	fy;

	fx = (mlx->xmax - mlx->xmin) / SIZEX;
	fy = (mlx->ymax - mlx->ymin) / SIZEY;
	if (keycode == 4)
	{
		mlx->max_it += 30;
		mlx->xmin = (mlx->xmin + ((fx * x) * 0.5));
		mlx->xmax = (mlx->xmax - ((fx * (SIZEX - x)) * 0.5));
		mlx->ymax = (mlx->ymax - ((fy * y) * 0.5));
		mlx->ymin = (mlx->ymin + ((fy * (SIZEY - y)) * 0.5));
	}
	if (keycode == 5)
	{
		mlx->xmin = (mlx->xmin - ((fx * x) * 0.5));
		mlx->xmax = (mlx->xmax + ((fx * (SIZEX - x)) * 0.5));
		mlx->ymax = (mlx->ymax + ((fy * y) * 0.5));
		mlx->ymin = (mlx->ymin - ((fy * (SIZEY - y)) * 0.5));
	}
	render(mlx, 1);
	return (0);
}

int	ft_exit(void)
{
	exit(1);
	return (0);
}
