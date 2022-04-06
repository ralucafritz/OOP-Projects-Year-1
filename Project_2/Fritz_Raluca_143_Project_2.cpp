#include <iostream>
#include <cstring>

/*      Se dau următoarele clase:
 *      -Abonament (char* nume_abonament, float pret, int perioadă)
 *      -Abonament_Premium (int reducere) : Abonament
 *      -Persoană (int id, char* nume, char* cnp)
 *      -Abonat (char* nr_telefon, Abonament x) : Persoana
 *
 *      ------Să se construiască clasa Clienți care reține o listă de abonați.
 *      ------Să se afle numărul de abonați premium.
 *      ------Să se realizeze o metodă care află care este suma de bani încasată de la toți abonații
 *      considerând faptul că perioada reprezintă numărul de luni care au trecut de când abonamentul
 *      este activ și faptul că prețul este plătit în fiecare lună.
*/

class Util

        // CLASA CU FUNCTII UTILE : validare int si float si printare meniu

{
public:
    static void validare_int(std::istream &citire, int &dest);
    static void validare_float(std::istream &citire, float &dest);
    static void print_menu();
};

void Util::print_menu()
{
    std::cout<< "1. Adaugati un client" <<  std::endl
             << "2. Scoateti primul client adaugat" <<  std::endl
             << "3. Afisati numarul de abonamente premium din lista clientilor" <<  std::endl
             << "4. Afisati suma total de plata a clientilor" <<  std::endl
             << "5. Adaugati o lista a clientilor" <<  std::endl
             << "6. Afisati lista clientilor" <<  std::endl
             << "7. Terminarea programului" <<  std::endl
             << "Alegeti o optiune: " << std::endl;
}

// https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer

void Util::validare_int(std::istream &citire, int &dest)
{
    citire >> dest;
    while (citire.fail())
    {
        std::cout << "Eroare. Ati introdus o valoare care nu este INT. Incercati din nou: " << std::endl;
        citire.clear();
        citire.ignore(256, '\n');
        citire >> dest;
    }
}

void Util::validare_float(std::istream &citire, float &dest)
{
    citire >> dest;
    while (citire.fail())
    {
        std::cout << "Eroare. Ati introdus o valoare care nu este FLOAT. Incercati din nou: " << std::endl;
        citire.clear();
        citire.ignore(256, '\n');
        citire >> dest;
    }
}

//                                              CLASA ABONAMENT

class Abonament
{
public:
    Abonament();
    Abonament(char *nume_abonament, float pret, int perioada);
    Abonament(const Abonament &abonament1);
    ~Abonament();

    Abonament &operator=(const Abonament &abonament1);
    friend std::istream &operator>>(std::istream &citire, Abonament &abonament1);
    friend std::ostream &operator<<(std::ostream &scriere, Abonament &abonament1);

    void set_nume_abonament(char *nume);
    void set_pret(float pret);
    void set_perioada(int perioada);

    char *get_nume_abonament() const;
    float get_pret() const;
    int get_perioada() const;

    virtual float de_plata();
    virtual bool este_premium();

private:
    char *nume_abonament;
    float pret;
    int perioada;

    virtual std::ostream &afisare(std::ostream &scriere, Abonament &abonament1);
};

Abonament::Abonament()
{
    // nu a fost implementat pentru ca nu il folosim
}

Abonament::Abonament(char *nume_abonament, float pret, int perioada)
{
    // https://stackoverflow.com/questions/21022644/how-to-get-the-real-and-total-length-of-char-char-array
    this->nume_abonament = new char[strlen(nume_abonament) + 1]; // +1 pentru null terminator /  null character
    strcpy(this->nume_abonament, nume_abonament);

    this->pret = pret;
    this->perioada = perioada;
}

Abonament::~Abonament()
{
    if (nume_abonament)
    {
        delete[] nume_abonament;
    }
}

Abonament::Abonament(const Abonament &abonament1)
{
    nume_abonament = new char[strlen(abonament1.nume_abonament) + 1];
    strcpy(nume_abonament, abonament1.nume_abonament);

    pret = abonament1.pret;
    perioada = abonament1.perioada;
}


// GETTERS

char *Abonament::get_nume_abonament() const
{
    return nume_abonament;
}

float Abonament::get_pret() const
{
    return pret;
}

