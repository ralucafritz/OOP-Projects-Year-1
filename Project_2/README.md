##### FRITZ RALUCA-MIHAELA 
##### GRUPA 143
##### ANUL 2020-2021
## <center> PROIECT 2 - PROGRAMARE ORIENTATA PE OBIECTE </center>

- Se dau următoarele clase:
```c++
Abonament (char* nume_abonament, float pret, int perioada)
Abonament_Premium (int reducere) : Abonament
Persoana (int id, char* nume, char* cnp)
Abonat (char* nr_telefon, Abonament x) : Persoana
```
- Să se construiască clasa `Clienți` care reține o listă de abonați. 
  
- Să se afle numărul de abonați premium. 
  
- Să se realizeze o metodă care află care este suma de bani încasată de la toți abonații considerând faptul că perioada reprezintă numărul de luni care au trecut de când abonamentul este activ și faptul că prețul este plătit în fiecare lună.

### REZOLVARE:

- Am creat toate clasele cerute + parametrii respectivi si am adaugat diverse metode pe care le folosim sauam considerat ca ar putea fi folosite ulterior.
  
- Am creat o clasa `Util` cu functii statice utile care sunt folosite in cel putin o alta clasa: `validare_int`, `validare_float`, `print_menu`.
  
- Clasa `Clienti` este o lista de forma unei cozi (`FIFO`). Contine metode de adaugare si eliminare de clienti + metodele cerute in cerinta (nr abonamente premium ++ suma total de plata)
  
- Am creat o clasa `Element_client` care reprezinta un client din lista clientilor si care are un membru carepointeaza catre urmatorul client din lista.
  
- Toata clasele (excluzand clasa `Util`) contin constructor de initializare(gol pentru ca nu este folosit),constructor parametrizat, constructor de copiere, destructor, operator `=`, supraincarcarea operatorilor `>>` si `<<`.
  
- Am folosit `strcpy` (pentru a transforma din `string` in `char*`), `strlen`, `std::ws` (pentru a elimina whitespaces) si `std::getline`(pentru a putea citii intreaga linie din consola -> sa citeasca mai multe cuvinte) si am introdus in comentarii link-urile aferente de pe StackOverflow unde am gasit informatiile care m-au ajutat.
  
- Am implementat constructorul de copiere si operatorul `=` in clasa `Persoana`, desi logic vorbind acest lucru nu ar trebui sa existe in realitate pentru ca CNP-ul este unic per persoana si ID-ul ar trebui sa nu se copieze. De asemenea, ID-ul unei persoane se incrementeaza cu fiecare creare de persoana -> chiar daca sunt doar 2 clienti in `lista_clienti`, clientii nu vor avea id-urile `1` si `2` pentru ca in procesele din spate se creaza persoane, iar pentru ca `id_curent` este o variabila statica, valoarea acesteia este incrementata de fiecare data cand este creata o persoana noua.
  
- Memoria este eliberata unde este nevoie (destructori si alte locuri in care este alocata memoria dinamic).
  
- Am folosit concepte de upcasting in mai multe metode din clasele `Abonament_Premium` si `Abonat`
    ```cpp
        Abonament *upcast = this;
        *upcast = a;
    ```
    ```cpp
        Persoana *upcast = this;
        *upcast = p;
    ```
- Am folosit concepte de functii virtuale:
  - in Abonament:
    ```cpp
        virtual float de_plata();
        virtual bool este_premium();
    ```
    ```cpp
        float Abonament::de_plata()
        {
            return perioada * pret;
        }

        bool Abonament::este_premium()
        {
            return false;
        }
    ```
  - in Abonament_premium:
    ```cpp
        float de_plata() override;
        bool este_premium() override;
    ```
    ```cpp
        float Abonament_premium::de_plata()
        {
            return Abonament::de_plata() * (1 - (float) reducere / (float) 100);
        }

        bool Abonament_premium::este_premium()

            return true;
        }
    ```
- Am folosit functii:
  - `const`, functiile get:
    ```cpp
        char *get_nume_abonament() const;
        float get_pret() const;
        int get_perioada() const;
    ```
  - statice:
    ```cpp
        static void validare_int(std::istream &citire, int &dest);
        static void validare_float(std::istream &citire, float &dest);
        static void print_menu();
    ```
- Am adaugat meniu interactiv prin care se pot:
  - adauga un client
  - sterge un client (primul adaugat)
  - afisarea numarului total de abonamente premium (metoda ceruta)
  - afisarea sumei totale de plata (metoda ceruta)
  - adaugarea unei liste de `N` clienti
  - afisarea unei liste de clienti

    ```
    1. Adaugati un client
    2. Scoateti primul client adaugat
    3. Afisati numarul de abonamente premium din lista clientilor
    4. Afisati suma total de plata a clientilor
    5. Adaugati o lista a clientilor
    6. Afisati lista clientilor
    7. Terminarea programului
    Alegeti o optiune:
    ```


##### EXEMPLE DIN CONSOLA:

Adaugare client + afisare lista curenta:  
[exemplu din consola](https://gcdnb.pbrd.co/images/Lt1J587MkRn6.png?o=1)

Adaugare element + afisare lista curenta:  
[exemplu din consola(1)](https://gcdnb.pbrd.co/images/ZaRX1Mi88Qzy.png?o=1), [exemplu din consola(2)](https://gcdnb.pbrd.co/images/rbu7ABCkvHbb.png?o=1)

Metoda pentru numarul de abonamente premium:  
[exemplu din consola](https://gcdnb.pbrd.co/images/0kKjfGpbMNvX.png?o=1)

Metoda pentru suma totala de plata:  
[exemplu din consola](https://gcdnb.pbrd.co/images/ndj2FTonNPXk.png?o=1)

Adaugarea a 2 clienti in lista:  
[exemplu din consola](https://gcdnb.pbrd.co/images/sLZ5z5RuwArL.png?o=1)

Lista clienti actuala:  
[exemplu din consola](https://gcdnb.pbrd.co/images/tAhuNmEdfLOf.png?o=1)