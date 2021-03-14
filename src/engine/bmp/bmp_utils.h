/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 21:31:21 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 09:32:18 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_UTILS_H
# define BMP_UTILS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define BMP_EXTN			".bmp"
# define BMP_IDENTIFIER		"BM"
# define BMP_BYTEPERPIXEL	4
# define BMP_SIZEOFHEADER	54
# define BMP_SIZEOFINFO		40
# define BMP_RESERVED		0
# define BMP_PLANES			1
# define BMP_BITPERPIXEL	32
# define BMP_COMPRESSION	0
# define BMP_SIZEIMAGE		0
# define BMP_XPELSPERMETER	0
# define BMP_YPELSPERMETER	0
# define BMP_CLRUSED		0
# define BMP_CLRIMPORTANT	0

/*
**	Struct Image
**
**	s_data from 42 docs
**	https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
*/

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_bitmapfileheader
{
	char			type[2];
	unsigned int	size;
	unsigned int	reserved;
	unsigned int	offset;
}				t_bitmapfileheader;

typedef struct	s_bitmapinfo
{
	int		size;
	int		width;
	int		height;
	short	planes;
	short	bitcount;
	int		compression;
	int		sizeimage;
	int		xpelspermeter;
	int		ypelspermeter;
	int		clrused;
	int		clrimportant;
}				t_bitmapinfo;

/*
** Sructure for setting/storage bmpfile image
*/

typedef struct	s_bmpfile
{
	t_bitmapfileheader	fileheader;
	t_bitmapinfo		info;
	char				*data;
}				t_bmpfile;

int				save_image_as_bmp(t_img *data, const char *name);
int				ft_write_bmp(int fd, t_bmpfile *bitmap);

#endif
