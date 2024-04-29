#pragma once
#pragma once
#include <SDL.h>
#include <stdbool.h>


struct SDL init();
void snake(SDL_Renderer* renderer, SDL_Rect* snakeRect);
void handle(SDL_Rect* snakeRect, bool* quit, int* direction);
void rend(SDL_Renderer* renderer, SDL_Rect* snakeRect, SDL_Rect* carre);