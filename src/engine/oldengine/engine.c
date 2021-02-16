/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 02:32:08 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/16 22:29:04 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include <stdio.h>
#include <time.h>

/*
**	eng->kw == 1 ? eng->plaY -= STEP : 0;
**	eng->ka == 1 ? eng->plaX -= STEP : 0;
**	eng->ks == 1 ? eng->plaY += STEP : 0;
**	eng->kd == 1 ? eng->plaX += STEP : 0;
**	eng->kr == 1 ? eng->angV -= STEP * 4: 0;
**	eng->kl == 1 ? eng->angV += STEP * 4: 0;
**	eng->camVX = cos(eng->angV + PI * 0.5) * (1 / tan(FOV * 0.5) * (PSIZE - 0.01) * 0.5) + eng->plaX;
**	eng->camVY = sin(eng->angV + PI * 0.5) * (1 / tan(FOV * 0.5) * (PSIZE - 0.01) * 0.5) + eng->plaY;
**	eng->camRX = -cos(eng->angV) * (PSIZE - 0.01) * 0.5 + eng->plaX;
**	eng->camRY = -sin(eng->angV) * (PSIZE - 0.01) * 0.5 + eng->plaY;
**	eng->camLX = cos(eng->angV) * (PSIZE - 0.01) * 0.5 + eng->plaX;
**	eng->camLY = sin(eng->angV) * (PSIZE - 0.01) * 0.5 + eng->plaY;
**	set_img_transparent(&eng->ray, eng->msx * BLOCK, eng->msy * BLOCK);
**	drawLine(&eng->ray, eng->camRX * BLOCK, eng->camRY * BLOCK, eng->camLX * BLOCK, eng->camLY * BLOCK, 0xAA00AA);
**	drawLine(&eng->ray, eng->plaX * BLOCK, eng->plaY * BLOCK, eng->camVX * BLOCK, eng->camVY * BLOCK, 0x888888);
**	drawLine(&eng->ray, eng->camVX * BLOCK, eng->camVY * BLOCK, eng->camLX * BLOCK, eng->camLY * BLOCK, 0x888888);
**	drawLine(&eng->ray, eng->camVX * BLOCK, eng->camVY * BLOCK, eng->camRX * BLOCK, eng->camRY * BLOCK, 0x888888);
**	put_circle(&eng->ray, eng->plaX * BLOCK, eng->plaY * BLOCK, 0xFF0000);
**	put_circle(&eng->ray, eng->camVX * BLOCK, eng->camVY * BLOCK, 0x00FF00);
**	put_circle(&eng->ray, eng->camRX * BLOCK, eng->camRY * BLOCK, 0xFF00FF);
**	put_circle(&eng->ray, eng->camLX * BLOCK, eng->camLY * BLOCK, 0xFFFF00);
*/

float	ft_ostatok(double nbr)
{
	float ostatok;

	ostatok = nbr - (int)nbr;
	return (ostatok);
}

int		check_wall(t_eng *eng)
{
	if ((eng->m[(int)(eng->plaY + PSIZE / 2)][(int)(eng->plaX + PSIZE / 2)] == '1')
	|| (eng->m[(int)(eng->plaY + PSIZE / 2)][(int)(eng->plaX - PSIZE / 2)] == '1')
	|| (eng->m[(int)(eng->plaY - PSIZE / 2)][(int)(eng->plaX + PSIZE / 2)] == '1')
	|| (eng->m[(int)(eng->plaY - PSIZE / 2)][(int)(eng->plaX - PSIZE / 2)] == '1'))
		return (1);
	return (0);
}
int		check_wallx(t_eng *eng)
{
	if ((eng->m[(int)(eng->plaY + PSIZE / 2 - STEP)][(int)(eng->plaX + PSIZE / 2)] == '1')
	|| (eng->m[(int)(eng->plaY + PSIZE / 2 - STEP)][(int)(eng->plaX - PSIZE / 2)] == '1')
	|| (eng->m[(int)(eng->plaY - PSIZE / 2 + STEP)][(int)(eng->plaX + PSIZE / 2)] == '1')
	|| (eng->m[(int)(eng->plaY - PSIZE / 2 + STEP)][(int)(eng->plaX - PSIZE / 2)] == '1'))
		return (1);
	return (0);
}
int		check_wally(t_eng *eng)
{
	if ((eng->m[(int)(eng->plaY + PSIZE / 2)][(int)(eng->plaX + PSIZE / 2 - STEP)] == '1')
	|| (eng->m[(int)(eng->plaY + PSIZE / 2)][(int)(eng->plaX - PSIZE / 2 + STEP)] == '1')
	|| (eng->m[(int)(eng->plaY - PSIZE / 2)][(int)(eng->plaX + PSIZE / 2 - STEP)] == '1')
	|| (eng->m[(int)(eng->plaY - PSIZE / 2)][(int)(eng->plaX - PSIZE / 2 + STEP)] == '1'))
		return (1);
	return (0);
}

