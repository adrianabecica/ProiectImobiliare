#include "imobiliar.h"
#include <string.h>

imobiliar::imobiliar()
{
    //ctor
}

imobiliar::imobiliar(string _tip, string _strada, string _bloc, string _pret)
{
    tipImobiliar=_tip;
    stradaImobiliar=_strada;
   blocImobiliar=_bloc;
    pretImobiliar=_pret;

}

string imobiliar::conversie_afisare()
{
    return tipImobiliar+" "+stradaImobiliar+" "+blocImobiliar+" "+pretImobiliar;
}

imobiliar::~imobiliar()
{
    // dtor
}



