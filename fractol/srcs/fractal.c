/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 19:10:01 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/27 17:09:09 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	mandelbrot(t_env *e, double x, double y)
{
	t_cpx	new;
	t_cpx	old;
	t_cpx	c;
	size_t	i;

	c.r = (HALFX / HALFY) * (x - HALFX) / (e->zoom * HALFX) + e->movex - 0.5;
	c.i = (y - HALFY) / (e->zoom * HALFY) + e->movey;
	new.r = 0;
	new.i = 0;
	i = 0;
	while (i < e->citer)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = SQ(old.r) - SQ(old.i) + c.r;
		new.i = 2.0 * old.r * old.i + c.i;
		if (SQ(new.r) + SQ(new.i) > 4)
			return (i);
		i++;
	}
	return (e->citer);
}

size_t	burning_ship(t_env *e, double x, double y)
{
	t_cpx	new;
	t_cpx	old;
	t_cpx	c;
	size_t	i;

	c.r = (HALFX / HALFY) * (x - HALFX) / (e->zoom * HALFX) + e->movex - 0.5;
	c.i = (y - HALFY) / (e->zoom * HALFY) + e->movey - 0.5;
	new.r = 0;
	new.i = 0;
	i = 0;
	while (i < e->citer)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = SQ(old.r) - SQ(old.i) + c.r;
		new.i = 2.0 * ABS(old.r * old.i) + c.i;
		if (SQ(new.r) + SQ(new.i) > 4)
			return (i);
		i++;
	}
	return (e->citer);
}

size_t	julia(t_env *e, double x, double y)
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
		new.r = SQ(old.r) - SQ(old.i) + c.r;
		new.i = 2.0 * old.r * old.i + c.i;
		if (SQ(new.r) + SQ(new.i) > 4)
			return (i);
		i++;
	}
	return (e->citer);
}

size_t	trimandel(t_env *e, double x, double y)
{
	t_cpx	new;
	t_cpx	old;
	t_cpx	c;
	size_t	i;

	c.r = (HALFX / HALFY) * (x - HALFX) / (0.7 * e->zoom * HALFX) + e->movex;
	c.i = (y - HALFY) / (0.8 * e->zoom * HALFY) + e->movey + 0.3;
	new.r = 0;
	new.i = 0;
	i = 0;
	while (i < e->citer)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = 2.0 * old.r * old.i + c.r;
		new.i = SQ(old.r) - SQ(old.i) + c.i;
		if (SQ(new.r) + SQ(new.i) > 5)
			return (i);
		i++;
	}
	return (e->citer);
}

size_t	weird(t_env *e, double x, double y)
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
		new.i = 2.0 * SQ(old.r * old.i) - 3.0 * ABS(old.r * old.i) + c.r;
		new.r = SQ(old.r) - SQ(old.i) + c.i;
		if (SQ(new.r) + SQ(new.i) > 5)
			return (i);
		i++;
	}
	return (e->citer);
}
