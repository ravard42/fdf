/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 03:42:28 by ravard            #+#    #+#             */
/*   Updated: 2016/05/16 01:19:51 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"

static int		is_fdf_file(char *s)
{
	char	*rev;

	rev = ft_revstr(s);
	rev[4] = '\0';
	if (!ft_strcmp("fdf.", rev))
		return (1);
	else
		return (0);
}

static int		expose_hook(t_env *param)
{
	print_env(param);
	draw(*param);
	return (0);
}

static int		key_hook(int keycode, t_env *param)
{
	m_a_j_env(param, param->x_origin, param->y_origin, keycode);
	mlx_clear_window(param->ptr, param->win);
	expose_hook(param);
	return (0);
}

static int		mouse_hook(int button, int j, int i, t_env *param)
{
	if (button)
		;
	m_a_j_env(param, j, i, param->unity);
	mlx_clear_window(param->ptr, param->win);
	expose_hook(param);
	return (0);
}

int				main(int argc, char **argv)
{
	int		fd;
	int		file_size[2];
	t_data	*list;
	int		**tab;
	t_env	e;

	if (argc == 2 && is_fdf_file(argv[1]))
	{
		if ((fd = open(argv[1], O_RDONLY)) != -1)
		{
			list = create_list(fd, file_size);
			tab = load_tab(list, file_size);
			if (init_env(&e, file_size, tab) == -1)
				return (0);
			mlx_expose_hook(e.win, &expose_hook, &e);
			mlx_key_hook(e.win, &key_hook, &e);
			mlx_mouse_hook(e.win, &mouse_hook, &e);
			mlx_loop(e.ptr);
		}
		else
			ft_putstr("error dans l ouverture du fichier\n");
	}
	else
		ft_putstr("usage : ./fdf fichier.fdf\n");
	return (0);
}
