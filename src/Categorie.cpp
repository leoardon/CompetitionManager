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
#include <vector>
#include <map>
#include <math.h>
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


void Categorie::PrintCombattants()
{
    cout << "Categorie des " << poids << ": " << endl;
    list<Participant*>::iterator it;
    for(it = combattants->begin(); it != combattants->end(); it++)
    {
        cout << "**";
        (*it)->Print();
    }
}

void Categorie::PrintTableau()
{
    vector<Participant*>::iterator it;
    for(it=tableau->begin(); it!= tableau->end(); it++)
    {
        cout << "_______________" << endl;
        if((*it)!= NULL)
            cout << (*it)->GetNom() << "|" << endl;
        else
            cout << "               |" << endl;
        cout << "_______________" << endl;
    }
}


void Categorie::trier()
{
    list<Participant*> *listeTriee = new list<Participant*>(); 
    list<Participant*>::iterator it;
    map<string, map<string, map< string, map<string, map<string, vector<Participant*>*> > > > > mapTri;

    for(it = combattants->begin(); it != combattants->end(); it++)
    {
        if(mapTri.find((*it)->GetPays()) == mapTri.end() || mapTri[(*it)->GetPays()].find((*it)->GetZone()) == mapTri[(*it)->GetPays()].end()
           || ((mapTri[(*it)->GetPays()])[(*it)->GetZone()]).find((*it)->GetRegion()) == ((mapTri[(*it)->GetPays()])[(*it)->GetZone()]).end()
           || (((mapTri[(*it)->GetPays()])[(*it)->GetZone()])[(*it)->GetRegion()]).find((*it)->GetDepartement()) == (((mapTri[(*it)->GetPays()])[(*it)->GetZone()])[(*it)->GetRegion()]).end()
           || ((((mapTri[(*it)->GetPays()])[(*it)->GetZone()])[(*it)->GetRegion()])[(*it)->GetDepartement()]).find((*it)->GetClub()) == ((((mapTri[(*it)->GetPays()])[(*it)->GetZone()])[(*it)->GetRegion()])[(*it)->GetDepartement()]).end())
        {
            (((((mapTri[(*it)->GetPays()])[(*it)->GetZone()])[(*it)->GetRegion()])[(*it)->GetDepartement()])[(*it)->GetClub()]) = new vector<Participant*>();
        }
        (((((mapTri[(*it)->GetPays()])[(*it)->GetZone()])[(*it)->GetRegion()])[(*it)->GetDepartement()])[(*it)->GetClub()])->push_back(*it);
    }
    
    map<string, map<string, map< string, map<string, map<string, vector<Participant*>*> > > > > ::iterator itMapPays;
    map<string, map< string, map<string, map<string, vector<Participant*>*> > > >::iterator itMapZone;
    map< string, map<string, map<string, vector<Participant*>*> > >::iterator itMapRegion;
    map<string, map<string, vector<Participant*>*> >  ::iterator itMapDepartement;
    map<string, vector<Participant*>*> ::iterator itMapClub;
    
    for(itMapPays = mapTri.begin(); itMapPays != mapTri.end(); itMapPays++)
    {
        //cout << "combattants pour le pays " << (*itMapPays).first << endl;
        for(itMapZone = (*itMapPays).second.begin(); itMapZone != ((*itMapPays).second).end(); itMapZone++)
        {
            //cout << "la zone :" << (*itMapZone).first << endl;
            for(itMapRegion = (*itMapZone).second.begin(); itMapRegion != ((*itMapZone).second).end(); itMapRegion++)
            {
                //cout << "la region :" << (*itMapRegion).first << endl;
                for(itMapDepartement = (*itMapRegion).second.begin(); itMapDepartement != ((*itMapRegion).second).end(); itMapDepartement++)
                {
                    //cout << "le departement :" << (*itMapDepartement).first << endl;
                    for(itMapClub = (*itMapDepartement).second.begin(); itMapClub != ((*itMapDepartement).second).end(); itMapClub++)
                    {
                        //cout << "le club :" << (*itMapClub).first << endl;
                        for(int i=0 ; i<(*itMapClub).second->size(); i++)
                            //(((*itMapClub).second)->at(i))->Print();
                            listeTriee->push_back((((*itMapClub).second)->at(i)));
                    }
                }
            }
        }
    }
    delete combattants;
    combattants = listeTriee;
}

