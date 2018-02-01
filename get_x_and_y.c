/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_x_and_y.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkabongo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:29:21 by gkabongo          #+#    #+#             */
/*   Updated: 2018/01/28 14:32:03 by gkabongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

void	get_x_and_y(char *str, t_info *ev)
{
	int		fd;
	char	*line;
	int		buff;
	int		inc;

	fd = open(str, O_RDONLY);
	line = NULL;
	inc = 1;
	if (get_next_line(fd, &line) > 0)
		buff = ft_count(line, ' ');
	while (get_next_line(fd, &line) > 0)
		inc++;
	ev->row = buff;
	ev->x = buff;
	ev->y = inc;
	close(fd);
}
