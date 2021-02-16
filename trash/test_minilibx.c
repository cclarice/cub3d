#include <mlx.h>
//
//typedef struct  s_data {
//    void        *img;
//    char        *addr;
//    int         bits_per_pixel;
//    int         line_length;
//    int         endian;
//}               t_data;
//
//typedef struct  s_vars {
//    void        *img;
//    char        *addr;
//    int         bits_per_pixel;
//    int         line_length;
//    int         endian;
//    int         color;
//    int         x;
//    int         y;
//    void        *mlx;
//    void        *mlx_win;
//    void        *mlx_win2;
//}               t_vars;
//
//void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//    char    *dst;
//
//    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//    *(unsigned int*)dst = color;
//}
//
//int            khook(void *arg)
//{
//    t_vars *vars = (t_vars *)arg;
//
//    vars->img = mlx_new_image(vars->mlx, 1200, 1200);
//    vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
//    while (vars->x < 1190)
//    {
//        while (vars->y < 1190)
//        {
//            my_mlx_pixel_put(vars->img, vars->x, vars->y, (0 << 16 | 200 << 8 | vars->x + vars->y));
//            vars->y++;
//        }
//        vars->x++;
//        vars->y = 10;
//    }
//    mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
//    vars->x = 10;
//    return 0;
//}          
//
//int             main(void)
//{
//    t_vars  vars;
//    vars.color = 0;
//    vars.x = 10;
//    vars.y = 10;
//    vars.mlx = mlx_init();
//    vars.mlx_win = mlx_new_window(vars.mlx, 1200, 1200, "Hello world!");
//    vars.mlx_win2 = mlx_new_window(vars.mlx, 1200, 1200, "Hello world pizda!");
//    mlx_loop_hook(vars.mlx, khook, &vars);
//    mlx_loop(vars.mlx);
//}




#include <mlx.h>
#include <stdio.h>

typedef struct  s_vars {
    void        *mlx;
    void        *win;
    int			x;
    int			y;
    int			color;
}               t_vars;

int            khook(void *arg)
{
	t_vars *vars = (t_vars *)arg;

	while (vars->x < 1296)
	{
		if (vars->color > 0xFFFFFF)
			vars->color = 0x000001;
		while (vars->y++ < 1296)
    		mlx_pixel_put(vars->mlx, vars->win, vars->x, vars->y, 0xF0FA1212);
    	vars->y = 50;
    	vars->x++;
	}
	vars->x = 50;
    return (1);
}

int             close(int keycode, t_vars *vars)
{
	printf("%d\n", keycode);
	//mlx_mouse_move(vars->win, 168, 168);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		return (-1);
	}
	return (0);
}

int             main(void)
{
    t_vars      vars;

    vars.color = 1;
    vars.x = 50;
    vars.y = 50;
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    mlx_loop_hook(vars.mlx, khook, &vars);
    mlx_key_hook(vars.win, close, &vars);
    mlx_loop(vars.mlx);
    return (0);
} 


//#include "mlx.h"
//
//int     render_next_frame(void *YourStruct);
//
//int		main()
//{
//	void    *mlx_ptr;
//	void	*win_ptr;
//	int		x;
//	int		y;
//	int		color;
//	void	*param;
//
//	y = 50;
//	x = 50;
//	param = 0;
//	color = 16777214;
//	mlx_ptr = 0;
//	win_ptr = 0;
//	mlx_ptr = mlx_init();
//	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Title");
//	y = 50;
//	while (1)
//	{
//		while (y++ < 450)
//	    {
//	        x = 50;
//	        while (x++ < 450)
//	        {
//	            mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
//	            if (color > 16777214)
//	    			color = 0;
//	    		color++;
//	        }
//	    }
//    mlx_loop_hook(mlx_ptr, render_next_frame, param);
//	mlx_loop(mlx_ptr);
//    }
//	return (0);
//}
//
//



//cc cube3d.c -L mlx/ -lmlx -framework OpenGL -framework AppKit