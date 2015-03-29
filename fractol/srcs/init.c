/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 16:17:52 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/27 19:28:21 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_key	get_key_event(int keycode, void (*event)(t_env *e))
{
	t_key	key;

	key.keycode = keycode;
	key.event = event;
	return (key);
}

void			init_color(t_env *e)
{
	int		i;

	i = 0;
	e->get_col[0] = &color_green;
	e->get_col[1] = &color_red;
	e->get_col[2] = &color_blue;
	e->get_col[3] = &color_white;
	e->get_col[4] = &color_rand;
	while (i < RANDCOLOR)
	{
		e->color[i] = (rand() % 16777214);
		i++;
	}
}

void			init_env(t_env *e)
{
	e->activem = 1;
	e->zoom = 0.5;
	e->movex = 0;
	e->movey = 0;
	e->citer = 16;
	e->juliac.r = -0.7;
	e->juliac.i = 0.27015;
	e->col = 0;
}

void			init_events(t_env *e)
{
	e->key_events[0] = get_key_event(ESC, &key_event_esc);
	e->key_events[1] = get_key_event(LEFT, &key_event_left);
	e->key_events[2] = get_key_event(RIGHT, &key_event_right);
	e->key_events[3] = get_key_event(UP, &key_event_up);
	e->key_events[4] = get_key_event(DOWN, &key_event_down);
	e->key_events[5] = get_key_event(PLUS, &key_event_plus);
	e->key_events[6] = get_key_event(MINUS, &key_event_minus);
	e->key_events[7] = get_key_event(KEY_F, &key_event_f);
	e->key_events[8] = get_key_event(KEY_C, &key_event_c);
	e->key_events[9] = get_key_event(KEY_M, &key_event_m);
	e->key_events[10] = get_key_event(STAR, &key_event_star);
	e->key_events[11] = get_key_event(SLASH, &key_event_slash);
	e->get_fract[0] = &julia;
	e->get_fract[1] = &mandelbrot;
	e->get_fract[2] = &burning_ship;
	e->get_fract[3] = &trimandel;
	e->get_fract[4] = &weird;
	e->get_fract[5] = &weird2;
}
