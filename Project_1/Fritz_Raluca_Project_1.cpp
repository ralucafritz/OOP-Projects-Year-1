#include <iostream>
#include <cmath>
using namespace std;

// Coadă de numere reale(alocată dinamic) - implementată ca un tablou unidimensional

class Coada
{
    int dimensiune;              // dimensiune stiva
    int* adresaStiva;            // elemente Coada
    int* adresaFront;            // primul element
    int* adresaBack;             // ultimul element

public:
    Coada(int dim);
    ~Coada();
    void push_back(int valoare);
    bool pop_front(int& poppedValue);
    void consecutive();
    bool ultimulElement();
    int getDimensiune() const;
// friend istream& operator >>(istream& citire, const Coada& coada);
// friend ostream& operator <<(ostream& afisare, const Coada& coada);

    int getDimensiune();
};

// constructor
Coada::Coada(int dim)
{
    adresaStiva = new int[dim];
    dimensiune = dim;
    adresaFront = NULL;
    adresaBack = NULL;
}

// destructor
Coada::~Coada()
{
    delete[] adresaStiva;
    adresaFront = NULL;
    adresaBack = NULL;
    cout<<"Program complet, memorie eliberata"; // DA, trebuie eu sa eliberez memoria
}


// Implementarea operației push_back (pentru a adăuga elemente în coadă)
void Coada::push_back(int valoare)
{
    //test daca mai avem spatiu in stiva sau dimensiunea stiveai este 0
    if (adresaStiva + (dimensiune - 1) == adresaBack || dimensiune == 0)
    {
        //se aloca spatiu nou cu adresa auxiliara
        int auxDimensiune = dimensiune == 0 ? 25 : dimensiune;
        int* aux = new int[4 * auxDimensiune];
        //se muta front si back
        adresaFront = aux;
        adresaBack = aux + dimensiune;
        //se copiaza stiva veche la noua adresa
        for (int i = 0; i < dimensiune; i++)
        {
            *(aux + i) = *(adresaStiva + i);
        }
        //se elibereaza memoria inutila
        delete[] adresaStiva;
        //se pointeaza catre noua zona
        adresaStiva = aux;
        //se modifica dimensiunea cu cea noua
        dimensiune = auxDimensiune;
    }

    //Daca nu avem elemente in stiva
    if (adresaFront == NULL)
    {
        //Initializam frontu si back-ul cu locul din stiva
        adresaFront = adresaStiva;
        adresaBack = adresaStiva;
        *adresaBack = valoare;
    }


        //Daca avem elemente pe stiva
    else
    {
        //Crestem back-ul
        adresaBack++;
        //Punem valoarea noua la adresaBack
        *adresaBack = valoare;
    }
}

// Implementarea operației pop_front (pentru a elimina elemente din coadă)
bool Coada::pop_front(int& poppedValue)
{
    bool notEmpty = true;

    if (adresaFront == NULL)
    {
        notEmpty = false;
    }
    else
    {
        poppedValue = *adresaFront;

        if (adresaFront == adresaBack)
        {
            adresaFront = NULL;
            adresaBack = NULL;
        }
        else
        {
            adresaFront++;
        }

        if (adresaFront != NULL && adresaBack - adresaFront == dimensiune / 4)
        {
            //se aloca spatiu nou cu adresa auxiliara
            int auxDimensiune = (adresaBack - adresaFront) + 1;
            int* aux = new int[auxDimensiune];
            //se copiaza stiva veche la noua adresa
            for (int i = 0; i < auxDimensiune; i++)
            {
                *(aux + i) = *(adresaFront + i);
            }
            //se muta front si back
            adresaFront = aux;
            adresaBack = (aux + auxDimensiune) -1;
            //se elibereaza memoria inutila
            delete[] adresaStiva;
            //se pointeaza catre noua zona
            adresaStiva = aux;
            //se modifica dimensiunea cu cea noua
            dimensiune = auxDimensiune;
        }

    }
    return notEmpty;
}

int Coada::getDimensiune() const {
    return dimensiune;
}

// Să se testeze dacă primele 2 elemente prezente în capul cozii (front) sunt consecutive, în modul, în mod repetat
// până când este întâlnită prima pereche de numere succesive non-consecutive și să se afișeze această pereche

