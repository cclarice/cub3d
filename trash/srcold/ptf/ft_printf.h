/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 16:34:30 by cclarice          #+#    #+#             */
/*   Updated: 2020/12/25 08:07:40 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define HEX	"0123456789abcdef"
# define FLAG	"-0123456789.*"
# define MIN	-2147483648

typedef struct	s_frmt
{
	va_list		v;
	char		*f;
	int			m;
	int			n;
	int			z;
	int			d;
	int			l;
	int			p;
}				t_frmt;

void			ft_putchar(char c);
int				ft_isdigit(char c);
int				ft_isflag(char c);
int				ft_ai(char *str);

void			ft_getn(t_frmt *s);
void			ft_getz(t_frmt *s);
int				ft_kostil(char *str);
void			ft_getm(t_frmt *s);
void			ft_getd(t_frmt *s);

int				ft_ps(long c);
int				ft_pz(long c);
int				ft_pzm(long c, int d);

int				ft_printf_nbr(t_frmt *s, int n);
int				ft_printf_unsigned(t_frmt *s, unsigned int n);
int				ft_printf_hex(t_frmt *s, unsigned long n, char h);
int				ft_printf_str(t_frmt *s, char *c);
int				ft_printf_char(t_frmt *s, unsigned int c);

int				ft_printf(const char *f, ...);

#endif
