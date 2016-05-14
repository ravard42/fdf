/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 13:25:08 by ravard            #+#    #+#             */
/*   Updated: 2016/04/22 19:37:07 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2

# include <fcntl.h>
# include "libft.h"

typedef struct					s_lst
{
	int							fd;
	char						*s;
	struct s_lst				*prev;
	struct s_lst				*next;
}								t_lst;

int								get_next_line(int const fd, char **line);

#endif
