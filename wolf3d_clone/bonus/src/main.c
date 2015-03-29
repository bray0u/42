/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 11:53:31 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/17 12:51:50 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mkart.h"

int				key_hook_press(int keycode, t_env *e)
{
	int		i;

	i = 0;
	while (i < KEYS)
	{
		if (e->key_events[i].keycode == keycode)
		{
			if (e->key_events[i].is_press == 0)
				e->key_events[i].is_press = 1;
			break ;
		}
		i++;
	}
	return (0);
}

int				key_hook_release(int keycode, t_env *e)
{
	int		i;

	i = 0;
	while (i < KEYS)
	{
		if (e->key_events[i].keycode == keycode)
		{
			if (e->key_events[i].is_press == 1)
				e->key_events[i].is_press = 0;
			break ;
		}
		i++;
	}
	return (0);
}

int				loop_hook(t_env *e)
{
	int		i;

	i = 0;
	while (i < KEYS)
	{
		if (e->key_events[i].is_press)
			e->key_events[i].event(e);
		i++;
	}
	set_fps(e);
	if (!e->fin)
		draw(e);
	else
	{
		mlx_do_sync(e->mlx);
		mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_env	e;

	if (ac != 1)
		usage(av[0]);
	key_event_r(&e);
	init_trigo(&e);
	init_events(&e);
	init_mlx(&e);
	init_sdist(&e);
	mlx_hook(e.win, 2, 0, key_hook_press, &e);
	mlx_hook(e.win, 3, 1, key_hook_release, &e);
	mlx_loop_hook(e.mlx, &loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
