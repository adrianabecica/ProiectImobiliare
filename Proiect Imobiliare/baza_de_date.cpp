#include "baza_de_date.h"
#include <bits/stdc++.h>

Baza_de_date::Baza_de_date()
{
    //ctor
}

void Baza_de_date::Adaugare_imobiliar(imobiliar c)
{
    ofstream f;
    f.open(FISIER, std::ios_base::app);

    if(f.fail())
    {
        cout<<"\t\tFisierul nu a putut fi deschis.";
        return;
    }
    else
        f<<"\n" << c.conversie_afisare();
    f.close();
}

list<imobiliar> Baza_de_date::Optine_imobiliare()
{
    list <imobiliar> listaimobiliare;
   imobiliar c;
    string sir, sir1, sir2, sir3, sir4;

    ifstream f;
    f.open(FISIER);

    if(f.fail())
    {
        cout<<"\t\tFisierul nu a putut fi deschis.";
    }
    else
    {
        while(getline(f,sir))
        {
            std::istringstream iss(sir);
            iss >> sir1 >> sir2 >> sir3 >> sir4;
            c.TipImobiliar(sir1);
            c.StradaImobiliar(sir2);
            c.BlocImobiliar(sir3);
            c.PretImobiliar(sir4);
            listaimobiliare.push_back(c);
        }
    }
    return listaimobiliare;

}

void Baza_de_date::AfisareToataLista(list<imobiliar> listaImobiliare)
{
    list <imobiliar> listaimobiliare;
    cout << "\t\t\xB2   TIP     STRADA   BLOC  PRET   \xB2";
    for (list<imobiliar>::iterator it = listaImobiliare.begin(); it != listaImobiliare.end(); it++)
    {
        cout << "\t\t  "<<it->conversie_afisare() << "\n";
    }
}
void Baza_de_date::SuprascriereFisier(list<imobiliar> listaImobiliare)
{
    ofstream f;
    f.open(FISIER);
     for (list<imobiliar>::iterator it = listaImobiliare.begin(); it != listaImobiliare.end(); it++)
    {
        f << it->conversie_afisare() << "\n";
    }
}
void Baza_de_date::RemoveItem(list<imobiliar> listaImobiliar, string tip, string strada)
{
    ofstream f;
    f.open(FISIER);
     for (list<imobiliar>::iterator it = listaImobiliar.begin(); it != listaImobiliar.end(); it++)
    {
        if(it->TipImobiliar() == tip && it->StradaImobiliar() == strada)
            continue;
        else
            f << it->conversie_afisare() << "\n";
    }
}


Baza_de_date::~Baza_de_date()
{
    //dtor
}
