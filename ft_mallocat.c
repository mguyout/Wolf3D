/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 06:58:05 by mguyout           #+#    #+#             */
/*   Updated: 2017/11/01 05:11:18 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include "Libft/libft.h"

void			*ft_xalloc(size_t size, int ref)
{
	t_xmap	*map;

	if (!(map = ft_xmap(ref, 0)))
		exit(1);
	if (map->ptr + 1 < map->size)
	{
		map->map[map->ptr] = ft_salloc(size);
		return (map->map[map->ptr++]);
	}
	ft_xmap(ref, 2);
	return (ft_xalloc(size, ref));
}

void			ft_xclear(int ref)
{
	t_xmap	*map;

	if (!(map = ft_xmap(ref, 0)))
		return ;
	while (map->ptr--)
	{
		if (map->map[map->ptr])
			free(map->map[map->ptr]);
	}
	ft_xmap(ref, 3);
}
