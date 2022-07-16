#include "CA.h"

void Init(const char*, int, int, int, int);

SDL_Renderer *renderer;
SDL_Window *window;

bool running = false;
CA *ca = new CA(100, 77);

int main(int argc, char* args[]) {
    Init("Celular Automata", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 320, 320);

    while(running){
        if(ca->generation < ca->size - 1) {
            ca->generate();
            ca->draw();
            SDL_Delay(200);
        }
        else{
            break;
        }
    }

    SDL_Delay(1000);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}

void Init(const char *title, int xpos, int ypos, int width, int height) {
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        window = SDL_CreateWindow(title, xpos, ypos, width, height, 0);
        std::cout << "Window status: " << ((window) ? "Initialized" : SDL_GetError()) << std::endl;
        renderer = SDL_CreateRenderer(window, -1, 0);
        std::cout << "Renderer status: " << ((renderer) ? "Initialized" : SDL_GetError()) << std::endl;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        running = true;
    }
    else
        running = false;
}