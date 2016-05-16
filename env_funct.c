/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 03:27:56 by ravard            #+#    #+#             */
/*   Updated: 2016/05/16 09:26:59 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			print_tab(int **tab, int *file_size)
{
	int	i;
	int	j;

	ft_putchar('\n');
	i = 0;
	while (i < file_size[0])
	{
		j = 0;
		while (j < file_size[1])
		{
			ft_putnbr(tab[i][j]);
			j++;
			if (j < file_size[1])
				ft_putchar(' ');
		}
		i++;
		ft_putchar('\n');
	}
	ft_putstr("\nNotre fichier contient ");
	ft_putnbr(i);
	ft_putstr(" lignes et ");
	ft_putnbr(j);
	ft_putstr(" colonnes\n");
}

int				init_env(t_env *e, int *file_size, int **tab)
{
	e->x_origin = LENGHT / 2;
	e->y_origin = WIDTH / 2;
	if ((e->ptr = mlx_init()) == NULL)
		return (-1);
	if ((e->win = mlx_new_window(e->ptr, LENGHT, WIDTH, "42")) == NULL)
		return (-1);
	e->unity = UNITY;
	e->color = 0xFFFFFF;
	e->file_size = file_size;
	e->tab = tab;
	return (0);
}

void			m_a_j_env(t_env *e, int x, int y, int keycode)
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
	else if (keycode == 15 && *((unsigned char *)&e->color + 2) != 0xFF)
		e->color += 0x3F0000;
	else if (keycode == 14 && *((unsigned char *)&e->color + 2) != 0x03)
		e->color -= 0x3F0000;
	else if (keycode == 5 && *((unsigned char *)&e->color + 1) != 0xFF)
		e->color += 0x003F00;
	else if (keycode == 3 && *((unsigned char *)&e->color + 1) != 0x03)
		e->color -= 0x003F00;
	else if (keycode == 11 && *((unsigned char *)&e->color) != 0xFF)
		e->color += 0x00003F;
	else if (keycode == 9 && *((unsigned char *)&e->color) != 0x03)
		e->color -= 0x00003F;
	else if (keycode == 53)
		exit(0);
}

static void		print_color_info(t_env *e, char decalage, char *color)
{
	if (*((unsigned char *)&e->color + decalage) == 0xFF)
	{
		ft_putstr(color);
		ft_putstr(" = 4/4\n");
	}
	else if (*((unsigned char *)&e->color + decalage) == 0xFF - 0x3F)
	{
		ft_putstr(color);
		ft_putstr(" = 3/4\n");
	}
	else if (*((unsigned char *)&e->color + decalage) == 0xFF - 0x3F * 2)
	{
		ft_putstr(color);
		ft_putstr(" = 2/4\n");
	}
	else if (*((unsigned char *)&e->color + decalage) == 0xFF - 0x3F * 3)
	{
		ft_putstr(color);
		ft_putstr(" = 1/4\n");
	}
	else if (*((unsigned char *)&e->color + decalage) == 0xFF - 0x3F * 4)
	{
		ft_putstr(color);
		ft_putstr(" = 0/4\n");
	}
}

void			print_env(t_env *e)
{
	ft_putstr("\n\n\n\n\n\n\n==================================ENV\
==================================\n\n");
	ft_putstr("x_origin = ");
	ft_putnbr(e->x_origin);
	ft_putstr("\ny_origin = ");
	ft_putnbr(e->y_origin);
	ft_putstr("\nunity = ");
	ft_putnbr(e->unity);
	ft_putchar('\n');
	print_color_info(e, 2, "red");
	print_color_info(e, 1, "green");
	print_color_info(e, 0, "blue");
	print_tab(e->tab, e->file_size);
	ft_putstr("\n\n=====================================\
==================================\n\n\n\n\n\n");
}
