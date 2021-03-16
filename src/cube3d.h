/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 19:28:37 by cclarice          #+#    #+#             */
/*   Updated: 2021/03/16 03:23:08 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUBE3D_H
# define FT_CUBE3D_H

/*
**	open, close, read, write, malloc, free, exit
*/

# include "./printf/ft_printf.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../mlx/mlx.h"

typedef struct	s_path
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sp;
}				t_path;

/*
**	Struct Variables
**
**	rx - Widht
**	ry - Height
**	fc - floor color
**	cc - ceiling color
**	mode - 	1	- --save
**			2	- --debug
*/

typedef struct	s_vars
{
	int			rx;
	int			ry;
	int			fc;
	int			cc;
	int			mode;
}				t_vars;

typedef struct	s_map
{
	t_path		pt;
	t_vars		vr;
	char		**map;
	char		*cub;
}				t_map;

/*
**		utils
**
**		init_map
**			Returns a map with filled variables.
**		get_file_size
**          Returns size of <file> in chars.
**		file_to_str
**          Returns the contents of the <file> as a string with <size>.
**		check_dotcub
**			Returns 1 if the <name> does not end with ".cub".
**		ft_atoi
**			Returns integer converted from ASCII string.
*/

char			*ft_strdup(char *src);
t_map			init_map(void);
int				get_file_size(char *file);
char			*file_to_str(char *file, int size);
int				check_dotcub(char *name);
int				ft_atoi(const char *str);
int				ft_isdigit(char c);
int				create_rgb(int r, int g, int b);
int				get_r(int rgb);
int				get_g(int rgb);
int				get_b(int rgb);
int				ft_strstr(char *str1, char *str2);

/*
**		vld
*/

int				vld(char *map, char ***m, t_path *pt, t_vars *vr);
void			getvars(char *m, t_path *pt, t_vars *vr, int *er);
void			vldmap(char *map, int *ei, char ***m);
void			validmap(char **map, int *e);
void			vldidn(char *map, int *ei);
void			put_errors(char *map, int *ei);
int				color_error(char *map, int *e);

/*
**		getcube
*/

/*
**		engine
*/

int				initialization(t_path pt, t_vars vr, char **map);

#endif
