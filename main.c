/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouhadou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:08:25 by aouhadou          #+#    #+#             */
/*   Updated: 2022/01/17 12:14:36 by aouhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_free(t_data *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_image(mlx->mlx, mlx->img->mlx_img);
	free(mlx->mlx);
	free(mlx->win);
	free(mlx->img);
}

void	ft_help(void)
{
	printf("---------- Fract'Ol HELP ---------\n");
	printf("use the mouse wheel to zoom in & out\n");
	printf("hey you can change the color using C\n");
	printf("to change the Julia Set use A/D/W/S\n");
	printf("use the arrows to move the image ← ↑ → ↓\n");
	printf("----------- SEE YOU!!---------\n");
}

void	ft_alert(int fract)
{
	if (fract > 2)
		printf("******    Make Sure You Only Use One parameter  *****\n");
	else
	{
		printf("******           invalid parameter         *****\n");
		printf("****** You Can Run Following Fractals      *****\n");
		printf("******              mandelbrot             *****\n");
		printf("******                julia                *****\n");
		printf("******              burningship            *****\n");
	}
}

void	render(t_data *mlx, int flag)
{
	if (mlx->fractol == 1)
	{
		if (flag)
			mandelbrot(mlx);
		else
			render_mandelbrot();
	}
	else if (mlx->fractol == 2)
	{
		if (flag)
			julia(mlx);
		else
			render_julia();
	}
	else if (mlx->fractol == 3)
	{
		if (flag)
			burning(mlx);
		else
			render_burning();
	}
}

int	main(int argc, char *argv[])
{
	t_data	mlx;

	if (argc == 2)
	{
		if (!ft_strcmp(argv[1], "mandelbrot"))
			mlx.fractol = 1;
		else if (!ft_strcmp(argv[1], "julia"))
			mlx.fractol = 2;
		else if (!ft_strcmp(argv[1], "burningship"))
			mlx.fractol = 3;
		else
		{
			ft_alert(argc);
			return (0);
		}
		ft_help();
		render((void *)&mlx, 0);
	}
	else
	{
		printf("******    You Need To Use One Parameter  *****\n");
		return (0);
	}
	ft_free((void *)&mlx);
}