void	check_movex(t_eng *eng)
{
	if (eng->kw == 1 && eng->kd == 1)
		eng->plaX -= sin(eng->angV - PI * 0.25) * STEP / 20;
	else if (eng->kw == 1 && eng->ka == 1)
		eng->plaX -= sin(eng->angV + PI * 0.25) * STEP / 20;
	else if (eng->ks == 1 && eng->kd == 1)
		eng->plaX -= sin(eng->angV - PI * 0.75) * STEP / 20;
	else if (eng->ks == 1 && eng->ka == 1)
		eng->plaX -= sin(eng->angV + PI * 0.75) * STEP / 20;
	else if (eng->kw == 1)
		eng->plaX -= sin(eng->angV) * STEP / 20;
	else if (eng->ka == 1)
		eng->plaX -= sin(eng->angV + PI * 0.5) * STEP / 20;
	else if (eng->ks == 1)
		eng->plaX -= sin(eng->angV - PI) * STEP / 20;
	else if (eng->kd == 1)
		eng->plaX -= sin(eng->angV - PI * 0.5) * STEP / 20;
}

void	check_movey(t_eng *eng)
{
	if (eng->kw == 1 && eng->kd == 1)
		eng->plaY -= cos(eng->angV - PI * 0.25) * STEP / 20;
	else if (eng->kw == 1 && eng->ka == 1)
		eng->plaY -= cos(eng->angV + PI * 0.25) * STEP / 20;
	else if (eng->ks == 1 && eng->kd == 1)
		eng->plaY -= cos(eng->angV - PI * 0.75) * STEP / 20;
	else if (eng->ks == 1 && eng->ka == 1)
		eng->plaY -= cos(eng->angV + PI * 0.75) * STEP / 20;
	else if (eng->kw == 1)
		eng->plaY -= cos(eng->angV) * STEP / 20;
	else if (eng->ka == 1)
		eng->plaY -= cos(eng->angV + PI * 0.5) * STEP / 20;
	else if (eng->ks == 1)
		eng->plaY -= cos(eng->angV - PI) * STEP / 20;
	else if (eng->kd == 1)
		eng->plaY -= cos(eng->angV - PI * 0.5) * STEP / 20;
}

