//
// Created by Raluca on 13-May-21.
//

#ifndef PROIECT3POO_VANZARE_H
#define PROIECT3POO_VANZARE_H

#include <set>
#include <iterator>
#include "Car.h"
#include "Vanzare.h"
#include "Util.h"
#include "Mini.h"
#include "Mica.h"
#include "Compacta.h"
#include "Monovolume.h"



using namespace std;

template <class T>
class Vanzare
{
private:
    int nr_total_masini; // -- automat
    int nr_masini_vandute; // ++ automat
    set <pair<T*, bool> > stoc;
    set <pair<T*, bool> > vandute;

    virtual void citire(istream &citire, Vanzare<T> &vanzare1);
    virtual void afisare(ostream &scriere, const Vanzare<T> &vanzare1) const;

public:
    Vanzare();
    Vanzare(int nr_total_masini, int nr_masini_vandute, set<pair<T*, bool> > stoc,
            set<pair<T*, bool> > vandute);
    Vanzare(const Vanzare<T> &vanzare1);

    virtual ~Vanzare();

    Vanzare &operator=(const Vanzare<T> &vanzare1);
    Vanzare &operator-=(const pair<T*, bool>& pereche);

    template <class CarType> friend istream &operator>>(istream &citire, Vanzare<CarType> &vanzare1);
    template <class CarType> friend ostream &operator<<(ostream &scriere, Vanzare<CarType> &vanzare1);

    int get_nr_total_masini() const;
    int get_nr_masini_vandute() const;
    set<pair<T*, bool> > get_stoc() const;
    set<pair<T*, bool> > get_vandute() const;


};

// https://stackoverflow.com/questions/3705740/c-lnk2019-error-unresolved-external-symbol-template-classs-constructor-and
//  // https://www.mygreatlearning.com/blog/set-in-cpp/


//////////////////////////////////////// CONSTRUCTORS ///////////////////////////////////


template<class T>
Vanzare<T>::Vanzare()
{
    nr_total_masini = 0;
    nr_masini_vandute = 0;
}


template<class T>
Vanzare<T>::Vanzare(int nr_total_masini, int nr_masini_vandute, set<pair<T*, bool> > stoc,
                    set<pair<T*, bool> > vandute)
{
    this->nr_total_masini = nr_total_masini;
    this->nr_masini_vandute = nr_masini_vandute;
    this->stoc = stoc;
    this->vandute = vandute;
}

template<class T>
Vanzare<T>::Vanzare(const Vanzare &vanzare1)
{
    nr_total_masini = vanzare1.nr_total_masini;
    nr_masini_vandute = vanzare1.nr_masini_vandute;
    stoc = vanzare1.stoc;
    vandute = vanzare1.vandute;
}

//////////////////////////////////////// DESTRUCTOR //////////////////////////////////////


template<class T>
Vanzare<T>::~Vanzare()
{
    if(!stoc.empty())
    {
        vandute.clear();
    }
    if(!vandute.empty())
    {
        vandute.clear();
    }
    nr_total_masini = 0;
    nr_masini_vandute = 0;
}

////////////////////////////////////// OPERATORI  >> / << //////////////////////////

template<class T>
istream &operator>>(istream &citire, Vanzare<T> &vanzare1)
{
    vanzare1.citire(citire, vanzare1);
    return citire;
}

template<class T>
ostream &operator<<(ostream &scriere, Vanzare<T> &vanzare1)
{
    vanzare1.afisare(scriere, vanzare1);
    return scriere;
}

////////////////////////////////////// OPERATORI = / -= ////////////////////////////////

template<class T>
Vanzare<T> &Vanzare<T>::operator = (const Vanzare<T> &vanzare1)
{
    if(!stoc.empty())
    {
        vandute.clear();
    }
    if(!vandute.empty())
    {
        vandute.clear();
    }
    nr_total_masini = vanzare1.nr_total_masini;
    nr_masini_vandute = vanzare1.nr_vandute;
    stoc = vanzare1.stoc;
    vandute = vanzare1.vandute;

    return *this;
}

template<class T>
Vanzare<T> &Vanzare<T>::operator-= (const pair<T*, bool> &pereche)
{
    nr_total_masini--;
    nr_masini_vandute++;

    vandute.insert(pereche);
    stoc.erase(stoc.find(pereche));

    return *this;
}


//////////////////////////////////////// VIRTUALE CITIRE SI AFISARE //////////////////////


