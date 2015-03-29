/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 11:53:31 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/25 21:43:49 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		expose_hook(t_env *e)
{
	draw(e);
	mlx_do_sync(e->mlx);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

int				key_hook_press(int keycode, t_env *e)
{
	int		i;

	i = 0;
	if (keycode == KEY_B)
		e->bot = 1;
	if (keycode == KEY_N)
		bot_stop(e);
	while (!e->bot && i < KEYS)
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
	while (!e->bot && i < KEYS)
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
	if (e->bot)
		bot_run(e);
	while (i < KEYS)
	{
		if (e->key_events[i].is_press)
			e->key_events[i].event(e);
		i++;
	}
	set_fps(e);
	expose_hook(e);
	return (0);
}

int				main(int ac, char **av)
{
	t_env	e;
	int		fd;

	if (ac != 2)
		usage(av[0]);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		quit("File error\n");
	init_map(&e, fd);
	e.player.angle = ANGLE;
	close(fd);
	init_trigo(&e);
	init_events(&e);
	init_mlx(&e);
	e.gif = 0;
	e.frame = 0;
	e.lastclock = clock();
	mlx_hook(e.win, 2, 1, key_hook_press, &e);
	mlx_hook(e.win, 3, 2, key_hook_release, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
