#include "Affichage.h"

//***************Affichage des Progs**************
void AfficherProg(Prog *head) {
    Prog *tmp = head;
    while (tmp != NULL) {
        printf("%s ", tmp->Name);
        tmp = tmp->suivant;
    }
    printf("\n");
}
//***************Affichage des Pages Libres**************

void AfficherPage(Page *head) {
    int i=1;
    Page *tmp = head;
    while (i<=25) {
        if(tmp->ProgMemoire==NULL){
            printf("%d ", tmp->num);
        }
        tmp = tmp->suivant;
        i=i+1;
    }
    printf("\n");
}

void AfficherPageOccuper(Page *head) {
    int i=1;
    Page *tmp = head;
    printf("les pages occupees sont:\n");
    while (i<=25) {
        if(tmp->ProgMemoire!=NULL){
            printf("%d\t", tmp->num);
            printf("%s\t\n",tmp->ProgMemoire->Name);
        }
        tmp = tmp->suivant;
        i=i+1;
    }
    printf("\n");
}


//****************** Afficher toutes la memoire
void AfficherMemoire(Page * Debut){
        int i,j;
        Page * tmp = Debut;
        printf("-------------------Memoire Centrale-----------------\n");
            for (i=1 ; i<=25; i++)
            {
                    if (tmp->ProgMemoire!=NULL)
		    {
                            printf("\t%s\t| ",tmp->ProgMemoire->Name);
                            if(i%5==0) printf("\n-----------------------------------------------------------------------------------\n");
                    }
                    else
		    {
                        printf("\t%d\t|",i);
                        if(i%5==0) printf("\n-----------------------------------------------------------------------------\n");
                    }
                    tmp=tmp->suivant;
            }
}
