#include "header.h"

int main(void)
{
    int choice,progSize;
    char progName[255];
    Prog * PrecedentProg = malloc(sizeof(Prog));
    Prog * ProgAjouter = malloc(sizeof(Prog));
    Prog * DebutProg = malloc(sizeof(Prog));
    PrecedentProg = NULL;
    int num;
    Page * Precedent, * DebutPage;
    Precedent = malloc(sizeof(Page));
    DebutPage = malloc(sizeof(Page));
    DebutPage = Initialisation(NULL,1);
    Precedent = DebutPage;
    for(num=2; num <=25; num++) {
        Precedent = Initialisation(Precedent,num);
    }
    int memorySize = 25*100;
	while (choice != 9) {
        system("COLOR 3e");
		printf("-------------------------MENU--------------------------------\n\n");
		printf("-------------------------------------------------------------\n");
		printf("***************1- charger un programme  *********************\n");
		printf("***************2- Afficher tous les programmes **************\n");
		printf("***************3- Afficher les pages occupées dans MC *******\n");
		printf("***************4- Afficher l'etat de la Memoire *************\n");
		printf("***************5- Afficher tous les pages libres ************\n");
		printf("***************6- Rechercher ********************************\n");
        printf("***************7- terminer l'execution du programme *********\n");
		printf("***************8- Supprimer un programme ********************\n");
		printf("***************9- Quitter ***********************************\n");
		printf("-------------------------------------------------------------\n\n");
		printf("\n             Saisir votre choix :     ");

		scanf("%d", &choice);
    int test;
    switch(choice){
		case 1:
		    printf("Saisir le nom du programme :\t");
            scanf("%s",&progName);
            printf("Saisir la taille du programme :\t");
            scanf("%d",&progSize);
            if (progSize<=memorySize){
                int x = TrouverProg(DebutProg, progName);
                    if (x==0){
                        Page * TempPage = malloc(sizeof(Page));
                        TempPage = DebutPage;
                        int NbrPages = TailleToPages(progSize);
                        memorySize= memorySize-NbrPages*100;
                        ProgAjouter = CreerProgramme(progSize,progName);
                        AjouterProg(PrecedentProg,ProgAjouter);
                        if(PrecedentProg==NULL){
                            DebutProg= ProgAjouter;
                        }
                        PrecedentProg = ProgAjouter;
                        while(NbrPages!=0)
                        {
                            if (TempPage->ProgMemoire==NULL){
                                TempPage->ProgMemoire = PrecedentProg;
                                NbrPages = NbrPages-1;
                            }
                            TempPage=TempPage->suivant;
                        }
                        printf("\nProgramme ajoute avec succes en MC.\n");
                    }
                    else{
                        printf("Programme deja existe\n\n");
                    }
            }
           else{
                printf("\n\n Stockage  insuffisant.\n\n");
            }
		break;
    case 2:
		    AfficherProg(DebutProg);
		break;
    case 3:
		    AfficherPageOccuper(DebutPage);
		break;
    case 4:
		    AfficherMemoire(DebutPage);
		    printf("\n-------- les pages disponibles : %d pages.-------\n",TailleToPages(memorySize));
		break;
    case 5:
		    AfficherPage(DebutPage);

    break;
    case 6:
		    printf("Saisir le Nom de programme a rechercher :\t");
		    scanf("%s",progName);
		    test = TrouverProg(DebutProg, progName);
		    if(test==1){
		        printf("les pages qui occupent le programme '%s' :\n",progName);
		    }
		    RechercherProg(DebutPage,progName);
		break;
    case 7:		    printf("Saisir le nom du programme a executer:\t");
		    scanf("%s",progName);
		    int test = TrouverProg(DebutProg, progName);
            if (test==1)
            {
            		    Prog * tmp;
            		    int x=0;
            		    if (strcmp(DebutProg->Name,progName)==0)
            		    {
            		        tmp =DebutProg->suivant;
            		        x=1;
            		    }
            		    progSize = ViderPage(DebutPage, progName);
            		    SupprimerProg(DebutProg, progName);
            		    printf("Ce programme a etait bien execute.\n\n");
            		    memorySize=memorySize+TailleToPages(progSize)*100;
            		    if(x==1)
            		    {
            		        DebutProg = tmp;
            		    }
            		    //test==0;
            }
        	else{
            		     printf("Programme n'existe pas!!\n\n");
            	}
		break;
		case 8:		    printf("Saisir le nom du prog à supprimer:\t");
		    scanf("%s",progName);
		    int test2 = TrouverProg(DebutProg, progName);
            if (test2==1)
            {
            		    Prog * tmp;
            		    int x=0;
            		    if (strcmp(DebutProg->Name,progName)==0)
            		    {
            		        tmp =DebutProg->suivant;
            		        x=1;
            		    }
            		    progSize = ViderPage(DebutPage, progName);
            		    SupprimerProg(DebutProg, progName);
            		    printf("Ce programme a etait bien supprime.\n\n");
            		    memorySize=memorySize+TailleToPages(progSize)*100;
            		    if(x==1)
            		    {
            		        DebutProg = tmp;
            		    }
            }
        	else{
            		     printf("Programme n'existe pas!!\n\n");
            	}
		break;
		case 9:
		    printf(" \n");
        break;
		default:
		    printf("Verifier votre choix.\n");
		break;
    }
	}
}
