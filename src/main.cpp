//
//  main.cpp
//  
//
//  Created by Leo Ardon on 10/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Participant.hpp"
#include "Categorie.hpp"
#include "categories.hpp"
#include "Server.hpp"

#include <iostream>
using namespace std;

static void choixCate(int &age, int &sexe)
{
    cout << "choisissez la categorie d'age: 1.Benjamin 2.Minime 3.Cadet 4.Junior 5.Senior" << endl;
    cin >> age;
    
    cout << "choisissez le sexe: 1.Masculin 2.Feminin" << endl;
    cin >> sexe;

}

int main(int argc, char** argv)
{
    
    Participant *leo = new Participant ("Ardon", "Leo", "M1690", "-60", Participant::N1D, "Stade Poitevin", "Vienne", "PCH");
    Participant *leo6 = new Participant ("Ardon", "Leo6", "M1690", "-60", Participant::N1D, "Le Plessis Robinson Judo", "Hauts de Seine", "IDF", "RegionParisienne");
    Participant *leo2 = new Participant ("Ardon", "Leo2", "M1690", "-60", Participant::N1D, "USJ86", "Vienne", "PCH");
    Participant *leo3 = new Participant ("Ardon", "Leo3", "M1690", "-60", Participant::N1D, "Stade Poitevin", "Vienne", "PCH");
    Participant *leo4 = new Participant ("Ardon", "Leo4", "M1690", "-60", Participant::N1D, "Stade couronnais", "Charente", "PCH");
    
    Participant *leo5 = new Participant ("Ardon", "Leo5", "M1690", "-60", Participant::N1D, "Palestra del sole", "Torino", "Piemonte", "Esterno", "IT");
    Categorie *cate = new Categorie("-60", Categorie::M, Categorie::Benjamin);
    cate->AddParticipant(leo);
    cate->AddParticipant(leo6);
    cate->AddParticipant(leo2);
    cate->AddParticipant(leo5);
    cate->AddParticipant(leo4);
    cate->AddParticipant(leo3);
    cate->GenererTableau();
    /*cate->PrintTableau();
    cout << "Tour 1" << endl;
    cate->EffectuerTour();
    int i=2;
    while(!(cate->EstTermine()))
    {
        cout << "Tour " << i++ << endl;
        cate->GenererTour();
        cate->EffectuerTour();
    }*/
    
    Server* serverJudo = Server::GetInstance();
}
