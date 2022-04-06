#include <iostream>
#include "Car.h"
#include "Monovolume.h"
#include "Mini.h"
#include "Mica.h"
#include "Compacta.h"
#include "Util.h"
#include "Vanzare.h"

using namespace std;

/*
 * Dintr-un parc auto se poate cumpăra o gamă variată de automobile de următoarele tipuri:
 *      MINI (mașină de oraș, de mic litraj, de obicei sub 4m lungime),
 *      MICA (mașină de oraș, cu spațiu interior mai mare decât MINI și lungime între 3.85 și 4.1),
 *      COMPACTA(mașină ușor de folosit, atât în oraș, cât și la drumlung, de dimensiune 4.2 – 4.5m
 * acest tip de mașini are formă de hatchback, combi sau sedan)
 *      și MONOVOLUME(automobile sub formă de van, ce pot transporta 5-7persoane)
 * Monovolumele pot fi achiziționate atât noi cât și second hand. La cele achiziționate second hand, se percepe
 * un discount proporțional cu numărul de ani vechimeai mașinii.
 *
 * Pentru toate automobilele, în lunile de vară, se beneficiazăde zile promoționale cu reducere fixă de 10% din preț.
 *
        * SH  - X ani -> X% reducere
        * VARA - reducere 10% din pret
 */
/////////////////////
/*
 *
 * Structura de date: set<pair<tip_automobil, bool nou>>(nou = false pentru cele sh)
 *
 */
/////////////////////
/*
 *
 * Să se construiască clasa template Vanzare care sa conțină numărul total de mașini aflate pe stoc
 * (decrementat automat la vânzarea unei mașini), numărul de mașini
 * vândute (incrementat automat) și două structuri de obiecte, alocate dinamic,
 * prin care să se gestioneze automobilele din stoc și cele vândute.
 *
*/
 /////////////////////
 /*
  *
 * Să se supraîncarce operatorul -= care să actualizeze datele din clasă la vanzarea unei mașini.
  *
*/
    /////////////////////
/*
 *
 * Să se adauge toate câmpurile relevante pentru modelarea acestei probleme.
 *
 * Cerința suplimentară:
 *
 * - Să se construiască o specializare pentru tipul MONOVOLUM care sa conțină și să
 *                  afișeze/gestioneze doar MONOVOLUMELE.
 */


int main()
{
    Vanzare<Car> vanzareMasini;
    Vanzare<Monovolume> vanzareMonovolume;


    int optiune;
    bool okay = true;
    while(okay)
    {
        Util::print_menu();
        std::cin >> optiune;
        switch(optiune)
        {
            case 1: // citire vanzare
            {
                cin >> vanzareMasini;
                break;
            }
            case 2: // afisare vanzare
            {
                cout << vanzareMasini;
                break;
            }
            case 3: // afisare lista stoc
            {
                set<pair<Car*,bool> > listaStoc = vanzareMasini.get_stoc();
                set<pair<Car*, bool> >::iterator i;
                int numar = 1;
                cout << "Lista masinilor din stoc: " << endl;
                for(i = listaStoc.begin(); i != listaStoc.end(); i++)
                {
                    cout << "-- Masina # " << numar << "--" << endl;
                    numar ++;
                    cout << *(*i).first << endl;
                }
                break;
            }
            case 4: // afisare lista vandute
            {
                set<pair<Car*,bool> > listaVandute = vanzareMasini.get_vandute();
                set<pair<Car*, bool> >::iterator i;
                int numar = 1;
                cout << "Lista masinilor vandute: " << endl;
                for(i = listaVandute.begin(); i != listaVandute.end(); i++)
                {
                    cout << "-- Masina # " << numar << "--" << endl;
                    numar ++;
                    cout << *(*i).first << endl;
                }
                break;
            }
            case 5: // vindeti o masina
            {
                set<pair<Car*,bool> > listaStoc = vanzareMasini.get_stoc();
                set<pair<Car*, bool> >::iterator i;
                cout << "Lista masinilor din stoc: " << endl;
                int numar = 1;
                int optiuneStoc;
                for(i = listaStoc.begin(); i != listaStoc.end(); i++)
                {
                    cout << "-- Masina # " << numar << "--" << endl;
                    numar ++;
                    cout << *(*i).first << endl << "Doriti sa o cumparati? 0 - NU / 1 - DA" << endl;
                    Util::validare_int(cin,optiuneStoc);
                    if(optiuneStoc == 1)
                    {
                        vanzareMasini -= *i;
                        break;
                    }
                }
                break;
            }
            case 6: // citire vanzare monovolume
            {
                cin >> vanzareMonovolume;
                break;
            }
            case 7: // afisare vanzare monovolume
            {
                cout << vanzareMonovolume;
                break;
            }
            case 8: // afisare lista monovolume din stoc
            {
                set<pair<Monovolume*,bool> > listaStoc = vanzareMonovolume.get_stoc();
                set<pair<Monovolume*, bool> >::iterator i;
                int numar = 1;
                cout << "Lista masinilor din stoc: " << endl;
                for(i = listaStoc.begin(); i != listaStoc.end(); i++)
                {
                    cout << "-- Masina # " << numar << "--" << endl;
                    numar ++;
                    cout << *(*i).first << endl;
                }
                break;
            }
            case 9: // afisare lista monovolumue vandute
            {
                set<pair<Monovolume*, bool> > listaVandute = vanzareMonovolume.get_vandute();
                set<pair<Monovolume*, bool> >::iterator i;
                int numar = 1;
                cout << "Lista masinilor vandute: " << endl;
                for(i = listaVandute.begin(); i != listaVandute.end(); i++)
                {
                    cout << "-- Masina # " << numar << "--" << endl;
                    numar ++;
                    cout << *(*i).first << endl;
                }
                break;
            }
            case 10:
            {
                set<pair<Monovolume*, bool> > listaStoc = vanzareMonovolume.get_stoc();
                set<pair<Monovolume*, bool> >::iterator i;
                cout << "Lista masinilor din stoc: " << endl;
                int numar = 1;
                int optiuneStoc;
                for(i = listaStoc.begin(); i != listaStoc.end(); i++)
                {
                    cout << "-- Masina # " << numar << "--" << endl;
                    numar ++;
                    cout << *(*i).first << endl << "Doriti sa o cumparati? 0 - NU / 1 - DA" << endl;
                    Util::validare_int(cin,optiuneStoc);
                    if(optiuneStoc == 1)
                    {
                        vanzareMonovolume -= *i;
                        break;
                    }
                }
                break;
            }
            default: // terminarea programului
                okay = false;
                break;
        }

    }

    return 0;
}
