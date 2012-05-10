//
//  Combat.hpp
//  
//
//  Created by Leo Ardon on 10/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef _Combat_hpp
#define _Combat_hpp

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Participant.hpp"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

class Combat {
    
public:
    Combat(Participant* unCombattantR, Participant* unCombattantB);
    ~Combat();
    void SetVainqueur(Participant* unCombattant);
    Participant* GetCombattantR();
    Participant* GetCombattantB();
    Participant* GetVainqueur();
    
    
private:
    Participant* combattantR;
    Participant* combattantB;
    Participant* vainqueur;
    int scoreR;
    int scoreB;
    
};




#endif
