
#include "affichage.h"

int main(){
        morpion m;
        SDL_Window* window=SDL_CreateWindow("Morpion by LEKADIR IDIR ",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,LARGEUR,HAUTEUR,0);
        SDL_Renderer* render=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        if (!window || !render){
                        fprintf(stderr,"erreur:%s\n",SDL_GetError());
                        return 1;
        }
        if (init_morpion(window,render,&m)) {
                        fprintf(stderr,"erreur :%s \n",SDL_GetError());
                        return 1;
        }
        running(render,&m);
        clean(window,render);
return 0;
}
