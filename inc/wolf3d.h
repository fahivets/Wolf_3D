/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamarsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 19:42:04 by dsamarsk          #+#    #+#             */
/*   Updated: 2019/07/27 19:09:31 by dsamarsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <SDL.h>
# include <SDL_image.h>
# define WIN_W 640
# define WIN_H 480
# define HALF_W 320
# define HALF_H 240
# define TEX_W 64
# define TEX_H 64

typedef struct		s_parsing
{
	char			**array;
	size_t			len_line;
	int				count_line;
	int				zero_count;
}					t_parsing;

typedef struct		s_vector2
{
	double			x;
	double			y;
}					t_vector2;

typedef struct		s_fps
{
	double			time;
	double			old_time;
}					t_fps;

typedef struct		s_map
{
	int				x;
	int				y;
}					t_map;

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Surface		*surface;
	SDL_Event		event;
	int				game_loop;
}					t_sdl;

typedef struct		s_textures
{
	SDL_Surface		*red_wall;
	SDL_Surface		*wood_wall;
	SDL_Surface		*grey_wall;
	SDL_Surface		*stone_wall;
	SDL_Surface		*floor;
	SDL_Surface		*ceiling;
	unsigned char	*data;
	unsigned char	*data_floor;
	unsigned char	*data_ceil;
	double			wall_x;
	int				x_pixel;
	int				y_pixel;
	int				d;
	int				init;
	int				pixel_position;
	t_vector2		floor_wall;
	double			dist_wall;
	double			dist_player;
	double			current_dist;
	t_vector2		current_floor;
	double			weight;
	t_map			floor_pixel;
	int				floor_pixel_position;
}					t_textures;

typedef struct		s_game
{
	t_vector2		pos;
	t_vector2		dir;
	t_vector2		old_dir;
	t_vector2		plane;
	t_vector2		old_plane;
	t_vector2		camera;
	t_vector2		ray_dir;
	t_vector2		side_dist;
	t_vector2		delta_dist;
	t_fps			fps;
	t_map			map_coords;
	t_map			step;
	char			**map;
	int				x_pixel;
	double			perp_wall_dist;
	int				side;
	int				hit;
	int				line_h;
	int				draw_start;
	int				draw_end;
	double			move_speed;
	double			rot_speed;
	int				move_up;
	int				move_down;
	int				rot_right;
	int				rot_left;
	t_sdl			sdl;
	t_textures		tex;
}					t_game;

/*
** main.c
*/
void				error_msg(char *str);
void				close_sdl(t_game *g);

/*
** parsing.c
*/
int					init_parsing(t_game *g, char *argv);

/*
** init.c
*/
void				init_start_params(t_game *g);
void				init_sdl_and_window(t_game *g);
void				init_textures(t_game *g);

/*
** raycasting.c
*/
void				raycasting(t_game *g);

/*
** rendering.c
*/
void				init_rendering(t_game *g);
void				init_textures(t_game *g);

/*
** hooks.c
*/
void				key_hooks(t_game *g);

/*
** make_move_and_rotate.c
*/
void				make_move_and_rot(t_game *g);

/*
** floor_casting.c
*/
void				init_floor_casting(t_game *g, unsigned char *data_pixels);

#endif
