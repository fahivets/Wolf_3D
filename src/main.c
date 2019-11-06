/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:12:31 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/08/01 18:39:25 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void		close_sdl(t_game *g)
{
	SDL_FreeSurface(g->tex.red_wall);
	g->tex.red_wall = NULL;
	SDL_FreeSurface(g->tex.wood_wall);
	g->tex.wood_wall = NULL;
	SDL_FreeSurface(g->tex.grey_wall);
	g->tex.grey_wall = NULL;
	SDL_FreeSurface(g->tex.stone_wall);
	g->tex.stone_wall = NULL;
	SDL_FreeSurface(g->tex.floor);
	g->tex.floor = NULL;
	SDL_FreeSurface(g->tex.ceiling);
	g->tex.ceiling = NULL;
	SDL_FreeSurface(g->sdl.surface);
	g->sdl.surface = NULL;
	SDL_DestroyWindow(g->sdl.window);
	g->sdl.window = NULL;
	if (g != NULL)
	{
		ft_arraydel(g->map);
		ft_memdel((void**)&g);
	}
	SDL_Quit();
	exit(0);
}

void		error_msg(char *str)
{
	ft_putendl(str);
	exit(0);
}

static void	game_loop(t_game *g)
{
	init_sdl_and_window(g);
	init_start_params(g);
	init_textures(g);
	while (g->sdl.game_loop)
	{
		SDL_FillRect(g->sdl.surface, NULL,
					SDL_MapRGB(g->sdl.surface->format, 0, 0, 0));
		raycasting(g);
		key_hooks(g);
		make_move_and_rot(g);
		SDL_UpdateWindowSurface(g->sdl.window);
		SDL_Delay(16);
	}
}

int			main(int argc, char **argv)
{
	t_game	*g;

	g = NULL;
	if (argc != 2)
		error_msg("Error: Bad input argument.");
	else
	{
		if ((ft_strstr(argv[1], ".map")) == NULL)
			error_msg("Error: Wrong filename or file extension.");
		g = (t_game *)ft_memalloc(sizeof(t_game));
		if (init_parsing(g, argv[1]) != 1)
			error_msg("Error: Bad map");
		game_loop(g);
		close_sdl(g);
	}
	error_msg("Magic error O_O");
	return (0);
}
