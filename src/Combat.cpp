//
//  Combat.cpp
//  
//
//  Created by Leo Ardon on 10/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

//---------- Réalisation du module <Combat> (fichier Combat.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système

#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Combat.hpp"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
//type Nom ( liste de paramètres )
// Algorithme :
//
//{
//} //----- fin de Nom


Combat::Combat(Participant* unCombattantR, Participant* unCombattantB): combattantR(unCombattantR), combattantB(unCombattantB), scoreR(0), scoreB(0)
{
} //----- fin de Constructeur

Combat::~Combat ()
{
} //----- fin de Destructeur

void SetVainqueur(Participant* unCombattant)
{
    vainqueur = unCombattant;
}

Participant* GetCombattantR()
{
    return combattantR;
}

Participant* GetCombattantB()
{
    return combattantB;
}

Participant* GetVainqueur()
{
    return vainqueur;
}









