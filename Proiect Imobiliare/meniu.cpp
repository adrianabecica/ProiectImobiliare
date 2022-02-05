#include "meniu.h"
#include "imobiliar.h"
#include "baza_de_date.h"
#include "beneficiar.h"
#include "evidenta_beneficiari.h"
#include <stdio.h>
#include <stdlib.h>
meniu::meniu()
{
    //ctor
}

void menu_principal();
void menu_imobiliar();
void menu_beneficiar();

void meniu::Meniu()
{
    meniu m;
    char choice;
    while(1)
    {
        system("cls");
        menu_principal();
        cout<<"\n\n\tAlegeti o optiune:";
        cin>>choice;
        switch(toupper(choice))
        {
        case 'A':
            m.Meniu_imobiliar();
            break;
        case 'B':
            m.Meniu_beneficiar();
            break;
        case 'X':
            exit(0);
            break;

        }
    }
}

void meniu::Meniu_imobiliar()
{
    meniu m;

    Baza_de_date adminimobiliar;
    list<imobiliar> listaimobiliar;
    char choice;


    cout<<endl;
    listaimobiliar = adminimobiliar.Optine_imobiliare();
    adminimobiliar.AfisareToataLista(listaimobiliar);
    while(1)
    {
        system("cls");
        menu_imobiliar();
        cout<<"\n\n\t\tAlegeti o optiune:";
        cin>>choice;
        switch(toupper(choice))
        {
        case 'A':
        {
            listaimobiliar = adminimobiliar.Optine_imobiliare();
            if ( listaimobiliar.size() != 0)
                adminimobiliar.AfisareToataLista(listaimobiliar);
            else
                cout<<"\n\t\tNu aveti momentan nici-o oferta imobiliar salvata.";
            break;
        }
        case 'C':
        {
            cout<<"\n\t\t\xB2 Introduceti tipul ofertei: ";
            string tipImobiliar;
            cin>>tipImobiliar;

            cout<<"\n\t\t\xB2 Introduceti strada: ";
            string stradaImobiliar;
            cin>>stradaImobiliar;

            cout<<"\n\t\t\xB2 Introduceti blocul: ";
            string blocImobiliar;
            cin>>blocImobiliar;

            cout<<"\n\t\t\xB2 Introduceti pretul: ";
            string pretImobiliar;
            cin>>pretImobiliar;

            imobiliar c(tipImobiliar, stradaImobiliar, blocImobiliar, pretImobiliar);
            adminimobiliar.Adaugare_imobiliar(c);
            break;
        }
        case 'F':
        {
            int ok = 0;
            cout<<"\n\t\t\xB2 Introduceti tipul ofertei cautate: ";
            string tip;
            cin>>tip;

            cout<<"\n\t\t\xB2 Introduceti strada acesteia: ";
            string strada;
            cin>>strada;

            listaimobiliar = adminimobiliar.Optine_imobiliare();

            for (list<imobiliar>::iterator it = listaimobiliar.begin(); it != listaimobiliar.end(); it++)
            {
                if( it->TipImobiliar() == tip && it->StradaImobiliar() == strada)
                {
                    ok =1;
                    cout<<"\n\n\t\t Oferta gasita !";
                    cout<<"\n\t\t"<<it->TipImobiliar()<<" "<<it->StradaImobiliar()<<" "<<it->BlocImobiliar()<<" "<<it->PretImobiliar();
                }
            }
            if (ok == 0)
            {
                cout<<"\n\n\t\t\xB2Oferta inexistenta !";
            }
            break;
        }
case 'M':
        {

            system("cls");
            cout<<"\n\n";
            if ( listaimobiliar.size() != 0)
                adminimobiliar.AfisareToataLista(listaimobiliar);
            else
                cout<<"\n\t\tNu aveti momentan nici o oferta.";
            cout<<"\n\t\t\xB2 Introduceti tipul ofertei pe care doriti sa o modificati.\n->";
            string tip;
            cin>>tip;

            cout<<"\n\t\t\xB2 Introduceti strada imobiliarului pe care doriti sa 0 modificati.\n->";
            string strada;
            cin>>strada;

            string bloc, pret;
            int ok = 0, ok2 = 1;

            listaimobiliar = adminimobiliar.Optine_imobiliare();

            for (list<imobiliar>::iterator it = listaimobiliar.begin(); it != listaimobiliar.end(); it++)
            {
                 if( it->TipImobiliar() == tip && it->StradaImobiliar() == strada)
                {
                    system("cls");
                    if ( listaimobiliar.size() != 0)
                        adminimobiliar.AfisareToataLista(listaimobiliar);
                    else
                        cout<<"\n\t\tNu aveti momentan nici o oferta salvata.";
                    ok = 1;
                    cout<<"\n\n\t\t Imobiliar gasit !";
                    cout<<"\n\t\t"<<it->TipImobiliar()<<" "<<it->StradaImobiliar()<<" "<<it->BlocImobiliar()<<" "<<it->PretImobiliar();
                    cout<<endl<<endl;
                    while (1)
                    {

                        cout<<"Ce camp doriti sa modificati ?";
                               cout<<"\n\t\tA. Tip oferta imobiliar;\n\t\tB. Strada oferta imobiliar;\n\t\tC. Bloc oferta imobiliar;\nD\t\t. Pret oferta imobiliar;\n\t\tX. Nimic.\n->";
                 char choice2;
                        cin>>choice2;
                        switch(toupper(choice2))
                        {
                        case 'A':
                        {
                            cout<<"\n\t\t\xB2 Introduceti noul tip a ofertei: \n\t\t";
                            cin>>tip;
                            break;
                        }
                        case 'B':
                        {
                            cout<<"\n\t\t\xB2 Introduceti noua strada a ofertei: \n\t\t";
                            cin>>strada;
                            break;
                        }
                        case 'C':
                        {
                            cout<<"\n\t\t\xB2 Introduceti noul bloc al ofertei: \n\t\t";
                            cin>>bloc;
                            break;
                        }
                         case 'D':
                        {
                            cout<<"\n\t\t\xB2 Introduceti noul pret al ofertei: \n\t\t";
                            cin>>pret;
                            break;
                        }

                        case 'X':
                        {
                            ok2 = 0;
                            break;
                        }
                        }
                        if(ok2 == 0)
                            break;
                    }
                    cout<<"\n\t\tSigur doriti sa modificati ? (Y/N)";
                    char choice2;
                    cin>>choice2;
                    if(toupper(choice2) == 'Y')
                    {
                        it->TipImobiliar(tip);
                        it->StradaImobiliar(strada);

                        adminimobiliar.SuprascriereFisier(listaimobiliar);
                        cout<<"\t\tOferta a fost modificata cu succes !";
                    }
                    else
                    {
                        cout<<"\t\tOferta NU a fost modificata.";
                        break;
                    }
                }
            }
            if (ok == 0)
            {
                cout<<"\n\n\t\tOferta inexistenta !";
            }
            break;
        }
        case 'R':
        {
     //       system("cls");
            if ( listaimobiliar.size() != 0)
                adminimobiliar.AfisareToataLista(listaimobiliar);
            else
                cout<<"\n\t\tNu aveti momentan nici o oferta imobiliar salvata.";
            cout<<"\n\t\tIntroduceti tipul ofertei pe care doriti sa o stergeti.\n->";
            string tip;
            cin>>tip;

            cout<<"\n\t\tIntroduceti strada ofertei imobiliar.\n->";
            string strada;
            cin>>strada;

            listaimobiliar = adminimobiliar.Optine_imobiliare();

            for (list<imobiliar>::iterator it = listaimobiliar.begin(); it != listaimobiliar.end(); ++it)
            {
                if( it->TipImobiliar() == tip && it->StradaImobiliar() == strada)
                {
                   system("cls");

                    if ( listaimobiliar.size() != 0)
                        adminimobiliar.AfisareToataLista(listaimobiliar);
                    else
                        cout<<"\n\t\tNu aveti momentan nici o oferta imobiliar salvata.";

                    cout<<"\n\n\t\t Oferta imobiliar gasita !";
                    cout<<"\n"<<it->TipImobiliar()<<" "<<it->StradaImobiliar()<<" "<<it->BlocImobiliar()<<" "<<it->PretImobiliar();
                    cout<<endl<<endl;
                    cout<<"\t\tSigur doriti sa stergeti acesta oferta imobiliar ? (Y/N)\n->";
                    char choice2;
                    cin>>choice2;
                    if(toupper(choice2) == 'Y')
                    {
                        adminimobiliar.RemoveItem(listaimobiliar, tip, strada);
                        cout<<"\n\t\tOferta imobiliar a fost stersa cu succes !";
                    }
                    else
                    {
                        cout<<"\n\t\tOferta imobiliar NU a fost stersa. ";
                    }
                }
            }
            break;
        }
        case 'X':
        {
             m.Meniu();
        }
        }
        cout<<"\n\n";
      system("pause");
    }

}

