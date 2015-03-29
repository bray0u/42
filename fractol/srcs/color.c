/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 12:10:15 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/25 23:31:47 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	color_blue(t_env *e, size_t i)
{
	t_rgb	rgb;

	if (i == e->citer)
		return (BLACK);
	rgb.rgb.r = 155.0 / e->citer * (double)i + 100;
	rgb.rgb.g = 155.0 / e->citer * (double)i + 100;
	rgb.rgb.b = 0;
	return (rgb.color);
}

size_t	color_green(t_env *e, size_t i)
{
	t_rgb	rgb;

	if (i == e->citer)
		return (BLACK);
	rgb.rgb.r = 0;
	rgb.rgb.g = 155.0 / e->citer * (double)i + 100;
	rgb.rgb.b = 0;
	return (rgb.color);
}

size_t	color_red(t_env *e, size_t i)
{
	t_rgb	rgb;

	if (i == e->citer)
		return (BLACK);
	rgb.rgb.r = 0;
	rgb.rgb.b = 155.0 / e->citer * (double)i + 100;
	rgb.rgb.g = rgb.rgb.b * 1.0 / 3.0;
	return (rgb.color);
}

size_t	color_white(t_env *e, size_t i)
{
	t_rgb	rgb;

	if (i == e->citer)
		return (BLACK);
	rgb.rgb.r = 155.0 / e->citer * (double)i + 100;
	rgb.rgb.g = 155.0 / e->citer * (double)i + 100;
	rgb.rgb.b = 155.0 / e->citer * (double)i + 100;
	return (rgb.color);
}

size_t	color_rand(t_env *e, size_t i)
{
	if (i != e->citer)
		return (e->color[i]);
	return (BLACK);
}
