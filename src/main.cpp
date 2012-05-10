//
//  main.cpp
//  
//
//  Created by Leo Ardon on 10/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Participant.hpp"
#include "Categorie.hpp"

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
    int age;
    int sexe;
    choixCate(age, sexe);
    
    Participant *leo = new Participant ("Ardon", "Leo", "M1690", "-60", Participant::N1D, "Stade Poitevin", "Vienne", "PCH");
    Msenior_60->addParticipant(leo);
    Msenior_60->Print();
}
