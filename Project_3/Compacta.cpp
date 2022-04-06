//
// Created by Raluca on 10-May-21.
//

#include "Compacta.h"
#include "Util.h"


//////////////////////////////////////// CONSTRUCTORS ///////////////////////////////////

Compacta:: Compacta() : Car()
{
    this->set_car_type(4);
    this->set_forma(Util::meniu_compacta());
}

Compacta::Compacta(Car &car1)
{
    Car *upcast = this;
    *upcast = car1;

    this->set_car_type(4);
    this->set_forma(Util::meniu_compacta());
}

Compacta::Compacta(const Compacta &compacta1) : Car(compacta1)
{
    // apeleaza constructorul de copiere al clasei Car
}


//////////////////////////////////////// DESTRUCTOR //////////////////////////////////////


Compacta::~Compacta()
{
    // nu trebuie implementat
}


///////////////////////////////////////// OPERATORI = / >> / << //////////////////////////


Compacta &Compacta::operator = (const Compacta &compacta1)
{
    Car *upcast = this;
    *upcast = compacta1;
    return *this;
}

istream &operator>>(istream &citire, Compacta &compacta1)
{
    compacta1.citire(citire, compacta1);
    return citire;
}

ostream &operator<<(ostream &scriere, Compacta &compacta1)
{
    compacta1.afisare(scriere, compacta1);
    return scriere;
}


//////////////////////////////////////// VIRTUALE CITIRE SI AFISARE //////////////////////


void Compacta::citire(istream &citire, Car &car1)
{
    Car car2 = car1;
    citire >> car2;

    car1 = car2;
    car1.set_car_type(4);
    car1.set_forma(Util::meniu_compacta());

    float numarFloat;
    if(car1.get_lungime() >= 4.5 && car1.get_lungime() <= 4.2)
    {
        cout << "EROARE -> Lungimea acestei masini trebuie sa fie intre 4.2 si 4.5 metri. " << endl
             << "Introduceti lungimea corecta: " << endl;

        while(true)
        {
            try
            {
                citire >> numarFloat;
                if(citire.fail())
                {
                    throw 10;
                }
                if(car1.get_lungime() >= 4.5 && car1.get_lungime() <= 4.2)
                {
                    throw 20;
                }
                car1.set_lungime(numarFloat);
                break;
            }
            catch (int err)
            {
                cout << "EROARE -> Lungimea acestei masini trebuie sa fie intre 4.2 si 4.5 metri. " << endl
                     << "Introduceti lungimea corecta: " << endl;
            }

        }
    }
}

void Compacta::afisare(ostream &scriere, const Car &car1) const
{
    scriere << "Numele masinii: " << this->get_nume() << endl;
    scriere << "Pretul masinii: " << this->get_pret() << endl;
    scriere << "Lungime: " << this->get_lungime() << " metri" << endl;
    scriere << "Tipul masinii: " <<  this->get_car_type() << endl;
    scriere << "Forma masinii: " <<  this->get_forma() << endl;
    scriere << "Reducere: " <<  this->get_reducere() << " % = " << (this->get_pret() * this->get_reducere())/100 << " LEI" << endl;
    scriere << "Litraj: " << this->get_litraj() << endl;
}


//////////////////////////////////////// SETTERS /////////////////////////////////////////


//////////////////////////////////////// GETTERS /////////////////////////////////////////

