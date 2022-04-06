//
// Created by Raluca on 10-May-21.
//

#include "Mini.h"
#include "Util.h"

//////////////////////////////////////// CONSTRUCTORS ///////////////////////////////////

Mini:: Mini() : Car()
{
    this->set_car_type(4);
    this->set_forma(0);
}

Mini::Mini(Car &car1)
{
    Car *upcast = this;
    *upcast = car1;

    this->set_car_type(4);
    this->set_forma(0);
}

Mini::Mini(const Mini &mini1) : Car(mini1)
{
    // apeleaza constructorul de copiere al clasei Car
}


//////////////////////////////////////// DESTRUCTOR //////////////////////////////////////


Mini::~Mini()
{
    // nu trebuie implementat
}


///////////////////////////////////////// OPERATORI = / >> / << //////////////////////////


Mini &Mini::operator = (const Mini &mini1)
{
    Car *upcast = this;
    *upcast = mini1;
    return *this;
}

istream &operator>>(istream &citire, Mini &mini1)
{
    mini1.citire(citire, mini1);
    return citire;
}

ostream &operator<<(ostream &scriere, Mini &mini1)
{
    mini1.afisare(scriere, mini1);
    return scriere;
}


//////////////////////////////////////// VIRTUALE CITIRE SI AFISARE //////////////////////


void Mini::citire(istream &citire, Car &car1)
{
    Car car2 = car1;
    citire >> car2;

    car1 = car2;
    car1.set_car_type(1);

    float numarFloat;
    if(car1.get_lungime() > 4)
    {
        cout << "EROARE -> Lungimea acestei masini trebuie sa fie sub 4 metri. " << endl
             << "Introduceti lungimea corecta: " << endl;

        while(true)
        {
            try
            {
                citire >> numarFloat;
                if(citire.fail())
                {
                    throw -1;
                }
                if(numarFloat > 4)
                {
                    throw -2;
                }
                car1.set_lungime(numarFloat);
                break;
            }
            catch (int err)
            {
                cout << "EROARE -> Lungimea acestei masini trebuie sa fie sub 4 metri. " << endl
                     << "Introduceti lungimea corecta: " << endl;
            }

        }
    }
}

void Mini::afisare(ostream &scriere, const Car &car1) const
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

