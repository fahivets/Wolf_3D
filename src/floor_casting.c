/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 15:28:27 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/26 20:55:47 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static void	draw_floor_and_ceil(t_game *g, int y, unsigned char *data_pixels)
{
	int	ceil_position;

	g->tex.pixel_position = 4 * (y * WIN_W + g->x_pixel);
	g->tex.floor_pixel_position = 4 * (TEX_W * g->tex.floor_pixel.y
			+ g->tex.floor_pixel.x);
	data_pixels[g->tex.pixel_position] =
		g->tex.data_floor[g->tex.floor_pixel_position];
	data_pixels[g->tex.pixel_position + 1] =
		g->tex.data_floor[g->tex.floor_pixel_position + 1];
	data_pixels[g->tex.pixel_position + 2] =
		g->tex.data_floor[g->tex.floor_pixel_position + 2];
	ceil_position = 4 * ((WIN_H - y) * WIN_W + g->x_pixel);
	data_pixels[ceil_position] =
		g->tex.data_ceil[g->tex.floor_pixel_position];
	data_pixels[ceil_position + 1] =
		g->tex.data_ceil[g->tex.floor_pixel_position + 1];
	data_pixels[ceil_position + 2] =
		g->tex.data_ceil[g->tex.floor_pixel_position + 2];
}

static void	check_wall_directions(t_game *g)
{
	if (g->side == 2 && g->ray_dir.x > 0)
	{
		g->tex.floor_wall.x = g->map_coords.x;
		g->tex.floor_wall.y = g->map_coords.y + g->tex.wall_x;
	}
	else if (g->side == 0 && g->ray_dir.x < 0)
	{
		g->tex.floor_wall.x = g->map_coords.x + 1.0;
		g->tex.floor_wall.y = g->map_coords.y + g->tex.wall_x;
	}
	else if (g->side == 3 && g->ray_dir.y > 0)
	{
		g->tex.floor_wall.x = g->map_coords.x + g->tex.wall_x;
		g->tex.floor_wall.y = g->map_coords.y;
	}
	else
	{
		g->tex.floor_wall.x = g->map_coords.x + g->tex.wall_x;
		g->tex.floor_wall.y = g->map_coords.y + 1.0;
	}
}

void		init_floor_casting(t_game *g, unsigned char *data_pixels)
{
	int		y;

	g->tex.data_floor = (unsigned char *)g->tex.floor->pixels;
	g->tex.data_ceil = (unsigned char *)g->tex.ceiling->pixels;
	check_wall_directions(g);
	g->tex.dist_wall = g->perp_wall_dist;
	g->tex.dist_player = 0.0;
	if (g->draw_end < 0)
		g->draw_end = WIN_H;
	y = g->draw_end + 1;
	while (y < WIN_H)
	{
		g->tex.current_dist = WIN_H / (2.0 * y - WIN_H);
		g->tex.weight = (g->tex.current_dist - g->tex.dist_player) /
			(g->tex.dist_wall - g->tex.dist_player);
		g->tex.current_floor.x = g->tex.weight * g->tex.floor_wall.x
			+ (1.0 - g->tex.weight) * g->pos.x;
		g->tex.current_floor.y = g->tex.weight * g->tex.floor_wall.y
			+ (1.0 - g->tex.weight) * g->pos.y;
		g->tex.floor_pixel.x = (int)(g->tex.current_floor.x * TEX_W) % TEX_W;
		g->tex.floor_pixel.y = (int)(g->tex.current_floor.y * TEX_H) % TEX_H;
		draw_floor_and_ceil(g, y, data_pixels);
		y++;
	}
}
