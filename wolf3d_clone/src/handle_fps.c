/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 15:45:43 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/17 12:39:18 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		set_speed(t_env *e)
{
	if (e->key_events[3].is_press && e->key_events[5].is_press)
		e->speed *= 0.75;
	if (e->key_events[3].is_press && e->key_events[6].is_press)
		e->speed *= 0.75;
	if (e->key_events[4].is_press && e->key_events[5].is_press)
		e->speed *= 0.75;
	if (e->key_events[4].is_press && e->key_events[6].is_press)
		e->speed *= 0.75;
}

void			set_fps(t_env *e)
{
	clock_t	newclock;

	newclock = clock();
	e->fps = CLOCKS_PER_SEC / (newclock - e->lastclock);
	e->speed = SPEED / (double)e->fps;
	set_speed(e);
	e->rot = ROTSPEED / (double)e->fps;
	e->lastclock = newclock;
	e->frame++;
	if (e->frame > e->fps / 24)
	{
		e->gif++;
		e->frame = 0;
	}
	if (e->gif > 52)
		e->gif = 0;
}
