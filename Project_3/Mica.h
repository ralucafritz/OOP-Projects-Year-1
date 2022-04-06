//
// Created by Raluca on 10-May-21.
//

#ifndef PROIECT3POO_MICA_H
#define PROIECT3POO_MICA_H

#include "Car.h"

class Mica: public Car
{
private:
    virtual void citire(istream &citire, Car &car1);
    virtual void afisare(ostream &scriere, const Car &car1) const;

public:
    Mica();
    Mica(Car &car1);
    Mica(const Mica &mica1);

    virtual ~Mica();

    Mica &operator = (const Mica &mica1);
    friend istream &operator >> (istream &citire, Mica &mica1);
    friend ostream &operator << (ostream &scriere, Mica &mica1);

};


#endif //PROIECT3POO_MICA_H
