/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 02:35:16 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/14 10:16:40 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "../cube3d.h"
# include "../utils/lists/lists.h"
# include "bmp/bmp_utils.h"

/*
**	P   - mathematical constant
**	PS	- Player Movement Speed
**	FOV - Field Of View
**	PS	- Player Size
*/

/*
**	# define Black	0x000000
**	# define White	0xFFFFFF
**	# define Red	0xFF0000
**	# define Lime	0x00FF00
**	# define Blue	0x0000FF
**	# define Yellow	0xFFFF00
**	# define Cyan	0x00FFFF
**	# define Magent	0xFF00FF
**	# define Silver	0xC0C0C0
**	# define Gray	0xAAAAAA
**	# define Maroon	0xAA4444
**	# define Olive	0xAAAA44
**	# define Green	0x44AA44
**	# define Purple	0xAA44AA
**	# define Teal	0x44AAAA
**	# define Navy	0x4444AA
*/

# define P	M_PI
# define PS	0.05
# define FOV 90 * (P/180)
# define PSZ 0.3
# define PHSZ 0.15

/*
**	Initialization Defines
*/

/*
**	# define MSW 320
**	# define MSH 240
*/

# define MSW 1
# define MSH 1
# define NAME "cclarice's cub3d"
# define NAME_D "cclarice's cub3d (debug mode)"
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

typedef struct		s_xpm
{
	void			*img;
	char			*ptr;
	int				bpp;
	int				length;
	int				endian;
	int				w;
	int				h;
}					t_xpm;

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

typedef struct		s_tex
{
	t_xpm			no;
	t_xpm			so;
	t_xpm			we;
	t_xpm			ea;
	t_xpm			sp;
}					t_tex;

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

typedef struct		s_cnt
{
	short			kw;
	short			ka;
	short			ks;
	short			kd;
	short			kr;
	short			kl;
	short			kfl;
	short			kfr;
	short			kf3;
	int				mx;
	int				my;
	short			br;
	short			bl;
	short			mm;
}					t_cnt;

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

typedef struct		s_eng
{
	short			mode;
	void			*mlx;
	void			*win;
	t_img			mdg;
	t_tex			tex;
	int				rex;
	int				rey;
	unsigned int	flc;
	unsigned int	cec;
	double			plx;
	double			ply;
	double			pla;
	double			plb;
	double			fov;
	char			**m;
	int				msx;
	int				msy;
	t_cnt			cnt;
	t_spr			*spr;
	double			*dst;
	double			*ray;
	double			*rayr;
}					t_eng;

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

/*
**	[code]	typedef struct	s_dts
**	[code]	{
**	[code]		double	a[3];
**	[code]		double	b[3];
**	[code]		double	c[3];
**	[code]		double	d[3];
**	[code]	}				t_dts;
*/

/*
**	Struct Raycasting
**
**	My metod of raycasting
**
**	a - curent angle of ray
**	c - curent line
**	s - step in angle between two rays
**	h - horizontal
**	v - vertical
**       x - x position
**       y - y position
**       g - cathetus between triangles
**       l - lenght between player and block crossing
*/

typedef struct		s_ray
{
	double			a;
	int				c;
	double			s;
	double			hx;
	double			hy;
	double			hc;
	double			hl;
	double			vx;
	double			vy;
	double			vc;
	double			vl;
}					t_ray;

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

typedef struct		s_blc
{
	int				x;
	int				y;
	int				xo;
	int				yo;
	int				size;
	int				trim;
}					t_blc;

/*
**	Struct Square
**
**	xa/ya - start
**	xe/ye - end
*/

typedef	struct		s_ab
{
	int				xa;
	int				ya;
	int				xe;
	int				ye;
}					t_ab;

/*
**	Initialization
*/

void				other_init(t_eng *e, t_vars v, char **map);
void				render_map(t_eng *e, void *img, int sizeb);
void				keyboard_init(t_eng *e);
int					mouse_init(t_eng *e);
void				window_init(t_eng *e, t_vars v);

/*
**	Engine
*/

int					tick(t_eng *e);
void				movement(t_eng *e);
void				collision(t_eng *e);
void				raycasting(t_eng *e);
void				raycasting_len(t_eng *e, t_ray *r);
void				sprites(t_eng *e);
unsigned char		*get_pafxmp(t_xpm *xpm, int x, double yy);

int					key_press(int key, t_eng *e);
int					key_release(int key, t_eng *e);
int					button_press(int hook, t_eng *e);
int					button_release(int hook, t_eng *e);
int					mouse_motion(int x, int y, t_eng *e);
void				get_sprite_distance(t_eng *e);
void				sort_sprites(t_eng *e);

void				destroyer();
int					expose(int hook, t_eng *e);
int					destroy_notify(int hook, t_eng *e);
void				raycastings(t_eng *e, t_ray r);
void				init_rays(t_eng *e, t_ray r);
void				calc_line(t_eng *e, t_ray *r, t_xpm *xpm, int xx);
void				mouse_tick(t_eng *e);
void				init_rays(t_eng *e, t_ray r);

int					find_sprite_ray(t_eng *e, double angle);
int					is_drawable_line(t_xpm *xpm, int x);
void				clear_sprite(t_eng *e, t_spr s);
int					is_drawable_line(t_xpm *xpm, int x);

/*
**	Utils
*/

void				fill_img_with_color(void *img, int x, int y, int color);
void				put_pixel_to_img(t_img *img, int x, int y, int color);
unsigned int		get_pixel_from_img(t_img *img, int x, int y);
unsigned int		get_pixel_from_xmp(t_xpm *xpm, int x, double yy);
void				engine(t_eng *e);
void				cub_get_mapsize(char **map, int *x, int *y);
void				my_put_char(t_img *img, char c, int x, int y, int size);

/*
**	Draw
*/

void				draw_rectangle(t_img *img, t_ab s, int color);
void				draw_full_rectangle(t_img *img, t_ab s, int color);
void				draw_dot(t_img *img, int x, int y, int color);

/*
**	void			draw_arrow(t_img *img, t_ab s, int size, double angle,
**														 int color);
**	void			draw_line(t_img *img, t_ab s, int color);
*/

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
