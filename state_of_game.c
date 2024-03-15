// this file will contain the functions for the state of the game
// the state of the game will be the functions that will be called in the main file


#include "header.h"

void	start_of_the_game(t_window *window)
{
	InitWindow(window->width, window->height, window->title);
	SetTargetFPS(60);
	while (IsKeyUp(KEY_ENTER))
	{
		BeginDrawing();
		DrawText("Press Enter to start the game", 230, window->height / 2, 20, MAGENTA);
		EndDrawing();
	}
}

void	game_over(t_window *window, t_ball *ball)
{
	while(IsKeyUp(KEY_Q) && IsKeyUp(KEY_ENTER))
	{
		BeginDrawing();
		ClearBackground(BLACK);
		// results
		if (ball->score == ball->score2)
			DrawText("It's a draw", window->width / 3, window->height / 4, 20, RAYWHITE);
		if (ball->score > ball->score2)
			DrawText("Player 2 Wins", window->width / 3, window->height / 4, 20, RAYWHITE);
		if (ball->score < ball->score2)
			DrawText("Player 1 Wins", window->width / 3, window->height / 4, 20, RAYWHITE);
		// options
		DrawText("Press Q to Quit", 10, window->height / 2, 20, RAYWHITE);
		DrawText("Press Enter to play again", window->width / 2, window->height / 2, 20, RAYWHITE);
		EndDrawing();
	}
	if (IsKeyDown(KEY_Q))
		CloseWindow();
	if (IsKeyDown(KEY_ENTER))
	{
		ball->score = 0;
		ball->score2 = 0;
		main_game();
	}
}

void	pause_game(t_window *window)
{
	while(IsKeyUp(KEY_P))
	{
		BeginDrawing();
		ClearBackground(BLACK);
		DrawText("Game Paused Click P To Continue", 230, window->height / 2, 20, BLACK);
		EndDrawing();
	}
}
