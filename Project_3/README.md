##### FRITZ RALUCA-MIHAELA 
##### GRUPA 143
##### ANUL 2020-2021
## <center> PROIECT 3 - PROGRAMARE ORIENTATA PE OBIECTE </center>

### Cerinta:

- Dintr-un parc auto se poate cumpăra o gamă variată de automobile de următoarele tipuri: 
  - `MINI` (mașină de oraș, de mic litraj, de obicei sub 4m lungime)
  - `MICA` (mașină de oraș, cu spațiu interior mai mare decât MINI și lungime între 3.85 și 4.1) 
  - `COMPACTA` (mașină ușor de folosit, atât în oraș, cât și la drum lung, de dimensiune 4.2 – 4.5m; acest tip de mașini are formă de hatchback, combi sau sedan) 
  - `MONOVOLUME` (automobile sub formă de van, ce pot transporta 5-7 persoane). 

- Monovolumele pot fi achiziționate atât noi cât și second hand. La cele achiziționate second hand, se percepe un discount proporțional cu numărul de ani vechime ai mașinii.

- Pentru toate automobilele, în lunile de vară, se beneficiază de zile promoționale cu reducere fixă de 10% din preț. 

- Structura de date: `set<pair<tip_automobil, bool nou>>` (nou = false pentru cele sh)

- Să se construiască clasa template `Vanzare` care sa conțină numărul total de mașini aflate pe stoc (decrementat automat la vânzarea unei mașini), numărul de mașini vândute (incrementat automat) și două structuri de obiecte, alocate dinamic, prin care să se gestioneze automobilele din stoc și cele vândute. 

- Să se supraîncarce operatorul `-=` care să actualizeze datele din clasă la vanzarea unei mașini.

- Să se adauge toate câmpurile relevante pentru modelarea acestei probleme.

### Rezolvare:

- Am creat toate clasele cerute + parametrii respectivi si am adaugat diverse metode pe care le folosim sau am considerat ca ar putea fi folosite ulterior.
  
- Am creat o clasa Util cu functii statice utile care sunt folosite in cel putin o alta clasa: `este_vara`, `car_type`, `forma`, `citireMasina`, `meniu_compacta`, `validare_int`, `validare_float`, `print_menu`.
  
- Toate clasele (excluzand clasa `Util`) cotin constructor de initializare, constructor parametrizat, constructor de copiere, destructor, operator `=`, supraincarcarea operatorilor `>>` si `<<` + functii virtuale pentru citire si afisare.
  
- Memoria este eliberata unde este nevoie (destructori si alte locuri in care este alocata memoria dinamic).
  
- Am folosit STL folosind `set<pair<T*,bool>>` si `pair<T*,bool>` 
- Am utilizat si definit template si specializarea lui
- Am tratat cateva exceptii:
```cpp
if(car1.get_lungime() >= 4.5 && car1.get_lungime() <= 4.2)
    {
        cout << "EROARE -> Lungimea acestei masini trebuie sa fie intre 4.2 si 4.5 metri. " << endl
             << "Introduceti lungimea corecta: " << endl;

        while(true)
        {
            try
            {
                citire >> numarFloat;
                if(citire.fail())
                {
                    throw 10;
                }
                if(car1.get_lungime() >= 4.5 && car1.get_lungime() <= 4.2)
                {
                    throw 20;
                }
                car1.set_lungime(numarFloat);
                break;
            }
            catch (int err)
            {
                cout << "EROARE -> Lungimea acestei masini trebuie sa fie intre 4.2 si 4.5 metri. " << endl
                     << "Introduceti lungimea corecta: " << endl;
            }

        }
    }
```
```cpp 
 if(car1.get_lungime() >= 4.1 && car1.get_lungime() <= 3.85)
    {
        cout << "EROARE -> Lungimea acestei masini trebuie sa fie intre 3.85 si 4.1 metri. " << endl
             << "Introduceti lungimea corecta: " << endl;

        while(true)
        {
            try
            {
                citire >> numarFloat;
                if(citire.fail())
                {
                    throw 1;
                }
                if(car1.get_lungime() >= 4.1 && car1.get_lungime() <= 3.85)
                {
                    throw 2;
                }
                car1.set_lungime(numarFloat);
                break;
            }
            catch (int err)
            {
                cout << "EROARE -> Lungimea acestei masini trebuie sa fie intre 3.85 si 4.1 metri. " << endl
                     << "Introduceti lungimea corecta: " << endl;
            }

        }
    }
```
- Am folosit concepte de `upcasting`:
```cpp
Monovolume::Monovolume(int ani_vechime, int max_transport, Car &car1)
{
    Car *upcast = this;
    *upcast = car1;
    .
    .
}
```
```cpp
Mini::Mini(Car &car1)
{
    Car *upcast = this;
    *upcast = car1;
    .
    .
}
```
```cpp
void Monovolume::citire(istream &citire, Car &car1)
{
    int numarInt;
    car1.set_car_type(3);
    car1.set_forma(4);
    Car car2 = car1;
    citire >> car2;

    Car* upcast = this;
    *upcast = car2;
    .
    .
}
```
- Am folosit concepte de `functii virtuale`:
  - In clasa de baza `Car`:
    ```cpp
    virtual void citire(istream &citire, Car &car1);
    virtual void afisare(ostream &scriere, const Car &car1) const;
    ```
  - In clasa derivata `Mini`:
    ```cpp
    class Mini: public Car
    {
    private:
        virtual void citire(istream &citire, Car &car1);
        virtual void afisare(ostream &scriere, const Car &car1) const;
        .
        .
    }
    ```
  - In clasa derivata `Mica`:
    ```cpp
    class Mica: public Car
    {
    private:
        virtual void citire(istream &citire, Car &car1);
        virtual void afisare(ostream &scriere, const Car &car1) const;
        .
        .
    }
    ```
  - In clasa derivata `Compacta`:
    ```cpp
    class Compacta: public Car
    {
    private:
        virtual void citire(istream &citire, Car &car1);
        virtual void afisare(ostream &scriere, const Car &car1) const;
        .
        .
    }
    ```
  - In clasa derivata `Monovolume`:
    ```cpp
    class Monovolume: public Car
    {
    private:
        int ani_vechime;
        int max_transport;

        virtual void citire(istream &citire, Car &car1);
        virtual void afisare(ostream &scriere, const Car &car1) const;
        .
        .
    }
    ```
  - In template `Vanzare`:
    ```cpp
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
        .
        .
    }
    ```
  - In template `Vanzare<Monovolume>`:
    ```cpp
    template <> class Vanzare <Monovolume>
    {
    private:
        int nr_masini;
        int nr_vandute;
        set<pair<Monovolume*, bool> > stoc;
        set<pair<Monovolume*, bool> > vandute;

        virtual void citire(istream &citire, Vanzare<Monovolume> &vanzareM);
        virtual void afisare(ostream &scriere, const Vanzare<Monovolume> &vanzareM) const;
        .
        .
    }
    ```