void	pushh(t_eng *eng)
{
	double mx;
	double my;

	if (eng->m[(int)(eng->plaY + PSIZE / 2)][(int)(eng->plaX + PSIZE / 2)] == '1')
	{
		mx = (eng->plaX + PSIZE / 2 - (int)eng->plaX) + STEP / 20;
		my = (eng->plaY + PSIZE / 2 - (int)eng->plaY) + STEP / 20;
		printf("DR MX = %f MY = %f", mx, my);
	}
	if (eng->m[(int)(eng->plaY + PSIZE / 2)][(int)(eng->plaX - PSIZE / 2)] == '1')
	{
		mx = (eng->plaX - PSIZE / 2 - (int)eng->plaX) - STEP / 20;
		my = (eng->plaY + PSIZE / 2 - (int)eng->plaY) + STEP / 20;
		printf("DL MX = %f MY = %f", mx, my);
	}
	if (eng->m[(int)(eng->plaY - PSIZE / 2)][(int)(eng->plaX - PSIZE / 2)] == '1')
	{
		mx = (eng->plaX - PSIZE / 2 - (int)eng->plaX) - STEP / 20;
		my = (eng->plaY - PSIZE / 2 - (int)eng->plaY) - STEP / 20;
		printf("UL MX = %f MY = %f", mx, my);
	}
	if (eng->m[(int)(eng->plaY - PSIZE / 2)][(int)(eng->plaX + PSIZE / 2)] == '1')
	{
		mx = (eng->plaX + PSIZE / 2 - (int)eng->plaX) + STEP / 20;
		my = (eng->plaY - PSIZE / 2 - (int)eng->plaY) - STEP / 20;
		printf("UR MX = %f MY = %f", mx, my);
	}
	if (mx > 1)
		mx = mx - 1;
	if (my > 1)
		my = my - 1;
	mx = fabs(mx);
	my = fabs(my);
	if (mx < my)
	{
		if (eng->m[(int)(eng->plaY + PSIZE / 2)][(int)(eng->plaX + PSIZE / 2)] == '1')
		{
			eng->plaX -= mx;
			printf("1-mx\n");
		}
		if (eng->m[(int)(eng->plaY + PSIZE / 2)][(int)(eng->plaX - PSIZE / 2)] == '1')
		{
			eng->plaX += mx;
			printf("2+mx\n");
		}
		if (eng->m[(int)(eng->plaY - PSIZE / 2)][(int)(eng->plaX - PSIZE / 2)] == '1')
		{
			eng->plaX += mx;
			printf("3+mx\n");
		}
		if (eng->m[(int)(eng->plaY - PSIZE / 2)][(int)(eng->plaX + PSIZE / 2)] == '1')
		{
			eng->plaX -= mx;
			printf("4+mx\n");
		}
	}
	else
	{
		if (eng->m[(int)(eng->plaY + PSIZE / 2)][(int)(eng->plaX + PSIZE / 2)] == '1')
		{
			eng->plaY -= my;
			printf("5-my\n");
		}
		if (eng->m[(int)(eng->plaY + PSIZE / 2)][(int)(eng->plaX - PSIZE / 2)] == '1')
		{
			eng->plaY -= my;
			printf("6-my\n");
		}
		if (eng->m[(int)(eng->plaY - PSIZE / 2)][(int)(eng->plaX - PSIZE / 2)] == '1')
		{
			eng->plaY += my;
			printf("7+my\n");
		}
		if (eng->m[(int)(eng->plaY - PSIZE / 2)][(int)(eng->plaX + PSIZE / 2)] == '1')
		{
			eng->plaY += my;
			printf("8+my\n");
		}
	}
}

void	movement(t_eng *eng)
{
	if (eng->kw == 1 && eng->kd == 1)
	{
		eng->plaX += sin(eng->angV - PI * 0.25) * STEP;
		eng->plaY += cos(eng->angV - PI * 0.25) * STEP;
	}
	else if (eng->kw == 1 && eng->ka == 1)
	{
		eng->plaX += sin(eng->angV + PI * 0.25) * STEP;
		eng->plaY += cos(eng->angV + PI * 0.25) * STEP;
	}
	else if (eng->ks == 1 && eng->kd == 1)
	{
		eng->plaX += sin(eng->angV - PI * 0.75) * STEP;
		eng->plaY += cos(eng->angV - PI * 0.75) * STEP;
	}
	else if (eng->ks == 1 && eng->ka == 1)
	{
		eng->plaX += sin(eng->angV + PI * 0.75) * STEP;
		eng->plaY += cos(eng->angV + PI * 0.75) * STEP;
	}
	else if (eng->kw == 1)
	{
		eng->plaX += sin(eng->angV) * STEP;
		eng->plaY += cos(eng->angV) * STEP;
	}
	else if (eng->ka == 1)
	{
		eng->plaX += sin(eng->angV + PI * 0.5) * STEP;
		eng->plaY += cos(eng->angV + PI * 0.5) * STEP;
	}
	else if (eng->ks == 1)
	{
		eng->plaX += sin(eng->angV - PI) * STEP;
		eng->plaY += cos(eng->angV - PI) * STEP;
	}
	else if (eng->kd == 1)
	{
		eng->plaX += sin(eng->angV - PI * 0.5) * STEP;
		eng->plaY += cos(eng->angV - PI * 0.5) * STEP;
	}
	while (check_wallx(eng))
		check_movex(eng);
	while (check_wally(eng))
		check_movey(eng);
	if (check_wall(eng))
		pushh(eng);
	eng->kr == 1 ? eng->angV += ASTEP : 0;
	eng->kl == 1 ? eng->angV -= ASTEP : 0;
}

