/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 11:53:31 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/12 14:49:47 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mkart.h"

void	compute_pos(t_env *e, t_coord *newpos)
{
	if (check_pos(e, newpos->x, newpos->y))
	{
		e->player.pos.x = newpos->x;
		e->player.pos.y = newpos->y;
	}
	else if (newpos->y >= 0.0 && newpos->y < (double)e->mur.y
			&& newpos->x >= 0.0 && newpos->x < (double)e->mur.x)
	{
		if (check_pos(e, (newpos->x), (e->player.pos.y)))
			e->player.pos.x = newpos->x;
		else if (check_pos(e, e->player.pos.x, newpos->y))
			e->player.pos.y = newpos->y;
	}
}

void	key_event_esc(t_env *e)
{
	free_all(e);
	exit(0);
}

void	key_event_r(t_env *e)
{
	int	i;

	i = 0;
	e->player.pos.x = 86.0 / 20.0 + 0.5;
	e->player.pos.y = 460.0 / 20.0 + 0.5;
	e->player.angle = ANGLE;
	e->resetclock = clock();
	e->inter = 0;
	e->tour = 0;
	e->ral = 0;
	e->fin = 0;
	while (i < MTOUR)
		e->run[i++] = 0;
}