int Abonament::get_perioada() const
{
    return perioada;
}

void Abonament::set_nume_abonament(char *nume_abonament)
{
    if (this->nume_abonament)
    {
        delete[] this->nume_abonament;
    }

    this->nume_abonament = new char[strlen(nume_abonament) + 1];

    strcpy(this->nume_abonament, nume_abonament);
}

void Abonament::set_pret(float pret)
{
    this->pret = pret;
}

void Abonament::set_perioada(int perioada)
{
    this->pret = perioada;
}

Abonament &Abonament::operator=(const Abonament &abonament1)
{
    nume_abonament = new char[strlen(abonament1.nume_abonament) + 1];
    strcpy(nume_abonament, abonament1.nume_abonament);

    pret = abonament1.pret;
    perioada = abonament1.perioada;

    return *this;
}

std::istream &operator>>(std::istream &citire, Abonament &abonament1)
{
    std::cout << "Introduceti numele abonamentului " << std::endl;
    std::string auxiliar;
    //https://stackoverflow.com/questions/32850601/using-getline-in-an-overloaded-input-operator
    //https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
    //https://stackoverflow.com/questions/7352099/stdstring-to-char

    citire >> std::ws;
    std::getline(citire, auxiliar);

    abonament1.nume_abonament = new char[auxiliar.length() + 1];
    strcpy(abonament1.nume_abonament, auxiliar.c_str());

    std::cout << "Introduceti perioada abonamentului " << std::endl;
    Util::validare_int(citire, abonament1.perioada);

    std::cout << "Introduceti pretul abonamentului " << std::endl;
    Util::validare_float(citire, abonament1.pret);

    return citire;
}

std::ostream &operator<<(std::ostream &scriere, Abonament &abonament1)
{
    return abonament1.afisare(scriere, abonament1);
}

std::ostream &Abonament::afisare(std::ostream &scriere, Abonament &abonament1)
{
    scriere << "Nume Abonament " << abonament1.nume_abonament << std::endl;
    scriere << "Perioada " << abonament1.perioada << std::endl;
    scriere << "Pret " << abonament1.pret << std::endl;

    return scriere;
}

float Abonament::de_plata()
{
    return perioada * pret;
}

bool Abonament::este_premium()
{
    return false;
}



//                                          CLASA ABONAMENT PREMIUM


class Abonament_premium : public Abonament
{
public:
    Abonament_premium();
    Abonament_premium(int reducere, Abonament &a);
    Abonament_premium(const Abonament_premium &abonament_premium1);
    ~Abonament_premium();

    Abonament_premium &operator=(const Abonament_premium &abonament_premium1);
    friend std::istream &operator>>(std::istream &citire, Abonament_premium &abonament_premium1);
    friend std::ostream &operator<<(std::ostream &scriere, Abonament_premium &abonament_premium1);

    void set_reducere(int reducere);
    int get_reducere() const;

    float de_plata() override;
    bool este_premium() override;

private:
    int reducere;

    virtual std::ostream &afisare(std::ostream &scriere, Abonament &abonament1) override;
};

Abonament_premium::Abonament_premium()
{
    // nu a fost implementat pentru ca nu il folosim
}

Abonament_premium::Abonament_premium(int reducere, Abonament &a)
{
    Abonament *upcast = this;
    *upcast = a;

    this->reducere = reducere;
}

Abonament_premium::~Abonament_premium()
{
    std::cout << "Abonament_premium" << std::endl;
}

Abonament_premium::Abonament_premium(const Abonament_premium &abonament_premium1) : Abonament(abonament_premium1)
{
    this->reducere = abonament_premium1.reducere;
}
// GETTER SI SETTER

int Abonament_premium::get_reducere() const
{
    return reducere;
}

void Abonament_premium::set_reducere(int reducere)
{
    this->reducere = reducere;
}

// OPERATOR =

Abonament_premium &Abonament_premium::operator = (const Abonament_premium &abonament_premium1)
{
    Abonament *upcast = this;
    *upcast = abonament_premium1;
    reducere = abonament_premium1.reducere;

    return *this;
}

// SUPRAINCARCARE >>

std::istream &operator >> (std::istream &citire, Abonament_premium &abonament_premium1)
{
    Abonament a;
    citire >> a;
    Abonament *upcast = &abonament_premium1;
    *upcast = a;

    std::cout << "Introduceti reducerea abonamentului " << std::endl;
    Util::validare_int(citire, abonament_premium1.reducere);

    return citire;
}

