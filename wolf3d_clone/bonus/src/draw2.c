/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 00:15:54 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/12 14:48:56 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mkart.h"

void		put_mili(t_env *e, double x, double y, int num)
{
	t_coord	pos;
	int		i;
	int		j;

	pos.y = 0;
	while (pos.y < 30)
	{
		pos.x = 0;
		while (pos.x < 26)
		{
			i = (int)pos.y * e->mil.l +
				(((int)(pos.x + num * 26) * e->mil.bpp) >> 3);
			j = (int)(pos.y + y) * e->img.l +
				(((int)(pos.x + x) * e->img.bpp) >> 3);
			e->img.data[j] = e->mil.data[i];
			e->img.data[j + 1] = e->mil.data[i + 1];
			e->img.data[j + 2] = e->mil.data[i + 2];
			pos.x++;
		}
		pos.y++;
	}
}

void		put_secb(t_env *e, double x, double y, int num)
{
	t_coord	pos;
	int		i;
	int		j;

	pos.y = 0;
	while (pos.y < 52)
	{
		pos.x = 0;
		while (pos.x < 50)
		{
			i = (int)pos.y * e->sb.l +
				(((int)(pos.x + num * 50) * e->sb.bpp) >> 3);
			j = (int)(pos.y + y) * e->img.l +
				(((int)(pos.x + x) * e->img.bpp) >> 3);
			e->img.data[j] = e->sb.data[i];
			e->img.data[j + 1] = e->sb.data[i + 1];
			e->img.data[j + 2] = e->sb.data[i + 2];
			pos.x++;
		}
		pos.y++;
	}
}

void		put_secr(t_env *e, double x, double y, int num)
{
	t_coord	pos;
	int		i;
	int		j;

	pos.y = 0;
	while (pos.y < 52)
	{
		pos.x = 0;
		while (pos.x < 50)
		{
			i = (int)pos.y * e->sr.l +
				(((int)(pos.x + num * 50) * e->sr.bpp) >> 3);
			j = (int)(pos.y + y) * e->img.l +
				(((int)(pos.x + x) * e->img.bpp) >> 3);
			e->img.data[j] = e->sr.data[i];
			e->img.data[j + 1] = e->sr.data[i + 1];
			e->img.data[j + 2] = e->sr.data[i + 2];
			pos.x++;
		}
		pos.y++;
	}
}

void		put_score(t_env *e)
{
	t_coord	pos;
	double	total;
	int		i;

	i = 0;
	total = 0;
	while (i < MTOUR)
		total += e->run[i++];
	pos.x = XSIZE - 176;
	pos.y = 20;
	put_secr(e, 20, pos.y, e->tour + 1);
	put_secr(e, pos.x, pos.y, get_dizaine(e->run[e->tour]));
	put_secr(e, pos.x + 52.0, pos.y, get_unit(e->run[e->tour]));
	put_mili(e, pos.x + 104.0, pos.y, get_dixieme(e->run[e->tour]));
	put_mili(e, pos.x + 130.0, pos.y, get_centieme(e->run[e->tour]));
	pos.y += 60;
	put_secb(e, pos.x, pos.y, get_dizaine(total));
	put_secb(e, pos.x + 52.0, pos.y, get_unit(total));
	put_mili(e, pos.x + 104.0, pos.y, get_dixieme(total));
	put_mili(e, pos.x + 130.0, pos.y, get_centieme(total));
}

void		put_speed(t_env *e)
{
	t_coord	os;
	t_coord	pos;
	t_rgb	rgb;

	rgb.rgb.b = 255;
	rgb.rgb.r = 0;
	os.x = XSIZE - 25;
	os.y = YSIZE - 105;
	pos.y = 0;
	while (pos.y < 100)
	{
		pos.x = 0;
		while (pos.x < 20)
		{
			rgb.rgb.g = ABS((ABS(pos.y - 100) / 100 * 255) - 255);
			if (ABS(pos.y - 100) <= ABS((e->speed / MSPEED) * 5000.0))
				mlx_put_pixel_to_img(e, os.x + pos.x, os.y + pos.y, rgb.color);
			else
				mlx_put_pixel_to_img(e, os.x + pos.x, os.y + pos.y, BLACK);
			pos.x++;
		}
		pos.y++;
	}
}
