//
// Created by Raluca on 10-May-21.
//

#ifndef PROIECT3POO_MONOVOLUME_H
#define PROIECT3POO_MONOVOLUME_H
#include "Car.h"

class Monovolume: public Car
{
private:
    int ani_vechime;
    int max_transport;

    virtual void citire(istream &citire, Car &car1);
    virtual void afisare(ostream &scriere, const Car &car1) const;


public:
    Monovolume();
    Monovolume(int ani_vechime, int max_transport, Car &car1);
    Monovolume(const Monovolume &monovolume1);

    virtual ~Monovolume();

    Monovolume &operator = (const Monovolume &monovolume1);
    friend istream &operator >> (istream &citire, Monovolume &monovolume1);
    friend ostream &operator << (ostream &scriere, Monovolume &monovolume1);

    void set_ani_vechime(int ani_vechime1);
    void set_max_transport(int max_transport1);

    int get_ani_vechime() const;
    int get_max_transport() const;

    virtual bool este_noua();

    void afisare_monovolume() const;
};


#endif //PROIECT3POO_MONOVOLUME_H
