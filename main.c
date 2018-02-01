/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkabongo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 14:14:57 by gkabongo          #+#    #+#             */
/*   Updated: 2018/01/28 15:45:27 by gkabongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wolf.h"

t_info		ft_do_stuff(t_info *ev)
{
	ft_ray_calc(ev);
	ft_side_dist_calc(ev);
	ft_dda_calc(ev);
	ft_draw_stuff(ev);
	ft_render_stuff(ev);
	return (*ev);
}

t_info		ft_init_stuff(t_info *ev)
{
	ev->pos_x = 2;
	ev->pos_y = 2;
	ev->dir_x = -1;
	ev->dir_y = 0;
	ev->plane_x = 0;
	ev->plane_y = 0.66;
	ev->time = 0;
	ev->old_time = 0;
	ev->height = 600;
	ev->width = 1000;
	return (*ev);
}

int			ft_sdl_init(t_info *ev)
{
	ev->running = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return (1);
	ev->window = SDL_CreateWindow("Wolf 3D",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			1000, 600, 0);
	ev->renderer = SDL_CreateRenderer(ev->window,
			-1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(ev->renderer, 0, 0, 0, 255);
	SDL_RenderClear(ev->renderer);
	return (0);
}

int			main(int ac, char *av[])
{
	t_info ev;

	if (ac == 2)
	{
		if (open(av[1], O_RDONLY) == -1)
			ft_putendl("Map error!");
		else
		{
			get_x_and_y(av[1], &ev);
			map_alloc(av[1], &ev);
			ft_sdl_init(&ev);
			ft_init_stuff(&ev);
			while (ev.running == 0)
			{
				while (ev.count_x++ < ev.width)
					ft_do_stuff(&ev);
				events(&ev);
			}
			SDL_DestroyWindow(ev.window);
			SDL_Quit();
		}
	}
	else
		ft_putendl("An error occured!");
	return (0);
}