template<class T>
void Vanzare<T> ::citire(istream &citire, Vanzare<T>  &vanzare1)
{
    int numarInt;
    cout << "Introduceti numarul de masini din stoc: " << endl;
    Util::validare_int(citire, numarInt);
    nr_total_masini = numarInt;
    pair<T*, bool> pereche;

    T *upcast;
    int i;
    if(nr_total_masini !=0)
    {
        cout << "Introduceti detaliile despre masinile de pe stoc: " << endl;
        for (i = 0; i < nr_total_masini; i++)
        {
            Util::citireMasina(citire, upcast);
            citire >> *upcast;
            pereche.first = upcast;
            pereche.second = upcast->este_noua();
            stoc.insert(pereche);
            cout << "------------------------------------------------------------------" << endl;
        }
    }

    cout << "Introduceti numarul de masini vandute: " << endl;
    Util::validare_int(citire, numarInt);
    nr_masini_vandute = numarInt;

    if(nr_masini_vandute !=0)
    {
        cout << "Introduceti detaliile despre masinile vandute: " << endl;
        for(i = 0; i < nr_masini_vandute; i++)
        {
            Util::citireMasina(citire, upcast);
            citire >> *upcast;
            pereche.first = upcast;
            pereche.second = upcast->este_noua();
            vandute.insert(pereche);
            cout << "------------------------------------------------------------------" << endl;
        }
    }
}

template<class T>
void Vanzare<T>::afisare(ostream &scriere, const Vanzare<T>  &vanzare1) const
{
    int numar;
    typename set<pair<T*, bool> >::iterator i;
    if(nr_total_masini != 0)
    {
        scriere << "Numatul total de masini in stoc este: " << nr_total_masini << endl
                << "---------------------------------Lista masini in stoc: ---------------------------------" << endl;
        numar = 1;
        for (i = stoc.begin(); i != stoc.end(); i++)
        {
            scriere << "----------------- Masina # " << numar << " -----------------" << endl;
            numar++;
            const Monovolume* downcast = dynamic_cast<const Monovolume*>((*i).first);
            if(downcast)
            {
                downcast->afisare_monovolume();
            }
            else
            {
                scriere<< *(*i).first << endl;
            }

        }
    }else
    {
        scriere << "Lista masinilor din stoc este goala. " << endl;
    }

    if(nr_masini_vandute != 0)
    {
        scriere << "Numarul total de masini vandute este: " << nr_masini_vandute << endl
                << "---------------------------------Lista masini vandute: ---------------------------------" << endl;
        numar = 1;
        for (i = vandute.begin(); i != vandute.end(); i++)
        {
            scriere << "----------------- Masina # " << numar << " -----------------" << endl;
            numar++;
            scriere << *(*i).first << endl;
        }
    }else
    {
        scriere << "Lista masinilor vandute este goala. " << endl;
    }
}

//////////////////////////////////////// SETTERS /////////////////////////////////////////


// nu mi s-a parut necesar


//////////////////////////////////////// GETTERS /////////////////////////////////////////

template<class T>
int Vanzare<T>::get_nr_total_masini() const
{
    return nr_total_masini;
}

template<class T>
int Vanzare<T>::get_nr_masini_vandute() const
{
    return nr_masini_vandute;
}

template<class T>
set<pair<T*,bool> > Vanzare<T>::get_stoc() const
{
    return stoc;
}

