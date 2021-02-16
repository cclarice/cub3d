/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 02:35:16 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/10 18:24:43 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

/*
**	open, close, read, write, malloc, free, exit
*/

#include "../cube3d.h"

/*
**	BLOCK size on screen
*/

#define RAYS 256
#define PI 3.141592653589793238462
#define D3 1.
#define BLOCK 160
#define STEP 0.03
#define ASTEP 3.6 * (PI/180)
#define PSIZE 0.3
#define CSIZE PSIZE * 0.90
#define FOV 60 * (PI/180)

typedef struct	s_tex
{
	void    	*img;
	int     	w;
    int     	h;
}				t_tex;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct	s_eng
{
	void		*win;
	void		*mlx;
	t_data		frm;
	t_data		cub3d;
	t_data		ray;
	t_tex		no;
	t_tex		so;
	t_tex		we;
	t_tex		ea;
	t_tex		sp;
	int			rx;
	int			ry;
	int			fc;
	int			cc;
	double		plaX;
	double		plaY;
	double		angV;
	double		camLX;
	double		camLY;
	double		camRX;
	double		camRY;
	double		camVX;
	double		camVY;
	double		dDX;
	double		dDY;
    int			msx;
    int			msy;
	short		kw;
	short		ka;
	short		ks;
	short		kd;
	short		kr;
	short		kl;
	float		acc;
	char		**m;
	int			mousex;
	int			mousey;
}				t_eng;

/*
**	Смотреть ExpainMap struct Ray
**	c1 - X и Y коор-ты первого верхнего пересечения со строками
**	c2 - X и Y коор-ты первого нижнего пересечения со строками
**	l1 - X и Y коор-ты первого левого пересечения со столбцами
**	l2 - X и Y коор-ты первого правого пересечения со столбцами
**	dc - X и Y коор-ты расстояние между пересечениями строк
**	dl - X и Y коор-ты расстояние между пересечениями строк
*/

typedef struct	s_ray
{
	double		c1[2];
	double		c2[2];
	double		l1[2];
	double		l2[2];
	double		dc[2];
	double		dl[2];
}				t_ray;

/*
**		engine
*/

void			engine(t_eng eng);
void			put_pixel_to_frame(t_data *data, int x, int y, int color);
void			put_square_to_image(t_data *img, int x, int y, int color);
void			put_player_to_image(t_data *img, int x, int y, int color);
void			set_img_transparent(t_data *img, int x, int y);
void			put_circle(t_data *img, int x, int y, int color);
void			drawLine(t_data *img, int x1, int y1, int x2, int y2, int color);
void			drawArrow(t_data *img, int x, int y, double angle, int color);

#endif