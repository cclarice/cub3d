/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclarice <cclarice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 07:26:55 by cclarice          #+#    #+#             */
/*   Updated: 2021/02/11 06:57:59 by cclarice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

/*
**	Event Category						Event Type
**	Keyboard events						KeyPress, KeyRelease
**	Pointer events						ButtonPress, ButtonRelease, MotionNotify
**	Window crossing events				EnterNotify, LeaveNotify
**	Input focus events					FocusIn, FocusOut
**	Keymap state notification event		KeymapNotify
**	Exposure events						Expose, GraphicsExpose, NoExpose
**	Structure control events			CirculateRequest, ConfigureRequest, MapRequest, ResizeRequest
**	Window state notification events	CirculateNotify, ConfigureNotify, CreateNotify, DestroyNotify, GravityNotify, MapNotify, MappingNotify, ReparentNotify, UnmapNotify, VisibilityNotify
**	Colormap state notification event	ColormapNotify
**	Client communication events			ClientMessage, PropertyNotify, SelectionClear, SelectionNotify, SelectionRequest
*/

#define ZeroEvent			0
#define OneEvent			1
#define KeyPress			2
#define KeyRelease			3
#define ButtonPress			4
#define ButtonRelease		5
#define MotionNotify		6
#define EnterNotify			7
#define LeaveNotify			8
#define FocusIn				9
#define FocusOut			10
#define KeymapNotify		11
#define Expose				12
#define GraphicsExpose		13
#define NoExpose			14
#define VisibilityNotify	15
#define CreateNotify		16
#define DestroyNotify		17
#define UnmapNotify			18
#define MapNotify			19
#define MapRequest			20
#define ReparentNotify		21
#define ConfigureNotify		22
#define ConfigureRequest	23
#define GravityNotify		24
#define ResizeRequest		25
#define CirculateNotify		26
#define CirculateRequest	27
#define PropertyNotify		28
#define SelectionClear		29
#define SelectionRequest	30
#define SelectionNotify		31
#define ColormapNotify		32
#define ClientMessage		33
#define MappingNotify		34
#define GenericEvent		35
#define LASTEvent			36

int		mouse(t_eng *e)
{
	ft_printf("mouse detected\n");
	return (0);
}

int		key(t_eng *e)
{
	ft_printf("key detected\n");
	return (0);
}

int		zero_event(int hook, t_eng *e)
{
	ft_printf("ZeroEvent detected [%d]\n", hook);
	return (0);
}
int		one_event(int hook, t_eng *e)
{
	ft_printf("OneEvent detected [%d]\n", hook);
	return (0);
}

int		key_press(int hook, t_eng *e)
{
	ft_printf("KeyPress detected [%d]\n", hook);
	return (0);
}

int		key_release(int hook, t_eng *e)
{
	ft_printf("KeyRelease detected [%d]\n", hook);
	return (0);
}

int		button_press(int hook, t_eng *e)
{
	ft_printf("ButtonPress detected [%d]\n", hook);
	return (0);
}

int		button_release(int hook, t_eng *e)
{
	ft_printf("ButtonRelease detected [%d]\n", hook);
	return (0);
}

int		motion_notify(int a, int b, t_eng *e)
{
	ft_printf("MotionNotify detected [%d][%d]\n", a, b);
	return (0);
}

int		enter_notify(int hook, t_eng *e)
{
	ft_printf("EnterNotify detected [%d]\n", hook);
	return (0);
}

int		leave_notify(int hook, t_eng *e)
{
	ft_printf("LeaveNotify detected [%d]\n", hook);
	return (0);
}

int		focus_in(int hook, t_eng *e)
{
	ft_printf("FocusIn detected [%d]\n", hook);
	return (0);
}

int		focus_out(int hook, t_eng *e)
{
	ft_printf("FocusIn detected [%d]\n", hook);
	return (0);
}

int		expose(int hook, t_eng *e)
{
	ft_printf("Expose detected [%d]\n", hook);
	return (0);
}