template<class T>
set<pair<T*,bool> > Vanzare<T>::get_vandute() const
{
    return vandute;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

template <> class Vanzare <Monovolume>
{
private:
    int nr_masini;
    int nr_vandute;
    set<pair<Monovolume*, bool> > stoc;
    set<pair<Monovolume*, bool> > vandute;

    virtual void citire(istream &citire, Vanzare<Monovolume> &vanzareM);
    virtual void afisare(ostream &scriere, const Vanzare<Monovolume> &vanzareM) const;

public:
    Vanzare();
    Vanzare(int nr_masini, int nr_vandute, set<pair<Monovolume*, bool> > stoc,
            set<pair<Monovolume*, bool> >  vandute);
    Vanzare(const Vanzare &vanzareM);

    virtual ~Vanzare();

    Vanzare &operator =(const Vanzare &vanzareM);
    Vanzare &operator -=(const pair<Monovolume*, bool>& pereche);

    friend istream& operator >> (istream &citire,  Vanzare<Monovolume> &vanzareM);
    friend ostream& operator << (ostream &scriere, Vanzare<Monovolume> &vanzareM);

    int get_nr_masini() const;
    int get_nr_vandute() const;
    set<pair<Monovolume*, bool> > get_stoc() const;
    set<pair<Monovolume*, bool> > get_vandute() const;

};


//////////////////////////////////////// CONSTRUCTORS ///////////////////////////////////


Vanzare<Monovolume>::Vanzare()
{
    nr_masini = 0;
    nr_vandute = 0;
}


Vanzare<Monovolume>:: Vanzare(int nr_masini, int nr_vandute, set<pair<Monovolume*, bool> > stoc,
                              set<pair<Monovolume*, bool> >  vandute)
{
    this->nr_masini = nr_masini;
    this->nr_vandute = nr_vandute;
    this->stoc = stoc;
    this->vandute = vandute;
}

Vanzare<Monovolume>:: Vanzare(const Vanzare &vanzareM)
{
    nr_masini = vanzareM.nr_masini;
    nr_vandute = vanzareM.nr_vandute;
    stoc = vanzareM.stoc;
    vandute = vanzareM.vandute;
}

//////////////////////////////////////// DESTRUCTOR //////////////////////////////////////


Vanzare<Monovolume>::~Vanzare()
{
    if(!stoc.empty())
    {
        vandute.clear();
    }
    if(!vandute.empty())
    {
        vandute.clear();
    }
    nr_masini = 0;
    nr_vandute = 0;
}

////////////////////////////////////// OPERATORI  >> / << //////////////////////////

istream &operator>>(istream &citire, Vanzare<Monovolume> &vanzareM)
{
    vanzareM.citire(citire, vanzareM);
    return citire;
}

ostream &operator<<(ostream &scriere, Vanzare<Monovolume> &vanzareM)
{
    vanzareM.afisare(scriere, vanzareM);
    return scriere;
}

////////////////////////////////////// OPERATORI = / -= ////////////////////////////////

Vanzare<Monovolume> &Vanzare<Monovolume>::operator = (const Vanzare &vanzareM)
{
    if(!stoc.empty())
    {
        vandute.clear();
    }
    if(!vandute.empty())
    {
        vandute.clear();
    }
    nr_masini = vanzareM.nr_masini;
    nr_vandute = vanzareM.nr_vandute;
    stoc = vanzareM.stoc;
    vandute = vanzareM.vandute;

    return *this;
}

Vanzare<Monovolume> &Vanzare<Monovolume>::operator-= (const pair<Monovolume*, bool>& pereche)
{
    nr_masini--;
    nr_vandute++;

    vandute.insert(pereche);
    stoc.erase(stoc.find(pereche));

    return *this;
}


//////////////////////////////////////// VIRTUALE CITIRE SI AFISARE //////////////////////


void Vanzare<Monovolume> ::citire(istream &citire, Vanzare<Monovolume>  &vanzareM)
{
    int numarInt;
    cout << "Introduceti numarul de Monovolume din stoc: " << endl;
    Util::validare_int(citire, numarInt);
    nr_masini = numarInt;
    int i;
    pair<Monovolume*, bool> pereche;
    Monovolume *masina;

    if(nr_masini != 0)
    {
        cout << "Introduceti detaliile despre Monovolumele de pe stoc: " << endl;

        for (i = 0; i < nr_masini; i++)
        {
            masina = new Monovolume();
            citire >> *masina;
            pereche.first = masina;
            pereche.second = masina->este_noua();
            stoc.insert(pereche);
            cout << "------------------------------------------------------------------" << endl;
        }
    }

    cout << "Introduceti numarul de masini vandute: " << endl;
    Util::validare_int(citire, numarInt);
    nr_vandute = numarInt;

    if(nr_vandute != 0)
    {
        cout << "Introduceti detaliile despre masinile vandute: " << endl;
        for (i = 0; i < nr_vandute; i++)
        {
            masina = new Monovolume();
            citire >> *masina;
            pereche.first = masina;
            pereche.second = masina->este_noua();
            vandute.insert(pereche);
            cout << "------------------------------------------------------------------" << endl;
        }
    }
}


void Vanzare<Monovolume>::afisare(ostream &scriere, const Vanzare<Monovolume> &vanzareM) const
{
    typename set<pair<Monovolume*, bool> >::iterator i;
    int numar = 1;
    if(nr_masini != 0)
    {
        scriere << "Numatul total de Monovolume in stoc este: " << vanzareM.nr_masini << endl
                << "---------------------------------Lista masini in stoc: ---------------------------------" << endl;
        for (i = stoc.begin(); i != stoc.end(); i++)
        {
            scriere << "----------------- Masina # " << numar << " -----------------" << endl;
            numar++;
            scriere << *(*i).first << endl;
        }
    }
    else
    {
        scriere << "Lista Monovolumelor din stoc este goala. " << endl;
    }

    if(nr_vandute != 0)
    {
        scriere << "Numarul total de Monovolume vandute este: " << vanzareM.nr_vandute << endl
                << "---------------------------------Lista masini vandute: ---------------------------------" << endl;
        numar = 1;
        for (i = vandute.begin(); i != vandute.end(); i++)
        {
            scriere << "----------------- Masina # " << numar << " -----------------" << endl;
            numar++;

            scriere << *(*i).first << endl;

        }
    }
    else
    {
        scriere << "Lista Monovolumelor vandute este goala. " << endl;
    }
}

//////////////////////////////////////// GETTERS /////////////////////////////////////////

int Vanzare<Monovolume>::get_nr_masini() const
{
    return nr_masini;
}

int Vanzare<Monovolume>::get_nr_vandute() const
{
    return nr_vandute;
}

set<pair<Monovolume*,bool> > Vanzare<Monovolume>::get_stoc() const
{
    return stoc;
}

set<pair<Monovolume*,bool> > Vanzare<Monovolume>::get_vandute() const
{
    return vandute;
}

#endif //PROIECT3POO_VANZARE_H
