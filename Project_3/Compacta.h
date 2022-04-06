//
// Created by Raluca on 10-May-21.
//

#ifndef PROIECT3POO_COMPACTA_H
#define PROIECT3POO_COMPACTA_H

#include "Car.h"

class Compacta: public Car
{
private:
    virtual void citire(istream &citire, Car &car1);
    virtual void afisare(ostream &scriere, const Car &car1) const;

public:
    Compacta();
    Compacta(Car &car1);
    Compacta(const Compacta &compacta1);

    virtual ~Compacta();

    Compacta &operator = (const Compacta &compacta1);
    friend istream &operator >> (istream &citire, Compacta &compacta1);
    friend ostream &operator << (ostream &scriere, Compacta &compacta1);


};


#endif //PROIECT3POO_COMPACTA_H
