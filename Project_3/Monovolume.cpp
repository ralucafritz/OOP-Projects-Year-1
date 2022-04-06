//
// Created by Raluca on 10-May-21.
//

#include "Monovolume.h"
#include "Util.h"


//////////////////////////////////////// CONSTRUCTORS ///////////////////////////////////


Monovolume::Monovolume()
{
    ani_vechime = 0;
    max_transport = 0;
    this->set_car_type(3);
    this->set_forma(4);
}

Monovolume::Monovolume(int ani_vechime, int max_transport, Car &car1)
{
    Car *upcast = this;
    *upcast = car1;

    this->set_car_type(3);
    this->set_forma(4);
    this->ani_vechime = ani_vechime;
    this->set_reducere((float) ani_vechime);
    this->max_transport = max_transport;
}

Monovolume::Monovolume(const Monovolume &monovolume1) : Car(monovolume1)
{
    this->ani_vechime = monovolume1.ani_vechime;
    this->max_transport = monovolume1.max_transport;
}


//////////////////////////////////////// DESTRUCTOR //////////////////////////////////////

Monovolume::~Monovolume()
{
    ani_vechime = 0;
    max_transport = 0;
}

///////////////////////////////////////// OPERATORI = / >> / << //////////////////////////

Monovolume &Monovolume::operator = (const Monovolume &monovolume1)
{
    Car *upcast = this;
    *upcast = monovolume1;
    ani_vechime = monovolume1.ani_vechime;
    max_transport = monovolume1.max_transport;

    return *this;
}

istream &operator>>(istream &citire, Monovolume &monovolume1)
{
    monovolume1.citire(citire, monovolume1);
    return citire;
}

ostream &operator<<(ostream &scriere, Monovolume &monovolume1)
{
    monovolume1.afisare(scriere, monovolume1);
    return scriere;
}

//////////////////////////////////////// VIRTUALE CITIRE SI AFISARE //////////////////////


void Monovolume::citire(istream &citire, Car &car1)
{
    int numarInt;
    car1.set_car_type(3);
    car1.set_forma(4);
    Car car2 = car1;
    citire >> car2;

    Car* upcast = this;
    *upcast = car2;

    cout << "Introduceti ani vechime ai masinii: " << endl;
    Util::validare_int(citire, numarInt);
    ani_vechime = numarInt;
    set_reducere((float) ani_vechime);

    cout << "Introduceti numarul maxim de persoane ce pot fi transportate in masina: " << endl;
    Util::validare_int(citire, numarInt);
    max_transport = numarInt;
    if(max_transport < 5 || max_transport > 7)
    {
        cout << "Ati introdus un numar invalid de persoane ce pot fi transportate in masina." << endl
             << "Introduceti un numarul valid de persoane: " << endl;

        while(true)
        {
            try
            {
                citire >> numarInt;
                if(citire.fail())
                {
                    throw 10;
                }
                if(numarInt < 5 || numarInt > 7)
                {
                    throw 20;
                }
                max_transport = numarInt;
                break;
            }
            catch (int err)
            {
                cout << "Ati introdus un numar invalid de persoane ce pot fi transportate in masina." << endl
                     << "Introduceti un numarul valid de persoane: " << endl;
            }
        }
    }

}
void Monovolume::afisare(ostream &scriere, const Car &car1) const
{
    cout << "Numele masinii: " << this->get_nume() << endl;
    cout << "Pretul masinii: " << this->get_pret() << endl;
    cout << "Lungime: " << this->get_lungime() << " metri" << endl;
    cout << "Tipul masinii: " <<  this->get_car_type() << endl;
    cout << "Forma masinii: " <<  this->get_forma() << endl;
    cout << "Reducere: " <<  this->get_reducere() << " % = " << (this->get_pret() * this->get_reducere())/100 << " LEI" << endl;
    cout << "Litraj: " << this->get_litraj() << endl;

    if(ani_vechime == 0)
    {
        scriere << "Masina este noua! " << endl;
    }
    else
    {
        scriere << "Masina este Second-Hand! Ani vechime: " << ani_vechime << endl;
    }

    scriere << "Numar maxim de persoane ce pot fi transportate in masina: " << max_transport << endl;
}


//////////////////////////////////////// SETTERS /////////////////////////////////////////


void Monovolume::set_ani_vechime(int ani_vechime1)
{
    this->ani_vechime = ani_vechime1;
}
void Monovolume::set_max_transport(int max_transport1)
{
    this->max_transport = max_transport1;
}


//////////////////////////////////////// GETTERS /////////////////////////////////////////


int Monovolume::get_ani_vechime() const
{
    return ani_vechime;
}
int Monovolume::get_max_transport() const
{
    return max_transport;
}


//////////////////////////////////////// EXTRA ///////////////////////////////////////////


bool Monovolume::este_noua()
{
    if(ani_vechime != 0)
    {
        return false;
    }
    return true;
}

void Monovolume::afisare_monovolume() const
{
    cout << "******  Afisare Monovolum  ******" << endl;
    cout << "Numele masinii: " << this->get_nume() << endl;
    cout << "Pretul masinii: " << this->get_pret() << endl;
    cout << "Lungime: " << this->get_lungime() << " metri" << endl;
    cout << "Tipul masinii: " <<  this->get_car_type() << endl;
    cout << "Forma masinii: " <<  this->get_forma() << endl;
    cout << "Reducere: " <<  this->get_reducere() << " % = " << (this->get_pret() * this->get_reducere())/100 << " LEI" << endl;
    cout << "Litraj: " << this->get_litraj() << endl;
    if(ani_vechime != 0)
    {
        cout << "Masina este Second-Hand -> Ani vechime: " << ani_vechime << endl;
    }
    else
    {
        cout << "Masina este noua!" << endl;
    }
    cout << "Numar maxim de oameni ce pot fi transportati: " << max_transport << endl;
}
