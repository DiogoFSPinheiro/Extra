/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:29:30 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/06 16:39:54 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

int size = 10;
int color = 0x0000ff;
int follow = 0;

void ft_draw_square(t_square *square, t_draw *draw);

int get_color()
{
        return (rand() % 2147483647);
}

int	ft_close(t_draw *draw)
{
    mlx_destroy_window(draw->mlx_conect, draw->mlx_win);
    mlx_destroy_display(draw->mlx_conect);
    free(draw->mlx_conect);
    free(draw);
    exit(EXIT_SUCCESS);
    return (0);
}

int	ft_event_checker(int Key, t_draw *draw)
{
	t_draw *img;

    img = (t_draw *)draw;
    if (Key == XK_Escape)
        ft_close(draw);
    else if(Key == XK_Return )
        ft_draw_square(&(t_square){0, 0, WIDTH, 0x000000}, draw);
    else if (Key == XK_Tab)
        color = get_color();
    else if (Key == XK_Delete)
    {
        follow = !follow;
    }
        
	
    return (0);
}

void ft_draw_square(t_square *square, t_draw *draw)
{
    int    i;
    int    j = 0;

    i = 0;
    while (i < square->size && i + square->y < HEIGHT)
    {
        while(j < square->size && i + square->x < WIDTH)
        {
            mlx_pixel_put(draw->mlx_conect, draw->mlx_win, square->x + j, square->y + i, square->color);
            j++;
        }
        j = 0;
        i++;
    }

}

int ft_read_mouse(int button, int mouse_x, int mouse_y, void *param)
{
    int x;
    int y;
    t_draw 		*draw;
	t_square	s;

    draw = (t_draw *) param;
	if (!draw)
		return (-1);
    if (mouse_x < 0 || mouse_x > WIDTH || mouse_y < 0 || mouse_y > HEIGHT)
        return 2;
    x = (mouse_x / size) * size;
    y = (mouse_y / size) * size;
    s = (t_square){x, y, size, color};
	ft_draw_square(&s, draw);
	(void)button;
	return (0);
}

int ft_follow_mouse(int mouse_x, int mouse_y, void *param)
{
    int x;
    int y;
    t_draw 		*draw;
	t_square	s;

    draw = (t_draw *) param;
	if (!draw)
		return (-1);
    if (mouse_x < 0 || mouse_x > WIDTH || mouse_y < 0 || mouse_y > HEIGHT)
        return 2;
    if (!follow)
        return 3;
    x = (mouse_x / size) * size;
    y = (mouse_y / size) * size;
    s = (t_square){x, y, size, color};
	ft_draw_square(&s, draw);
	return (0);
}

int	main(void)
{
    t_draw		*draw;
	void		*mlx_conect;
    void		*mlx_win;
	// iniciar connection com o X server
	mlx_conect = mlx_init();
	// abrir uma nova janela
	mlx_win = mlx_new_window(mlx_conect, WIDTH, HEIGHT, "my window");
	draw = (t_draw *)malloc(sizeof(t_draw));
	draw->mlx_conect = mlx_conect;
	draw->mlx_win = mlx_win;

    mlx_hook(mlx_win, MotionNotify, PointerMotionMask, &ft_follow_mouse, draw);
    ft_draw_square(&(t_square){200, 500, 50, 0x0000ff}, draw);
	mlx_mouse_hook(mlx_win, &ft_read_mouse, draw); // mlx_mouse_hook (win_ptr, read_mouse, param); segue o mouse
                
    
	mlx_hook(mlx_win, KeyPress, KeyPressMask, &ft_event_checker, draw);
	mlx_hook(mlx_win, 17, 0, &ft_close, draw);
    
	
    mlx_loop(mlx_conect); // loop de render
}