void Categorie::AddParticipant(Participant *unParticipant)
{
    combattants->push_back(unParticipant);
}

void Categorie::tirage(Participant *combattant, int indicePremierElem, int taille, bool &ok)
{
    if(taille == 1)
    {
        if(tableau->at(indicePremierElem)== NULL)
        {
            tableau->at(indicePremierElem) = combattant;
        }
        else
            ok = false;
        return;
    }
    
    int itTab1; //iterateur pour le tableau
    int clubTab1 = 0;
    int clubTab2 = 0;
    int deptTab1 = 0;
    int deptTab2 = 0;
    int regTab1 = 0;
    int regTab2 = 0;
    int zoneTab1 = 0;
    int zoneTab2 = 0;
    int paysTab1 = 0;
    int paysTab2 = 0;

    for(itTab1 = indicePremierElem; itTab1 < taille/2; itTab1++)
    {
        if((tableau->at(itTab1))!= NULL)
        {
            if(combattant->GetClub() == (tableau->at(itTab1))->GetClub())
                clubTab1++;
            if(combattant->GetDepartement() == (tableau->at(itTab1))->GetDepartement())
                deptTab1++;
            if(combattant->GetRegion() == (tableau->at(itTab1))->GetRegion())
                regTab1++;
            if(combattant->GetZone() == (tableau->at(itTab1))->GetZone())
                zoneTab1++;
            if(combattant->GetPays() == (tableau->at(itTab1))->GetPays())
                paysTab1++;
        }
    }
        
    for(itTab1 = indicePremierElem+taille/2; itTab1 < indicePremierElem+taille; itTab1++)
    {
        if((tableau->at(itTab1))!= NULL)
        {
            if(combattant->GetClub() == (tableau->at(itTab1))->GetClub())
                clubTab2++;
            if(combattant->GetDepartement() == (tableau->at(itTab1))->GetDepartement())
                deptTab2++;
            if(combattant->GetRegion() == (tableau->at(itTab1))->GetRegion())
                regTab2++;
            if(combattant->GetZone() == (tableau->at(itTab1))->GetZone())
                zoneTab2++;
            if(combattant->GetPays() == (tableau->at(itTab1))->GetPays())
                paysTab2++;
        }
    }
    
    if(clubTab1 == clubTab2)
    {
        if(deptTab1 == deptTab2 )
        {
            if(regTab1 == regTab2)
            {
                if(zoneTab1 == zoneTab2)
                {
                    if(paysTab1 < paysTab2)
                    {
                        premierDemiTableau(combattant, indicePremierElem, taille, ok);
                        if(!ok)
                            return;
                    }
                    else if (paysTab1 > paysTab2)
                    {
                        secondDemiTableau(combattant, indicePremierElem, taille, ok);
                        if(!ok)
                            return;
                    }
                    else if( paysTab1 == paysTab2)
                    {
                        int choix = rand() % 2 + 1;
                        if(choix == 1)
                        {
                            premierDemiTableau(combattant, indicePremierElem, taille, ok);
                            if(!ok)
                                return;
                        }
                        else
                        {
                            secondDemiTableau(combattant, indicePremierElem, taille, ok);
                            if(!ok)
                                return;
                        }
                    }
                }
                else if (zoneTab1 < zoneTab2)
                {
                    premierDemiTableau(combattant, indicePremierElem, taille, ok);
                    if(!ok)
                        return;
                }
                else if (zoneTab1 > zoneTab2)
                {
                    secondDemiTableau(combattant, indicePremierElem, taille, ok);
                    if(!ok)
                        return;
                }
            }
            else if (regTab1 < regTab2)
            {
                premierDemiTableau(combattant, indicePremierElem, taille, ok);
                if(!ok)
                    return;
            }
            else if (regTab1 > regTab2)
            {
                secondDemiTableau(combattant, indicePremierElem, taille, ok);
                if(!ok)
                    return;
            }
        }
        else if (deptTab1 < deptTab2)
        {
            premierDemiTableau(combattant, indicePremierElem, taille, ok);
            if(!ok)
                return;
        }
        else if (deptTab1 > deptTab2)
        {
            secondDemiTableau(combattant, indicePremierElem, taille, ok);
            if(!ok)
                return;
        }
    }
    else if (clubTab1 < clubTab2)
    {
        premierDemiTableau(combattant, indicePremierElem, taille, ok);
        if(!ok)
            return;
    }
    else if (clubTab1 > clubTab2)
    {
        secondDemiTableau(combattant, indicePremierElem, taille, ok);
        if(!ok)
            return;
    }
}

