/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/14 12:17:33 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/26 22:09:41 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mkart.h"

static void		draw_sky(t_env *e, int x)
{
	int	y;

	y = 0;
	while (y < YSIZE / 5)
	{
		mlx_put_pixel_to_img(e, x, y, SKY);
		y++;
	}
}

static void		set_cam(t_env *e)
{
	double	alpha;

	alpha = e->player.angle - 18000.0;
	alpha = alpha >= 0 ? alpha : alpha + 36000.0;
	e->cam.x = (2.5 * e->cos[(int)alpha]) + e->player.pos.x;
	e->cam.y = (-2.5 * e->sin[(int)alpha]) + e->player.pos.y;
}

void			mlx_put_pixel_to_img(t_env *e, int x, int y, int color)
{
	int		i;
	t_rgb	rgb;

	rgb.color = color;
	i = y * e->img.l + ((x * e->img.bpp) >> 3);
	e->img.data[i] = rgb.rgb.r;
	e->img.data[i + 1] = rgb.rgb.g;
	e->img.data[i + 2] = rgb.rgb.b;
}

int				check_pos(t_env *e, double x, double y)
{
	int	i;

	x *= 20.0;
	y *= 20.0;
	i = (int)y * e->mur.l + (((int)x * e->mur.bpp) >> 3);
	if ((t_byte)e->mur.data[i] == 0 && x >= 0.0 && x < (double)e->mur.x
			&& y >= 0.0 && y < (double)e->mur.y)
		return (0);
	else if ((t_byte)e->mur.data[i] == 112)
	{
		e->ral = 2;
		return (1);
	}
	e->ral = 1;
	return (1);
}

void			draw(t_env *e)
{
	int			i;
	double		beta;

	e->player.angle_3000 = (double)(e->player.angle) + 3000.0;
	set_cam(e);
	i = 0;
	while (i < XSIZE)
	{
		beta = i < e->xsize_2 ? 0.0 - (e->xsize_6k * ((double)i - e->xsize_2))
			: 36000.0 - (e->xsize_6k * ((double)i - e->xsize_2));
		draw_sky(e, i);
		cast_floor(e, i, YSIZE / 5, beta);
		i++;
	}
	put_player(e);
	put_start(e);
	put_speed(e);
	put_score(e);
	mlx_do_sync(e->mlx);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
}
