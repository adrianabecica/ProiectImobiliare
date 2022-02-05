#ifndef IMOBILIAR_H_INCLUDED
#define IMOBILIAR_H_INCLUDED
#include "Librarii.h"
class imobiliar
{
public:


    imobiliar();
    imobiliar(string, string, string, string);
    string conversie_afisare();
    virtual ~imobiliar();

    // Getters and setters
    void TipImobiliar(string s)
    {
        tipImobiliar=s;
    }
    string TipImobiliar()
    {
        return tipImobiliar;
    }

    void StradaImobiliar(string s)
    {
        stradaImobiliar=s;
    }
    string StradaImobiliar()
    {
        return stradaImobiliar;
    }

    void BlocImobiliar(string s)
    {
        blocImobiliar=s;
    }
    string BlocImobiliar()
    {
        return blocImobiliar;
    }

    void PretImobiliar(string s)
    {
        pretImobiliar=s;
    }
    string PretImobiliar()
    {
        return pretImobiliar;
    }


protected:

private:
    string tipImobiliar, stradaImobiliar, blocImobiliar, pretImobiliar;
};

#endif // IMOBILIAR_H_INCLUDED
