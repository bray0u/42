/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 18:17:56 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/26 22:05:43 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				expose_hook(t_env *e)
{
	if (e->zoom < 0.5)
		e->zoom = 0.5;
	if (e->movex < -2)
		e->movex = -2;
	if (e->movey < -2)
		e->movey = -2;
	if (e->movex > 2)
		e->movex = 2;
	if (e->movey > 2)
		e->movey = 2;
	draw(e);
	mlx_do_sync(e->mlx);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

static int		key_hook(int keycode, t_env *e)
{
	int	i;

	i = 0;
	while (i < KEYS)
	{
		if (e->key_events[i].keycode == keycode)
			e->key_events[i].event(e);
		i++;
	}
	return (0);
}

static int		pointer_handle(int x, int y, t_env *e)
{
	if (e->activem && (!e->fract || e->fract > 3))
	{
		e->juliac.r = (x - HALFX) / HALFX;
		e->juliac.i = (y - HALFY) / HALFY;
		expose_hook(e);
	}
	return (0);
}

static int		scroll_handle(int button, int x, int y, t_env *e)
{
	if (button == 4)
		e->zoom *= 1.1;
	if (button == 5)
		e->zoom /= 1.1;
	if (button == 1 || button == 4 || button == 5)
	{
		e->movex = (HALFX / HALFY) * (x - HALFX) / (e->zoom * HALFX) + e->movex;
		e->movey = (y - HALFY) / (e->zoom * HALFY) + e->movey;
		expose_hook(e);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_env	e;

	parse_args(&e, argc, argv);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, (int)XSIZE, (int)YSIZE, "fractol");
	e.img.img = mlx_new_image(e.mlx, XSIZE, YSIZE);
	e.img.data = mlx_get_data_addr(e.img.img, &e.img.bpp, &e.img.l, &e.img.e);
	init_env(&e);
	init_events(&e);
	init_color(&e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_hook(e.win, 6, 5, &pointer_handle, &e);
	mlx_hook(e.win, 4, 4, &scroll_handle, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
