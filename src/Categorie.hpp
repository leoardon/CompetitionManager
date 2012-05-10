//
//  Categorie.hpp
//  
//
//  Created by Leo Ardon on 10/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _Categorie_hpp
#define _Categorie_hpp

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Participant.hpp"
#include <list>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class Categorie {
    
public:
    typedef enum {M, F} tSexe;
    typedef enum {Benjamin, Minime, Cadet, Junior, Senior} tAge;
    Categorie(string unPoids, tSexe unSexe, tAge unAge);
    ~Categorie();
    void Print();
    void addParticipant(Participant *unParticipant);

    
private:
    void tirage();
    
    //attributs
    string poids;
    tSexe sexe;
    tAge age;
    list<Participant*> *combattants;
    
};




#endif
