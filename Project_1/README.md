##### FRITZ RALUCA-MIHAELA 
##### GRUPA 143
##### ANUL 2020-2021
## <center> PROIECT 1 - PROGRAMARE ORIENTATA PE OBIECTE </center>

Problema numarul 6.

### Coadă de numere reale(alocată dinamic) - implementată ca un tablou unidimensional 

Are drept parametrii: 

1. Dimensiunea stivei (int) 
2. Elementele prezente în coadă (se pot adăuga/elimina doar folosind push_back și pop_front)  
3. Front (primul element introdus în coadă) 
4. Back (ultimul element introdus în coadă) 

Metode ale clasei:

1. Implementarea operației `push_back` (pentru a adăuga elemente în coadă) 

2. Implementarea operației `pop_front` (pentru a elimina elemente din coadă) 

3. Să se testeze dacă primele 2 elemente prezente în capul cozii (front) 
sunt consecutive, în modul, în mod repetat până când este întâlnită 
primul pereche de numere succesive non-consecutive și să se afișeze această pereche 

4. Să se testeze dacă ultimul element deja adăugat este negativ și are pătratul mai mic sau egal cu 100 

BONUS : 
1. permiterea `push_back` a mai multor elemente decat este deja spatiu alocat -> cresterea
dimensiunii cozii de 4  ori fata de cat e in mod curent

2. in urma mai multor pop_front -uri daca este mai putin de un sfert din 
spatiul alocat initial pentru coada -> redimensionarea cozii astfel incat sa ocupe
in memorie un spatiu egal fix cu cate elemente sunt prezente in coada

### REZOLVARE:

Clasa are:
* 4 membri privati: 
	- un int -> dimensiunea stivei
	- 3 pointeri catre ints :
		- `adresaStiva` = elementele cozii 
		- `adresaFront` = primul elemnt din coada
		- `adresaBack` = ultimul element din coada
* 9 metode publice:
	- un constructor cu un parametru
	- un destructor
	- `push_back(1)`, cu un parametru, care nu returneaza nimic
	- `pop_front(2)`, cu un parametru, care returneaza un bool
	- `consecutive(3)` care nu returneaza nimic 
	- `ultimulElement(4)` care returneaza un bool
	- `getDimensiune` care returneaza dimensiunea stivei
	- 2 metode pentru supradefinirea citirei si afisarii

1. constructorul: 
- primeste un parametru pentru setarea dimensiunii stivei 
- initializeaza vectorul `adresaStiva`
- initializeaza `adresaFront` si `adresaBack` cu `NULL`

2.  destructor:
- se elibereaza memoria -> `delete[]`
- se dezinitializeaza: `adresaFront` si `adresaBack`

3. `push_back`:
- se testeaza daca mai este spatiu in stiva sau daca dimensiunea stivei este 0
	- daca testul este true:
		- se creeaza o adresa auxiliara si alocam spatiu nou stivei
		- se muta `adresaFront` la inceputul adresei auxiliare
		- se muta `adresaBack` la adresa ultimului element din coada (aux + dimensiune)
		- se copiaza stiva veche la adresa noua si se elibereaza memoria
		- se pointeaza catre noua adresa
		- se modifica dimensiunea cu cea noua
- se teseaza daca sunt sau nu elemente in stiva
	- daca nu sunt elemente pe stiva:
		- se initializeaza `adresaFront` si `adresaBack` cu locul din stiva
		- se pune la `adresaBack` valoarea noului element 
	- daca sunt elemente pe stiva:
		- se incrementeaza `adresaBack`
		- se pune la `adresaBack` valoarea noului element
		
- in concluzie, metoda nu returneaza nimic, dar modifica adresele front, back si 
per total coada
		
4. `pop_front`:
- primeste un parametru: referinta `poppedValue`
- se testeaza daca coada este goala:
	- daca coada este goala:
		- se returneaza `true`
	- daca coada nu este goala:
		- `poppedValue` ia valoarea adresei front
		- se testeaza daca `adresaFront` este egala cu `adresaBack` ( este doar un element in coada)
			- daca este doar un element in coada 
				- se reinitializeaza `adresaBack` si `adresaFront` cu `NULL`
			- daca nu este doar un element in coada
				- se incrementeaza `adresaFront`
		- se testeaza daca `adresaFront` este `NULL` si daca este mai putin de un sfert spatiu liber in stiva:
            - se aloca spatiu nou cu ajutorul unei adrese auxiliare
    		- se copiaza stiva veche la adresa noua
    		- se muta `adresaBack `si `adresaFront`
    		- se elibereaza memoria
    		- se pointeaza `adresaStiva` catre noua zona de memorie
    		- se modifica dimensiunea catre noua dimensiune
- returnea `true` daca coada este goala si `false` daca nu este goala

5. `getDimensiune`:
- returneaza valoarea dimensiune

6. consecutive:
- se initializeaza 2 bool-uri (gasit si initializat ) cu false 
- se creeaza 2 int-uri (precedent si curent )
- se foloseste un loop while care se va termina in momentul in care o pereche succesiva 
nu este consecutiva (pana cand bool gasit = true )
- se testeaza daca int precedent este initializat sau nu
	- daca nu este initializat, in momentul in care se face testul, este initializeaza
	in momentul testului (de asemenea, daca coada este goala, se afiseaza "Nu mai sunt valori")
	- daca este initializat:
		- se testeaza daca exista un element curent
			- daca exista un element curent:
				- se testeaza daca `|element precedent| + 1 != |curent|` ( |x| = modul de x )
					- daca este true:
						- se afiseaza perechea gasita
						- se schimba valoarea lui gasit in true
					- daca este false:
						- se pune valoarea lui curent in precedent
			- daca nu exista un element curent se afiseaza "Nu mai sunt valori"

7. `ultimulElement`:
- se initializeaza un int valoare cu valoarea de la pointerul adresaBack
- se testeaza daca numarul valoare este mai mic ca 0 si daca patratul este mai mic decat 100
	- se returneaza true daca numarul este mai mic ca 0 si patratul este mai mic decat 100
	- else se returneaza false

8. si 9. -> o incercare de supradefinire a operatorilor de citire si write pentru obiectul Coada

#### Extra:

Metoda `printMeniu`:
- un meniu cu optiuni pentru metodele clasei + terminarea programului

Main: 
- se citeste dimensiunea stivei
- se initializeaza obiectul `Coada` in `oCoada`
- se initializeaza bool `okay` cu `true`
- se creeaza un int `optiune`
- se foloseste un loop care se va termina in momentul in care okay devine `false`
- se foloseste `printMeniu` si se afiseaza meniul cu optiuni
- se citeste de la tastatura o valoare pentru optiune
- se foloseste un switch cu 6 cazuri + default pentru fiecare dintre optiunile meniului
- in momentul in care orice valoare diferita de 1-6 este introdusa in program, okay devine false
si programul se termina.






