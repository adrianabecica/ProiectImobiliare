#include "evidenta_clienti.h"
#include <bits/stdc++.h>

Evidenta_clienti::Evidenta_clienti()
{
    //ctor
}

void Evidenta_clienti::Adaugare_client(client c)
{
    ofstream f;
    f.open(FISIER_CLIENTI, std::ios_base::app);

    if(f.fail())
    {
        cout<<"Fisierul nu a putut fi deschis.";
        return;
    }
    else
        f<<"\n" << c.conversie_afisare_client();
    f.close();
}

list<client> Evidenta_clienti::Optine_clienti()
{
    list <client> listab;
    client c;
    string sir, sir1, sir2, cnp;


    ifstream f;
    f.open(FISIER_CLIENTI);

    if(f.fail())
    {
        cout<<"Fisierul nu a putut fi deschis.";
    }
    else
    {
        while(getline(f,sir))
        {
            std::istringstream iss(sir);
            iss >> sir1 >> sir2 >> cnp;
            c.NumeClient(sir1);
            c.PrenumeClient(sir2);
            c.Cnp(cnp);
            listab.push_back(b);
        }
    }
    return listab;
}

void Evidenta_clienti::AfisareToataLista(list<client>listaClienti)
{
    list <client> listab;
    for (list<beneficiar>::iterator it = listaBeneficiari.begin(); it != listaBeneficiari.end(); it++)
    {
        cout << it->conversie_afisare_beneficiar() << "\n";
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
