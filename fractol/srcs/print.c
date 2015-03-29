/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 18:41:55 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/26 23:07:11 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(char *str)
{
	if (!str)
		ft_putstr("Too few arguments...");
	else
	{
		ft_putstr("Bad arguments: ");
		ft_putstr(str);
	}
	ft_putstr("\nUsage: ./fractol [-c] [fractal]\n");
	ft_putstr(" -c : Show commands list\nFractals list:\n");
	ft_putstr(" julia\n mandelbrot\n burningship\n trimandel\n weird\n");
	ft_putstr(" weird2\n");
	exit(0);
}

void	print_bind(void)
{
	ft_putstr("Raccourcis :\n");
	ft_putstr(" C = changer de coloration\n");
	ft_putstr(" F = changer de fractal\n");
	ft_putstr(" + ou molette haut = Zoomer\n");
	ft_putstr(" - ou molette bas = Dezoomer\n");
	ft_putstr(" * = augmenter les iterations\n");
	ft_putstr(" / = reduire les iterations\n");
	ft_putstr(" m = desactive ou active la modification");
	ft_putstr(" de constante de julia a la souris\n");
	ft_putstr("\nDeplacement avec les fleches clavier ou clic gauche\n");
}
