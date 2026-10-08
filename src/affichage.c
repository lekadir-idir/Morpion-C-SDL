#include "affichage.h"

void dessin_grille(SDL_Renderer* render, int nbr_case){
        int cpt= TAILLE_CASE;
        couleur F=COULEUR_FOND;
        SDL_SetRenderDrawColor(render,F.r,F.g,F.b,F.a);
        SDL_RenderClear(render);
        couleur C=COULEUR_COLONNE;
        SDL_SetRenderDrawColor(render,C.r,C.g,C.b,C.a);
        while (cpt!=nbr_case*TAILLE_CASE){
        SDL_RenderDrawLine(render,cpt,0,cpt,HAUTEUR);
        cpt+=TAILLE_CASE;
        }
        cpt=TAILLE_CASE;
        while(cpt!=nbr_case*TAILLE_CASE){
        SDL_RenderDrawLine(render,0,cpt,LARGEUR,cpt);
        cpt+=TAILLE_CASE;
        }
};

void dessine_x(SDL_Renderer* render,morpion *m){
couleur CJ1=COULEUR_J1;
couleur CJ2=COULEUR_J2;
for (int i=0;i<=m->nbr_coord;i++){
if (i%2==0) SDL_SetRenderDrawColor(render,CJ1.r,CJ1.g,CJ1.b,CJ1.a);
else  SDL_SetRenderDrawColor(render,CJ2.r,CJ2.g,CJ2.b,CJ2.a);
SDL_RenderDrawLine(render,m->tab_coord[i].x*TAILLE_CASE,m->tab_coord[i].y*TAILLE_CASE,m->tab_coord[i].x*TAILLE_CASE+TAILLE_CASE,m->tab_coord[i].y*TAILLE_CASE+TAILLE_CASE);
SDL_RenderDrawLine(render,m->tab_coord[i].x*TAILLE_CASE,m->tab_coord[i].y*TAILLE_CASE+TAILLE_CASE,m->tab_coord[i].x*TAILLE_CASE+TAILLE_CASE,m->tab_coord[i].y*TAILLE_CASE);
}
}


void affichage_finale(int actuel){
if(actuel==1) fprintf(stderr,"LE JOUEUR 1 A GAGNE !!!!!!");
else if (actuel==2) fprintf(stderr,"LE JOUEUR 2 A GAGNE !!!!!!");
else if(actuel==3) fprintf(stderr,"MATCH NULL !!!!!!");
else fprintf(stderr,"PARTIE ABANDONNER !!!!!!");

}

void running(SDL_Renderer* render,morpion *m){

        SDL_Event event;
        int i,j;
        int actuel =mise_a_jour(m);
        while(m->running && actuel==EN_PLEIN_MATCH){
                dessin_grille(render,N);
                dessine_x(render,m);
                SDL_RenderPresent(render);
                while(SDL_PollEvent(&event) && actuel==EN_PLEIN_MATCH){
                        if (event.type==SDL_QUIT) m->running=0;
                        if(event.type==SDL_KEYDOWN && event.key.keysym.sym==SDLK_ESCAPE) m->running=0;
                        if(verification(m) && event.type==SDL_MOUSEBUTTONDOWN) {
                                int case_vide=joue(&i,&j,m,&event);
                                if(case_vide){
                                        m->nbr_coord++;
                                        m->mat[i][j]=m->a_qui_de_jouer;
                                        m->tab_coord[m->nbr_coord].x=i;
                                        m->tab_coord[m->nbr_coord].y=j;
                                        changement_de_joueur(m);
                                        actuel=mise_a_jour(m);
                                }
                        }
                }
        }

affichage_finale(actuel);
}

void clean(SDL_Window* window,SDL_Renderer* render){
SDL_DestroyRenderer(render);
SDL_DestroyWindow(window);
SDL_Quit();
}
