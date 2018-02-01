/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_draw_stuff.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkabongo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:09:22 by gkabongo          #+#    #+#             */
/*   Updated: 2018/01/28 15:10:46 by gkabongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

t_info		ft_render_stuff(t_info *ev)
{
	draw_ceiling(ev);
	ev->count_y = ev->draw_start;
	if (ev->side == 0)
		SDL_SetRenderDrawColor(ev->renderer, 0, 0, 255, 255);
	if (ev->side != 0)
		SDL_SetRenderDrawColor(ev->renderer, 255, 0, 0, 255);
	if (ev->side == 0 && ev->ray_dir_x < 0)
		SDL_SetRenderDrawColor(ev->renderer, 0, 255, 0, 255);
	if (ev->side == 1 && ev->ray_dir_y < 0)
		SDL_SetRenderDrawColor(ev->renderer, 255, 255, 255, 255);
	while (ev->count_y < ev->draw_end)
	{
		SDL_RenderDrawPoint(ev->renderer, ev->count_x, ev->count_y);
		ev->count_y++;
	}
	return (*ev);
}