- Am ilustrat concepte de `RTTI` raportat la template-uri utilizand `dynamic_cast` in `template<class T> Vanzare`:
```cpp
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
    .
    .
}
```
- Am utilizat functii `const`:
```cpp
    string get_forma() const;
    string get_nume() const;
    float get_pret() const;
    float get_lungime() const;
    string get_car_type() const;
    float get_reducere() const;
    float get_litraj() const;
```
- Am utilizat `functii statice` si o `variabila statica`:
```cpp
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
```
```cpp
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
```
- Am adaugat meniu interactiv prin care se pot:
  - Adauga numarul de masini din stoc si cele vandute + listele masinilor din stoc si celor vandute
  - Afisarea numarul de masini din stoc si cele vandute + listele masinilor din stoc si celor vandute
  - Afisarea listei masinilor din stoc
  - Afisarea listei masinilor vandute 
  - Vinderea unei masini din stoc 
  - Adauga numarul de Monovolume din stoc si cele vandute + listele Monovolumelor din stoc si celor vandute
  - Afisarea numarul de Monovolume din stoc si cele vandute + listele Monovolume din stoc si celor vandute
  - Afisarea listei `Monovolume` din stoc 
  - Afisarea listei `Monovolume` vandute 
  - Vinderea unui `Monovolum` din stoc
  - Terminarea programului
  
```
1. Introduceti numarul masinilor din stoc, celor vandute si ambele liste
2. Afisati numarul masinilor din stoc, celor vandute si ambele liste
3. Afisati lista masinilor stoc
4. Afisati lista masinilor vandute
5. Vindeti o masina
6. Introduceti numarul monovolumelor din stoc, celor vandute si ambele liste
7. Afisati numarul monovolumelor din stoc, celor vandute si ambele liste
8. Afisati lista monovolumelor din stoc
9. Afisati lista monovolumelor vandute
10. Vindeti o masina Monovolum
11. Terminarea programului
Alegeti o optiune:  
```
  
Citire masini stoc: masini vandute (optiunea 1):  
![](https://gcdnb.pbrd.co/images/RYkJrEM2FpF4.png?o=1)  
![](https://gcdnb.pbrd.co/images/Cu74iYYdA4mZ.png?o=1)

Afisare masini stoc + masini vandute (optiunea 2):  
![](https://gcdnb.pbrd.co/images/J6HKENjmQpZN.png?o=1)

Afisare masini stoc (optiunea 3):  
![](https://gcdnb.pbrd.co/images/e7KyDxjpk2u8.png?o=1)

Vinderea unei masini (optiunea 5): stergem a 2-a masina:  
![](https://gcdnb.pbrd.co/images/Ku90706lkT4s.png?o=1)

Afisare masini vandute (optiunea 4):  
![](https://gcdnb.pbrd.co/images/V8bmlgvCqw3C.png?o=1)

Afisare masini stoc + vandute (optiunea 2):  
![](https://gcdnb.pbrd.co/images/YP1mjjKepcVT.png?o=1)

Citire masini stoc + masini vandute (optiunea 6):  
![](https://gcdnb.pbrd.co/images/9R9FGxmaGc0s.png?o=1)  
![](https://gcdnb.pbrd.co/images/mLduuMumqbSV.png?o=1)
 
Afisare masini stoc + masini vandute (optiunea 7):  
![](https://gcdnb.pbrd.co/images/tfmMutD0QEZA.png?o=1)

Afisare masini stoc (optiunea 8):  
![](https://gcdnb.pbrd.co/images/SKFhsLHuRcDZ.png?o=1)

Vinderea unei masini (optiunea 10): stergem a 2-a masina:  
![](https://gcdnb.pbrd.co/images/ocKALmIfun7o.png?o=1)

Afisare masini vandute (optiunea 9):  
![](https://gcdnb.pbrd.co/images/loFkEcKyPrOs.png?o=1)

Afisare masini stoc + vandute (optiunea 7):  
![](https://gcdnb.pbrd.co/images/uFvYpYgfkjYN.png?o=1)