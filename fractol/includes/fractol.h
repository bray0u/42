/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 11:11:50 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/27 19:28:12 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

# define ESC		53
# define LEFT		123
# define RIGHT		124
# define UP			126
# define DOWN		125
# define MINUS		78
# define PLUS		69
# define KEY_F		3
# define KEY_C		8
# define KEY_M		46
# define STAR		67
# define SLASH		75
# define KEYS		12

# define ABS(x)		((x) < 0 ? -(x) : (x))
# define SQ(x)		((x) * (x))

# define XSIZE		(800.0)
# define YSIZE		(600.0)
# define HALFX		(400.0)
# define HALFY		(300.0)

# define BLACK		0x000000

# define PI			(3.141592653589793)
# define MAXCOUNT	2048.0
# define MINCOUNT	16.0
# define RANDCOLOR	2048
# define TFRACT		6
# define TCOLOR		5

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

typedef struct			s_cpx
{
	double				r;
	double				i;
}						t_cpx;

typedef struct			s_fimg
{
	void				*img;
	char				*data;
	int					bpp;
	int					l;
	int					e;
	int					x;
	int					y;
}						t_fimg;

typedef	struct			s_key
{
	int					keycode;
	void				(*event)(t_env *e);
}						t_key;

struct					s_env
{
	void				*mlx;
	void				*win;
	t_fimg				img;
	size_t				citer;
	int					fract;
	int					col;
	double				zoom;
	double				movex;
	double				movey;
	t_cpx				juliac;
	int					activem;
	size_t				color[RANDCOLOR];
	size_t				(*get_fract[TFRACT])(t_env *e, double x, double y);
	size_t				(*get_col[TCOLOR])(t_env *e, size_t i);
	t_key				key_events[KEYS];
};

void					draw(t_env *e);
int						expose_hook(t_env *e);
void					ft_putstr(char *str);
int						ft_strcmp(char *s1, char *s2);
void					parse_args(t_env *e, int argc, char **argv);
void					print_bind(void);
void					print_usage(char *str);
void					init_env(t_env *e);
void					init_events(t_env *e);
void					init_color(t_env *e);
void					key_event_esc(t_env *e);
void					key_event_left(t_env *e);
void					key_event_right(t_env *e);
void					key_event_up(t_env *e);
void					key_event_down(t_env *e);
void					key_event_plus(t_env *e);
void					key_event_minus(t_env *e);
void					key_event_f(t_env *e);
void					key_event_c(t_env *e);
void					key_event_m(t_env *e);
void					key_event_star(t_env *e);
void					key_event_slash(t_env *e);
size_t					color_red(t_env *e, size_t i);
size_t					color_green(t_env *e, size_t i);
size_t					color_blue(t_env *e, size_t i);
size_t					color_white(t_env *e, size_t i);
size_t					color_rand(t_env *e, size_t i);
size_t					julia(t_env *e, double x, double y);
size_t					mandelbrot(t_env *e, double x, double y);
size_t					burning_ship(t_env *e, double x, double y);
size_t					trimandel(t_env *e, double x, double y);
size_t					weird(t_env *e, double x, double y);
size_t					weird2(t_env *e, double x, double y);

#endif
