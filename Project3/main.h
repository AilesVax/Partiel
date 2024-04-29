#pragma once
#include <SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL_events.h>
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 600
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
struct SDL {
    SDL_Window* window;
    SDL_Renderer* renderer;
};