/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 04:43:46 by mguyout           #+#    #+#             */
/*   Updated: 2017/11/01 06:08:49 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		pixel_to_image2(t_struct *env)
{
	env->r = 255;
	env->b = 255;
	env->g = 255;
	if (env->side == 0 && env->stepx == 1)
		env->b = 0;
	else if (env->side == 0 && env->stepx == -1)
		env->g = 100;
	else if (env->side == 1 && env->stepy == 1)
		env->b = 150;
	else
		env->g = 150;
	env->data[env->pos] = env->r;
	env->data[env->pos + 1] = env->g;
	env->data[env->pos + 2] = env->b;
}

void		pixel_to_image(int x, int y, t_struct *env, int clr)
{
	env->pos = (x * 4) + ((y * env->size_line));
	if (clr == 1)
	{
		env->data[env->pos] = (char)220;
		env->data[env->pos + 1] = (char)186;
		env->data[env->pos + 2] = 16;
	}
	else if (clr == 3)
	{
		env->data[env->pos] = 13;
		env->data[env->pos + 1] = (char)129;
		env->data[env->pos + 2] = 0;
	}
	else
		pixel_to_image2(env);
	env->data[env->pos + 3] = 0;
}

void		ft_print(t_struct *env, int x)
{
	int i;

	env->lineheight = (int)(1000 / env->perpwalldist);
	env->drawstart = -env->lineheight / 2 + 1000 / 2;
	if (env->drawstart < 0)
		env->drawstart = 0;
	env->drawend = env->lineheight / 2 + 1000 / 2;
	if (env->drawend >= 1000)
		env->drawend = 1000 - 1;
	i = -1;
	while (++i <= env->drawstart)
		pixel_to_image(x, i, env, 1);
	while (env->drawstart++ <= env->drawend)
		pixel_to_image(x, env->drawstart, env, 255);
	while (env->drawend++ < 999)
		pixel_to_image(x, env->drawend, env, 3);
	env->oldtime = env->time;
	env->time = clock();
	env->frametime = (env->time - env->oldtime) / 1000;
	env->ms = env->frametime * 15.0;
	env->rs = env->frametime * 9.0;
}
