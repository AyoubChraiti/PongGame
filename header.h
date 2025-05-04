/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achraiti <achraiti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 01:55:35 by achraiti          #+#    #+#             */
/*   Updated: 2024/03/15 03:46:01 by achraiti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include "/opt/homebrew/opt/raylib/include/raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

typedef struct s_window
{
    int             width;
    int             height;
    char            *title;
}                   t_window;

typedef struct s_ball
{
    int             x;
    int             y;
    int             dx;
    int             dy;
    int             speed;
    int             radius;
    int             score;
    int             score2;
    int             flag;
}                   t_ball;

typedef struct s_players
{
    int             x_pos;
    int             y_pos;
    int             speed;
    int             width;
    int             height;
}                   t_players;

void	game_over(t_window *window, t_ball *ball);
void	start_of_the_game(t_window *window);
void	player2_movement(t_players *player2);
void	player1_movement(t_players *player1);
void    ball_movement(t_ball *ball);
void    goals(t_window *window, t_ball *ball, t_players *player1, t_players *player2);
void	pause_game(t_window *window);
void    main_game();

#endif