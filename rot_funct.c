/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:04:43 by ravard            #+#    #+#             */
/*   Updated: 2016/05/14 16:04:45 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		trigo_rot(t_env *e)
{
	int		**ret;
	int		i;
	int		j;
	int		tmp;

	ret = (int **)malloc(sizeof(int *) * e->file_size[1]);
	i = -1;
	while (++i < e->file_size[1])
		ret[i] = (int *)malloc(sizeof(int) * e->file_size[0]);
	i = -1;
	while (++i < e->file_size[1])
	{
		j = -1;
		while (++j < e->file_size[0])
			ret[i][j] = e->tab[j][e->file_size[1] - i - 1];
	}
	tmp = e->file_size[0];
	e->file_size[0] = e->file_size[1];
	e->file_size[1] = tmp;
	free(e->tab);
	e->tab = ret;
}

void		horaire_rot(t_env *e)
{
	int		**ret;
	int		i;
	int		j;
	int		tmp;

	ret = (int **)malloc(sizeof(int *) * e->file_size[1]);
	i = -1;
	while (++i < e->file_size[1])
		ret[i] = (int *)malloc(sizeof(int) * e->file_size[0]);
	i = -1;
	while (++i < e->file_size[1])
	{
		j = -1;
		while (++j < e->file_size[0])
			ret[i][j] = e->tab[e->file_size[0] - 1 - j][i];
	}
	tmp = e->file_size[0];
	e->file_size[0] = e->file_size[1];
	e->file_size[1] = tmp;
	free(e->tab);
	e->tab = ret;
}