void	rotating(t_eng *eng)
{
	if (eng->angV > PI * 2)
		eng->angV -= PI * 2;
	else if (eng->angV < 0)
		eng->angV += PI * 2;
	//printf("angle: %f\n", eng->angV);
	eng->camVX = eng->plaX + sin(eng->angV) * (CSIZE * 1.15);
	eng->camVY = eng->plaY + cos(eng->angV) * (CSIZE * 1.15);
	eng->camRX = sin(eng->angV + PI / 2) * (CSIZE / 2) + eng->plaX;
	eng->camRY = cos(eng->angV + PI / 2) * (CSIZE / 2) + eng->plaY;
	eng->camLX = sin(eng->angV - PI / 2) * (CSIZE / 2) + eng->plaX;
	eng->camLY = cos(eng->angV - PI / 2) * (CSIZE / 2) + eng->plaY;
	//ft_printf("Angle: %f\n", eng->angV);
}

void	verLine(t_eng *eng, int x, int drawStart, int drawEnd, int color)
{
	while (drawStart < drawEnd)
	{
		put_pixel_to_frame(&eng->cub3d, x, drawStart, color);
		drawStart++;
	}
}

void	calcLine(t_eng *eng, double perpWallDist, int x)
{
	//Calculate height of line to draw on screen
    int lineHeight = (int)(eng->ry / perpWallDist);

    //calculate lowest and highest pixel to fill in current stripe
    int drawStart = -lineHeight / 2 + eng->ry / 2;
    if (drawStart < 0)
    	drawStart = 0;
    int drawEnd = lineHeight / 2 + eng->ry / 2;
    if (drawEnd >= eng->ry)
    	drawEnd = eng->ry - 1;
    verLine(eng, x, drawStart, drawEnd, 0xFFFFFF - 0x010101 * (int)(perpWallDist * 2));
}

void	get_side_dist(t_eng *eng, double x, double y, double *sdx, double *sdy, double angle)
{
	printf("[ %f | %f ]\n", x, y);
	if (sin(angle) < 0)
		*sdx = (eng->plaX - (int)eng->plaX);
	else
		*sdy = ((int)eng->plaX + 1.0 - eng->plaX);
	if (cos(angle) < 0)
		*sdy = (eng->plaY - (int)eng->plaY);
	else
		*sdy = ((int)eng->plaY + 1.0 - eng->plaY);
	printf("[ %f | %f ]\n", *sdx, *sdy);
}

void	ray_debug(t_eng *eng, double x, double y, double angle, t_ray r)
{
	//put_circle(&eng->ray, (int)eng->plaX * BLOCK, eng->plaY * BLOCK, 0xef7126);
	//put_circle(&eng->ray, ((int)eng->plaX + 1) * BLOCK, eng->plaY * BLOCK, 0xef7126);
	//put_circle(&eng->ray, eng->plaX * BLOCK, (int)eng->plaY * BLOCK, 0xef7126);
	//put_circle(&eng->ray, eng->plaX * BLOCK, ((int)eng->plaY + 1) * BLOCK, 0xdf7126);

	put_circle(&eng->ray, ((int)eng->plaX) * BLOCK    , ((int)eng->plaY) * BLOCK, 0xaaef7126);
	put_circle(&eng->ray, ((int)eng->plaX + 1) * BLOCK, ((int)eng->plaY) * BLOCK, 0xaaef7126);
	put_circle(&eng->ray, ((int)eng->plaX) * BLOCK    , ((int)eng->plaY + 1) * BLOCK, 0xaaef7126);
	put_circle(&eng->ray, ((int)eng->plaX + 1) * BLOCK, ((int)eng->plaY + 1) * BLOCK, 0xaaef7126);
	//if (eng->plaY > 2 && eng->plaY < eng->msy - 2)
	//	if ((angle > PI * 0.15 && angle < PI * 0.85) || (angle > PI * 1.15 && angle < PI * 1.85))
	//	{
	//		put_circle(&eng->ray, vx1[0] * BLOCK, vx1[1] * BLOCK, 0x0fff31);
	//		put_circle(&eng->ray, vx2[0] * BLOCK, vx2[1] * BLOCK, 0x0fff31);
	//	}
	if (eng->plaX > 2 && eng->plaX < eng->msx - 2)
		if (angle < PI * 0.35 || (angle > PI * 0.65 && angle < PI * 1.35) || angle > PI * 1.65)
		{
			put_circle(&eng->ray, vc1[0] * BLOCK, vc1[1] * BLOCK, 0x0f31ff);
			put_circle(&eng->ray, vc2[0] * BLOCK, vc2[1] * BLOCK, 0x0f31ff);
		}
}

