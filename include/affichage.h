#include <SDL2/SDL.h>
#include "morpion.h"

typedef struct couleur{
    int r,g,b,a;
}couleur;

void dessin_grille(SDL_Renderer* render, int nbr_case);
void dessine_x(SDL_Renderer* render,morpion *m);
void affichage_finale(int actuel);
void running(SDL_Renderer* render,morpion *m);
void clean(SDL_Window* window,SDL_Renderer* render);
