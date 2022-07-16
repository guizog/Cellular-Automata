#include "CA.h"

extern SDL_Renderer* renderer;

std::vector<int> IntToBin(int n){
    std::vector<int> vec = std::vector<int>(8, 0);
    int i = 7;
    while(n > 0 && n < 256){
        vec[i] = n % 2;
        n = n / 2;
        i--;
    }
    return vec;
}

CA::CA(int n, int dec) {
    size = n;
    generation = 0;

    grid = std::vector<std::vector<int>>(size, std::vector<int>(size, 0));
    grid[0][size/2] = 1;

    set = std::vector<int>(8);
    set = IntToBin(dec);
}

CA::~CA() = default;

void CA::generate() {
    std::vector<int> nextgen = std::vector<int>(size, 0);
    for(int i = 1; i < size - 1; i++){
        int left = grid[generation][i-1];
        int mid = grid[generation][i];
        int right = grid[generation][i+1];
        nextgen[i] = set[7-(4*left + 2*mid + right)];
    }
    grid[++generation] = nextgen;
}


void CA::draw() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_FRect rect;
    rect.w = rect.h = 320.0f/(float)size;
    for(int i = 0; i < size; i++){
        for(int j = 0; j <= generation; j++){
            if(grid[j][i]){
                rect.x = (320.0f/(float)size) * (float)i;
                rect.y = (320.0f/(float)size) * (float)j;
                SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
                SDL_RenderDrawRectF( renderer, &rect );
                SDL_RenderFillRectF(renderer, &rect);
            }
        }
    }

    SDL_RenderPresent(renderer);
}




