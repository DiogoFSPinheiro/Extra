/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:44:06 by diogosan          #+#    #+#             */
/*   Updated: 2024/05/29 14:56:57 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

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
	if (Key == XK_Escape || Key == XK_Tab)
		ft_close(draw);
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

	int c = 0;
	int i = 0;
	while(i < 100)
	{
		while(c < 50)
		{
			mlx_pixel_put(mlx_conect, mlx_win, 250 + c, 250 + c + i, 0xffffff);
			mlx_pixel_put(mlx_conect, mlx_win, 250 + c +i, 250 + c , 0xff0000);
			c++;
		}
		c = 0;
		i++;
	}
	i = c = 0;

	while(i < 100)
	{
		while(c < 99)
		{
			mlx_pixel_put(mlx_conect, mlx_win, 300 + c, 300 + i, 0x0000ff);
			c++;
		}
		c = 0;
		i++;
	}
    
	mlx_hook(mlx_win, KeyPress, KeyPressMask, &ft_event_checker, draw);
	mlx_hook(mlx_win, 17, 0, &ft_close, draw);
	mlx_loop(mlx_conect); // loop de render
}