void meniu::Meniu_beneficiar()
{
    meniu m;
    Evidenta_beneficiari adminb;
    list<beneficiar> listab;
    char choice;


    cout<<endl;
    listab = adminb.Optine_beneficiari();
    adminb.AfisareToataLista(listab);
    while(1)
    {
        system("cls");
        menu_beneficiar();
        cout<<"\n\n\t\tAlegeti o optiune:";
        cin>>choice;
        switch(toupper(choice))
        {
        case 'A':
        {
            listab = adminb.Optine_beneficiari();
            if ( listab.size() != 0)
                adminb.AfisareToataLista(listab);
            else
                cout<<"\n\t\tNu aveti momentan nici un beneficiar salvat.";
            break;
        }
        case 'C':
        {
            cout<<"\n\t\t\xB2 Introduceti numele beneficiarului: ";
            string numebeneficiar;
            cin>>numebeneficiar;

            cout<<"\n\t\t\xB2 Introduceti prenumele beneficiarului: ";
            string prenume;
            cin>>prenume;

            cout<<"\n\t\t\xB2 Introduceti cnp-ul beneficiarului: ";
            string cnp;
            cin>>cnp;



            beneficiar c(numebeneficiar, prenume, cnp);
            adminb.Adaugare_beneficiar(c);
            break;
        }
        case 'F':
        {
            int ok = 0;
            cout<<"\n\t\t\xB2 Introduceti numele beneficiarului cautat: ";
            string nume;
            cin>>nume;

            cout<<"\n\t\t\xB2 Introduceti prenumele beneficiarului cautat: ";
            string prenume;
            cin>>prenume;

            listab = adminb.Optine_beneficiari();

            for (list<beneficiar>::iterator it = listab.begin(); it != listab.end(); it++)
            {
                if( it->NumeBeneficiar() == nume && it->PrenumeBeneficiar() == prenume)
                {
                    ok =1;
                    cout<<"\n\n\t\t Beneficiar gasit !";
                    cout<<"\n"<<it->NumeBeneficiar()<<" "<<it->PrenumeBeneficiar()<<" "<<it->Cnp();
                }
            }
            if (ok == 0)
            {
                cout<<"\n\n\t\t Beneficiar inexistent !";
            }
            break;
        }
        case 'M':
        {

           // system("cls");
            if ( listab.size() != 0)
                adminb.AfisareToataLista(listab);
            else
                cout<<"\n\t\tNu aveti momentan nici o beneficiar.";
            cout<<"\n\t\t\xB2 Introduceti numele beneficiarului pe care doriti sa il modificati.\n->";
            string nume;
            cin>>nume;

            cout<<"\n\t\t\xB2 Introduceti prenumele beneficiarului pe care doriti sa il modificati.\n->";
            string prenume;
            cin>>prenume;

            string edit, gen;
            int ok = 0, ok2 = 1;

            listab = adminb.Optine_beneficiari();

            for (list<beneficiar>::iterator it = listab.begin(); it != listab.end(); it++)
            {
                if( it->NumeBeneficiar() == nume && it->PrenumeBeneficiar() == prenume)
                {
                    system("cls");
                    if ( listab.size() != 0)
                        adminb.AfisareToataLista(listab);
                    else
                        cout<<"\n\t\tNu aveti momentan nici o beneficiar salvat.";
                    ok = 1;
                    cout<<"\n\n\t\t Beneficiar gasit !";
                    cout<<"\n\t\t"<<it->NumeBeneficiar()<<" "<<it->PrenumeBeneficiar()<<" "<<it->Cnp();
                    cout<<endl<<endl;
                    while (1)
                    {

                        cout<<"Ce camp doriti sa modificati ?";
                        cout<<"\n\t\tA. Nume beneficiar;\n\t\tB. Nume prenume;\n\t\tC. CNP;\n\t\tX. Nimic.\n\t\t->";
                        char choice2;
                        cin>>choice2;
                        switch(toupper(choice2))
                        {
                        case 'A':
                        {
                            cout<<"\n\t\t\xB2 Introduceti noul nume al beneficiar: \n\t\t";
                            cin>>nume;
                            break;
                        }
                        case 'B':
                        {
                            cout<<"\n\t\t\xB2 Introduceti noul prenume al beneficiarului: \n\t\t";
                            cin>>prenume;
                            break;
                        }
                        case 'C':
                        {
                            cout<<"\n\t\t\xB2 Introduceti noul CNP: \n\t\t";
                            cin>>edit;
                            break;
                        }

                        case 'X':
                        {
                            ok2 = 0;
                            break;
                        }
                        }
                        if(ok2 == 0)
                            break;
                    }
                    cout<<"\n\t\tSigur doriti sa modificati ? (Y/N)";
                    char choice2;
                    cin>>choice2;
                    if(toupper(choice2) == 'Y')
                    {
                        it->NumeBeneficiar(nume);
                        it->PrenumeBeneficiar(prenume);

                        adminb.SuprascriereFisier(listab);
                        cout<<"\t\tBeneficiarul a fost modificat cu succes !";
                    }
                    else
                    {
                        cout<<"\t\tBeneficiarul NU a fost modificat.";
                        break;
                    }
                }
            }
            if (ok == 0)
            {
                cout<<"\n\n\t\tBeneficiar inexistent !";
            }
            break;
        }
        case 'R':
        {
            //system("cls");
             if ( listab.size() != 0)
                adminb.AfisareToataLista(listab);
            else
                cout<<"\n\t\tNu aveti momentan nici un beneficiar salvat.";


            cout<<"\n\t\tIntroduceti numele beneficiarului pe care doriti sa il stergeti.\n->";
            string nume;
            cin>>nume;

            cout<<"\n\t\tIntroduceti prenumele beneficiarului pe care doriti sa il stergeti.\n->";
            string prenume;
            cin>>prenume;

            listab = adminb.Optine_beneficiari();

            for (list<beneficiar>::iterator it = listab.begin(); it != listab.end(); ++it)
            {
                if( it->NumeBeneficiar() == nume && it->PrenumeBeneficiar() == prenume)
                {
                    system("cls");

                    if ( listab.size() != 0)
                        adminb.AfisareToataLista(listab);
                    else
                        cout<<"\n\t\tNu aveti momentan nici un beneficiar salvat.";

                    cout<<"\n\n\t\t Beneficiar gasit !";
                    cout<<"\n"<<it->NumeBeneficiar()<<" "<<it->PrenumeBeneficiar()<<" "<<it->Cnp();
                    cout<<endl<<endl;
                    cout<<"\t\tSigur doriti sa stergeti acest contact ? (Y/N)\n->";
                    char choice2;
                    cin>>choice2;
                    if(toupper(choice2) == 'Y')
                    {
                        adminb.RemoveItem(listab, nume, prenume);
                        cout<<"\n\t\tBeneficarul a fost sters cu succes !";
                    }
                    else
                    {
                        cout<<"\n\t\tBeneficarul NU a fost sters. ";
                    }
                }
            }
            break;
        }
        case 'X':
        {
            m.Meniu();
        }
        }
        cout<<"\n\n";
        system("pause");
    }
}

