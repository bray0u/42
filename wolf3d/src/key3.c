/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 19:54:20 by gexbraya          #+#    #+#             */
/*   Updated: 2015/02/06 17:45:44 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	bot_stop(t_env *e)
{
	int	i;

	i = 0;
	e->bot = 0;
	while (i < KEYS)
	{
		e->key_events[i].is_press = 0;
		i++;
	}
}

void	bot_run(t_env *e)
{
	int	i;

	i = 1;
	while (i < KEYS - 1)
	{
		if (rand() % 100 > 90)
			e->key_events[i].is_press =
				ABS(e->key_events[i].is_press - 1);
		i++;
	}
}
