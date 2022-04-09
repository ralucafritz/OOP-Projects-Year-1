# <center> OOP-Projects-Year-1 </center>

In this repository you can find all the small projects I made for my `Object Orientated Programming (C++)` class during my first year of University.
The `README.md` files, comments and the requirements for each project are written in Romanian.

#### [Proiectul 1: Coadă de numere reale(alocată dinamic) implementată ca un tablou unidimensional](https://github.com/ralucafritz/OOP-Projects-Year-1/tree/main/Project_1)
- Are drept parametrii:
  - Dimensiunea stivei (int)
  - Elementele prezente în coadă (se pot adăuga/eliminadoarfolosind push_back și pop_front)
    - Front (primul element introdus în coadă)
    - Back (ultimul element introdus în coadă)
  
- Metode ale clasei:
    - Implementarea operației `push_back` (pentru a adăuga elemente în coadă)
    - Implementarea operației `pop_front` (pentru a elimina elemente din coadă)
  
- Să se testeze dacă primele 2 elemente prezente încapul cozii(front) sunt consecutive, în modul, în mod repetat până cândeste întâlnită primul pereche de numere succesive non-consecutive și să se afișeze această pereche

- Să se testeze dacă ultimul element deja adăugat este negativ și are pătratul mai mic sau egal cu 100


#### [Proiectul 2:  Abonamente, abonati si clienti](https://github.com/ralucafritz/OOP-Projects-Year-1/tree/main/Project_2)

- Se dau următoarele clase:
```c++
Abonament (char* nume_abonament, float pret, int perioada)
Abonament_Premium (int reducere) : Abonament
Persoana (int id, char* nume, char* cnp)
Abonat (char* nr_telefon, Abonament x) : Persoana
```
- Să se construiască clasa Clienți care reține o listă de abonați. 
  
- Să se afle numărul de abonați premium. 
  
- Să se realizeze o metodă care află care este suma de bani încasată de la toți abonații considerând faptul că perioada reprezintă numărul de luni care au trecut de când abonamentul este activ și faptul că prețul este plătit în fiecare lună.

#### [Proiectul 3: Vanzare cumparare masini](https://github.com/ralucafritz/OOP-Projects-Year-1/tree/main/Project_3)

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