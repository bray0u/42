/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/12 14:49:34 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/12 14:49:37 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mkart.h"

static t_key	get_key_event(int keycode, void (*event)(t_env *e))
{
	t_key	key;

	key.keycode = keycode;
	key.is_press = 0;
	key.event = event;
	return (key);
}

void			init_sdist(t_env *e)
{
	int	row;

	row = 0;
	while (row < YSIZE / 5.0)
	{
		e->sdist[row] = (double)((e->ysize_2) / ABS(YSIZE / 5.0 - row))
			* e->proj_dist_ysize;
		row++;
	}
	while (row < YSIZE)
	{
		e->sdist[row] = (double)((e->ysize_2) / (row - YSIZE / 5.0))
			* e->proj_dist_ysize;
		row++;
	}
}

void			init_events(t_env *e)
{
	e->key_events[0] = get_key_event(ESC, &key_event_esc);
	e->key_events[1] = get_key_event(LEFT, &key_event_left);
	e->key_events[2] = get_key_event(RIGHT, &key_event_right);
	e->key_events[3] = get_key_event(UP, &key_event_up);
	e->key_events[4] = get_key_event(DOWN, &key_event_down);
	e->key_events[5] = get_key_event(KEY_R, &key_event_r);
}

void			init_trigo(t_env *e)
{
	int			i;
	double		rad;

	i = 0;
	while (i < 36000)
	{
		rad = (((double)i / (100.0)) * (2.0) * PI) / (360.0);
		(e->cos)[i] = cos(rad);
		(e->sin)[i] = sin(rad);
		(e->tan)[i] = tan(rad);
		i++;
	}
}