int		graphics_expose(int hook, t_eng *e)
{
	ft_printf("GraphicsExpose detected [%d]\n", hook);
	return (0);
}

int		no_expose(int hook, t_eng *e)
{
	ft_printf("NoExpose detected [%d]\n", hook);
	return (0);
}

int		visibility_notify		(int hook, t_eng *e)
{
	ft_printf("ХVisibilityNotify detected [%d]\n", hook);
	return (0);
}
	
int		create_notify			(int hook, t_eng *e)
{
	ft_printf("ХCreateNotify detected [%d]\n", hook);
	return (0);
}
		
int		destroy_notify			(int hook, t_eng *e)
{
	ft_printf("ХDestroyNotify detected [%d]\n", hook);
	return (0);
}
		
int		unmap_notify			(int hook, t_eng *e)
{
	ft_printf("ХUnmapNotify detected [%d]\n", hook);
	return (0);
}
			
int		map_notify				(int hook, t_eng *e)
{
	ft_printf("ХMapNotify detected [%d]\n", hook);
	return (0);
}
			
int		map_request				(int hook, t_eng *e)
{
	ft_printf("ХMapRequest detected [%d]\n", hook);
	return (0);
}
			
int		reparent_notify			(int hook, t_eng *e)
{
	ft_printf("ХReparentNotify detected [%d]\n", hook);
	return (0);
}
		
int		configure_notify		(int hook, t_eng *e)
{
	ft_printf("ХConfigureNotify	 detected [%d]\n", hook);
	return (0);
}
	
int		configure_request		(int hook, t_eng *e)
{
	ft_printf("ХConfigureRequest detected [%d]\n", hook);
	return (0);
}
	
int		gravity_notify			(int hook, t_eng *e)
{
	ft_printf("ХGravityNotify detected [%d]\n", hook);
	return (0);
}
		
int		resize_request			(int hook, t_eng *e)
{
	ft_printf("ХResizeRequest detected [%d]\n", hook);
	return (0);
}
		
int		circulate_notify		(int hook, t_eng *e)
{
	ft_printf("ХCirculateNotify detected [%d]\n", hook);
	return (0);
}
		
int		circulate_request		(int hook, t_eng *e)
{
	ft_printf("ХCirculateRequest detected [%d]\n", hook);
	return (0);
}
	
int		property_notify			(int hook, t_eng *e)
{
	ft_printf("ХPropertyNotify detected [%d]\n", hook);
	return (0);
}
		
int		selection_clear			(int hook, t_eng *e)
{
	ft_printf("ХSelectionClear detected [%d]\n", hook);
	return (0);
}
		
int		selection_request		(int hook, t_eng *e)
{
	ft_printf("ХSelectionRequest detected [%d]\n", hook);
	return (0);
}
	
int		selection_notify		(int hook, t_eng *e)
{
	ft_printf("ХSelectionNotify detected [%d]\n", hook);
	return (0);
}
	
int		colormap_notify			(int hook, t_eng *e)
{
	ft_printf("ХColormapNotify detected [%d]\n", hook);
	return (0);
}
		
int		client_message			(int hook, t_eng *e)
{
	ft_printf("ХClientMessage detected [%d]\n", hook);
	return (0);
}
		
int		mapping_notify			(int hook, t_eng *e)
{
	ft_printf("ХMappingNotify detected [%d]\n", hook);
	return (0);
}
		
int		generic_event			(int hook, t_eng *e)
{
	ft_printf("ХGenericEvent detected [%d]\n", hook);
	return (0);
}
		
int		last_event				(int hook, t_eng *e)
{
	ft_printf("ХLASTEvent detected [%d]\n", hook);
	return (0);
}
			

int		tick(int hook, t_eng *e)
{
	ft_printf("Tick [%d]\n", hook);
	return (0);
}

