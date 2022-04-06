//
// Created by Raluca on 08-May-21.
//

#include "Car.h"
#include "Util.h"

int Car::id_curent = 0;

//////////////////////////////////////// CONSTRUCTORS ///////////////////////////////////

Car::Car()
{
    nume =  "";
    pret = 0.0;
    lungime = 0.0;
    car_type = Util::car_type(0);
    reducere = 0.0;
    litraj = 0.0;
    id = ++id_curent;

}

Car::Car(const string& nume, float pret, float lungime, int car_type, int forma, float litraj)
{
    this->nume = nume;
    this->pret = pret;
    this->lungime = lungime;
    this->car_type = Util::car_type(car_type);
    this->forma = Util::forma(forma);
    if(Util::este_vara())
    {
        this->reducere = 10;
    }
    this->litraj = litraj;
    id = ++id_curent;
}

Car::Car(const Car &car1)
{
    nume = car1.nume;
    pret = car1.pret;
    lungime = car1.lungime;
    car_type = car1.car_type;
    forma = car1.forma;
    reducere = car1.reducere;
    litraj = car1.litraj;
    id = ++id_curent;
}

//////////////////////////////////////// DESTRUCTOR //////////////////////////////////////

Car::~Car()
{
    nume = "";
    pret = 0.0;
    lungime = 0.0;
    car_type = "";
    forma = "";
    reducere = 0.0;
    litraj = 0.0;
}


///////////////////////////////////////// OPERATORI = / < / >> / << //////////////////////////

Car &Car::operator=(const Car &car1)
{
    nume = car1.nume;
    pret = car1.pret;
    lungime = car1.lungime;
    car_type = car1.car_type;
    forma = car1.forma;
    reducere = car1.reducere;
    litraj = car1.litraj;
    id = car1.id;

    return *this;
}

bool operator==(const Car &car1, const Car &car2)
{
    if(car1.id == car2.id)
    {
        return true;
    }
    return false;
}

bool operator<(const Car &car1, const Car &car2)
{
    if(car1.id < car2.id)
        return true;
    return false;
}

istream &operator>>(istream &citire, Car &car1)
{
    car1.citire(citire, car1);
    return citire;
}

ostream &operator<<(ostream &scriere, const Car &car1)
{
    car1.afisare(scriere, car1);
    return scriere;
}


//////////////////////////////////////// VIRTUALE CITIRE SI AFISARE //////////////////////


void Car::citire(istream &citire, Car &car1)
{
    float numarFloat;
    cout<< "Introduceti numele masinii: " << endl;
    citire >> std::ws;
    getline(citire, car1.nume);

    cout<< "Introduceti pretul: " << endl;
    Util::validare_float(citire, numarFloat);
    car1.pret = numarFloat;

    cout<< "Introduceti lungimea: " << endl;
    Util::validare_float(citire, numarFloat);
    car1.lungime = numarFloat;

    if(Util::este_vara())
    {
        reducere += 10;
    }

    cout<< "Introduceti litrajul masinii: " << endl;
    Util::validare_float(citire,numarFloat);
    car1.litraj = numarFloat;
}

void Car::afisare (ostream &scriere, const Car &car1) const
{
    scriere << "Numele masinii: " << car1.nume << endl;
    scriere << "Pret: " << car1.pret << endl;
    scriere << "Lungime: " << car1.lungime << " metri" << endl;
    scriere << "Tipul masinii: " << car1.car_type << endl;
    scriere << "Forma masinii: " << car1.forma << endl;
    scriere << "Reducere: " << car1.reducere << " % = " << (pret * reducere)/100 << " LEI" << endl;
    scriere << "Litraj: " << car1.litraj << endl;

}


//////////////////////////////////////// SETTERS /////////////////////////////////////////


void Car::set_nume(const string &nume)
{
    this->nume = nume;
}
void Car::set_pret(float pret1)
{
    this->pret = pret1;
}
void Car::set_lungime(float lungime1)
{
    this->lungime = lungime1;
}
void Car::set_car_type(int car_type1)
{
    this->car_type = Util::car_type(car_type1);
}
void Car::set_forma(int forma1)
{
    this->forma = Util::forma(forma1);
}
void Car::set_reducere(float ani_vechime1)
{
    reducere += (float) ani_vechime1;
}

void Car::set_litraj(float litraj1)
{
    this->litraj = litraj1;
}

//////////////////////////////////////// GETTERS /////////////////////////////////////////


string Car::get_nume() const
{
    return nume;
}
float Car::get_pret() const
{
    return pret;
}
float Car::get_lungime() const
{
    return lungime;
}
string Car::get_car_type() const
{
    return car_type;
}
string Car::get_forma() const
{
    return forma;
}
float Car::get_reducere() const
{
    return reducere;
}
float Car::get_litraj() const
{
    return litraj;
}


///////////////////////////////////////////// EXTRA ///////////////////////////////////////


bool Car::este_noua()
{
    return true;
}

