/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 18:19:49 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/12 14:23:53 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	get_cei_color(t_env *e, double x, double y, int row)
{
	t_rgb	rgb;
	int		i;
	double	grad;

	grad = ABS(row - e->ysize_2) / (e->ysize_2);
	x *= e->cei.y;
	y *= e->cei.y;
	x = x >= 0 ? x : x + e->cei.y;
	y = y >= 0 ? y : y + e->cei.y;
	i = (int)y * e->cei.l + (int)x * e->cei.bpp / 8;
	rgb.rgb.r = (t_byte)(e->cei.data[i]) * grad;
	rgb.rgb.g = (t_byte)(e->cei.data[i + 1]) * grad;
	rgb.rgb.b = (t_byte)(e->cei.data[i + 2]) * grad;
	return (rgb.color);
}

static int	get_flo_color(t_env *e, double x, double y, int row)
{
	t_rgb	rgb;
	int		i;
	double	grad;

	grad = ABS(row - e->ysize_2) / (e->ysize_2);
	x *= e->flo.y;
	y *= e->flo.y;
	x = x >= 0 ? x : x + e->flo.y;
	y = y >= 0 ? y : y + e->flo.y;
	i = (int)y * e->flo.l + (int)x * e->flo.bpp / 8;
	rgb.rgb.r = (t_byte)(e->flo.data[i]) * grad;
	rgb.rgb.g = (t_byte)(e->flo.data[i + 1]) * grad;
	rgb.rgb.b = (t_byte)(e->flo.data[i + 2]) * grad;
	return (rgb.color);
}

void		cast_ceil(t_env *e, int col, double beta, int stop)
{
	double	sdist;
	double	adist;
	double	a;
	t_coord	pix;
	int		row;

	row = 0;
	a = e->player.angle_3000 - (double)col / e->xsize_6000;
	a = a >= 36000 ? a - 36000.0 : a;
	a = a < 0 ? a + 36000.0 : a;
	while (row < stop)
	{
		sdist = (double)((e->ysize_2) / ABS(e->ysize_2 - row))
			* (e->proj_dist / YSIZE);
		adist = beta < 36000 && beta >= 0 ? sdist / e->cos[(int)beta] : sdist;
		pix.x = (adist * e->cos[(int)a]) + e->player.pos.x;
		pix.y = (-adist * e->sin[(int)a]) + e->player.pos.y;
		pix.x = (pix.x - (int)pix.x);
		pix.y = (pix.y - (int)pix.y);
		mlx_put_pixel_to_img(e, col, row, get_cei_color(e, pix.x, pix.y, row));
		row++;
	}
}

void		cast_floor(t_env *e, int col, int row, double beta)
{
	double	sdist;
	double	adist;
	double	a;
	t_coord	pix;

	a = e->player.angle_3000 - (double)col / e->xsize_6000;
	a = a >= 36000 ? a - 36000.0 : a;
	a = a < 0 ? a + 36000.0 : a;
	while (row < YSIZE)
	{
		sdist = (double)((e->ysize_2) / (row - e->ysize_2))
			* (e->proj_dist / YSIZE);
		adist = beta < 36000 && beta >= 0 ? sdist / e->cos[(int)beta] : sdist;
		pix.x = (adist * e->cos[(int)a]) + e->player.pos.x;
		pix.y = (-adist * e->sin[(int)a]) + e->player.pos.y;
		pix.x = (pix.x - (int)pix.x);
		pix.y = (pix.y - (int)pix.y);
		mlx_put_pixel_to_img(e, col, row, get_flo_color(e, pix.x, pix.y, row));
		row++;
	}
}
