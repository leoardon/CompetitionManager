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
#include "Combat.hpp"
#include <list>
#include <vector>
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
    //enum
    typedef enum {M, F} tSexe;
    typedef enum {Benjamin, Minime, Cadet, Junior, Senior} tAge;
    
    //constructeur
    Categorie(string unPoids, tSexe unSexe, tAge unAge);
    
    //destructeur
    ~Categorie();
    
    //méthodes
    void PrintCombattants();
    void AddParticipant(Participant *unParticipant);
    void GenererTableau();
    void PrintTableau();
    void GenererTour();
    void PrintCombats();
    
    //TESTS//
    void testGenererTableau();

    
private:
    //méthodes
    void tirage(Participant *combattant, int indicePremierElem, int taille, 
        bool &ok);
    void premierDemiTableau(Participant* combattant, int indicePremierElem, int taille, bool &ok);
    void secondDemiTableau(Participant* combattant, int indicePremierElem, int taille, bool &ok);
    void trier();
    
    //attributs
    string poids;
    tSexe sexe;
    tAge age;
    list<Participant*> *combattants;
    vector<Participant*> *tableau;
    vector<list<Combat*> > *combats;
    int nbTours;
    
};




#endif