// SUPRAINCARCARE <<

std::ostream &operator << (std::ostream &scriere, Abonament_premium &abonament_premium1)
{
    Abonament *upcast = &abonament_premium1;

    return abonament_premium1.afisare(scriere, *upcast);
}

std::ostream &Abonament_premium::afisare(std::ostream &scriere, Abonament &abonament1)
{
    scriere << "Nume Abonament " << abonament1.get_nume_abonament() << std::endl;
    scriere << "Perioada " << abonament1.get_perioada() << std::endl;
    scriere << "Pret " << abonament1.get_pret() << std::endl;
    scriere << "Reducere " << reducere << std::endl;

    return scriere;
}

float Abonament_premium::de_plata()
{
    return Abonament::de_plata() * (1 - (float) reducere / (float) 100);
}

bool Abonament_premium::este_premium()
{
    return true;
}

//                                          CLASA PERSOANA

class Persoana
{
public:
    Persoana();
    Persoana(char *nume, char *cnp);
    Persoana(const Persoana &persoana1);
    ~Persoana();

    Persoana &operator=(const Persoana &persoana1);
    friend std::istream &operator>>(std::istream &citire, Persoana &persoana1);
    friend std::ostream &operator<<(std::ostream &scriere, const Persoana &persoana1);

    void set_nume(char *nume);
    char *get_nume() const;
    int get_id() const;
    char *get_cnp() const;

private:
    static int id_curent;
    int id;
    char *nume;
    char *cnp;
};

int Persoana::id_curent = 0;

Persoana::Persoana()
{
    // nu a fost implementat pentru ca nu il folosim
}

Persoana::Persoana(char *nume, char *cnp)
{
    id_curent++;
    this->id = id_curent;
    this->nume = nume;
    this->cnp = cnp;
}


Persoana::Persoana(const Persoana &persoana1)
{
// din punct de vedere logic aceasta functie nu ar trebui sa existe.
// exista set pentru nume care se poate schimba, dar cnp-ul nu poate exista la 2 persoane
// si id-ul este un identificator si nu ar trebui sa se copieze.

    nume = new char[strlen(persoana1.nume) + 1];
    strcpy(nume, persoana1.nume);

    cnp = new char[strlen(persoana1.cnp) + 1];
    strcpy(cnp, persoana1.cnp);

    id_curent++;
    id = id_curent;
}

Persoana::~Persoana()
{
    if (nume)
    {
        delete[] nume;
    }
    if (cnp)
    {
        delete[] cnp;
    }

}

// OPERATOR =

Persoana &Persoana::operator = (const Persoana &persoana1)
{
// din punct de vedere logic aceasta functie nu ar trebui sa existe.
// exista set pentru nume care se poate schimba, dar cnp-ul nu poate exista la 2 persoane
// si id-ul este un identificator si nu ar trebui sa se copieze.

    // https://stackoverflow.com/questions/21022644/how-to-get-the-real-and-total-length-of-char-char-array
    nume = new char[strlen(persoana1.nume) + 1];
    strcpy(nume, persoana1.nume);

    cnp = new char[strlen(persoana1.cnp) + 1];
    strcpy(cnp, persoana1.cnp);

    id_curent++;
    id = id_curent;

    return *this;
}

// SUPRAINCARCARE >>

std::istream &operator >> (std::istream &citire, Persoana &persoana1)
{
    std::cout << "Introduceti numele persoanei " << std::endl;

    std::string auxiliar;
    citire >> std::ws;
    std::getline(citire, auxiliar);

    persoana1.nume = new char[auxiliar.length() + 1];

    strcpy(persoana1.nume, auxiliar.c_str());

    std::cout << "Introduceti CNP-ul persoanei " << std::endl;
    citire >> std::ws;
    std::getline(citire, auxiliar);

    persoana1.cnp = new char[auxiliar.length() + 1];
    strcpy(persoana1.cnp, auxiliar.c_str());

    Persoana::id_curent++;
    persoana1.id = Persoana::id_curent;

    return citire;
}

// SUPRAINCARCARE <<

