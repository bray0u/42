/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 19:48:48 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/12 14:49:08 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mkart.h"

void			free_all(t_env *e)
{
	mlx_destroy_window(e->mlx, e->win);
	free(e->img.img);
	free(e->mur.img);
	free(e->flo.img);
	free(e->kar.img);
	free(e->sta.img);
	free(e->cp.img);
	free(e->sr.img);
	free(e->sb.img);
	free(e->mil.img);
	free(e->mlx);
}
