/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 01:41:11 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/12 14:49:04 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mkart.h"

static void	print_final(t_env *e)
{
	t_coord pos;

	pos.y = 0;
	while (pos.y < YSIZE)
	{
		pos.x = 0;
		while (pos.x < XSIZE)
		{
			mlx_put_pixel_to_img(e, pos.x, pos.y, SKY);
			pos.x++;
		}
		pos.y++;
	}
}

static void print_tour(t_env *e, double x, double y, int tour)
{
	put_secr(e, x, y, get_dizaine(e->run[tour]));
	put_secr(e, x + 52.0, y, get_unit(e->run[tour]));
	put_mili(e, x + 104.0, y, get_dixieme(e->run[tour]));
	put_mili(e, x + 130.0, y, get_centieme(e->run[tour]));
}

static void print_score(t_env *e)
{
	int		i;
	double	total;
	t_coord pos;

	i = 0;
	total = 0;
	pos.x = (XSIZE - 152) / 2;
	pos.y = (YSIZE - MTOUR * 60) / 2;
	while (i < MTOUR)
	{
		total += e->run[i];
		print_tour(e, pos.x, pos.y, i);
		pos.y += 60;
		i++;
	}
	put_secb(e, pos.x, pos.y, get_dizaine(total));
	put_secb(e, pos.x + 52.0, pos.y, get_unit(total));
	put_mili(e, pos.x + 104.0, pos.y, get_dixieme(total));
	put_mili(e, pos.x + 130.0, pos.y, get_centieme(total));
}

static void	finish(t_env *e)
{
	e->tourclock = clock();
	e->tour++;
	e->inter = 0;
	if (e->tour == MTOUR)
	{
		e->fin = 1;
		print_final(e);
		print_score(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	}
}

void		check_finish(t_env *e, double x, double y)
{
	int	j;

	x *= 20.0;
	y *= 20.0;
	j = (int)y * e->cp.l + (((int)x * e->cp.bpp) >> 3);
	if ((t_byte)e->cp.data[j + 2] == 255)
		e->inter = 1;
	if ((t_byte)e->cp.data[j + 1] == 255 && e->inter)
		finish(e);
}
