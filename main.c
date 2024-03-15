// Created 2021-04-10
// in this file we will use the functions from the header file and the movements file to create a simple game of pong
// the game will have a ball and two players
// the ball will move in the window and bounce off the walls
// the players will be able to move up and down
// the game will end when the ball goes off the screen
// the game will start when the user presses enter
// the game will end when the user presses esc
// the game will be played in a window of size 800x450 !!! IM PLANING ON CHANGING IT LATERR

#include "header.h"

void	inisiaze(t_window *window, t_ball *ball, t_players *player1, t_players *player2)
{
	window->width = 800;
	window->height = 450;
	window->title = "Game window";
	ball->x = window->width / 2;
	ball->y = window->height / 2;
	ball->dx = 8;
	ball->dy = 8;
	ball->speed = 500;
	ball->radius = 8;
	ball->score = 0;
	ball->score2 = 0;
	ball->flag = 0;
	player1->x_pos = 0;
	player1->y_pos = 225;
	player1->speed = 5;
	player1->width = 10;
	player1->height = 90;
	player2->x_pos = 800 - 10;
	player2->y_pos = 225;
	player2->speed = 5;
	player2->width = 10;
	player2->height = 90;
}

void	draw_shapes(t_ball *ball, t_players *player1, t_players *player2)
{
	DrawCircle(ball->x, ball->y, ball->radius, BLACK);
	DrawRectangle(player1->x_pos, player1->y_pos, player1->width, player1->height, RED);
	DrawRectangle(player2->x_pos, player2->y_pos, player2->width, player2->height, BLUE);
}

void	display_scorings(t_ball *ball, t_window *window)
{
	char *score = malloc(100);
	char *score2 = malloc(100);
	sprintf(score, "Player 1: %d", ball->score);
	sprintf(score2, "Player 2: %d", ball->score2);
	DrawText(score, 10, 10, 20, BLACK);
	DrawText(score2, window->width - 120, 10, 20, BLACK);
	free(score);
	free(score2);
}

void main_game()
{
	t_window window;
	t_ball ball;
	t_players player1;
	t_players player2;
	
	inisiaze(&window, &ball, &player1, &player2);
	start_of_the_game(&window);
	while (1) // loop dyal lgame
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);
		draw_shapes(&ball, &player1, &player2);
		ball_movement(&ball);
		player1_movement(&player1);
		player2_movement(&player2);
		goals(&window, &ball, &player1, &player2);
		display_scorings(&ball, &window);
		EndDrawing();
		if (IsKeyDown(KEY_P))
			pause_game(&window);
		if (IsKeyDown(KEY_ESCAPE))
			break;
	}
	game_over(&window, &ball);
}

int main(void)
{
	int i = 0;
	
	main_game();
	CloseWindow();
	return 0;
}