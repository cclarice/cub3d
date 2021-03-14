/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:16:17 by enena             #+#    #+#             */
/*   Updated: 2021/03/14 09:37:57 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp_utils.h"
#include "../../printf/ft_printf.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	p = str;
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	while (*s1)
	{
		*p = *s1;
		p++;
		s1++;
	}
	while (*s2)
	{
		*p = *s2;
		p++;
		s2++;
	}
	return (str);
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *pdst;
	unsigned char *psrc;

	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	if (psrc == 0 && pdst == 0)
		return (dst);
	while (n-- > 0)
		*pdst++ = *psrc++;
	return (dst);
}

static void		set_bmp_info_from_image(t_bitmapinfo *info, t_img *data)
{
	info->size = BMP_SIZEOFINFO;
	info->width = data->width;
	info->height = -data->height;
	info->planes = BMP_PLANES;
	info->bitcount = BMP_BITPERPIXEL;
	info->compression = BMP_COMPRESSION;
	info->sizeimage = BMP_SIZEIMAGE;
	info->xpelspermeter = BMP_XPELSPERMETER;
	info->ypelspermeter = BMP_YPELSPERMETER;
	info->clrused = BMP_CLRUSED;
	info->clrimportant = BMP_CLRIMPORTANT;
}

static void		set_bmp_data_from_image(t_bmpfile *bmp, t_img *data)
{
	ft_memcpy(bmp->fileheader.type, BMP_IDENTIFIER, sizeof(BMP_IDENTIFIER));
	bmp->fileheader.size = data->width * data->height * BMP_BYTEPERPIXEL +
		BMP_SIZEOFHEADER;
	bmp->fileheader.reserved = 0;
	bmp->fileheader.offset = BMP_SIZEOFHEADER;
	set_bmp_info_from_image(&bmp->info, data);
	bmp->data = data->addr;
}

/*
**	bmp_file_name = ft_sec_free(bmp_file_name);
*/

int				save_image_as_bmp(t_img *data, const char *name)
{
	int			fd;
	char		*bmp_file_name;
	t_bmpfile	bmp_data;

	if (!(bmp_file_name = ft_strjoin(name, BMP_EXTN)))
		return (0);
	if ((fd = open(bmp_file_name, O_CREAT | O_WRONLY | O_TRUNC,
											S_IRUSR | S_IWUSR)) < 0)
		return (0);
	set_bmp_data_from_image(&bmp_data, data);
	if (!(ft_write_bmp(fd, &bmp_data)))
	{
		if (close(fd) < 0)
			return (0 || 0);
		return (0);
	}
	if (close(fd) < 0)
		return (0);
	return (1);
}