void	shot_ray(t_eng *eng, double x, double y, double angle)
{
	t_ray	r;

	r.vl1[0] = ((int)x);
	r.vl1[1] = (y - (x - (int)x) * (1 / tan(angle)));
	r.vl2[0] = ((int)x + 1);
	r.vl2[1] = (y - ((int)x + 1 - x) * (1 / -tan(angle)));
	r.vc1[0] = (x - (y - (int)y) * tan(angle));
	r.vc1[1] = ((int)y);
	r.vc2[0] = (x - ((int)y + 1 - y) * -tan(angle));
	r.vc2[1] = ((int)y + 1);
	ray_debug(eng, x, y, angle, r);
}

void	raycasting(t_eng *eng)
{
	shot_ray(eng, eng->plaX, eng->plaY, eng->angV);
}

void	renderpl(t_eng *eng)
{
	drawLine(&eng->ray, (eng->plaX - PSIZE / 2) * BLOCK, (eng->plaY - PSIZE / 2) * BLOCK, (eng->plaX + PSIZE / 2) * BLOCK, (eng->plaY - PSIZE / 2) * BLOCK, 0xFF0000);
	drawLine(&eng->ray, (eng->plaX + PSIZE / 2) * BLOCK, (eng->plaY + PSIZE / 2) * BLOCK, (eng->plaX - PSIZE / 2) * BLOCK, (eng->plaY + PSIZE / 2) * BLOCK, 0xFF0000);
	drawLine(&eng->ray, (eng->plaX + PSIZE / 2) * BLOCK, (eng->plaY + PSIZE / 2) * BLOCK, (eng->plaX + PSIZE / 2) * BLOCK, (eng->plaY - PSIZE / 2) * BLOCK, 0xFF0000);
	drawLine(&eng->ray, (eng->plaX - PSIZE / 2) * BLOCK, (eng->plaY + PSIZE / 2) * BLOCK, (eng->plaX - PSIZE / 2) * BLOCK, (eng->plaY - PSIZE / 2) * BLOCK, 0xFF0000);
	put_circle(&eng->ray, eng->plaX * BLOCK, eng->plaY * BLOCK, 0xFF0000);
	put_circle(&eng->ray, eng->camRX * BLOCK, eng->camRY * BLOCK, 0xFF00FF);
	put_circle(&eng->ray, eng->camLX * BLOCK, eng->camLY * BLOCK, 0xFFFF00);
	raycasting(eng);
	//mlx_put_image_to_window(eng->mlx, eng->win, eng->cub3d.img, 0, 0);
	drawArrow(&eng->ray, eng->camVX * BLOCK, eng->camVY * BLOCK, eng->angV, 0xFFFF00);
	mlx_put_image_to_window(eng->mlx, eng->win, eng->frm.img, 0, 0);
	mlx_put_image_to_window(eng->mlx, eng->win, eng->ray.img, 0, 0);
}

