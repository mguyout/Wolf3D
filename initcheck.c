/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 04:38:31 by mguyout           #+#    #+#             */
/*   Updated: 2017/11/01 04:48:30 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_struct	*ft_init(t_struct *env)
{
	env->posx = 22;
	env->posy = 12;
	env->dirx = -1;
	env->diry = 0;
	env->planex = 0;
	env->planey = 0.66;
	env->time = 0;
	env->oldtime = 0;
	env->lock = 0;
	env->data = mlx_get_data_addr(env->im, &env->bpp,
			&env->size_line, &env->endian);
	return (env);
}

void		ft_init2(t_struct *env)
{
	if (env->lock == 0)
	{
		env->posx = 22;
		env->posy = 12;
		env->dirx = -1;
		env->diry = 0;
		env->planex = 0;
		env->planey = 0.66;
	}
	env->time = 0;
	env->oldtime = 0;
}

void		ft_init3(t_struct *env)
{
	env->rayposx = env->posx;
	env->rayposy = env->posy;
	env->raydirx = env->dirx + env->planex * env->camerax;
	env->raydiry = env->diry + env->planey * env->camerax;
	env->mapx = (int)env->rayposx;
	env->mapy = (int)env->rayposy;
	env->deltadistx = sqrt(1 + (env->raydiry * env->raydiry) /
			(env->raydirx * env->raydirx));
	env->deltadisty = sqrt(1 + (env->raydirx * env->raydirx) /
			(env->raydiry * env->raydiry));
	env->hit = 0;
}

void		ft_checkwalls(t_struct *env)
{
	static int	worldmap[24][24] = XB;

	while (env->hit == 0)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->deltadistx;
			env->mapx += env->stepx;
			env->side = 0;
		}
		else
		{
			env->sidedisty += env->deltadisty;
			env->mapy += env->stepy;
			env->side = 1;
		}
		if (worldmap[env->mapx][env->mapy] > 0)
			env->hit = 1;
	}
}

void		ft_checkpos(t_struct *env)
{
	if (env->raydirx < 0)
	{
		env->stepx = -1;
		env->sidedistx = (env->rayposx - env->mapx) * env->deltadistx;
	}
	else
	{
		env->stepx = 1;
		env->sidedistx = (env->mapx + 1.0 - env->rayposx) * env->deltadistx;
	}
	if (env->raydiry < 0)
	{
		env->stepy = -1;
		env->sidedisty = (env->rayposy - env->mapy) * env->deltadisty;
	}
	else
	{
		env->stepy = 1;
		env->sidedisty = (env->mapy + 1.0 - env->rayposy) * env->deltadisty;
	}
}
