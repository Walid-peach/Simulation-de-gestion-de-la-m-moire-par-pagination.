#ifndef AJOUTER_H_INCLUDED
#define AJOUTER_H_INCLUDED
#include "header.h"
#include "Suppression.h"
#include "Affichage.h"
#include "Recherche.h"
#include "Initialiser.h"

Prog *AjouterProg(Prog *Precedent, Prog *ProgrammeAjouter);
Prog *CreerProgramme(int Taille, char Name[255]);

#endif // AJOUTER_H_INCLUDED
