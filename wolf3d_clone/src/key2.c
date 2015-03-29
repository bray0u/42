/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 11:53:31 by gexbraya          #+#    #+#             */
/*   Updated: 2015/02/06 17:41:22 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	set_osx(t_env *e, double distv, double disth)
{
	if (distv >= disth)
	{
		e->wall = e->wallh;
		while (e->hit.x > 1)
			e->hit.x -= 1;
		e->osx = e->wall == 2 ? e->hit.x * e->mur.x : e->hit.x * e->cat.x;
	}
	else
	{
		e->wall = e->wallv;
		while (e->hit.y > 1)
			e->hit.y -= 1;
		e->osx = e->wall == 2 ? e->hit.y * e->mur.x : e->hit.y * e->cat.x;
	}
}

void	compute_pos(t_env *e, t_coord *newpos)
{
	if (newpos->y >= 0.0 && newpos->y < (double)e->ymap
			&& newpos->x >= 0.0 && newpos->x < (double)e->xmap
			&& e->map[(int)(newpos->y)][(int)(newpos->x)] < 2)
	{
		e->player.pos.x = newpos->x;
		e->player.pos.y = newpos->y;
	}
	else if (newpos->y >= 0.0 && newpos->y < (double)e->ymap
			&& newpos->x >= 0.0 && newpos->x < (double)e->xmap)
	{
		if (e->map[(int)(newpos->y)][(int)(e->player.pos.x)] < 2)
			e->player.pos.y = newpos->y;
		else if (e->map[(int)(e->player.pos.y)][(int)(newpos->x)] < 2)
			e->player.pos.x = newpos->x;
	}
}

void	key_event_esc(t_env *e)
{
	free_all(e);
	exit(0);
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
