//
// Created by Raluca on 08-May-21.
//

#ifndef PROIECT3POO_UTIL_H
#define PROIECT3POO_UTIL_H
#include <iostream>
#include "Car.h"
#include <set>

class Util
{
public:
    static bool este_vara();
    static std::string car_type(int car_type);
    static std::string forma(int forma);
    static void citireMasina(std::istream &citire, Car*& masina);
    static int meniu_compacta();
    static void validare_int(std::istream &citire, int &dest);
    static void validare_float(std::istream &citire, float &dest);
    static void print_menu();
};

#endif //PROIECT3POO_UTIL_H
