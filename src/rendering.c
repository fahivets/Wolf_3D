/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:11:06 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/08/01 18:36:02 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static void	draw_textures(t_game *g)
{
	unsigned char	*data_pixels;

	data_pixels = (unsigned char *)g->sdl.surface->pixels;
	init_floor_casting(g, data_pixels);
	while (g->draw_start < g->draw_end)
	{
		g->tex.pixel_position = 4 * (g->draw_start * WIN_W + g->x_pixel);
		g->tex.d = g->draw_start * 256 - WIN_H * 128 + g->line_h * 128;
		g->tex.y_pixel = ((g->tex.d * TEX_H) / g->line_h) / 256;
		data_pixels[g->tex.pixel_position] =
			g->tex.data[4 * (TEX_H * g->tex.y_pixel + g->tex.x_pixel)];
		data_pixels[g->tex.pixel_position + 1] =
			g->tex.data[4 * (TEX_H * g->tex.y_pixel + g->tex.x_pixel) + 1];
		data_pixels[g->tex.pixel_position + 2] =
			g->tex.data[4 * (TEX_H * g->tex.y_pixel + g->tex.x_pixel) + 2];
		g->draw_start++;
	}
}

static void	init_textures_param(t_game *g)
{
	if (g->side == 0 || g->side == 2)
		g->tex.wall_x = g->pos.y + g->perp_wall_dist * g->ray_dir.y;
	else
		g->tex.wall_x = g->pos.x + g->perp_wall_dist * g->ray_dir.x;
	g->tex.wall_x -= floor((g->tex.wall_x));
	g->tex.x_pixel = (int)(g->tex.wall_x * (double)(TEX_W));
	if ((g->side == 0 || g->side == 2) && g->ray_dir.x > 0)
		g->tex.x_pixel = TEX_W - g->tex.x_pixel - 1;
	if ((g->side == 1 || g->side == 3) && g->ray_dir.y < 0)
		g->tex.x_pixel = TEX_W - g->tex.x_pixel - 1;
	if (g->side == 0)
		g->tex.data = (unsigned char *)g->tex.red_wall->pixels;
	else if (g->side == 1)
		g->tex.data = (unsigned char *)g->tex.wood_wall->pixels;
	else if (g->side == 2)
		g->tex.data = (unsigned char *)g->tex.grey_wall->pixels;
	else if (g->side == 3)
		g->tex.data = (unsigned char *)g->tex.stone_wall->pixels;
	draw_textures(g);
}

static void	check_side_and_put_pixel(t_game *g, unsigned char *data, int pixel)
{
	if (g->side == 0)
	{
		data[pixel] = 0;
		data[pixel + 1] = 0;
		data[pixel + 2] = 255;
	}
	if (g->side == 1)
	{
		data[pixel] = 0;
		data[pixel + 1] = 255;
		data[pixel + 2] = 0;
	}
	if (g->side == 2)
	{
		data[pixel] = 255;
		data[pixel + 1] = 0;
		data[pixel + 2] = 0;
	}
	if (g->side == 3)
	{
		data[pixel] = 255;
		data[pixel + 1] = 0;
		data[pixel + 2] = 255;
	}
}

void		init_rendering(t_game *g)
{
	unsigned char	*data_pixels;
	int				pixel_position;

	data_pixels = (unsigned char *)g->sdl.surface->pixels;
	if (g->tex.init == 1)
		init_textures_param(g);
	else
	{
		while (g->draw_start < g->draw_end)
		{
			pixel_position = 4 * (g->draw_start * WIN_W + g->x_pixel);
			check_side_and_put_pixel(g, data_pixels, pixel_position);
			g->draw_start++;
		}
	}
}
