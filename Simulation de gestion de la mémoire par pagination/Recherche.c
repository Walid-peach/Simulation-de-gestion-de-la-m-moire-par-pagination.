#include "Recherche.h"

//****************** Recherche Par Page
void RechercherProg(Page*Debut,char nom[100]){
    int i=1;
    int x=0;
    Page * tmp=Debut;
    while (i<=25) {
        if((tmp->ProgMemoire!=NULL) && (strcmp(tmp->ProgMemoire->Name, nom)==0)){
            printf("\t%d\t| ",tmp->num);
            if(i%5==0) printf("\n----------------|---------------|---------------|---------------|---------------|\n");
            x=tmp->ProgMemoire->Size;
        }
        tmp = tmp->suivant;
        i=i+1;
    }
    if (x==0){
        printf("Aucune page de la memoire");
    }
    else{
        printf("\nSa taille est %d",x);
    }
    printf("\n\n");

}



//************** Trouver
int TrouverProg(Prog *head, char *nom) {
    int x=0;
    Prog *tmp = head;
    while (tmp !=NULL) {
        if(strcmp(tmp->Name, nom)==0){
            x=1;
        }
        tmp = tmp->suivant;
    }
    return x;
}
