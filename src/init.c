/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:06:36 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/11/06 20:22:56 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void	init_textures(t_game *g)
{
	if ((g->tex.red_wall = IMG_Load("./textures/redbrick.png")) == NULL)
		error_msg("Textures_error: Can't load redbrick.png");
	if ((g->tex.wood_wall = IMG_Load("./textures/wood.png")) == NULL)
		error_msg("Textures_error: Can't load wood.png");
	if ((g->tex.grey_wall = IMG_Load("./textures/greystone.png")) == NULL)
		error_msg("Textures_error: Can't load greystone.png");
	if ((g->tex.stone_wall = IMG_Load("./textures/colorstone.png")) == NULL)
		error_msg("Textures_error: Can't load colorstone.png");
	if ((g->tex.floor = IMG_Load("./textures/floor.png")) == NULL)
		error_msg("Textures_error: Can't load floor.png");
	if ((g->tex.ceiling = IMG_Load("./textures/ceiling.png")) == NULL)
		error_msg("Textures_error: Can't load ceiling.png");
}

void	init_start_params(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((g->map) && g->map[i++][j] != '0')
	{
		j = 0;
		while ((g->map[i][j]) && g->map[i][j] != '0')
			j++;
	}
	g->pos.x = (double)i - 0.5;
	g->pos.y = (double)j + 0.5;
	g->dir.x = 1;
	g->dir.y = 0;
	g->plane.x = 0;
	g->plane.y = 0.66;
	g->fps.time = 0;
	g->fps.old_time = 0;
	g->move_speed = 0.05;
	g->rot_speed = 0.05;
}

void	init_sdl_and_window(t_game *g)
{
	g->sdl.window = NULL;
	g->sdl.surface = NULL;
	g->sdl.game_loop = 1;
	SDL_Init(SDL_INIT_EVERYTHING);
	g->sdl.window = SDL_CreateWindow("WOLF_3D",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WIN_W, WIN_H, SDL_WINDOW_ALLOW_HIGHDPI);
	if (g->sdl.window == NULL)
		error_msg("SDL_error: Window could not be created!");
	g->sdl.surface = SDL_GetWindowSurface(g->sdl.window);
	if (g->sdl.surface == NULL)
		error_msg("SDL_error: Unable to create surface");
}
