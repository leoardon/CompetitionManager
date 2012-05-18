//
//  Participant.hpp
//  
//
//  Created by Leo Ardon on 10/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _Participant_hpp
#define _Participant_hpp

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class Participant {
    
public:
    typedef enum {Bla, BJ, J, JO, O, OV, V, Ble, M, N1D, N2D, N3D, N4D, N5D, N6D, N7D, N8D, N9D, N10D} tGrade;
    Participant (string unNom, string unPrenom, string unNoLicence, string unPoids, tGrade unGrade, string unClub, string unDepartement, string unRegion, string uneZone = "SO", string unPays = "FR", int unClassement = 0);
    ~Participant();
    void Print();
    string GetClub();
    string GetDepartement();
    string GetRegion();
    string GetZone();
    string GetPays();
    string GetNom();
    
private:
    string nom;
    string prenom;
    string noLicence;
    string poids;
    tGrade grade;
    string club;
    string departement;
    string region;
    string zone;
    string pays;
    int classement; // 0 si non classé
    
    
};



#endif
