#include "Ajouter.h"


//****************Creation d'un programme
Prog *CreerProgramme(int Size, char Name[100]) {

    Prog *Resultat = malloc(sizeof(Prog));

    Resultat->Size = Size;

	  strcpy(Resultat->Name, Name);

    Resultat->suivant = NULL;

    return Resultat;
}

//**********************Ajout d'un programme
Prog *AjouterProg(Prog *Precedent, Prog *ProgrammeAjouter) {
	if(Precedent!=NULL){
        Precedent->suivant = ProgrammeAjouter;
    }
    return ProgrammeAjouter;
}
