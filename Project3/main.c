#include <stdio.h>
#include <SDL.h> 
#include <stdbool.h>
#include "main.h"
#include "fonction.h"

int main(int argc, char* argv[]) {
  
    struct SDL valeurs = init();
    SDL_Window* window = valeurs.window;
    SDL_Renderer* renderer = valeurs.renderer;
    int n = rand() % 300;
    int a = rand() % 200;

    SDL_Rect snakeRect = { 300, 200, 20, 20 }; 
    SDL_Rect carre = { n, a, 20, 20 };
    int direction = RIGHT;
    bool quit = false;
    while (!quit) {
        rend(renderer, &snakeRect,&carre);

        handle(&snakeRect, &quit, &direction);
    }

    // Libérer la mémoire et quitter SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}