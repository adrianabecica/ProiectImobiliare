#ifndef BENEFICIAR_H_INCLUDED
#define BENEFICIAR_H_INCLUDED
#include "Librarii.h"
class beneficiar
{
    public:
        beneficiar();
        beneficiar(string, string, string);
        string conversie_afisare_beneficiar();
        virtual ~beneficiar();

    void NumeBeneficiar(string s)
    {
        numeBeneficiar=s;
    }
    string NumeBeneficiar()
    {
        return numeBeneficiar;
    }

    void PrenumeBeneficiar(string s)
    {
        prenumeBeneficiar=s;
    }
    string PrenumeBeneficiar()
    {
        return prenumeBeneficiar;
    }

    void Cnp(string s)
    {
        CNP=s;
    }
    string Cnp()
    {
        return CNP;
    }

    protected:

    private:
        string numeBeneficiar, prenumeBeneficiar;
        string CNP;
};



#endif // BENEFICIAR_H_INCLUDED
