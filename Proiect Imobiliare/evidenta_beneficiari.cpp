#include "evidenta_beneficiari.h"
#include <bits/stdc++.h>

Evidenta_beneficiari::Evidenta_beneficiari()
{
    //ctor
}

void Evidenta_beneficiari::Adaugare_beneficiar(beneficiar b)
{
    ofstream f;
   f.open(FISIER_BENEFICIARI, std::ios_base::app);
  cout << "\t\t\xB2   NUME     PRENUME    CNP   \xB2";
    if(f.fail())
    {
        cout<<"\t\tFisierul nu a putut fi deschis.";
        return;
    }
    else
        f<<"\n" << b.conversie_afisare_beneficiar();
    f.close();
}

list<beneficiar> Evidenta_beneficiari::Optine_beneficiari()
{
    list <beneficiar> listab;
    beneficiar b;
    string sir, sir1, sir2, cnp;


    ifstream f;
    f.open(FISIER_BENEFICIARI);

    if(f.fail())
    {
        cout<<"\t\tFisierul nu a putut fi deschis.";
    }
    else
    {
        while(getline(f,sir))
        {
            std::istringstream iss(sir);
            iss >> sir1 >> sir2 >> cnp;
            b.NumeBeneficiar(sir1);
            b.PrenumeBeneficiar(sir2);
            b.Cnp(cnp);
            listab.push_back(b);
        }
    }
    return listab;
}

void Evidenta_beneficiari::AfisareToataLista(list<beneficiar>listaBeneficiari)
{
    list <beneficiar> listab;
    for (list<beneficiar>::iterator it = listaBeneficiari.begin(); it != listaBeneficiari.end(); it++)
    {
        cout << "\t\t"<<it->conversie_afisare_beneficiar() << "\n";
    }
}

void Evidenta_beneficiari::SuprascriereFisier(list<beneficiar>listaBeneficiari)
{
    ofstream f;
    f.open(FISIER_BENEFICIARI);
     for (list<beneficiar>::iterator it = listaBeneficiari.begin(); it != listaBeneficiari.end(); it++)
    {
        f << it->conversie_afisare_beneficiar() << "\n";
    }
}

void Evidenta_beneficiari::RemoveItem(list<beneficiar>listaBeneficiari, string nume, string prenume)
{
    ofstream f;
    f.open(FISIER_BENEFICIARI);
     for (list<beneficiar>::iterator it = listaBeneficiari.begin(); it != listaBeneficiari.end(); it++)
    {
        if(it->NumeBeneficiar() == nume && it->PrenumeBeneficiar() == prenume)
            continue;
        else
            f << it->conversie_afisare_beneficiar() << "\n";
    }
}


Evidenta_beneficiari::~Evidenta_beneficiari()
{
    //dtor
}
