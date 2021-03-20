#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED
#include "header.h"
#include "Ajouter.h"
#include "Suppression.h"
#include "Recherche.h"
#include "Initialiser.h"

void AfficherMemoire(Page * Debut);
void AfficherPageOccuper(Page *head);
void AfficherPage(Page *head);
void AfficherProg(Prog *head);

#endif // AFFICHAGE_H_INCLUDED
