#include "manger.h"

void bouffe(SDL_Renderer* renderer, SDL_Rect* carre) {

    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 0);
    SDL_RenderFillRect(renderer, carre);
}