#ifndef EVIDENTA_BENEFICIARI_H_INCLUDED
#define EVIDENTA_BENEFICIARI_H_INCLUDED

#include "beneficiar.h"

class Evidenta_beneficiari
{
    public:
        Evidenta_beneficiari();

        void Adaugare_beneficiar(beneficiar);
        list<beneficiar> Optine_beneficiari();
        void AfisareToataLista(list<beneficiar> listaBeneficiari);
        void SuprascriereFisier(list<beneficiar> listaBeneficiari);
        void RemoveItem(list<beneficiar> listaBeneficiari, string nume, string prenume);

        virtual ~Evidenta_beneficiari();

    protected:

    private:
};


#endif // EVIDENTA_BENEFICIARI_H_INCLUDED
