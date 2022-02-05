#include "beneficiar.h"
#include <string.h>

beneficiar::beneficiar()
{
    //ctor
}

beneficiar::beneficiar(string _nume, string _prenume, string _cnp)
{
    numeBeneficiar=_nume;
    prenumeBeneficiar= _prenume;
    CNP=_cnp;
}
string beneficiar::conversie_afisare_beneficiar()
{
    return numeBeneficiar+" "+prenumeBeneficiar+" "+CNP;
}

beneficiar::~beneficiar()
{
    //dtor
}
