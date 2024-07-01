/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diogosan <diogosan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:37:41 by diogosan          #+#    #+#             */
/*   Updated: 2024/06/06 15:56:12 by diogosan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>
# include <sys/wait.h>
# include <signal.h>
# include "libraries/libft/libft.h"
# include "libraries/printf/ft_printf.h"
# include "libraries/get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 600
# define TILE_WIDTH 20
# define TILE_HEIGHT 10


typedef struct s_draw
{
	void		*mlx_conect;
    void		*mlx_win;
}				t_draw;

typedef struct s_square
{
    int         x;
    int         y;
    int         size;
    int         color;
}               t_square;




#endif
