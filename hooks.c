/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 04:41:33 by mguyout           #+#    #+#             */
/*   Updated: 2017/11/01 06:09:02 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_hookupdown(int keycode, t_struct *env)
{
	static int worldmap[24][24] = XB;

	if (keycode == 13)
	{
		if (worldmap[(int)(env->posx + env->dirx * env->ms)]
				[(int)env->posy] == 0)
			env->posx += env->dirx * env->ms;
		if (worldmap[(int)env->posx]
				[(int)(env->posy + env->diry * env->ms)] == 0)
			env->posy += env->diry * env->ms;
	}
	if (keycode == 1)
	{
		if (worldmap[(int)(env->posx - env->dirx * env->ms)]
				[(int)env->posy] <= 0)
			env->posx -= env->dirx * env->ms;
		if (worldmap[(int)env->posx]
				[(int)(env->posy - env->diry * env->ms)] <= 0)
			env->posy -= env->diry * env->ms;
	}
}

void		ft_hookleftright(int keycode, t_struct *env)
{
	if (keycode == 2)
	{
		env->olddirx = env->dirx;
		env->dirx = env->dirx * cos(-env->rs) - env->diry * sin(-env->rs);
		env->diry = env->olddirx * sin(-env->rs) + env->diry * cos(-env->rs);
		env->oldplanex = env->planex;
		env->planex = env->planex * cos(-env->rs) - env->planey * sin(-env->rs);
		env->planey = env->oldplanex * sin(-env->rs) +
			env->planey * cos(-env->rs);
	}
	if (keycode == 0)
	{
		env->olddirx = env->dirx;
		env->dirx = env->dirx * cos(env->rs) - env->diry * sin(env->rs);
		env->diry = env->olddirx * sin(env->rs) + env->diry * cos(env->rs);
		env->oldplanex = env->planex;
		env->planex = env->planex * cos(env->rs) - env->planey * sin(env->rs);
		env->planey = env->oldplanex * sin(env->rs) +
			env->planey * cos(env->rs);
	}
}

int			ft_hook(int keycode, t_struct *env)
{
	if (keycode == 53)
	{
		system("killall afplay &");
		exit(0);
	}
	if (keycode == 1 || keycode == 13 || keycode == 0 || keycode == 2)
	{
		if (keycode == 1 || keycode == 13)
			ft_hookupdown(keycode, env);
		if (keycode == 0 || keycode == 2)
			ft_hookleftright(keycode, env);
		env->lock = 1;
		env = ft_raycasting(env);
		mlx_put_image_to_window(env->mlx, env->win, env->im, 0, 0);
		env->lock = 0;
	}
	return (0);
}
