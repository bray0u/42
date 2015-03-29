/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 11:40:35 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/27 16:10:47 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>

# define ESC		53
# define LEFT		123
# define RIGHT		124
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_B		11
# define KEY_N		45
# define KEYS		7

# define ABS(x)		((x) < 0 ? -(x) : (x))
# define SQ(x)		((x) * (x))

# define XSIZE		800.0
# define YSIZE		450.0
# define MMGRID		8.0
# define ANGLE		9000

# define SPEED		8.0
# define ROTSPEED	30000.0

# define WALL		"textures/wall.xpm"
# define CAT		"textures/gifcat.xpm"
# define FLOOR		"textures/floor.xpm"
# define CEIL		"textures/ceil.xpm"

# define YELLOW		0xFFFF00
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define WHITE		0xFFFFFF
# define BLACK		0x000000

# define PI (3.141592653589793)

typedef unsigned char	t_byte;

typedef struct s_env	t_env;

typedef struct			s_color
{
	t_byte				r;
	t_byte				g;
	t_byte				b;
}						t_color;

typedef union			u_rgb
{
	size_t				color;
	t_color				rgb;
}						t_rgb;

typedef struct			s_coord
{
	double				x;
	double				y;
}						t_coord;

typedef struct			s_player
{
	t_coord				pos;
	int					angle;
	double				angle_3000;
}						t_player;

typedef struct			s_w3img
{
	void				*img;
	char				*data;
	int					bpp;
	int					l;
	int					e;
	int					x;
	int					y;
}						t_w3img;

typedef	struct			s_key
{
	int					keycode;
	int					is_press;
	void				(*event)(t_env *e);
}						t_key;

struct					s_env
{
	void				*mlx;
	void				*win;
	double				*cos;
	double				*sin;
	double				*tan;
	double				speed;
	double				proj_dist;
	double				xsize_6000;
	double				xsize_6k;
	double				xsize_2;
	double				ysize_2;
	double				rot;
	t_w3img				img;
	t_w3img				mur;
	t_w3img				cat;
	t_w3img				cei;
	t_w3img				flo;
	t_coord				hit;
	clock_t				lastclock;
	char				wall;
	char				wallv;
	char				wallh;
	int					bot;
	int					fps;
	int					frame;
	int					gif;
	int					osx;
	int					osy;
	int					xmap;
	int					ymap;
	t_key				key_events[KEYS];
	int					**map;
	t_player			player;
};

void					init_map(t_env *e, int fd);
void					init_trigo(t_env *e);
void					init_events(t_env *e);
void					init_mlx(t_env *e);
void					free_all(t_env *e);
void					quit(char *str);
void					usage(char *str);
void					key_event_esc(t_env *e);
void					key_event_left(t_env *e);
void					key_event_right(t_env *e);
void					key_event_key_w(t_env *e);
void					key_event_key_s(t_env *e);
void					key_event_key_a(t_env *e);
void					key_event_key_d(t_env *e);
void					bot_run(t_env *e);
void					bot_stop(t_env *e);
void					compute_pos(t_env *e, t_coord *newpos);
void					draw(t_env *e);
void					minimap(t_env *e);
void					set_fps(t_env *e);
void					set_osx(t_env *e, double distv, double disth);
int						get_wall_color(t_env *e, double h, int y, int color);
void					cast_ceil(t_env *e, int col, double beta, int stop);
void					cast_floor(t_env *e, int col, int row, double beta);
void					mlx_put_pixel_to_img(t_env *e, int x, int y, int color);

#endif
