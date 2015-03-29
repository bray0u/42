/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 19:02:24 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/25 20:37:13 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		put_pixel_to_img(t_env *e, int x, int y, int color)
{
	int		i;
	t_rgb	rgb;

	rgb.color = color;
	i = y * e->img.l + x * 4;
	e->img.data[i] = rgb.rgb.r;
	e->img.data[i + 1] = rgb.rgb.g;
	e->img.data[i + 2] = rgb.rgb.b;
}

void			draw(t_env *e)
{
	double	x;
	double	y;

	y = 0;
	while (y < YSIZE)
	{
		x = 0;
		while (x < XSIZE)
		{
			put_pixel_to_img(e, (int)x, (int)y,
					e->get_col[e->col](e, e->get_fract[e->fract](e, x, y)));
			x++;
		}
		y++;
	}
}