void Categorie::premierDemiTableau(Participant* combattant, int indicePremierElem, int taille, bool &ok)
{
    tirage(combattant, indicePremierElem, taille/2, ok);
    if(!ok)
    {
        ok = true;
        tirage(combattant, indicePremierElem+taille/2, taille/2, ok);
    }
    return;
}

void Categorie::secondDemiTableau(Participant* combattant, int indicePremierElem, int taille, bool &ok)
{
    tirage(combattant, indicePremierElem+taille/2, taille/2, ok);
    if(!ok)
    {
        ok = true;
        tirage(combattant, indicePremierElem, taille/2, ok);
    }
    return;
}

void Categorie::GenererTableau()
{
    int nbCombattants = combattants->size();
    bool ok = true;
    unsigned long res = 2;
    while(res<nbCombattants)
        res<<=1;
    tableau = new vector<Participant*>(res, NULL);
    nbTours = log2(res);
    combats = new vector<list<Combat*> >(nbTours, list<Combat*>());
    
    trier();
    
    list<Participant*>::iterator itCombattants;
    for(itCombattants = combattants->begin(); itCombattants != combattants->end(); itCombattants++)
    {
        tirage((*itCombattants), 0, tableau->size(), ok);
    }
    
    for(int i = 0; i < tableau->size(); i+=2)
    {
        Combat* combat;
        if(tableau->at(i) == NULL)
        {
            //cout << "tableau->at(i) == NULL" << endl;
            combat = new Combat(NULL, tableau->at(i+1));
            combat->SetVainqueur(combat->GetCombattantB());
        }
        else if(tableau->at(i+1) == NULL)
        {
            //cout << "tableau->at(i+1) == NULL" << endl;
            combat = new Combat(tableau->at(i), NULL);
            combat->SetVainqueur(combat->GetCombattantR());
        }
        else
        {
            //cout << "OK pas de NULL" << endl;
            combat = new Combat(tableau->at(i), tableau->at(i+1));
        }
        combats->at(0).push_back(combat);
    }
}

void Categorie::PrintCombats()
{
    list<Combat*>::iterator it;
    for(it = combats->at(0).begin(); it != combats->at(0).end(); it++)
    {
        if((*it)->GetCombattantR() != NULL)
            cout << (*it)->GetCombattantR()->GetNom();
        else
            cout << "VIDE";
        cout << " vs "; 
        if((*it)->GetCombattantB() != NULL)
            cout << (*it)->GetCombattantB()->GetNom();
        else
            cout << "VIDE";
        cout << endl;
    }
}

