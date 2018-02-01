/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_and_ceiling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkabongo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:07:10 by gkabongo          #+#    #+#             */
/*   Updated: 2018/01/28 15:08:54 by gkabongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

t_info		draw_floor(t_info *ev)
{
	ev->count_j = ev->draw_end + 1;
	while (ev->count_j < ev->height)
	{
		SDL_SetRenderDrawColor(ev->renderer, 0, 124, 255, 255);
		SDL_RenderDrawPoint(ev->renderer, ev->count_x, ev->count_j);
		ev->count_j++;
	}
	return (*ev);
}

t_info		draw_ceiling(t_info *ev)
{
	ev->count_j = ev->draw_end + 1;
	while (ev->count_j < ev->height)
	{
		SDL_SetRenderDrawColor(ev->renderer, 255, 124, 255, 255);
		SDL_RenderDrawPoint(ev->renderer, ev->count_x, ev->height -
				ev->count_j);
		ev->count_j++;
	}
	draw_floor(ev);
	return (*ev);
}
