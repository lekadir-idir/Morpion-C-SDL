#include<stdio.h>
#include<stdlib.h>
#include<SDL2/SDL.h>

#define LARGEUR 900
#define HAUTEUR 900
#define N 3
#define TAILLE_CASE LARGEUR/N
#define COULEUR_FOND {255,255,255,255}
#define COULEUR_LIGNE {0,0,255,255}
#define COULEUR_COLONNE {0,0,255,255}
#define J1 1
#define J2 100
#define COULEUR_J1 {255, 0, 0,255}
#define COULEUR_J2 {0,0,0,0}
#define J1_A_GAGNE 1
#define J2_A_GAGNE 2
#define MATCH_NULL 3
#define EN_PLEIN_MATCH 4
typedef struct morpion{
        int running ;
        int mat[N][N];
        int a_qui_de_jouer;
        SDL_Point tab_coord[N*N];
        int nbr_coord;
}morpion;
int init_morpion(SDL_Window* window ,SDL_Renderer* render,morpion* m);
void cherche_indice(int *i,int *j);
int joue(int* i,int* j,morpion* m,SDL_Event *event);
int verification (morpion *m);
void changement_de_joueur(morpion* m);
int verif_ligne(morpion *m,int J);
int verif_colonne(morpion* m,int J);
int verif_diag(morpion* m,int J);
int verif_antidiag(morpion* m,int J);
int mise_a_jour(morpion* m);