void Categorie::GenererTour()
{
    if(nbTours == 0)
        return;
    list<Combat*>::iterator itcombats;
    int indice = combats->size() - nbTours - 1;
    for(itcombats=combats->at(indice).begin(); itcombats != combats->at(indice).end(); itcombats++)
    {
        Combat *combat = new Combat((*itcombats)->GetVainqueur(), (*(++itcombats))->GetVainqueur());
        combats->at(indice+1).push_back(combat);
    }
}

void Categorie::EffectuerTour()
{
    if(nbTours == 0)
        return;
    list<Combat*>::iterator itcombats;
    int indice = combats->size() - nbTours;
    for(itcombats = combats->at(indice).begin(); itcombats != combats->at(indice).end(); itcombats++)
    {
        if((*itcombats)->GetVainqueur() == NULL)
        {
            char v;
            string nomR = (*itcombats)->GetCombattantR()->GetNom();
            string nomB = (*itcombats)->GetCombattantB()->GetNom();
            cout << "combat: " << nomR << " vs " << nomB << endl;
            bool error = false;
            do{
                cout << "Indiquez le vainqueur (R/B) :";
                cin >> v;
                if(v=='r' || v=='R')
                {
                    cout << "vainqueur rouge" << endl;
                    (*itcombats)->SetVainqueur((*itcombats)->GetCombattantR());
                    error = false;
                }
                else if(v=='b' || v=='B')
                {
                    cout << "vainqueur blanc" << endl;
                    (*itcombats)->SetVainqueur((*itcombats)->GetCombattantB());
                    error =false;
                }
                else
                    error = true;
            }while(error);
        }
    }
    nbTours--;
}

bool Categorie::EstTermine()
{
    return (nbTours==0);
}






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////           TESTS          /////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Categorie::testGenererTableau()
{
    Participant *leo = new Participant ("Ardon", "Leo1", "M1690", "-60", Participant::N1D, "Stade Poitevin", "Vienne", "PCH");
    Participant *leo2 = new Participant ("Ardon", "Leo2", "M1690", "-60", Participant::N1D, "Stade Poitevin", "Vienne", "PCH");
    Participant *leo3 = new Participant ("Ardon", "Leo3", "M1690", "-60", Participant::N1D, "Stade Poitevin", "Vienne", "PCH");
    bool error = false;
    
    this->AddParticipant(leo); //ajout d'un combattant
    this->GenererTableau();
    if(tableau->size() != 2)
    {
        cout << "nombre combattants: " << combattants->size() << endl;
        cout << "taille tableau: " << tableau->size() << endl;
        cout << "Erreur pour un combattant" << endl;
        error = true;
    }
    
    this->AddParticipant(leo2); //ajout d'un deuxième combattant
    this->GenererTableau();
    if(tableau->size() != 2)
    {
        cout << "nombre combattants: " << combattants->size() << endl;
        cout << "taille tableau: " << tableau->size() << endl;
        cout << "Erreur pour deux combattants" << endl;
        error = true;
    }
    
    this->AddParticipant(leo3); //ajout d'un troisième combattant
    this->GenererTableau();
    if(tableau->size() != 4)
    {
        cout << "nombre combattants: " << combattants->size() << endl;
        cout << "taille tableau: " << tableau->size() << endl;
        cout << "Erreur pour 3 combattants" << endl;
        error = true;
    }
    
    /*for(int i=0; i<61; i++) //ajout de 61 autres combattants => 61 + 3 = 64
    {
        Participant *leoi = new Participant ("Ardon", "Leo", "M1690", "-60", Participant::N1D, "Stade Poitevin", "Vienne", "PCH");
        this->AddParticipant(leoi);
    }
    this->GenererTableau();
    if(tableau->size() != 64)
    {
        cout << "nombre combattants: " << combattants->size() << endl;
        cout << "taille tableau: " << tableau->size() << endl;
        cout << "Erreur pour 64 combattants" << endl;
        error = true;
    }*/
    
    if(!error)
    {
        cout << "test réussit !" << endl;
        this->PrintTableau();
    }
}


