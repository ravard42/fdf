/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 03:38:01 by ravard            #+#    #+#             */
/*   Updated: 2016/05/14 15:58:29 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define LENGHT 1200
# define WIDTH 900
# define UNITY 7

# include "get_next_line.h"
# include <mlx.h>
# include <math.h>

typedef struct			s_data
{
	char			*data;
	struct s_data	*next;
}						t_data;

typedef struct			s_env
{
	void		*ptr;
	void		*win;
	int			x_origin;
	int			y_origin;
	int			unity;
	int			*file_size;
	int			**tab;
}						t_env;

t_data					*new_elem(t_data *prev, char *content);
t_data					*create_list(int fd, int *file_size);
int						**load_tab(t_data *list, int *file_size);
void					print_tab(int **tab, int *file_size);

int						init_env(t_env *e, int	*file_size, int **tab);
void					m_a_j_env(t_env *e, int x, int y, int keycode);
void					print_env(t_env *e);

void					draw(t_env e);

void					trigo_rot(t_env *e);
void					horaire_rot(t_env *e);

#endif
