/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gexbraya <gexbraya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/13 13:17:06 by gexbraya          #+#    #+#             */
/*   Updated: 2015/03/12 14:49:26 by gexbraya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mkart.h"

static void		init_img2(t_env *e)
{
	t_w3img	*cp;
	t_w3img	*sb;
	t_w3img	*sr;
	t_w3img	*mil;

	cp = &e->cp;
	sb = &e->sb;
	sr = &e->sr;
	mil = &e->mil;
	cp->img = mlx_xpm_file_to_image(e->mlx, CP, &cp->x, &cp->y);
	cp->data = mlx_get_data_addr(cp->img, &cp->bpp, &cp->l, &cp->e);
	sr->img = mlx_xpm_file_to_image(e->mlx, SR, &sr->x, &sr->y);
	sr->data = mlx_get_data_addr(sr->img, &sr->bpp, &sr->l, &sr->e);
	sb->img = mlx_xpm_file_to_image(e->mlx, SB, &sb->x, &sb->y);
	sb->data = mlx_get_data_addr(sb->img, &sb->bpp, &sb->l, &sb->e);
	mil->img = mlx_xpm_file_to_image(e->mlx, MILI, &mil->x, &mil->y);
	mil->data = mlx_get_data_addr(mil->img, &mil->bpp, &mil->l, &mil->e);
}

static void		init_img1(t_env *e)
{
	t_w3img	*img;
	t_w3img	*mur;
	t_w3img	*flo;
	t_w3img	*kar;
	t_w3img	*sta;

	img = &e->img;
	mur = &e->mur;
	flo = &e->flo;
	kar = &e->kar;
	sta = &e->sta;
	img->img = mlx_new_image(e->mlx, XSIZE, YSIZE);
	img->data = mlx_get_data_addr(img->img, &img->bpp, &img->l, &img->e);
	mur->img = mlx_xpm_file_to_image(e->mlx, WALL, &mur->x, &mur->y);
	mur->data = mlx_get_data_addr(mur->img, &mur->bpp, &mur->l, &mur->e);
	flo->img = mlx_xpm_file_to_image(e->mlx, FLOOR, &flo->x, &flo->y);
	flo->data = mlx_get_data_addr(flo->img, &flo->bpp, &flo->l, &flo->e);
	kar->img = mlx_xpm_file_to_image(e->mlx, KART, &kar->x, &kar->y);
	kar->data = mlx_get_data_addr(kar->img, &kar->bpp, &kar->l, &kar->e);
	sta->img = mlx_xpm_file_to_image(e->mlx, START, &sta->x, &sta->y);
	sta->data = mlx_get_data_addr(sta->img, &sta->bpp, &sta->l, &sta->e);
}

void			init_mlx(t_env *e)
{
	e->inter = 0;
	e->xsize_2 = XSIZE / 2.0;
	e->ysize_2 = YSIZE / 2.0;
	e->xsize_6000 = XSIZE / 6000.0;
	e->xsize_6k = 6000.0 / XSIZE;
	e->proj_dist = XSIZE / 2.0 / e->tan[3000];
	e->proj_dist_ysize = e->proj_dist / YSIZE;
	e->lastclock = clock();
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, XSIZE, YSIZE, "Wolf3d");
	init_img1(e);
	init_img2(e);
}
