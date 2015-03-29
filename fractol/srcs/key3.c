/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 21:14:39 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/24 21:24:10 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_event_star(t_env *e)
{
	e->citer += 16;
	if (e->citer > MAXCOUNT)
		e->citer = MAXCOUNT;
	expose_hook(e);
}

void	key_event_slash(t_env *e)
{
	e->citer -= 16;
	if (e->citer < MINCOUNT)
		e->citer = MINCOUNT;
	expose_hook(e);
}
