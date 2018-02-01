/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkabongo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:35:07 by gkabongo          #+#    #+#             */
/*   Updated: 2018/01/28 15:35:20 by gkabongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

void	map_fill(char *str, t_info *ev)
{
	char	*line;
	char	**split;

	ev->fill_x = 0;
	ev->fill_y = 0;
	ev->fd = open(str, O_RDONLY);
	while (get_next_line(ev->fd, &line) > 0 && ev->fill_y < ev->y)
	{
		if ((ft_count(line, ' ')) >= ev->row)
		{
			split = ft_strsplit(line, ' ');
			ev->fill_x = 0;
			while (ev->fill_x < ev->x)
			{
				ev->map[ev->fill_y][ev->fill_x] =
					(int)ft_atoi(split[ev->fill_x]);
				ev->fill_x++;
			}
			ev->fill_y++;
			free(line);
		}
		else
			printf("Map Error!\n");
	}
	close(ev->fd);
}

void	map_alloc(char *str, t_info *ev)
{
	int		index;

	index = 0;
	ev->map = (double **)malloc(sizeof(double *) * ev->y);
	while (index < ev->y)
	{
		ev->map[index] = (double *)malloc(sizeof(double) * ev->x);
		index++;
	}
	map_fill(str, ev);
}
