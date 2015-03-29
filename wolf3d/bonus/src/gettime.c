/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 04:38:17 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/12 14:49:13 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mkart.h"

int	get_dizaine(double time)
{
	return ((int)time / 10 % 10);
}

int	get_unit(double time)
{
	return ((int)time % 10);
}

int	get_dixieme(double time)
{
	return ((int)(time * 10.0) % 10);
}

int	get_centieme(double time)
{
	return ((int)(time * 100.0) % 10);
}
