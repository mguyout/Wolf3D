/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguyout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 01:58:02 by mguyout           #+#    #+#             */
/*   Updated: 2017/11/01 05:14:30 by mguyout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "Libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# define X1 {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
# define X2	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
# define X3	{1,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
# define X4	{1,0,2,0,0,0,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
# define X5	{1,0,2,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
# define X6	{1,0,2,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
# define X7	{1,0,2,0,0,0,2,0,0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,1},
# define X8	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
# define X9	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
# define X10 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,3,0,0,0,0,0,1},
# define X11 {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,1},
# define X12 {1,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,4,0,0,0,1},
# define X13 {1,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,0,0,0,1},
# define X14 {1,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,1},
# define X15 {1,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,1},
# define X16 {1,0,0,4,0,0,0,0,4,4,4,4,4,0,0,0,0,4,4,0,0,0,0,1},
# define X17 {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
# define X18 {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
# define X19 {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
# define X20 {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
# define X21 {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
# define X22 {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
# define X23 {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
# define X24 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}}
# define XA X1 X2 X3 X4 X5 X6 X7 X8 X9 X10 X11 X12 X13 X14 X15 X16 X17 X18
# define XB XA X19 X20 X21 X22 X23 X24

typedef	struct		s_struct
{
	void			*mlx;
	void			*win;
	void			*im;
	char			*data;
	int				**tab;
	int				**worldmap;
	int				bpp;
	int				size_line;
	int				endian;
	int				pos;
	int				lock;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	double			camerax;
	double			cameray;
	double			raydirx;
	double			raydiry;
	double			rayposx;
	double			rayposy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			frametime;
	double			ms;
	double			rs;
	double			olddirx;
	double			oldplanex;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				mapx;
	int				mapy;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				r;
	int				g;
	int				b;
}					t_struct;

typedef struct		s_xmap
{
	void			**map;
	int				flags;
	size_t			ptr;
	size_t			size;
}					t_xmap;

void				*ft_salloc(size_t size);
void				*ft_xalloc(size_t size, int ref);
void				*ft_xcalloc(size_t size, int ref);
void				ft_xclear(int ref);
void				ft_init2(t_struct *env);
void				ft_init3(t_struct *env);
void				ft_checkwalls(t_struct *env);
void				ft_checkpos(t_struct *env);
void				ft_print(t_struct *env, int x);
t_xmap				*ft_xmap(int ref, int mode);
t_struct			*ft_init(t_struct *env);
t_struct			*ft_raycasting(t_struct *env);
int					ft_hook(int keypad, t_struct *env);
#endif