std::ostream &operator << (std::ostream &scriere, const Persoana &persoana1)
{
    scriere << "Numele persoanei: " << persoana1.nume << std::endl;
    scriere << "ID-ul persoanei: " << persoana1.id << std::endl;
    scriere << "CNP-ul persoanei:  " << persoana1.cnp << std::endl;

    return scriere;
}
// GETTERS SI SETTER
int Persoana::get_id() const
{
    return id;
}

char *Persoana::get_nume() const
{
    return nume;
}

char *Persoana::get_cnp() const
{
    return cnp;
}

void Persoana::set_nume(char *nume)
{
    if (this->nume)
    {
        delete[] this->nume;
    }

    this->nume = new char[strlen(nume) + 1];

    strcpy(this->nume, nume);
}


//                                                  CLASA ABONAT

class Abonat : public Persoana
{
public:
    Abonat();
    Abonat(const Abonat &persoana1);
    Abonat(const Persoana &p, char *nr_telefon);
    ~Abonat();

    Abonat &operator=(const Abonat &abonat1);
    friend std::istream &operator>>(std::istream &citire, Abonat &abonat1);
    friend std::ostream &operator<<(std::ostream &scriere, Abonat &abonat1);

    void set_nr_telefon(char *nr_telefon);
    void set_abonament(Abonament &abonament);
    void set_abonament(Abonament_premium &abonament_premium);

    Abonament *get_abonament() const;
    char *get_nr_telefon() const;

private:
    char *nr_telefon;
    Abonament *x;
};

Abonat::Abonat()
{
// nu il implementam pentru ca nu il folosim
}

Abonat::Abonat(const Abonat &abonat1) : Persoana(abonat1)
{
    nr_telefon = new char[strlen(abonat1.nr_telefon) + 1];
    strcpy(nr_telefon, abonat1.nr_telefon);

    x = abonat1.x;
}

Abonat::Abonat(const Persoana &p, char *nr_telefon)
{
    Persoana *upcast = this;
    *upcast = p;

    this->nr_telefon = new char[strlen(nr_telefon) + 1];
    strcpy(this->nr_telefon, nr_telefon);
}

Abonat::~Abonat()
{
    if (nr_telefon)
    {
        delete[] nr_telefon;
    }

    if (x)
    {
        delete x;
    }
}

// OPERATOR =

Abonat &Abonat::operator = (const Abonat &abonat1)
{
    Persoana *upcast = this;
    *upcast = abonat1;

    if (nr_telefon)
    {
        delete[] nr_telefon;
    }

    nr_telefon = new char[strlen(abonat1.nr_telefon) + 1];
    strcpy(nr_telefon, abonat1.nr_telefon);

    x = abonat1.x;

    return *this;
}

// SUPRAINCARCARE >>

std::istream &operator>>(std::istream &citire, Abonat &abonat1)
{
    Persoana p;
    citire >> p;
    Persoana *upcast = &abonat1;
    *upcast = p;

    std::cout << "Introduceti numarul de telefon: " << std::endl;

    std::string auxiliar;
    citire >> std::ws;
    std::getline(citire, auxiliar);

    abonat1.nr_telefon = new char[auxiliar.length() + 1];
    strcpy(abonat1.nr_telefon, auxiliar.c_str());

    int optiune = 0;

    while (optiune != 1 && optiune != 2)
    {
        std::cout << "Abonament normal (1) sau premium (2)? " << std::endl;
        Util::validare_int(citire, optiune);

        if (optiune == 1)
        {
            Abonament *a = new Abonament();
            citire >> *a;
            abonat1.x = a;
        } else
            if(optiune == 2)
        {
            Abonament_premium *a = new Abonament_premium();
            std::cin >> *a;
            abonat1.x = a;
        }

        return citire;
    }
}

// SUPRAINCARCARE <<

std::ostream &operator<<(std::ostream &scriere, Abonat &abonat1)
{
    Persoana *upcast = &abonat1;
    scriere << *upcast;
    scriere << "Numarul de telefon:  " << abonat1.nr_telefon << std::endl;
    scriere << *abonat1.x;

    return scriere;
}
// SETTERS

void Abonat::set_nr_telefon(char *nr_telefon)
{
    if (this->nr_telefon)
    {
        delete[] this->nr_telefon;
    }

    this->nr_telefon = new char[strlen(nr_telefon) + 1];

    strcpy(this->nr_telefon, nr_telefon);
}

