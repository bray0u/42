/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 22:51:53 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/26 21:31:45 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void parse_arg(t_env *e, char *str, int *c)
{
	if (!ft_strcmp(str, "-c") && 1 + (*c = 1))
		print_bind();
	else if (!ft_strcmp(str, "julia"))
		e->fract = 0;
	else if (!ft_strcmp(str, "mandelbrot"))
		e->fract = 1;
	else if (!ft_strcmp(str, "burningship"))
		e->fract = 2;
	else if (!ft_strcmp(str, "trimandel"))
		e->fract = 3;
	else if (!ft_strcmp(str, "weird"))
		e->fract = 4;
	else if (!ft_strcmp(str, "weird2"))
		e->fract = 5;
	else
		print_usage(str);
}

void		parse_args(t_env *e, int argc, char **argv)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	e->fract = -1;
	while (++i < argc)
		parse_arg(e, argv[i], &c);
	if (e->fract == -1 && !c)
		print_usage(" Please, choose a fractal");
	else if (e->fract == -1)
		exit(0);
}
