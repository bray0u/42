/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 12:17:33 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/17 19:24:45 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void				mlx_put_pixel_to_img(t_env *e, int x, int y, int color)
{
	int		i;
	t_rgb	rgb;

	rgb.color = color;
	i = y * e->img.l + x * e->img.bpp / 8;
	e->img.data[i] = rgb.rgb.r;
	e->img.data[i + 1] = rgb.rgb.g;
	e->img.data[i + 2] = rgb.rgb.b;
}

static double		calc_dist_h(t_env *e, int i)
{
	t_coord	p;
	double	xa;
	double	ya;
	double	a;

	a = e->player.angle_3000 - (double)i / (e->xsize_6000);
	a = a >= 36000 ? a - 36000.0 : a;
	a = a < 0 ? a + 36000.0 : a;
	ya = a < 18000 ? -1 : 1;
	p.y = (int)(e->player.pos.y);
	p.y = a < 18000 ? p.y - 0.00001 : p.y + 1.0;
	xa = -ya / (e->tan)[(int)a];
	p.x = e->player.pos.x + (e->player.pos.y - p.y) / e->tan[(int)a];
	while (p.x >= 0 && p.y >= 0 && p.x < e->xmap && p.y < e->ymap
			&& (e->map)[(int)(p.y)][(int)(p.x)] < 2)
	{
		p.x = p.x + xa;
		p.y = p.y + ya;
	}
	if (p.x >= 0 && p.y >= 0 && p.x < e->xmap && p.y < e->ymap)
		e->wallh = (e->map)[(int)(p.y)][(int)(p.x)];
	e->hit.x = p.x;
	if (p.x < 0 || p.y < 0 || p.x >= e->xmap || p.y >= e->ymap)
		return (100);
	return (sqrt(SQ(e->player.pos.x - p.x) + SQ(e->player.pos.y - p.y)));
}

static double		calc_dist_v(t_env *e, int i)
{
	t_coord	p;
	double	xa;
	double	ya;
	double	a;

	a = e->player.angle_3000 - (double)i / (e->xsize_6000);
	a = a >= 36000 ? a - 36000.0 : a;
	a = a < 0 ? a + 36000.0 : a;
	xa = a >= 9000 && a < 27000 ? -1 : 1;
	p.x = (int)(e->player.pos.x);
	p.x = a >= 9000 && a < 27000 ? p.x - 0.00001 : p.x + 1.0;
	ya = -xa * (e->tan)[(int)a];
	p.y = e->player.pos.y + (e->player.pos.x - p.x) * (e->tan)[(int)a];
	while (p.x >= 0 && p.y >= 0 && p.x < e->xmap && p.y < e->ymap
			&& (e->map)[(int)(p.y)][(int)(p.x)] < 2)
	{
		p.x = p.x + xa;
		p.y = p.y + ya;
	}
	if (p.x >= 0 && p.y >= 0 && p.x < e->xmap && p.y < e->ymap)
		e->wallv = (e->map)[(int)(p.y)][(int)(p.x)];
	e->hit.y = p.y;
	if (p.x < 0 || p.y < 0 || p.x >= e->xmap || p.y >= e->ymap)
		return (100);
	return (sqrt(SQ(e->player.pos.x - p.x) + SQ(e->player.pos.y - p.y)));
}

static void			draw_colone(t_env *e, double dist, int x, int color)
{
	double	i;
	int		y;
	double	beta;

	beta = x < e->xsize_2 ? 0.0 - (e->xsize_6k * ((double)x - e->xsize_2))
		: 36000.0 - (e->xsize_6k * ((double)x - e->xsize_2));
	if (beta < 36000 && beta >= 0)
		dist = dist * e->cos[(int)beta];
	dist = 1.0 / dist * e->proj_dist;
	i = e->ysize_2 - dist / 2.0;
	y = i < 0 ? -i : 0;
	cast_ceil(e, x, beta, y + i);
	while (y + i < YSIZE - i)
	{
		mlx_put_pixel_to_img(e, x, y + i, get_wall_color(e, dist, y, color));
		y++;
		if (y + i > YSIZE)
			return ;
	}
	if (y + i < YSIZE)
		cast_floor(e, x, y + i, beta);
}

void				draw(t_env *e)
{
	int			i;
	double		disth;
	double		distv;
	double		a;

	i = -1;
	e->player.angle_3000 = (double)(e->player.angle) + 3000.0;
	while (++i < XSIZE)
	{
		disth = calc_dist_h(e, i);
		distv = calc_dist_v(e, i);
		a = e->player.angle_3000 - (double)i / e->xsize_6000;
		a = a >= 36000 ? a - 36000.0 : a;
		a = a < 0 ? a + 36000.0 : a;
		set_osx(e, distv, disth);
		if (distv >= disth && a > 18000)
			draw_colone(e, disth, i, RED);
		else if (distv >= disth && a <= 18000)
			draw_colone(e, disth, i, YELLOW);
		else if (a >= 9000 && a < 27000)
			draw_colone(e, distv, i, BLUE);
		else
			draw_colone(e, distv, i, GREEN);
	}
	minimap(e);
}
