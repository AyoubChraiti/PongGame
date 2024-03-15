// this file contains the functions for the movement of the ball and the players


#include "header.h"

void ball_movement(t_ball *ball)
{
    if (ball->x > 800 - 10 - 10 || ball->x < 10 + 10) // 10 is the radius of the ball and the width of the player
        ball->dx *= -1;
    if (ball->y > 450 - 10 || ball->y < 10)
        ball->dy *= -1;
    ball->x += ball->dx;
    ball->y += ball->dy;
}

void	player1_movement(t_players *player1)
{
	if(IsKeyDown(KEY_W) && player1->y_pos > 0)
		player1->y_pos -= 6;
	if(IsKeyDown(KEY_S) && player1->y_pos < 450 - 90)
		player1->y_pos += 6;
}

void	player2_movement(t_players *player2)
{
	if(IsKeyDown(KEY_UP) && player2->y_pos > 0)
		player2->y_pos -= 6;
	if(IsKeyDown(KEY_DOWN) && player2->y_pos < 450 - 90)
		player2->y_pos += 6;
}

void goals(t_window *window, t_ball *ball, t_players *player1, t_players *player2)
{
	if ((ball->x > 800 - 10 - 10) && (!(player2->y_pos < ball->y && ball->y < player2->y_pos + 90)))
	{
		ball->x = 400;
		ball->y = 225;
		ball->dx *= -1;
		ball->score++;
		ball->flag = 1;
	}
	if ((ball->x < 10 + 10) && (!(player1->y_pos < ball->y && ball->y < player1->y_pos + 90)))
	{
		ball->x = 400;
		ball->y = 225;
		ball->dx *= -1;
		ball->score2++;
		ball->flag = 1;
	}
}
