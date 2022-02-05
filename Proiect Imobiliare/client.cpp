#include "client.h"
#include <string.h>

client::client()
{
    //ctor
}

client::client(string _nume, string _prenume, string _cnp)
{
    numeClient=_nume;
    prenumeClient= _prenume;
    CNP=_cnp;
}
string client::conversie_afisare_client()
{
    return numeClient+" "+prenumeClient+" "+CNP;
}

client::~client()
{
    //dtor
}
