/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:42:26 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/26 20:55:44 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static void		find_dist(t_game *g)
{
	if (g->side == 0 || g->side == 2)
		g->perp_wall_dist =
			(g->map_coords.x - g->pos.x + (1 - g->step.x) / 2) / g->ray_dir.x;
	else
		g->perp_wall_dist =
			(g->map_coords.y - g->pos.y + (1 - g->step.y) / 2) / g->ray_dir.y;
	g->line_h = (int)(WIN_H / g->perp_wall_dist);
	g->draw_start = -g->line_h / 2 + HALF_H;
	if (g->draw_start < 0)
		g->draw_start = 0;
	g->draw_end = g->line_h / 2 + HALF_H;
	if (g->draw_end >= WIN_H)
		g->draw_end = WIN_H - 1;
}

static void		init_dda(t_game *g)
{
	g->hit = 0;
	while (g->hit == 0)
	{
		if (g->side_dist.x < g->side_dist.y)
		{
			g->side_dist.x += g->delta_dist.x;
			g->map_coords.x += g->step.x;
			if (g->ray_dir.x < 0)
				g->side = 0;
			else
				g->side = 2;
		}
		else
		{
			g->side_dist.y += g->delta_dist.y;
			g->map_coords.y += g->step.y;
			if (g->ray_dir.y < 0)
				g->side = 1;
			else
				g->side = 3;
		}
		if (g->map[g->map_coords.x][g->map_coords.y] != 48)
			g->hit = 1;
	}
}

static void		calculate_step_and_side_dist(t_game *g)
{
	if (g->ray_dir.x < 0)
	{
		g->step.x = -1;
		g->side_dist.x = (g->pos.x - g->map_coords.x) * g->delta_dist.x;
	}
	else
	{
		g->step.x = 1;
		g->side_dist.x = (g->map_coords.x + 1.0 - g->pos.x) * g->delta_dist.x;
	}
	if (g->ray_dir.y < 0)
	{
		g->step.y = -1;
		g->side_dist.y = (g->pos.y - g->map_coords.y) * g->delta_dist.y;
	}
	else
	{
		g->step.y = 1;
		g->side_dist.y = (g->map_coords.y + 1.0 - g->pos.y) * g->delta_dist.y;
	}
}

static void		init_camera_and_rays(t_game *g)
{
	g->camera.x = (2 * (g->x_pixel / (double)WIN_W)) - 1;
	g->ray_dir.x = g->dir.x + g->plane.x * g->camera.x;
	g->ray_dir.y = g->dir.y + g->plane.y * g->camera.x;
	g->map_coords.x = (int)g->pos.x;
	g->map_coords.y = (int)g->pos.y;
	g->delta_dist.x = fabs(1 / g->ray_dir.x);
	g->delta_dist.y = fabs(1 / g->ray_dir.y);
}

void			raycasting(t_game *g)
{
	g->x_pixel = 0;
	while (g->x_pixel < WIN_W)
	{
		init_camera_and_rays(g);
		calculate_step_and_side_dist(g);
		init_dda(g);
		find_dist(g);
		init_rendering(g);
		g->x_pixel++;
	}
}
