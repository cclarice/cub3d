/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 02:35:16 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/16 23:01:55 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "../cube3d.h"

/*
**	P   - mathematical constant
**	PS	- Player Movement Speed
**	FOV - Field Of View
**	PS	- Player Size
*/

# define P	M_PI
# define PS	0.06//0.03
# define FOV 70 * (P/180)
# define PSZ 0.3
# define PHSZ 0.15

/*
**	Initialization Defines
*/

# define NAME "cclarice's cub3d"
# define NAME_D "cclarice's cub3d (debug mode)"
# define MSW 320
# define MSH 240
# define WWC ft_printf("\033[36mWarning! Wight was changed to %d!\n", e->rex)
# define HWC ft_printf("\033[36mWarning! Height was changed to %d!\n", e->rey)

/*
**	Struct X PixMap
**
**	X PixMap (XPM) is an image file format
**
**	img - pointer to image
**	w	- widht of image
**	h	- height of image
*/

typedef struct	s_xpm
{
	void		*img;
	int			w;
	int			h;
}				t_xpm;

/*
**	Struct Image
**
**	s_data from 42 docs
**	https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
*/

typedef struct	s_img {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

/*
**	Struct Textures
**
**	.xpm textures
**
**	no - North texture
**	so - South texture
**	we - West texture
**	ea - East texture
**	sp - Sprite texture
*/

typedef struct	s_tex
{
	t_xpm		no;
	t_xpm		so;
	t_xpm		we;
	t_xpm		ea;
	t_xpm		sp;
}				t_tex;

/*
**	Struct Control
**
**	Key pressed -> 1
**	Key release -> 0
**
**	kw - W key
**	ka - A key
**	ks - S key
**	kd - D key
**	kr - right arrow key ->
**	kl - left  arrow key <-
**	mx - mouse position x
**	my - mouse position y
**	mr - mouse right key
**	ml - mouse left  key
*/

typedef struct	s_cnt
{
	short		kw;
	short		ka;
	short		ks;
	short		kd;
	short		kr;
	short		kl;
	short		kf3;
	int			mx;
	int			my;
	short		br;
	short		bl;
	short		mm;
}				t_cnt;

/*
**	Struct MiniMap
**
**	fullb - fullscreen minimap block size
**	minib - minimap block size
**	mode  - mode of minimap [0 mini] [1 - mini dynamic] [2 - full] [-1 - only map]
**	b_clr - block color
**	t_clr - trim color of block
**	o_clr - outline color
**	d_clr - detected block color
**	s_clr - sprite color
**	p_clr - player color
*/

typedef struct	s_mmp
{
	int			fullb;
	int			minib;
	int			mode;
	int			b_clr;
	int			t_clr;
	int			o_clr;
	int			d_clr;
	int			s_clr;
	int			p_clr;
	int			f_clr;
	int			a_clr;
}				t_mmp;

/*
**	Struct/Linked list - Walls List
**
**	a - first dot
**	b - second dot
**	l - min len betwen player and wall
**	next - pointer to next wall
*/

typedef struct		s_wli
{
	double			a;
	double			b;
	double			l;
	struct s_wli	*next;
}					t_wli;

/*
**	Struct Engine
**
**	MLX is a simple X-Window programming API in C, designed for students
**
**	mlx - pointer to mlx
**	win - pointer to window
**
**	lma - layer map
**	lmi - layer minimap
**	rma - ray layer map
**	rmi - ray layer minimap
**	frg - foreground	image
**	mdg - middleground	image
**	bcg - background	image
**	tex - textures
**	rex - widht of the screen
**	rey - height of the screen
**	m	- map[y][x] in chars
**	flc - floor color
**	cec - ceiling color
**	plx - player x
**	ply - player y
**	pla - player angle
**	fov - Field of View
**	msx - map size X
**	msy - map size Y
**	wli - Walls List
*/

typedef struct	s_eng
{
	void		*mlx;
	void		*win;
	t_img		lma;
	t_img		lmi;
	t_img		rma;
	t_img		rmi;
	t_img		frg;
	t_img		mdg;
	t_img		bcg;
	t_tex		tex;
	int			hsz;
	int			rex;
	int			rey;
	int			flc;
	int			cec;
	double		plx;
	double		ply;
	double		pla;
	double		fov;
	char		**m;
	int			msx;
	int			msy;
	t_cnt		cnt;
	t_mmp		mmp;
	t_wli		wli;
}				t_eng;

/*
**	Struct Dots
**
**	a, b, c, d - corners of block
**	a---c
**	|	|
**	|	|
**	b---d
**
**	Struct of each Dot:
**		[0] - x coordinate
**		[1] - y coordinate
**		[2] - 0 - I can't see this point
**			  1 - I have to see this point, but it is not in my field of vision
**			  2 - I see this dot!
*/

typedef struct	s_dts
{
	double	a[3];
	double	b[3];
	double	c[3];
	double	d[3];
}				t_dts;

/*
**	Struct Raycasting
**
**	My own metod of raycasting
**	Explained on Russian in explaination.*
**
**	hoU - Upper Horizontal
**	hoD - Lower Horizontal
**	veL - Left  Vertical
**	veR - Right Vertical
**	hLe - Lenght bethew Upper and Lower Horizontal
**	vLe - Lenght bethew Left  and Right Vertical
**	hRa - Current Horizontal Ray Position
**	vRa - Current Vertical   Ray Position
*/

typedef struct	s_ray
{
	t_dts		dts;
	double		hou[2];
	double		hod[2];
	double		vel[2];
	double		ver[2];
	double		h_l[2];
	double		v_l[2];
	double		h_r[2];
	double		v_r[2];
}				t_ray;

/*
**	Struct Block
**
**	x - x on map
**	y - y on map
**	xo - x offset on screen
**	yo - x offset on screen
**	size - size of block
**	trim - size of trim
*/

typedef struct	s_blc
{
	int			x;
	int			y;
	int			xo;
	int			yo;
	int			size;
	int			trim;
}				t_blc;

/*
**	Struct Square
**
**	xa/ya - start
**	xe/ye - end
*/

typedef	struct	s_ab
{
	int			xa;
	int			ya;
	int			xe;
	int			ye;
}				t_ab;

/*
**	Initialization
*/

void			other_init(t_eng *e, t_vars v, char **map);
void			render_map(t_eng *e, t_img *img, int sizeb);

/*
**	Engine
*/

void			movement(t_eng *e);
void			collision(t_eng *e);
void			raycasting(t_eng *e);

int				key_press(int key, t_eng *e)
int				key_release(int key, t_eng *e)
int				tick(t_eng *e)

/*
**	Utils
*/

void			fill_img_with_color(t_img *data, int x, int y, int color);
void			put_pixel_to_img(t_img *data, int x, int y, int color);
void			engine(t_eng *e);
void			cub_get_mapsize(char **map, int *x, int *y);
void			my_put_string(t_img *img, char *str, int x, int y, int size);

/*
**	Draw
*/

void			draw_line(t_img *img, t_ab s, int color);
void			draw_rectangle(t_img *img, t_ab s, int color);
void			draw_full_rectangle(t_img *img, t_ab s, int color);
void			draw_dot(t_img *img, int x, int y, int color);
void			draw_arrow(t_img *img, t_ab s, int size, double angle, int color);

/*
**	void	аput_pixel_to_frame(t_data *data, int x, int y, int color);
**	void	put_square_to_image(t_data *img, int x, int y, int color);
**	void	put_player_to_image(t_data *img, int x, int y, int color);
**	void	set_img_transparent(t_data *img, int x, int y);
**	void	put_circle(t_data *img, int x, int y, int color);
**	void	drawLine(t_data *img, int x1, int y1, int x2, int y2, int color);
**	void	drawArrow(t_data *img, int x, int y, double angle, int color);
*/

#endif