void Coada::consecutive()
{
    bool initializat = false;
    int precedent;
    int curent;
    bool gasit = false;

    while (!gasit)
    {
        if (!initializat)
        {
            if (!pop_front(precedent))
            {
                cout << "Nu mai sunt valori"<<endl;
                break;
            }
            initializat = true;
        }
        else
        {
            if (pop_front(curent))
            {
                if (abs(precedent) + 1 != abs(curent))
                    //(abs(precedent) + 1 != abs(curent) || abs(precedent) - 1 != abs(curent))
                    // varianta pentru numere succesive consecutive crescatoare si descrescatoare
                {
                    cout << "S-a gasit o pereche succesiva non-consecutiva: "
                         << precedent << " " << curent << endl;
                    gasit = true;
                }
                else
                {
                    precedent = curent;
                }
            }
            else
            {
                cout << "Nu mai sunt valori"<<endl;
                break;
            }
        }
    }
}

// Să se testeze dacă ultimul element deja adăugat este negativ și are pătratul mai mic sau egal cu 100

bool Coada::ultimulElement()
{
    int valoare = *(adresaBack);

    if (valoare < 0 && valoare * valoare <= 100)

        return true;

    return false;
}

int Coada::getDimensiune() {
    return dimensiune;
}

// incercare supradefinire "operator >>"

istream& operator >>(istream& citire, Coada coada) // istream-> exemplu laborator
{
    cout << "Introduceti primul element: ";
    int valoare;
    citire >> valoare;
    coada.push_back(valoare);
    for(int i=1;i<coada.getDimensiune();i++)
    {
        cout << "Introduceti urmatorul element: ";
        citire >> valoare;
        coada.push_back(valoare);
    }

    return citire;
}

// incercare supradefinire "operator <<"

ostream& operator <<(ostream& afisare, Coada coada) // ostream- > https://docs.microsoft.com/en-us/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=msvc-160
{
    cout<< "Elementele cozii actuale sunt: " << endl;

    for (int i = 0; i < coada.getDimensiune(); i++) {
        int poppedValue;
        if(!coada.pop_front(poppedValue))
            afisare << poppedValue << " ";
    }
    afisare << endl;
    return afisare;
}


void printMeniu()
{
    cout<< "1. Adaugati un element in coada" << endl
        << "2. Scoateti un element din coada" << endl
        << "3. Afisati perechile succesive non-consecutive" << endl
        << "4. Testati ultimul element adaugat daca este negativ si patratul este <= 100" << endl
        << "5. EXTRA 1 - Cititi intreaga coada" << endl
        << "6. EXTRA 2 - Afisati intreaga coada" << endl
        << "7. Terminarea programului" << endl
        << "Alegeti o optiune: ";
}

int main()
{
    cout<<"Introduceti dimensiunea stivei dorite: ";

    int dimensiuneStiva;
    cin >> dimensiuneStiva;

    Coada oCoada(dimensiuneStiva);

    int optiune;
    bool okay = true;
    while (okay)
    {
        printMeniu();
        cin >> optiune;

        switch (optiune)
        {
            case 1: // push
                int numarNou;
                cout << "Introduceti elementul pe care doriti sa il adaugati in coada: ";
                cin >> numarNou;
                oCoada.push_back(numarNou);
                break;

            case 2: // pop
                int poppedNumber;
                if (oCoada.pop_front(poppedNumber))
                {
                    cout << "Elementul " << poppedNumber << " a fost eliminat din coada"<<endl;
                }
                else
                {
                    cout << "Coada este goala."<<endl;
                }
                break;

            case 3: // comparare perechi
                oCoada.consecutive();
                break;

            case 4: // test ultimul element
                if (oCoada.ultimulElement())
                {
                    cout << "Ultimul element este negativ, iar patratul acestuia este mai mic sau egal cu 100" << endl;
                }
                else
                {
                    cout << "Ultimul element este pozitiv sau patratul acestuia este mai mare decat 100" << endl;
                }
                break;

            case 5: // citeste coada ca obiect - supradefinire >>
                cin>>oCoada;

            case 6: // afiseaza coada ca obiect - supradefinire <<
                cout<<oCoada;

            default:
                okay = false;
                break;
        }
    }

    return 0;

}