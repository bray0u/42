/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 13:17:06 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/17 12:45:50 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			init_mlx(t_env *e)
{
	t_w3img	*mur;
	t_w3img	*img;
	t_w3img	*cat;
	t_w3img	*cei;
	t_w3img	*flo;

	mur = &e->mur;
	img = &e->img;
	cat = &e->cat;
	flo = &e->flo;
	cei = &e->cei;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, XSIZE, YSIZE, "Wolf3d");
	cat->img = mlx_xpm_file_to_image(e->mlx, CAT, &cat->x, &cat->y);
	cat->data = mlx_get_data_addr(cat->img, &cat->bpp, &cat->l, &cat->e);
	cei->img = mlx_xpm_file_to_image(e->mlx, CEIL, &cei->x, &cei->y);
	cei->data = mlx_get_data_addr(cei->img, &cei->bpp, &cei->l, &cei->e);
	flo->img = mlx_xpm_file_to_image(e->mlx, FLOOR, &flo->x, &flo->y);
	flo->data = mlx_get_data_addr(flo->img, &flo->bpp, &flo->l, &flo->e);
	mur->img = mlx_xpm_file_to_image(e->mlx, WALL, &mur->x, &mur->y);
	mur->data = mlx_get_data_addr(mur->img, &mur->bpp, &mur->l, &mur->e);
	img->img = mlx_new_image(e->mlx, XSIZE, YSIZE);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->l, &img->e);
}

void			init_map(t_env *e, int fd)
{
	char	buff[3];
	int		x;
	int		y;

	y = -1;
	read(fd, buff, 3);
	e->xmap = (buff[0] - '0') * 10 + buff[1] - '0';
	read(fd, buff, 3);
	e->ymap = (buff[0] - '0') * 10 + buff[1] - '0';
	e->map = (int **)malloc(sizeof(int *) * e->ymap);
	while (++y < e->ymap)
	{
		x = 0;
		e->map[y] = (int *)malloc(sizeof(int) * e->xmap);
		while (x < e->xmap && read(fd, buff, 1))
		{
			if (buff[0] == '1')
			{
				e->player.pos.x = x + 1.0 / 2.0;
				e->player.pos.y = y + 1.0 / 2.0;
			}
			if (buff[0] <= '9' && buff[0] >= '0')
				e->map[y][++x - 1] = buff[0] - '0';
		}
	}
}

static t_key	get_key_event(int keycode, void (*event)(t_env *e))
{
	t_key	key;

	key.keycode = keycode;
	key.is_press = 0;
	key.event = event;
	return (key);
}

void			init_events(t_env *e)
{
	e->bot = 0;
	e->key_events[0] = get_key_event(ESC, &key_event_esc);
	e->key_events[1] = get_key_event(LEFT, &key_event_left);
	e->key_events[2] = get_key_event(RIGHT, &key_event_right);
	e->key_events[3] = get_key_event(KEY_W, &key_event_key_w);
	e->key_events[4] = get_key_event(KEY_A, &key_event_key_a);
	e->key_events[5] = get_key_event(KEY_D, &key_event_key_d);
	e->key_events[6] = get_key_event(KEY_S, &key_event_key_s);
}

void			init_trigo(t_env *e)
{
	int			i;
	double		rad;

	i = 0;
	e->cos = (double *)malloc(sizeof(double) * 36000);
	e->sin = (double *)malloc(sizeof(double) * 36000);
	e->tan = (double *)malloc(sizeof(double) * 36000);
	while (i < 36000)
	{
		rad = (((double)i / (100.0)) * (2.0) * PI) / (360.0);
		(e->cos)[i] = cos(rad);
		(e->sin)[i] = sin(rad);
		(e->tan)[i] = tan(rad);
		i++;
	}
	e->xsize_2 = XSIZE / 2.0;
	e->ysize_2 = YSIZE / 2.0;
	e->xsize_6000 = XSIZE / 6000.0;
	e->xsize_6k = 6000.0 / XSIZE;
	e->proj_dist = XSIZE / 2.0 / e->tan[3000];
}
