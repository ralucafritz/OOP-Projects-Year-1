//
// Created by Raluca on 08-May-21.
//

#include "Util.h"
#include <exception>
#include "Mica.h"
#include "Mini.h"
#include "Monovolume.h"
#include "Compacta.h"

using namespace std;


bool Util::este_vara()
{
    cout<<"Pe timpul verii beneficiati de o reducere de 10%. Introduceti luna actuala: " << endl
        <<"1 pentru Ianuarie" << endl
        <<"2 pentru Februarie" << endl
        <<"3 pentru Martie" << endl
        <<"4 pentru Aprilie" << endl
        <<"5 pentru Mai" << endl
        <<"6 pentru Iunie" << endl
        <<"7 pentru Iulie" << endl
        <<"8 pentru August" << endl
        <<"9 pentru Septembrie" << endl
        <<"10 pentru Octombrie" << endl
        <<"11 pentru Noiembrie" << endl
        <<"12 pentru Decembrie" << endl;

    int numar;
    cin>>numar;
    if(6 <= numar && numar <= 8)
    {
        return true;
    }
    return false;

}

std::string Util::car_type(int car_type)
{
    string returnString;


    switch(car_type)
    {
        case 0:
            returnString = "NEDETERMINAT";
            break;
        case 1:
            returnString = "Oras";
            break;
        case 2:
            returnString = "Drum lung";
            break;
        case 3:
            returnString = "Transport";
            break;
        case 4:
            returnString = "Oras si drum lung";
            break;
    }

    return returnString;
}

std::string Util::forma(int forma)
{
    string returnString;


    switch(forma)
    {
        case 0:
            returnString = "NEDETERMINAT";
            break;
        case 1:
            returnString = "Hatchback";
            break;
        case 2:
            returnString = "Combi";
            break;
        case 3:
            returnString = "Sedan";
            break;
        case 4:
            returnString = "Van";
            break;
    }

    return returnString;
}

void Util::citireMasina(std::istream &citire, Car*& masina)
{
    int numarInt;
    cout << "Selectati tipul masinii: " << endl
    << "1 - Mini " << endl
    << "2 - Mica " << endl
    << "3 - Compacta " << endl
    << "4 - Monovolume " << endl;
    validare_int(citire,numarInt);
    switch(numarInt)
    {
        case 1:
            masina = new Mini();
            break;
        case 2:
            masina = new Mica();
            break;
        case 3:
            masina = new Compacta();
            break;
        case 4:
            masina = new Monovolume();
            break;
        default:
            masina = new Car();
            break;
    }

}


int Util::meniu_compacta()
{
    int numarInt;
    cout << "Introduceti numarul corespunzator formei masinii: " << endl
         << "1 - Hatchback " << endl
         << "2 - Combi" << endl
         << "3 - Sedan" << endl;
    Util::validare_int(cin,numarInt);

    return numarInt;
}

void Util::validare_int(std::istream &citire, int &dest)
{
    citire >> dest;
    while (citire.fail())
    {
        std::cout << "Eroare. Ati introdus o valoare care nu este INT. Incercati din nou: " << std::endl;
        citire.clear();
        citire.ignore(256, '\n');
        citire >> dest;
    }
}

void Util::validare_float(std::istream &citire, float &dest)
{
    citire >> dest;
    while (citire.fail())
    {
        std::cout << "Eroare. Ati introdus o valoare care nu este FLOAT. Incercati din nou: " << std::endl;
        citire.clear();
        citire.ignore(256, '\n');
        citire >> dest;

    }
}

void Util::print_menu()
{
    std::cout<< "1. Introduceti numarul masinilor din stoc, celor vandute si ambele liste" << std::endl
             << "2. Afisati numarul masinilor din stoc, celor vandute si ambele liste" <<  std::endl
             << "3. Afisati lista masinilor stoc" <<  std::endl
             << "4. Afisati lista masinilor vandute" <<  std::endl
             << "5. Vindeti o masina" <<  std::endl
             << "6. Introduceti numarul monovolumelor din stoc, celor vandute si ambele liste" << std::endl
             << "7. Afisati numarul monovolumelor din stoc, celor vandute si ambele liste" << std::endl
             << "8. Afisati lista monovolumelor din stoc" <<  std::endl
             << "9. Afisati lista monovolumelor vandute" <<  std::endl
             << "10. Vindeti o masina Monovolum" <<  std::endl
             << "11. Terminarea programului" <<  std::endl
             << "Alegeti o optiune: " << std::endl;
}

