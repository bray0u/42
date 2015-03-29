/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 19:48:48 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/17 12:45:52 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			free_all(t_env *e)
{
	int y;

	y = -1;
	mlx_destroy_window(e->mlx, e->win);
	while (++y < e->ymap)
		free(e->map[y]);
	free(e->map);
	free(e->cos);
	free(e->sin);
	free(e->tan);
	free(e->img.img);
	free(e->cat.img);
	free(e->mur.img);
	free(e->cei.img);
	free(e->flo.img);
	free(e->mlx);
}
