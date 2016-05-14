/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 04:08:53 by ravard            #+#    #+#             */
/*   Updated: 2016/05/14 04:21:56 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		*int_malloc(int size)
{
	int	i;
	int	*buf;

	buf = (int *)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		buf[i] = 0;
	return (buf);
}

t_data			*new_elem(t_data *prev, char *content)
{
	t_data		*new;

	if ((new = (t_data *)malloc(sizeof(t_data))) == NULL)
		return (NULL);
	new->data = ft_strdup(content);
	if (prev)
		prev->next = new;
	new->next = NULL;
	return (new);
}

t_data			*create_list(int fd, int *file_size)
{
	int			i;
	int			j;
	char		*line;
	t_data		*list[2];

	list[0] = NULL;
	file_size[1] = 0;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		list[0] = new_elem(list[0], line);
		i++;
		j = 0;
		while (ft_strsplit(list[0]->data, ' ')[j])
			j++;
		if (i == 1)
			list[1] = list[0];
		if (j > file_size[1])
			file_size[1] = j;
	}
	file_size[0] = i;
	return (list[1]);
}

int				**load_tab(t_data *list, int *file_size)
{
	int	i;
	int	j;
	int	**tab;

	tab = (int **)malloc(sizeof(int *) * file_size[0]);
	i = 0;
	while (i < file_size[0])
	{
		tab[i] = int_malloc(file_size[1]);
		j = -1;
		while (ft_strsplit(list->data, ' ')[++j])
			tab[i][j] = ft_atoi(ft_strsplit(list->data, ' ')[j]);
		list = list->next;
		i++;
	}
	return (tab);
}

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
	ft_putstr("Notre fichier contient ");
	ft_putnbr(i);
	ft_putstr(" lignes et ");
	ft_putnbr(j);
	ft_putstr(" colonnes\n");
}
