#ifndef BAZA_DE_DATE_H_INCLUDED
#define BAZA_DE_DATE_H_INCLUDED
#include "imobiliar.h"
class Baza_de_date
{
    public:
        Baza_de_date();

        void Adaugare_imobiliar(imobiliar);
        list<imobiliar> Optine_imobiliare();
        void AfisareToataLista(list<imobiliar> listaImobiliare);
        void SuprascriereFisier(list<imobiliar> listaImobiliare);
        void RemoveItem(list<imobiliar> listaImobiliar, string tip, string strada);

        virtual ~Baza_de_date();

    protected:

    private:
};

#endif // BAZA_DE_DATE_H_INCLUDED
