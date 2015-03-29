/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 11:40:35 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/17 12:51:46 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MKART_H
# define MKART_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <time.h>

# define ESC		53
# define LEFT		123
# define RIGHT		124
# define UP			126
# define DOWN		125
# define KEY_R		15
# define KEYS		6

# define ABS(x)		((x) < 0 ? -(x) : (x))
# define SQ(x)		((x) * (x))

# define XSIZE		(1280.0)
# define YSIZE		(720.0)
# define MMGRID		(8.0)
# define ANGLE		(9000)
# define MSPEED		(12.0)
# define MTOUR		(3)

# define WALL		"textures/collision.xpm"
# define FLOOR		"textures/map.xpm"
# define KART		"textures/toad.xpm"
# define START		"textures/start.xpm"
# define CP			"textures/checkpoint.xpm"
# define SR			"textures/secred.xpm"
# define SB			"textures/secblue.xpm"
# define MILI		"textures/mili.xpm"

# define YELLOW		0xFFFF00
# define RED		0xFF0000
# define GREEN		0x00A800
# define BLUE		0x0000FF
# define WHITE		0xFFFFFF
# define BLACK		0x000000
# define SKY		0x4595FF

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
	double				cos[36000];
	double				sin[36000];
	double				tan[36000];
	double				sdist[(int)YSIZE];
	double				grad[(int)YSIZE];
	double				speed;
	double				start;
	double				ral;
	double				proj_dist;
	double				proj_dist_ysize;
	double				xsize_6000;
	double				xsize_6k;
	double				xsize_2;
	double				ysize_2;
	double				rot;
	t_w3img				img;
	t_w3img				mur;
	t_w3img				flo;
	t_w3img				kar;
	t_w3img				sta;
	t_w3img				cp;
	t_w3img				sr;
	t_w3img				sb;
	t_w3img				mil;
	int					inter;
	int					fin;
	int					tour;
	double				run[MTOUR + 1];
	clock_t				lastclock;
	clock_t				resetclock;
	clock_t				tourclock;
	int					fps;
	t_key				key_events[KEYS];
	t_player			player;
	t_coord				cam;
};

void					init_sdist(t_env *e);
void					init_trigo(t_env *e);
void					init_events(t_env *e);
void					init_mlx(t_env *e);
void					free_all(t_env *e);
void					quit(char *str);
void					usage(char *str);
void					key_event_esc(t_env *e);
void					key_event_left(t_env *e);
void					key_event_right(t_env *e);
void					key_event_up(t_env *e);
void					key_event_down(t_env *e);
void					key_event_r(t_env *e);
int						check_pos(t_env *e, double x, double y);
void					compute_pos(t_env *e, t_coord *newpos);
void					set_fps(t_env *e);
void					draw(t_env *e);
void					cast_floor(t_env *e, int col, int row, double beta);
void					mlx_put_pixel_to_img(t_env *e, int x, int y, int color);
int						get_unit(double time);
int						get_dixieme(double time);
int						get_centieme(double time);
int						get_dizaine(double time);
void					check_finish(t_env *e, double x, double y);
void					put_start(t_env *e);
void					put_player(t_env *e);
void					put_speed(t_env *e);
void					put_score(t_env *e);
void					put_mili(t_env *e, double x, double y, int num);
void					put_secb(t_env *e, double x, double y, int num);
void					put_secr(t_env *e, double x, double y, int num);

#endif