void menu_principal()
{
    cout<<"\n\n\t\xB2\xB2\xB2\xB2 MENIU PRINCIPAL \xB2\xB2\xB2  \n ";

    cout<<"\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n ";
    cout<<"\t\xB2 A. Meniu imobiliare. \xB2";
    cout<<"\n\t\xB2 B. Meniu beneficiari.\xB2";
    cout<<"\n\t\xB2 X. Inchide program.  \xB2";
    cout<<"\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n ";
}

 void menu_imobiliar()
{
     cout<<"\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MENIU IMOBILIARE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n ";

    cout<<"\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   \n ";
     cout<<"\t\t\xB2 A. Afisare oferte imobiliare.            \xB2";
    cout<<"\n\t\t\xB2 C. Creare si adaugare oferta imobiliare. \xB2";
    cout<<"\n\t\t\xB2 F. Cauta oferta imobiliar.               \xB2";
    cout<<"\n\t\t\xB2 M. Modifica o oferta.                    \xB2";
    cout<<"\n\t\t\xB2 R. Sterge o oferta.                      \xB2";
    cout<<"\n\t\t\xB2 X. Inchide program.                      \xB2";
      cout<<"\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   \n ";

}

void menu_beneficiar()
{
     cout<<"\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MENIU BENEFICIARI \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  \n ";
  cout<<"\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   \n ";

    cout<<"\t\t\xB2 A. Afisare beneficiari.           \xB2";
    cout<<"\n\t\t\xB2 C. Creare si adaugare beneficiar. \xB2";
    cout<<"\n\t\t\xB2 F. Cauta beneficiar.              \xB2";
    cout<<"\n\t\t\xB2 M. Modifica un beneficiar.        \xB2";
    cout<<"\n\t\t\xB2 R. Sterge un beneficiar.          \xB2";
    cout<<"\n\t\t\xB2 X. Inchide program.               \xB2";
     cout<<"\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2   \n ";

}



meniu::~meniu()
{
    //dtor
}
