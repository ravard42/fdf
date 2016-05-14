/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 03:56:08 by ravard            #+#    #+#             */
/*   Updated: 2016/05/14 04:08:13 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			draw_spatial_system(t_env e)
{
	mlx_pixel_put(e.ptr, e.win, e.x_origin, e.y_origin, 0xFFFFFF);
	mlx_pixel_put(e.ptr, e.win, 42, 42, 0xFFFFFF);
	mlx_pixel_put(e.ptr, e.win, 42 + e.unity * cos(M_PI / 6),
			42 + e.unity * sin(M_PI / 6), 0xFF0000);
	mlx_pixel_put(e.ptr, e.win, 42 - e.unity * cos(M_PI / 6),
			42 + e.unity * sin(M_PI / 6), 0x00FF00);
	mlx_pixel_put(e.ptr, e.win, 42, 42 - e.unity, 0x0000FF);
}

static void			draw_line(t_env *e, float *first, float *second)
{
	char			abscisse;
	float			min[2];

	min[0] = (first[0] <= second[0]) ? first[0] - 1 : second[0] - 1;
	min[1] = (first[1] <= second[1]) ? first[1] - 1 : second[1] - 1;
	abscisse = (v_abs_diff(second[0], first[0]) >=
			v_abs_diff(second[1], first[1])) ? 'x' : 'y';
	if (abscisse == 'x')
		while (min[0]++ < first[0] || min[0] < second[0])
			mlx_pixel_put(e->ptr, e->win, min[0],
					(second[1] - first[1]) / (second[0] - first[0])
					* (min[0] - first[0]) + first[1], 0xFFFFFF);
	else if (abscisse == 'y')
		while (min[1]++ < first[1] || min[1] < second[1])
			mlx_pixel_put(e->ptr, e->win,
					(second[0] - first[0]) / (second[1] - first[1]) *
					(min[1] - first[1]) + first[0], min[1], 0xFF00FF);
}

static void			horizontal_draw(t_env e, int i)
{
	int		j;
	float	first[2];
	float	second[2];

	j = -1;
	while (++j < e.file_size[1] - 1)
	{
		first[0] = e.x_origin - e.unity * cos(M_PI / 6) * (i - j);
		first[1] = e.y_origin +
			e.unity * (sin(M_PI / 6) * (i + j) - e.tab[i][j]);
		second[0] = e.x_origin - e.unity * cos(M_PI / 6) * (i - j - 1);
		second[1] = e.y_origin +
			e.unity * (sin(M_PI / 6) * (i + j + 1) - e.tab[i][j + 1]);
		draw_line(&e, first, second);
	}
}

static void			vertical_draw(t_env e, int j)
{
	int		i;
	float	first[2];
	float	second[2];

	i = -1;
	while (++i < e.file_size[0] - 1)
	{
		first[0] = e.x_origin - e.unity * cos(M_PI / 6) * (i - j);
		first[1] = e.y_origin +
			e.unity * (sin(M_PI / 6) * (i + j) - e.tab[i][j]);
		second[0] = e.x_origin - e.unity * cos(M_PI / 6) * (i + 1 - j);
		second[1] = e.y_origin +
			e.unity * (sin(M_PI / 6) * (i + j + 1) - e.tab[i + 1][j]);
		draw_line(&e, first, second);
	}
}

void				draw(t_env e)
{
	int	i;
	int	j;

	draw_spatial_system(e);
	i = -1;
	while (++i < e.file_size[0])
		horizontal_draw(e, i);
	j = -1;
	while (++j < e.file_size[1])
		vertical_draw(e, j);
}
