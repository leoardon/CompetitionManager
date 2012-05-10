//
//  Participant.cpp
//  
//
//  Created by Leo Ardon on 10/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

//---------- Réalisation du module <PARTICIPANT> (fichier Participant.cpp) -----

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Participant.hpp"

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

Participant::Participant (string unNom, string unPrenom, string unNoLicence, string unPoids, tGrade unGrade, string unClub, string unDepartement, string unRegion) : nom(unNom), prenom(unPrenom), noLicence(unNoLicence), poids(unPoids), grade(unGrade), club(unClub), departement(unDepartement), region(unRegion), classement(0)
{
} //----- fin de Constructeur

Participant::~Participant ()
{
} //----- fin de Destructeur

void Participant::Print()
{
    cout << "Participant: " << nom << " " << prenom << endl;
    cout << "noLicence: " << noLicence << endl;
    cout << "poids: " << poids << " grade: " << grade << endl;
    cout << "region: " << region << " departement: " << departement << " club: " << club << endl;
    cout << "classement: " << classement << endl;
}


