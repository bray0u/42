/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 21:11:29 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/27 19:27:59 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	weird2(t_env *e, double x, double y)
{
	t_cpx	new;
	t_cpx	old;
	t_cpx	c;
	size_t	i;

	i = 0;
	c = e->juliac;
	new.r = (HALFX / HALFY) * (x - HALFX) / (e->zoom * HALFX) + e->movex;
	new.i = (y - HALFY) / (e->zoom * HALFY) + e->movey;
	while (i < e->citer)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = (old.i * old.i * old.i) - (old.r * old.r * old.r) + (2.0 * c.r);
		new.i = 2.0 * old.i * old.r * (2.0 * c.i);
		if (SQ(new.r) + SQ(new.i) > 4)
			return (i);
		i++;
	}
	return (e->citer);
}
