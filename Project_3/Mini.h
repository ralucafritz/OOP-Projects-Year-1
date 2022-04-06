//
// Created by Raluca on 10-May-21.
//

#ifndef PROIECT3POO_MINI_H
#define PROIECT3POO_MINI_H

#include "Car.h"

class Mini: public Car
{
private:
    virtual void citire(istream &citire, Car &car1);
    virtual void afisare(ostream &scriere, const Car &car1) const;

public:
    Mini();
    Mini(Car &car1);
    Mini(const Mini &mini1);

    virtual ~Mini();

    Mini &operator = (const Mini &mini1);
    friend istream &operator >> (istream &citire, Mini &mini1);
    friend ostream &operator << (ostream &scriere, Mini &mini1);

};


#endif //PROIECT3POO_MINI_H
