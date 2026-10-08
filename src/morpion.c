#include "morpion.h"
int init_morpion(SDL_Window* window ,SDL_Renderer* render,morpion* m){
	(void)window;
	(void)render;
        if(SDL_Init(SDL_INIT_EVERYTHING)) return 1;
        m->running=1;
        m->a_qui_de_jouer=J1;
        m->nbr_coord=-1;
        for(int i=0;i<N;i++)
                for(int j=0;j<N;j++) m->mat[i][j]=0;

        for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                        m->mat[i][j]=0;
                        m->tab_coord[i].x=0;
                        m->tab_coord[i].y=0;
                }
        }
return 0;
}
void cherche_indice(int *i,int *j){
*i/=TAILLE_CASE;
*j/=TAILLE_CASE;

}
int joue(int* i,int* j,morpion* m,SDL_Event *event){

        *i=event->button.x;
        *j=event->button.y;
        printf("un clique sur (%d,%d)\n",*i,*j);
        cherche_indice(i,j);
         return (!m->mat[*i][*j]);
}
int verification (morpion *m){
 for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        if(!m->mat[i][j]) return 1;

return 0;
}
void changement_de_joueur(morpion* m){
 if(m->a_qui_de_jouer==J1) m->a_qui_de_jouer=J2;
 else m->a_qui_de_jouer=J1;

}
int verif_ligne(morpion *m,int J){
        int som=0;
        for(int j=0;j<N;j++){
                for(int i=0;i<N;i++){
                        som+=m->mat[i][j];
                }
           if(som==N*J) return 1;
           som=0;
        }
return 0;
}

int verif_colonne(morpion* m,int J){
        int som=0;
        for(int j=0;j<N;j++){
               for(int i=0;i<N;i++){
                        som+=m->mat[j][i];
                }
           if(som==N*J) return 1;
                som=0;
        }
return 0;
}

int verif_diag(morpion* m,int J){
        int som=0;
        for(int j=0;j<N;j++){
                for(int i=0;i<N;i++){
                if (i==j) som+=m->mat[i][j];
                }
        }
if(som==N*J) return 1;
return 0;

}
int verif_antidiag(morpion* m,int J){
        int som=0;

for (int i = 0; i < N; i++) {
        int j = N - 1 - i;
        som += m->mat[i][j];
    }
if(som==N*J) return 1;
return 0;


}
int mise_a_jour(morpion* m){
if(verif_ligne(m,J1)) return J1_A_GAGNE;
if(verif_ligne(m,J2)) return J2_A_GAGNE;
if(verif_colonne(m,J1)) return J1_A_GAGNE;
if(verif_colonne(m,J2)) return J2_A_GAGNE;
if(verif_diag(m,J1))return J1_A_GAGNE;
if(verif_diag(m,J2))return J2_A_GAGNE;
if(verif_antidiag(m,J1))return J1_A_GAGNE;
if(verif_antidiag(m,J2))return J2_A_GAGNE;
if (verification(m)) return EN_PLEIN_MATCH;
return MATCH_NULL;
}
