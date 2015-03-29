/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 11:53:31 by gexbraya          #+#    #+#             */
/*   Updated: 2015/02/06 17:48:57 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_event_key_s(t_env *e)
{
	t_coord		newpos;

	newpos.x = e->player.pos.x - e->speed * e->cos[e->player.angle];
	newpos.y = e->player.pos.y + e->speed * e->sin[e->player.angle];
	newpos.y = (double)((int)(newpos.y * 10000)) / 10000.0;
	newpos.x = (double)((int)(newpos.x * 10000)) / 10000.0;
	newpos.y = (double)(newpos.y - (int)newpos.y) > 0.0 ?
		newpos.y : newpos.y + 0.0001;
	newpos.x = (double)(newpos.x - (int)newpos.x) > 0.0 ?
		newpos.x : newpos.x + 0.0001;
	compute_pos(e, &newpos);
}

void	key_event_key_w(t_env *e)
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

void	key_event_key_a(t_env *e)
{
	t_coord		newpos;
	int			angle;

	angle = e->player.angle + 9000;
	angle %= 36000;
	newpos.x = e->player.pos.x + e->speed * e->cos[angle];
	newpos.y = e->player.pos.y - e->speed * e->sin[angle];
	newpos.y = (double)((int)(newpos.y * 10000)) / 10000.0;
	newpos.x = (double)((int)(newpos.x * 10000)) / 10000.0;
	newpos.y = (double)(newpos.y - (int)newpos.y) > 0.0 ?
		newpos.y : newpos.y + 0.0001;
	newpos.x = (double)(newpos.x - (int)newpos.x) > 0.0 ?
		newpos.x : newpos.x + 0.0001;
	compute_pos(e, &newpos);
}

void	key_event_key_d(t_env *e)
{
	t_coord		newpos;
	int			angle;

	angle = e->player.angle - 9000;
	angle += 36000;
	angle %= 36000;
	newpos.x = e->player.pos.x + e->speed * e->cos[angle];
	newpos.y = e->player.pos.y - e->speed * e->sin[angle];
	newpos.y = (double)((int)(newpos.y * 10000)) / 10000.0;
	newpos.x = (double)((int)(newpos.x * 10000)) / 10000.0;
	newpos.y = (double)(newpos.y - (int)newpos.y) > 0.0 ?
		newpos.y : newpos.y + 0.0001;
	newpos.x = (double)(newpos.x - (int)newpos.x) > 0.0 ?
		newpos.x : newpos.x + 0.0001;
	compute_pos(e, &newpos);
}
