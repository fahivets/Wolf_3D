/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:43:05 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/27 17:01:11 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static void	key_move(t_game *g)
{
	if (g->sdl.event.key.keysym.scancode == 26
			|| g->sdl.event.key.keysym.sym == SDLK_UP)
		g->move_up = g->sdl.event.type == SDL_KEYDOWN;
	if (g->sdl.event.key.keysym.scancode == 22
			|| g->sdl.event.key.keysym.sym == SDLK_DOWN)
		g->move_down = g->sdl.event.type == SDL_KEYDOWN;
	if (g->sdl.event.key.keysym.scancode == 4
			|| g->sdl.event.key.keysym.sym == SDLK_LEFT)
		g->rot_left = g->sdl.event.type == SDL_KEYDOWN;
	if (g->sdl.event.key.keysym.scancode == 7
			|| g->sdl.event.key.keysym.sym == SDLK_RIGHT)
		g->rot_right = g->sdl.event.type == SDL_KEYDOWN;
}

void		key_hooks(t_game *g)
{
	while (SDL_PollEvent(&g->sdl.event) != 0)
	{
		if (g->sdl.event.type == SDL_KEYDOWN || g->sdl.event.type == SDL_KEYUP)
		{
			key_move(g);
			if (g->sdl.event.type == SDL_KEYDOWN
					&& g->sdl.event.key.keysym.scancode == SDL_SCANCODE_T)
				g->tex.init = (g->tex.init == 0) ? (1) : (0);
			if (g->sdl.event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				g->sdl.game_loop = 0;
		}
		if (g->sdl.event.type == SDL_QUIT)
			g->sdl.game_loop = 0;
	}
}
