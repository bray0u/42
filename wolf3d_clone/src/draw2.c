/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 12:17:33 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/17 12:36:38 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			mlx_add_pixel_to_img(t_env *e, int x, int y, int color)
{
	int		i;
	t_rgb	rgb;

	rgb.color = color;
	i = y * e->img.l + x * e->img.bpp / 8;
	e->img.data[i] = ((t_byte)e->img.data[i] + rgb.rgb.r * 2) / 3;
	e->img.data[i + 1] = ((t_byte)e->img.data[i + 1] + rgb.rgb.g * 2) / 3;
	e->img.data[i + 2] = ((t_byte)e->img.data[i + 2] + rgb.rgb.b * 2) / 3;
}

int					get_wall_color(t_env *e, double h, int y, int color)
{
	t_rgb	rgb;
	t_rgb	old;
	int		i;
	double	g;

	if (h < 20)
		return (BLACK);
	g = YSIZE / h / 2 > 1 ? YSIZE / h / 2 : 1;
	old.color = color;
	if (e->wall == 2)
	{
		e->osy = y * e->mur.y / h;
		i = e->osy * e->mur.l + e->osx * e->mur.bpp / 8;
		rgb.rgb.r = ((old.rgb.r + (t_byte)(e->mur.data[i]) * 9) / 10) / g;
		rgb.rgb.g = ((old.rgb.g + (t_byte)(e->mur.data[i + 1]) * 9) / 10) / g;
		rgb.rgb.b = ((old.rgb.b + (t_byte)(e->mur.data[i + 2]) * 9) / 10) / g;
		return (rgb.color);
	}
	e->osy = y * e->cat.x / h;
	i = (e->osy + e->gif * e->cat.x) * e->cat.l + e->osx * e->cat.bpp / 8;
	rgb.rgb.r = ((old.rgb.r + (t_byte)(e->cat.data[i]) * 9) / 10) / g;
	rgb.rgb.g = ((old.rgb.g + (t_byte)(e->cat.data[i + 1]) * 9) / 10) / g;
	rgb.rgb.b = ((old.rgb.b + (t_byte)(e->cat.data[i + 2]) * 9) / 10) / g;
	return (rgb.color);
}

void				draw_player(int x, int y, t_env *e)
{
	mlx_add_pixel_to_img(e, x - 1, y - 1, GREEN);
	mlx_add_pixel_to_img(e, x - 1, y, GREEN);
	mlx_add_pixel_to_img(e, x, y - 1, GREEN);
	mlx_add_pixel_to_img(e, x, y, GREEN);
	mlx_add_pixel_to_img(e, x + 1, y + 1, GREEN);
	mlx_add_pixel_to_img(e, x, y + 1, GREEN);
	mlx_add_pixel_to_img(e, x + 1, y, GREEN);
	mlx_add_pixel_to_img(e, x - 1, y + 1, GREEN);
	mlx_add_pixel_to_img(e, x + 1, y - 1, GREEN);
}

void				minimap(t_env *e)
{
	int			x;
	int			y;
	int			xx;
	int			yy;

	x = 0;
	xx = XSIZE - (e->xmap * MMGRID) - 1;
	yy = YSIZE - (e->ymap * MMGRID) - 1;
	while (x < e->xmap * MMGRID)
	{
		y = 0;
		while (y < e->ymap * MMGRID)
		{
			if (e->map[y / (int)MMGRID][x / (int)MMGRID] > 1)
				mlx_add_pixel_to_img(e, x + xx, y + yy, WHITE);
			else if (e->map[y / (int)MMGRID][x / (int)MMGRID] < 2)
				mlx_add_pixel_to_img(e, x + xx, y + yy, BLACK);
			y++;
		}
		x++;
	}
	x = e->player.pos.x * MMGRID;
	y = e->player.pos.y * MMGRID;
	draw_player(x + xx, y + yy, e);
}