void	mouse_hook(t_eng *eng)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (eng->mousex == -16000)
		mlx_mouse_show();
	else
	{
		mlx_mouse_hide();
		mlx_mouse_get_pos(eng->win, &x, &y);
		eng->angV -= (x - eng->msx * BLOCK / 2) * 0.0006;
		mlx_mouse_move(eng->win, eng->msx * BLOCK / 2, eng->msy * BLOCK / 2);
		mlx_mouse_get_pos(eng->win, &eng->mousex, &eng->mousey);
		mlx_mouse_move(eng->win, eng->msx * BLOCK / 2, eng->mousey);
	}
}

int		tick(t_eng *eng)
{
	set_img_transparent(&eng->ray, eng->msx * BLOCK, eng->msy * BLOCK);
	set_img_transparent(&eng->cub3d, eng->rx, eng->ry);
	mlx_clear_window(eng->mlx, eng->win);
	mouse_hook(eng);
	movement(eng);
	rotating(eng);
	drawLine(&eng->ray, eng->camRX * BLOCK, eng->camRY * BLOCK, eng->camLX * BLOCK, eng->camLY * BLOCK, 0x0000FF);
	renderpl(eng);
	return (0);
}

int		key_press(int key, t_eng *eng)
{
	ft_printf("k: %d\n", key);
	if (key == 53)
	{
		ft_printf("\033[1A\033[9D[ESC][EXIT]\n[GAME OVER]\n");
		mlx_destroy_window(eng->mlx, eng->win);
		exit(0);
	}
	key == 10 ? eng->mousex = -16000 : 0;
	key == 13 ? eng->kw = 1 : 0;
	key == 0 ? eng->ka = 1 : 0;
	key == 1 ? eng->ks = 1 : 0;
	key == 2 ? eng->kd = 1 : 0;
	key == 123 ? eng->kr = 1 : 0;
	key == 124 ? eng->kl = 1 : 0;
	eng->kw == 1 && eng->ks == 1 ? eng->ks = 0 : 0;
	eng->kw == 1 && eng->ks == 1 ? eng->kw = 0 : 0;
	eng->ka == 1 && eng->kd == 1 ? eng->ka = 0 : 0;
	eng->ka == 1 && eng->kd == 1 ? eng->kd = 0 : 0;
	//tick(key, &eng[0]);
	return (0);
}

int		key_release(int key, t_eng *eng)
{
	ft_printf("release\n");
	key == 13 ? eng->kw = 0 : 0;
	key == 0 ? eng->ka = 0 : 0;
	key == 1 ? eng->ks = 0 : 0;
	key == 2 ? eng->kd = 0 : 0;
	key == 123 ? eng->kr = 0 : 0;
	key == 124 ? eng->kl = 0 : 0;
	//tick(key, &eng[0]);
	return (0);
}

int		mouse(int button, int x, int y, t_eng *eng)
{
	ft_printf("b: %d\n", button);
	x = y;
	x = button;
	if (eng->mousex == -16000)
	{
		eng->mousex = 1;
		mlx_mouse_move(eng->win, eng->msx * BLOCK / 2, eng->msy * BLOCK / 2);
		mlx_mouse_get_pos(eng->win, &eng->mousex, &eng->mousey);
		mlx_mouse_move(eng->win, eng->msx * BLOCK / 2, eng->mousey);
		mlx_mouse_get_pos(eng->win, &eng->mousex, &eng->mousey);
		ft_printf("%d %d\n", eng->mousex, eng->mousey);
	}
	return (0);
}

void	set_mouse_to_screen(t_eng *eng)
{
	int n;

	mlx_mouse_move(eng->win, eng->msx * BLOCK / 2, eng->msy * BLOCK / 2);
	mlx_mouse_get_pos(eng->win, &n, &eng->mousey);
	mlx_mouse_move(eng->win, eng->msx * BLOCK / 2, eng->mousey);
	ft_printf("MS");
}

void	engine(t_eng eng)
{
	set_mouse_to_screen(&eng);
	ft_printf("Engine BrBrBr\033[95m\n\n");
	mlx_key_hook(eng.win, &key_release, &eng);
	mlx_mouse_hook(eng.win, &mouse, &eng);
	mlx_hook(eng.win, 2, 1L<<0, &key_press, &eng);
	mlx_loop_hook(eng.mlx, &tick, &eng);
    mlx_loop(eng.mlx);
}