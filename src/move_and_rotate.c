/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:28:55 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/11/06 20:22:48 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

static void	rotate_right(t_game *g)
{
	if (g->rot_right)
	{
		g->old_dir.x = g->dir.x;
		g->dir.x = g->dir.x * cos(-g->rot_speed)
					+ g->dir.y * sin(-g->rot_speed);
		g->dir.y = -g->old_dir.x * sin(-g->rot_speed)
					+ g->dir.y * cos(-g->rot_speed);
		g->old_plane.x = g->plane.x;
		g->plane.x = g->plane.x * cos(-g->rot_speed)
					+ g->plane.y * sin(-g->rot_speed);
		g->plane.y = -g->old_plane.x * sin(-g->rot_speed)
					+ g->plane.y * cos(-g->rot_speed);
	}
}

static void	rotate_left(t_game *g)
{
	if (g->rot_left)
	{
		g->old_dir.x = g->dir.x;
		g->dir.x = g->dir.x * cos(g->rot_speed)
					+ g->dir.y * sin(g->rot_speed);
		g->dir.y = -g->old_dir.x * sin(g->rot_speed)
					+ g->dir.y * cos(g->rot_speed);
		g->old_plane.x = g->plane.x;
		g->plane.x = g->plane.x * cos(g->rot_speed)
					+ g->plane.y * sin(g->rot_speed);
		g->plane.y = -g->old_plane.x * sin(g->rot_speed)
					+ g->plane.y * cos(g->rot_speed);
	}
}

void		make_move_and_rot(t_game *g)
{
	if (g->move_up)
	{
		if (g->map[(int)(g->pos.x + g->dir.x * g->move_speed * 6)]
				[(int)(g->pos.y)] == '0')
			g->pos.x += g->dir.x * g->move_speed;
		if (g->map[(int)(g->pos.x)]
				[(int)(g->pos.y + g->dir.y * g->move_speed * 6)] == '0')
			g->pos.y += g->dir.y * g->move_speed;
	}
	if (g->move_down)
	{
		if (g->map[(int)(g->pos.x - g->dir.x * g->move_speed * 6)]
				[(int)(g->pos.y)] == '0')
			g->pos.x -= g->dir.x * g->move_speed;
		if (g->map[(int)(g->pos.x)]
				[(int)(g->pos.y - g->dir.y * g->move_speed * 6)] == '0')
			g->pos.y -= g->dir.y * g->move_speed;
	}
	rotate_left(g);
	rotate_right(g);
}
