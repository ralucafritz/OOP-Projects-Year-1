//
// Created by Raluca on 10-May-21.
//

#include "Mica.h"
#include "Util.h"

//////////////////////////////////////// CONSTRUCTORS ///////////////////////////////////

Mica:: Mica() : Car()
{
    this->set_car_type(2);
    this->set_forma(0);
}

Mica::Mica(Car &car1)
{
    Car *upcast = this;
    *upcast = car1;

    this->set_car_type(2);
    this->set_forma(0);

}

Mica::Mica(const Mica &mica1) : Car(mica1)
{
    // apeleaza constructorul de copiere al clasei Car
}


//////////////////////////////////////// DESTRUCTOR //////////////////////////////////////


Mica::~Mica()
{
    // nu trebuie implementat
}


///////////////////////////////////////// OPERATORI = / >> / << //////////////////////////


Mica &Mica::operator = (const Mica &mica1)
{
    Car *upcast = this;
    *upcast = mica1;
    return *this;
}

istream &operator>>(istream &citire, Mica &mica1)
{
    mica1.citire(citire, mica1);
    return citire;
}

ostream &operator<<(ostream &scriere, Mica &mica1)
{
    mica1.afisare(scriere, mica1);
    return scriere;
}


//////////////////////////////////////// VIRTUALE CITIRE SI AFISARE //////////////////////


void Mica::citire(istream &citire, Car &car1)
{
    Car car2 = car1;
    citire >> car2;

    car1 = car2;
    car1.set_car_type(1);

    float numarFloat;
    if(car1.get_lungime() >= 4.1 && car1.get_lungime() <= 3.85)
    {
        cout << "EROARE -> Lungimea acestei masini trebuie sa fie intre 3.85 si 4.1 metri. " << endl
             << "Introduceti lungimea corecta: " << endl;

        while(true)
        {
            try
            {
                citire >> numarFloat;
                if(citire.fail())
                {
                    throw 1;
                }
                if(car1.get_lungime() >= 4.1 && car1.get_lungime() <= 3.85)
                {
                    throw 2;
                }
                car1.set_lungime(numarFloat);
                break;
            }
            catch (int err)
            {
                cout << "EROARE -> Lungimea acestei masini trebuie sa fie intre 3.85 si 4.1 metri. " << endl
                     << "Introduceti lungimea corecta: " << endl;
            }

        }
    }
}

void Mica::afisare(ostream &scriere, const Car &car1) const
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