void Abonat::set_abonament(Abonament &abonament1)
{
    if (x)
    {
        delete x;
    }

    x = new Abonament(abonament1);
}

void Abonat::set_abonament(Abonament_premium &abonament_premium1)
{
    if (x)
    {
        delete x;
    }

    x = new Abonament_premium(abonament_premium1);
}

// GETTERS

Abonament *Abonat::get_abonament() const
{
    return x;
}

char *Abonat::get_nr_telefon() const
{
    return nr_telefon;
}

//                                                      CLASA ELEMENT CLIENT

 class Element_client
 {
 public:
     Element_client();
     Element_client(Abonat &x);
     ~Element_client();

     Element_client &operator=(const Element_client &element_client1);
     friend std::istream &operator>>(std::istream &citire, Element_client &element_client1);
     friend std::ostream &operator<<(std::ostream &scriere, Element_client &element_client1);

     void set_urmatorul_client(Element_client &element_client1);

     Abonat *get_abonat() const;
     Element_client *get_urmatorul_client() const;

 private:
     Element_client(Element_client &element_client1);

     Abonat *x;
     Element_client *urmatorul_client;
 };


 Element_client::Element_client()
 {
     // nu a fost implementat pentru ca nu il folosim
 }

 Element_client::Element_client(Abonat & x)
 {
     if (!this->x)
     {
         this->x = new Abonat();
     }
     this->x = &x;
     this->urmatorul_client = NULL;
 }

 Element_client::Element_client(Element_client & element_client1)
 {
     // nu a fost implementat pentru ca nu il folosim
 }

 Element_client::~Element_client()
 {
     if (x)
     {
         delete x;
     }
 }

// GETTERS SI SETTER

 Abonat *Element_client::get_abonat() const
 {
     return x;
 }

 Element_client *Element_client::get_urmatorul_client() const
 {
     return urmatorul_client;
 }

 void Element_client::set_urmatorul_client(Element_client &element_client1)
 {
     urmatorul_client = &element_client1;
 }

 // OPERATOR =

 Element_client &Element_client::operator = (const Element_client &element_client1)
 {
     if (x)
     {
         delete x;
     }
     x = new Abonat();
     x = element_client1.x;

     urmatorul_client = element_client1.urmatorul_client;

     return *this;
 }

// SUPRAINCARCARE >>

std::istream &operator >> (std::istream &citire, Element_client &element_client1)
 {
     element_client1.x = new Abonat();
     citire >> *element_client1.x;
     element_client1.urmatorul_client = NULL;

     return citire;
 }

// SUPRAINCARCARE <<

 std::ostream &operator<<(std::ostream &scriere, Element_client &element_client1)
 {
     scriere << "Clientul este:" << std::endl;
     scriere << *(element_client1.x);

     return scriere;
 }


//                                                     CLASA CLIENTI

 class Clienti
 {
 public:
     Clienti();
     Clienti(Element_client &primul);
     ~Clienti();

     bool pop_front(Element_client& element_curent);
     void push_back(Abonat &abonat1);

     Clienti &operator=(const Clienti &clienti1);
     friend std::istream &operator>>(std::istream &citire, Clienti &clienti1);
     friend std::ostream &operator<<(std::ostream &scriere, Clienti &clienti1);

     int nr_clienti_premium();
     float de_plata();

 private:
     Clienti(Clienti &clienti1);

     Element_client *primul = NULL;
 };

 Clienti::Clienti()
 {
     // nu a fost implementat pentru ca nu il folosim
 }

 Clienti::Clienti(Element_client & primul)
 {
     this->primul = &primul;
 }

 Clienti::Clienti(Clienti & clienti1)
 {
     // nu o implementam pentru ca nu o folosim
 }

 Clienti::~Clienti()
 {
     while (primul)
     {
         Element_client *aux = primul->get_urmatorul_client();
         delete primul;
         primul = aux;
     }
 }

// pop_front = pentru a putea elimina Clienti din lista

bool Clienti::pop_front(Element_client& element_curent)
{
    if (!primul)
    {
        return false;
    }
    else
    {
        Element_client* aux = primul;
        element_curent = *primul;
        primul = primul->get_urmatorul_client();
        delete aux;

        std::cout << "Clientul a fost sters cu success. " << std::endl;
        return true;
    }
}

