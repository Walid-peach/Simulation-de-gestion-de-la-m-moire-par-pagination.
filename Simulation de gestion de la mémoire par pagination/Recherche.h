#ifndef RECHERCHE_H_INCLUDED
#define RECHERCHE_H_INCLUDED
#include "header.h"
#include "Ajouter.h"
#include "Suppression.h"
#include "Affichage.h"
#include "Initialiser.h"

void RechercherProg(Page*Debut,char nom[255]);
int TrouverProg(Prog *head, char *nom);


#endif // RECHERCHE_H_INCLUDED
