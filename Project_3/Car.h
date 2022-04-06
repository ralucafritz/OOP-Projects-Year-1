//
// Created by Raluca on 08-May-21.
//

#ifndef PROIECT3POO_CAR_H
#define PROIECT3POO_CAR_H

#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
    string nume;
    float pret;
    float lungime;
    string car_type;
    string forma;
    float reducere;
    float litraj;
    int id;
    static int id_curent;

    virtual void citire(istream &citire, Car &car1);
    virtual void afisare(ostream &scriere, const Car &car1) const;

public:
    Car();

    Car(const string& nume, float pret, float lungime, int car_type, int forma, float litraj);
    Car(const Car &car1);
    virtual ~Car();

    Car &operator=(const Car &car1);

    friend bool operator==(const Car &car1, const Car &car2);
    friend bool operator<(const Car &car1, const Car &car2);
    friend istream &operator>>(istream &citire, Car &car1);
    friend ostream &operator<<(ostream &scriere, const Car &car1);

    void set_nume(const string &nume);
    void set_pret(float pret1);
    void set_lungime(float lungime1);
    void set_car_type(int carType1);
    void set_forma(int forma1);
    void set_reducere(float ani_vechime1);
    void set_litraj(float litraj1);

    string get_forma() const;
    string get_nume() const;
    float get_pret() const;
    float get_lungime() const;
    string get_car_type() const;
    float get_reducere() const;
    float get_litraj() const;


    virtual bool este_noua();

};


#endif //PROIECT3POO_CAR_H