// push_back = pentru a putea adauga Clienti in lista

 void Clienti::push_back(Abonat &abonat1)
 {
     if (!primul)
     {
         primul = new Element_client(abonat1);
     } else
     {
         Element_client *element_curent = primul;


         while (element_curent->get_urmatorul_client())
         {
             element_curent = element_curent->get_urmatorul_client();

         }
         element_curent->set_urmatorul_client(*(new Element_client(abonat1)));
     }

     std::cout << "Clientul a fost adaugat cu success." << std::endl;
 }

 // OPERATOR =

 Clienti &Clienti::operator = (const Clienti &clienti1)
 {
     while (primul)
     {
         Element_client *aux = primul->get_urmatorul_client();
         delete primul;
         primul = aux;
     }

     Element_client *aux = clienti1.primul;
     Element_client *element_nou;
     Element_client *element_precedent;

     while (aux)
     {
         element_nou = new Element_client();
         *element_nou = *aux;
         if (!primul)
         {
             primul = element_nou;
         } else
         {
             element_precedent->set_urmatorul_client(*element_nou);
         }
         element_precedent = element_nou;
         aux = aux->get_urmatorul_client();
     }

     return *this;
 }

// SUPRAINCARCARE <<

std::istream &operator >> (std::istream &citire, Clienti &clienti1)
 {
     std::cout << "Introduceti lista clientilor: " << std::endl;
     int optiune = 1;

     while (optiune == 1)
     {
         Abonat *abonat_nou = new Abonat();
         citire >> *abonat_nou;
         clienti1.push_back(*abonat_nou);

         std::cout << "Mai adaugati un client?" << std::endl <<
                   "1 = DA | 2 = NU" << std::endl;
         Util::validare_int(citire, optiune);
     }

     return citire;
 }

// SUPRAINCARCARE <<

 std::ostream &operator<<(std::ostream &scriere, Clienti &clienti1)
 {
     scriere << "Lista clientilor este: " << std::endl;
     Element_client *element_curent = clienti1.primul;

     while (element_curent)
     {
         scriere << *element_curent;
         element_curent = element_curent->get_urmatorul_client();
     }

     return scriere;
 }

 // metoda care afiseaza numarul de Clienti premium din lista

 int Clienti::nr_clienti_premium()
 {
     Element_client *element_curent = primul;
     int nr = 0;

     while (element_curent)
     {
         if (element_curent->get_abonat()->get_abonament()->este_premium())
         {
             nr++;
         }
         element_curent = element_curent->get_urmatorul_client();
     }

     return nr;
 }

 // metoda care afiseaza suma totala de plata a tuturor clientilor

 float Clienti::de_plata()
 {
     Element_client *element_curent = primul;
     float suma = 0;

     while (element_curent)
     {
         suma += element_curent->get_abonat()->get_abonament()->de_plata();

         element_curent = element_curent->get_urmatorul_client();
     }

     return suma;
 }

/*
PREVIEW MENIU

1. Adaugati un client
2. Scoateti primul client adaugat
3. Afisati numarul de abonamente premium din lista clientilor
4. Afisati suma total de plata a clientilor
5. Adaugati o lista a clientilor
6. Afisati lista clientilor
7. Terminarea programului

 */

int main()
{
    Abonat *abonat = NULL;
    Element_client client;
    Clienti lista_clienti;


    int optiune;
    bool okay = true;
    while (okay)
    {
        Util::print_menu();
        std::cin >> optiune;

        switch (optiune)
        {
            case 1: // push back
                abonat = new Abonat();
                std::cin >> *abonat;
                lista_clienti.push_back(*abonat);
                break;
            case 2: // pop front
                if(lista_clienti.pop_front(client))
                {
                    std::cout << client;
                }
                break;
            case 3: // nr_clienti_premium
                std::cout << lista_clienti.nr_clienti_premium() << " abonamente premium" << std::endl;
                break;
            case 4: // de_plata
                std::cout << lista_clienti.de_plata() << " LEI de plata in total " << std::endl;
                break;
            case 5: // citire Clienti
                std::cin >> lista_clienti;
                break;
            case 6: // scriere Clienti
                std::cout << lista_clienti;
                break;
            default:
                okay = false;
                break;
        }
    }

    return 0;
}