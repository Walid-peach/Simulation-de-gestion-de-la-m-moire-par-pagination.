#include "Suppression.h"

//******************Supprimer****************
void SupprimerProg(Prog *head,char *nom){
    Prog *tmp = head;
    Prog *tmp2 = NULL;

    if((strcmp(nom, head->Name) == 0)){
        tmp = head;
        head = head->suivant;
        free(tmp);
    }
    else {
        while ((strcmp(tmp->Name, nom)!=0)) {

            tmp2=tmp;
            tmp = tmp->suivant;
        }
        if((strcmp(tmp->Name, nom)==0)) {
            tmp2->suivant = tmp->suivant;
            free(tmp);
        }

        //tmp = NULL;
    }
    //printf("Ce programme a etait bien supprime.\n\n");
}
//*******************Vider***********************
int ViderPage(Page * head,char *nom){
    int i=1;
    Page * tmp = head;
    int taille = 0;
    while (i<=25) {
        if((tmp->ProgMemoire!=NULL) && (strcmp(tmp->ProgMemoire->Name, nom)==0)){
            taille=tmp->ProgMemoire->Size;
            tmp->ProgMemoire=NULL;
        }
        tmp = tmp->suivant;
        i=i+1;
    }
    return taille;
}
