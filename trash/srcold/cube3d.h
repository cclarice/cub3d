/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:34:30 by cclarice          #+#    #+#             */
/*   Updated: 2021/01/23 20:54:29 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUBE3D_H
# define FT_CUBE3D_H

#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "./ptf/ft_printf.h"
#include "../Lmlx/mlx.h"
#include <math.h>

typedef struct		s_cube
{
	int				x;
	int				y;
	unsigned int	error;
	int				*error_index;
	int				f;
	int				c;
	char			**map;
	int				mx;
	int				my;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sp;
}					t_cube;

typedef struct		s_tex
{
	void    		*img;
	int     		w;
    int     		h;
}					t_tex;

typedef struct		s_mlx
{
	t_cube			cube;
	void			*mlx;
	void			*win;
	t_tex			no;
	t_tex			so;
	t_tex			we;
	t_tex			ea;
	t_tex			sp;
	float			px;
	float			py;
	char			**map;
}					t_mlx;

void	cube_init(char *map, int debug);
void	map_error(char *map, t_cube cube);
void	map_debug(char *map, t_cube cube);
int		skip_s(char *str);
int		create_rgb(int r, int g, int b);
int		get_r(int rgb);
int		get_g(int rgb);
int		get_b(int rgb);
int		ft_atoi(const char *str);
int		ft_atois(const char *str);
int		ft_atoit(const char *str);
char	*int_to_bin(int k);
int		ft_pthlen(char *pth);
int		ft_isempty(char *str);
int		ft_ftr(char *str);
int		ft_ftc(char *str);
void	image_init(t_mlx *mlx, t_cube cube);

#endif