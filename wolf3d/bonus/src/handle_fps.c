/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:45:43 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/12 14:49:18 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mkart.h"

static void		put_sprite(t_env *e, t_coord pos, t_coord os, int sprite)
{
	int	i;
	int	j;

	i = (int)(os.y + sprite * 40) * e->sta.l + (((int)os.x * e->sta.bpp) >> 3);
	j = (int)pos.y * e->img.l + (((int)pos.x * e->img.bpp) >> 3);
	if (!((t_byte)e->sta.data[i] == 0
			&& (t_byte)e->sta.data[i + 1] == 255
			&& (t_byte)e->sta.data[i + 2] == 255))
	{
		e->img.data[j] = e->sta.data[i];
		e->img.data[j + 1] = e->sta.data[i + 1];
		e->img.data[j + 2] = e->sta.data[i + 2];
	}
}

static void		get_speed(t_env *e)
{
	if (e->start >= 3)
	{
		if (e->speed >= 0)
		{
			e->speed = e->speed - (MSPEED / (double)e->fps / 100.0 * e->ral);
			if (e->speed < 0)
				e->speed = 0;
		}
		else
		{
			e->speed = e->speed + (MSPEED / (double)e->fps / 100.0 * e->ral);
			if (e->speed > 0)
				e->speed = 0;
		}
	}
}

void			put_start(t_env *e)
{
	t_coord pos;
	t_coord	os;

	os.y = 0;
	pos.y = 50;
	while (e->start < 4 && pos.y < 170)
	{
		os.x = 0;
		pos.x = 70;
		while (pos.x < 175)
		{
			put_sprite(e, pos, os, e->start);
			pos.x++;
			os.x = (pos.x - 70) / 3.0;
		}
		pos.y++;
		os.y = (pos.y - 50) / 3.0;
	}
}

static void		new_pos(t_env *e)
{
	t_coord		newpos;

	newpos.x = e->player.pos.x + e->speed * e->cos[e->player.angle];
	newpos.y = e->player.pos.y - e->speed * e->sin[e->player.angle];
	newpos.y = (double)((int)(newpos.y * 10000)) / 10000.0;
	newpos.x = (double)((int)(newpos.x * 10000)) / 10000.0;
	newpos.y = (double)(newpos.y - (int)newpos.y) > 0.0 ?
		newpos.y : newpos.y + 0.0001;
	newpos.x = (double)(newpos.x - (int)newpos.x) > 0.0 ?
		newpos.x : newpos.x + 0.0001;
	compute_pos(e, &newpos);
}

void			set_fps(t_env *e)
{
	clock_t	newclock;

	if (!e->key_events[3].is_press && !e->key_events[4].is_press)
		get_speed(e);
	new_pos(e);
	check_finish(e, e->player.pos.x, e->player.pos.y);
	newclock = clock();
	e->fps = newclock > e->lastclock ?
		CLOCKS_PER_SEC / (newclock - e->lastclock) : 10;
	e->rot = 10000.0 / (double)e->fps;
	e->lastclock = newclock;
	e->start = (newclock - e->resetclock) / CLOCKS_PER_SEC;
	if (e->start < 3)
	{
		e->speed = 0;
		e->rot = 0;
		e->tourclock = newclock;
	}
	else
	{
		e->run[e->tour] = ((newclock - (double)e->tourclock)
				/ (double)CLOCKS_PER_SEC) / 5.0 * 6.0;
	}
}
