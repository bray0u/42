/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 16:19:29 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/25 22:24:58 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_event_esc(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img.img);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

void	key_event_left(t_env *e)
{
	e->movex -= 1.0 / e->zoom;
	expose_hook(e);
}

void	key_event_right(t_env *e)
{
	e->movex += 1.0 / e->zoom;
	expose_hook(e);
}

void	key_event_up(t_env *e)
{
	e->movey -= 1.0 / e->zoom;
	expose_hook(e);
}

void	key_event_down(t_env *e)
{
	e->movey += 1.0 / e->zoom;
	expose_hook(e);
}
