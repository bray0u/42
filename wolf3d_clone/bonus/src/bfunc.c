/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfunc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 14:11:35 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/12 14:48:49 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mkart.h"

static int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void			usage(char *str)
{
	write(1, "Usage: ./", 7);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}

void			quit(char *str)
{
	write(1, str, ft_strlen(str));
	exit(0);
}
