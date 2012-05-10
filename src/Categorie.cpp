//
//  Categorie.cpp
//  
//
//  Created by Leo Ardon on 10/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

//---------- Réalisation du module <CATEGORIE> (fichier Categorie.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Categorie.hpp"

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


Categorie::Categorie(string unPoids, tSexe unSexe, tAge unAge): poids(unPoids), sexe(unSexe), age(unAge)
{
    combattants = new list<Participant*>();
} //----- fin de Constructeur


void Categorie::Print()
{
    cout << "Categorie des " << poids << ": " << endl;
    list<Participant*>::iterator it;
    for(it = combattants->begin(); it != combattants->end(); it++)
    {
        cout << "**";
        (*it)->Print();
    }
}

void Categorie::addParticipant(Participant *unParticipant)
{
    combattants->push_back(unParticipant);
}

void Categorie::tirage()
{
    if(taille du tableau1 = 1)
    {
        je le mets dedans
    }
    if(club appartient à tableau1)
    {
        je le mets dans tableau2
    }
    else
    {
        je le mets dans le tableau1
    }
}


