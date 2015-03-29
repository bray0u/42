/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 16:19:29 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/25 21:44:52 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_event_plus(t_env *e)
{
	e->zoom *= 1.5;
	expose_hook(e);
}

void	key_event_minus(t_env *e)
{
	e->zoom /= 1.5;
	expose_hook(e);
}

void	key_event_f(t_env *e)
{
	e->fract++;
	if (e->fract >= TFRACT)
		e->fract = 0;
	e->zoom = 0.5;
	e->movex = 0;
	e->movey = 0;
	expose_hook(e);
}

void	key_event_c(t_env *e)
{
	e->col++;
	if (e->col >= TCOLOR)
		e->col = 0;
	expose_hook(e);
}

void	key_event_m(t_env *e)
{
	e->activem = ABS(e->activem - 1);
}
