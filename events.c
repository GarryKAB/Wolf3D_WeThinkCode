/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkabongo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:45:17 by gkabongo          #+#    #+#             */
/*   Updated: 2018/02/01 15:53:00 by gkabongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

void		move_left(t_info *ev)
{
	ev->old_dir_x = ev->dir_x;
	ev->dir_x = ev->dir_x * cos(ev->rot_speed) - ev->dir_y * sin(ev->rot_speed);
	ev->dir_y = ev->old_dir_x * sin(ev->rot_speed) +
		ev->dir_y * cos(ev->rot_speed);
	ev->old_plane_x = ev->plane_x;
	ev->plane_x = ev->plane_x * cos(ev->rot_speed) - ev->plane_y *
		sin(ev->rot_speed);
	ev->plane_y = ev->old_plane_x * sin(ev->rot_speed) + ev->plane_y *
		cos(ev->rot_speed);
}

void		move_right(t_info *ev)
{
	ev->old_dir_x = ev->dir_x;
	ev->dir_x = ev->dir_x * cos(-ev->rot_speed) - ev->dir_y *
		sin(-ev->rot_speed);
	ev->dir_y = ev->old_dir_x * sin(-ev->rot_speed) + ev->dir_y *
		cos(-ev->rot_speed);
	ev->old_plane_x = ev->plane_x;
	ev->plane_x = ev->plane_x * cos(-ev->rot_speed) - ev->plane_y *
		sin(-ev->rot_speed);
	ev->plane_y = ev->old_plane_x * sin(-ev->rot_speed) + ev->plane_y *
		cos(-ev->rot_speed);
}

void		move_down(t_info *ev)
{
	if (ev->map[(int)(ev->pos_x - ev->dir_x * ev->move_speed)][(int)ev->pos_y]
			== 0)
		ev->pos_x -= ev->dir_x * ev->move_speed;
	if (ev->map[(int)ev->pos_x][(int)(ev->pos_y - ev->dir_y * ev->move_speed)]
			== 0)
		ev->pos_y -= ev->dir_y * ev->move_speed;
}

void		move_up(t_info *ev)
{
	if (ev->map[(int)(ev->pos_x + ev->dir_x * ev->move_speed)][(int)ev->pos_y]
			== 0)
		ev->pos_x += ev->dir_x * ev->move_speed;
	if (ev->map[(int)ev->pos_x][(int)(ev->pos_y + ev->dir_y *
				ev->move_speed)] == 0)
		ev->pos_y += ev->dir_y * ev->move_speed;
}

void		events(t_info *ev)
{
	ev->count_x = 0;
	ev->old_time = ev->time;
	ev->time = SDL_GetTicks();
	ev->frame_time = (ev->time - ev->old_time) / 1000.0;
	SDL_RenderPresent(ev->renderer);
	SDL_SetRenderDrawColor(ev->renderer, 0, 0, 0, 255);
	SDL_RenderClear(ev->renderer);
	ev->move_speed = ev->frame_time * 7.0;
	ev->rot_speed = ev->frame_time * 4.0;
	while (SDL_PollEvent(&ev->event))
	{
		if (ev->event.type == SDL_QUIT)
			ev->running = 1;
		if (ev->event.type == SDL_KEYDOWN)
		{
			if (ev->event.key.keysym.sym == SDLK_ESCAPE)
				ev->running = 1;
			if (ev->event.key.keysym.sym == SDLK_UP ||
					ev->event.key.keysym.sym == SDLK_w)
				move_up(ev);
			if (ev->event.key.keysym.sym == SDLK_DOWN ||
					ev->event.key.keysym.sym == SDLK_s)
				move_down(ev);
			if (ev->event.key.keysym.sym == SDLK_RIGHT ||
					ev->event.key.keysym.sym == SDLK_d)
				move_right(ev);
			if (ev->event.key.keysym.sym == SDLK_LEFT ||
					ev->event.key.keysym.sym == SDLK_a)
				move_left(ev);
		}
	}
}
