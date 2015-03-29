/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 11:53:31 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/12 14:49:43 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mkart.h"

void	key_event_down(t_env *e)
{
	if (e->start >= 3)
	{
		if (e->ral == 1)
		{
			e->speed = e->speed - (MSPEED / (double)e->fps / 70.0);
			if (e->speed < 0 && e->speed < -(MSPEED / e->fps))
				e->speed = -(MSPEED / e->fps);
		}
		else
		{
			e->speed = e->speed >= 0 ?
				e->speed - (MSPEED / (double)e->fps / 70.0 * 2) :
				e->speed + (MSPEED / (double)e->fps / 70.0 * 2);
			if (e->speed < 0 && e->speed < -(MSPEED / e->fps / 3.0))
				e->speed = -(MSPEED / e->fps / 3.0);
		}
	}
}

void	key_event_up(t_env *e)
{
	if (e->start >= 3)
	{
		if (e->ral == 1)
		{
			e->speed = e->speed + (MSPEED / (double)e->fps / 70.0);
			if (e->speed > 0 && e->speed > MSPEED / e->fps)
				e->speed = MSPEED / e->fps;
		}
		else
		{
			e->speed = e->speed >= 0 ?
				e->speed - (MSPEED / (double)e->fps / 70.0 * 2) :
				e->speed + (MSPEED / (double)e->fps / 70.0 * 2);
			if (e->speed > 0 && e->speed < MSPEED / e->fps / 3.0)
				e->speed = MSPEED / e->fps / 3.0;
		}
	}
}

void	key_event_left(t_env *e)
{
	int	angle;

	angle = e->player.angle + e->rot;
	e->player.angle = angle % 36000;
}

void	key_event_right(t_env *e)
{
	int	angle;

	angle = e->player.angle - e->rot;
	angle += 36000;
	e->player.angle = angle % 36000;
}