void	engine(t_eng *e)
{
	ft_printf("Run Engine\n");
	mlx_put_image_to_window(e->mlx, e->win, e->lma.img, 0, 0);
	//mlx_mouse_hook(e->win, &mouse, &e);
	//mlx_key_hook(e->win, &key, &e);
	//mlx_expose_hook(e->win, &expose, &e);
	mlx_hook(e->win,	ZeroEvent			, 0L, &zero_event			, &e);
	mlx_hook(e->win,	OneEvent			, 0L, &one_event			, &e);
	mlx_hook(e->win,	KeyPress			, 0L, &key_press			, &e); // +
	mlx_hook(e->win,	KeyRelease			, 0L, &key_release			, &e); // +
	mlx_hook(e->win,	ButtonPress			, 0L, &button_press			, &e); // +
	mlx_hook(e->win,	ButtonRelease		, 0L, &button_release		, &e); // +
	mlx_hook(e->win,	MotionNotify		, 0L, &motion_notify		, &e); // If spam just comment // +
	//mlx_hook(e->win,	EnterNotify			, 0L, &enter_notify			, &e); // Only with more than one window
	//mlx_hook(e->win,	LeaveNotify			, 0L, &leave_notify			, &e); // Only with more than one window
	//mlx_hook(e->win,	FocusIn				, 0L, &focus_in				, &e); // Windows Focus
	//mlx_hook(e->win,	FocusOut			, 0L, &focus_out			, &e); // Windows Focus
	mlx_hook(e->win,	Expose				, 0L, &expose				, &e); // +
	//mlx_hook(e->win,	GraphicsExpose		, 0L, &graphics_expose		, &e); // Hz
	//mlx_hook(e->win,	NoExpose			, 0L, &no_expose			, &e); // Hz
	//mlx_hook(e->win,	VisibilityNotify	, 0L, &visibility_notify	, &e);
	//mlx_hook(e->win,	CreateNotify		, 0L, &create_notify		, &e);
	mlx_hook(e->win,	DestroyNotify		, 0L, &destroy_notify		, &e);
	//mlx_hook(e->win,	UnmapNotify			, 0L, &unmap_notify			, &e);
	//mlx_hook(e->win,	MapNotify			, 0L, &map_notify			, &e);
	//mlx_hook(e->win,	MapRequest			, 0L, &map_request			, &e); // Hz
	//mlx_hook(e->win,	ReparentNotify		, 0L, &reparent_notify		, &e);
	//mlx_hook(e->win,	ConfigureNotify		, 0L, &configure_notify		, &e);
	//mlx_hook(e->win,	ConfigureRequest	, 0L, &configure_request	, &e);
	//mlx_hook(e->win,	GravityNotify		, 0L, &gravity_notify		, &e);
	//mlx_hook(e->win,	ResizeRequest		, 0L, &resize_request		, &e); // Hz
	//mlx_hook(e->win,	CirculateNotify		, 0L, &circulate_notify		, &e);
	//mlx_hook(e->win,	CirculateRequest	, 0L, &circulate_request	, &e);
	//mlx_hook(e->win,	PropertyNotify		, 0L, &property_notify		, &e);
	//mlx_hook(e->win,	SelectionClear		, 0L, &selection_clear		, &e); // Hz
	//mlx_hook(e->win,	SelectionRequest	, 0L, &selection_request	, &e); // Hz
	//mlx_hook(e->win,	SelectionNotify		, 0L, &selection_notify		, &e); // Hz
	//mlx_hook(e->win,	ColormapNotify		, 0L, &colormap_notify		, &e);
	//mlx_hook(e->win,	ClientMessage		, 0L, &client_message		, &e);
	//mlx_hook(e->win,	MappingNotify		, 0L, &mapping_notify		, &e);
	//mlx_hook(e->win,	GenericEvent		, 0L, &generic_event		, &e);
	//mlx_hook(e->win,	LASTEvent			, 0L, &last_event			, &e);
	mlx_loop_hook(e->win, &tick, &e);
	mlx_loop(e->mlx);
}