/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 03:27:56 by ravard            #+#    #+#             */
/*   Updated: 2016/05/14 15:59:13 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		init_env(t_env *e, int *file_size, int **tab)
{
	e->x_origin = LENGHT / 2;
	e->y_origin = WIDTH / 2;
	if ((e->ptr = mlx_init()) == NULL)
		return (-1);
	if ((e->win = mlx_new_window(e->ptr, LENGHT, WIDTH, "42")) == NULL)
		return (-1);
	e->unity = UNITY;
	e->file_size = file_size;
	e->tab = tab;
	return (0);
}

void	m_a_j_env(t_env *e, int x, int y, int keycode)
{
	e->x_origin = x;
	e->y_origin = y;
	if (keycode == 123)
		trigo_rot(e);
	else if (keycode == 124)
		horaire_rot(e);
	else if (keycode == 126)
		e->unity = e->unity + 1;
	else if (keycode == 125)
		e->unity = e->unity - 1;
	else if (keycode == 53)
		exit(0);
}

void	print_env(t_env *e)
{
	ft_putstr("x_origin = ");
	ft_putnbr(e->x_origin);
	ft_putstr("\ny_origin = ");
	ft_putnbr(e->y_origin);
	ft_putstr("\nunity : ");
	ft_putnbr(e->unity);
	print_tab(e->tab, e->file_size);
}
