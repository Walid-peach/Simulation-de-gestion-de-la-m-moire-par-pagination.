#include "Initialiser.h"

int TailleToPages(int a){
    float res;
    res =(float) a/100;

    return ceil(res);
}


//***********************Initier les Pages
Page *Initialisation(Page * Precedent,int num){
    Page * PageLibre = malloc(sizeof(Page));
    PageLibre->num = num;
	PageLibre->suivant = NULL;
	PageLibre->ProgMemoire= NULL;
    if(Precedent!=NULL){
        Precedent->suivant = PageLibre;
    }
    return PageLibre;
}
