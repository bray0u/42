/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 18:19:49 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/12 14:48:59 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mkart.h"

static void	put_sprite(t_env *e, t_coord pos, t_coord os, int sprite)
{
	int	i;
	int	j;

	i = (int)(os.y + sprite * e->kar.x) *
		e->kar.l + (((int)os.x * e->kar.bpp) >> 3);
	j = (int)pos.y * e->img.l + (((int)pos.x * e->img.bpp) >> 3);
	if ((t_byte)e->kar.data[i] != 51
		&& (t_byte)e->kar.data[i + 1] != 255
		&& (t_byte)e->kar.data[i + 2] != 51)
	{
		e->img.data[j] = e->kar.data[i];
		e->img.data[j + 1] = e->kar.data[i + 1];
		e->img.data[j + 2] = e->kar.data[i + 2];
	}
}

static int	set_sprite(t_env *e)
{
	if (e->key_events[2].is_press && !e->key_events[1].is_press)
		return (1);
	else if (e->key_events[1].is_press && !e->key_events[2].is_press)
		return (2);
	return (0);
}

void		put_player(t_env *e)
{
	t_coord pos;
	t_coord	os;

	os.y = 0;
	pos.y = YSIZE / 2.0 - 58.0;
	while (pos.y < YSIZE / 2.0 + 38.0)
	{
		os.x = 0;
		pos.x = XSIZE / 2.0 - 48.0;
		while (pos.x < XSIZE / 2.0 + 48.0)
		{
			put_sprite(e, pos, os, set_sprite(e));
			pos.x++;
			os.x = (pos.x - (XSIZE / 2.0 - 48.0)) / 3.0;
		}
		pos.y++;
		os.y = (pos.y - (YSIZE / 2.0 - 58.0)) / 3.0;
	}
}

static int	get_flo_color(t_env *e, double x, double y)
{
	t_rgb	rgb;
	int		i;

	x *= (double)e->flo.x;
	y *= (double)e->flo.y;
	i = (int)y * e->flo.l + (((int)x * e->flo.bpp) >> 3);
	rgb.rgb.r = e->flo.data[i];
	rgb.rgb.g = e->flo.data[i + 1];
	rgb.rgb.b = e->flo.data[i + 2];
	return (rgb.color);
}

void		cast_floor(t_env *e, int col, int row, double beta)
{
	double	adist;
	double	a;
	t_coord	pix;

	a = e->player.angle_3000 - (double)col / e->xsize_6000;
	a = a >= 36000 ? a - 36000.0 : a;
	a = a < 0 ? a + 36000.0 : a;
	while (row < YSIZE)
	{
		adist = beta < 36000 && beta >= 0 ?
			e->sdist[row] / e->cos[(int)beta] : e->sdist[row];
		pix.x = (adist * e->cos[(int)a]) + (e->cam.x);
		pix.y = (-adist * e->sin[(int)a]) + (e->cam.y);
		pix.x = pix.x / (double)e->mur.x;
		pix.y = pix.y / (double)e->mur.y;
		pix.x *= 20.0;
		pix.y *= 20.0;
		if (pix.x >= 1.0 || pix.y >= 1.0 || pix.x < 0.0 || pix.y < 0.0)
			mlx_put_pixel_to_img(e, col, row, GREEN);
		else
			mlx_put_pixel_to_img(e, col, row, get_flo_color(e, pix.x, pix.y));
		row++;
	}
}
