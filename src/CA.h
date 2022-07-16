#ifndef SDL_CELULARAUTOMATA_CA_H
#define SDL_CELULARAUTOMATA_CA_H

#include <iostream>
#include <SDL.h>
#include <vector>

class CA {
public:
    CA(int n, int dec);
    ~CA();

    std::vector<std::vector<int>> grid;
    std::vector<int> set;
    int generation;
    int size;

    void generate();
    void draw();

private:

};


#endif //SDL_CELULARAUTOMATA_CA_H
