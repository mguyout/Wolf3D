/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 01:53:48 by mguyout           #+#    #+#             */
/*   Updated: 2017/11/01 05:12:12 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_end(void)
{
	system("killall afplay &");
	exit(0);
}

t_struct	*ft_raycasting(t_struct *env)
{
	int			x;

	x = -1;
	ft_init2(env);
	while (++x < 1000)
	{
		env->camerax = 2 * x / (double)1000 - 1;
		ft_init3(env);
		ft_checkpos(env);
		ft_checkwalls(env);
		if (env->side == 0)
			env->perpwalldist = (env->mapx - env->rayposx +
					(1 - env->stepx) / 2) / env->raydirx;
		else
			env->perpwalldist = (env->mapy - env->rayposy +
					(1 - env->stepy) / 2) / env->raydiry;
		ft_print(env, x);
	}
	return (env);
}

int			main(void)
{
	t_struct *env;

	system("afplay music.mp3 &");
	if (!(env = ft_xalloc(sizeof(t_struct), 0)))
		exit(1);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, 1000, 1000, "Wolf3D");
	env->im = mlx_new_image(env->mlx, 1000, 1000);
	env = ft_init(env);
	env = ft_raycasting(env);
	if (!(mlx_put_image_to_window(env->mlx, env->win, env->im, 0, 0)))
		return (0);
	mlx_hook(env->win, 2, 0, ft_hook, env);
	mlx_hook(env->win, 17, 0, ft_end, env);
	mlx_loop(env->mlx);
	mlx_destroy_image(env->mlx, env->im);
	ft_xclear(0);
	return (0);
}
