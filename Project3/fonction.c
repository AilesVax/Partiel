#include <SDL.h>
#include "fonction.h"
#include "main.h"
#include <SDL_events.h>
#include "manger.h"
struct SDL init()
{
    // init SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Failed to load SDL\n");
        exit(EXIT_FAILURE);
    }
    // create SDL window
    SDL_Window* window = SDL_CreateWindow("Red square moving",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Failed to create window\n");
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    // create render 
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL) {
        printf("Failed to create renderer\n");
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }

    return (struct SDL) { window, renderer };
}

void snake(SDL_Renderer* renderer, SDL_Rect* snakeRect) {
    
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, snakeRect);
}
void mouv(int* direction, SDL_Rect* snakeRect) {
    switch (*direction) {
    case UP:
        if (snakeRect->y > 0) {
            snakeRect->y -= 5;
        }
        break;
    case DOWN:
        if (snakeRect->y < WINDOW_HEIGHT - snakeRect->h) {
            snakeRect->y += 5;
        }
        break;
    case LEFT:
        if (snakeRect->x > 0) {
            snakeRect->x -= 5;
        }
        break;
    case RIGHT:
        if (snakeRect->x < WINDOW_WIDTH - snakeRect->w) {
            snakeRect->x += 5;
        }
        break;
    }
}
void handle(SDL_Rect* snakeRect, bool* quit, int* direction)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *quit = true;
        }
        else if (event.type == SDL_KEYDOWN) {
            SDL_Keycode key = event.key.keysym.sym;
            if (key == SDLK_UP && *direction != DOWN && snakeRect->y > 0) {
                *direction = UP;
            }
            else if (key == SDLK_DOWN && *direction != UP && snakeRect->y < WINDOW_HEIGHT - snakeRect->h) {
                *direction = DOWN;
            }
            else if (key == SDLK_LEFT && *direction != RIGHT && snakeRect->x > 0) {
                *direction = LEFT;
            }
            else if (key == SDLK_RIGHT && *direction != LEFT && snakeRect->x < WINDOW_WIDTH - snakeRect->w) {
                *direction = RIGHT;
            }
        }
    }
    mouv(direction, snakeRect);
}


void rend(SDL_Renderer* renderer, SDL_Rect* snakeRect, SDL_Rect* carre) {

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); 
    SDL_RenderClear(renderer);
    snake(renderer, snakeRect);
    bouffe(renderer, carre);
    SDL_RenderPresent(renderer);
}