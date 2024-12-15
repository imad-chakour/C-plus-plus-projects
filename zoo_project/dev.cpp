#include "dev.h"

// Animal
Animal::Animal(string n, string e, int a)
    : nom(n), espece(e), age(a) {}

void Animal::afficher() {
    cout << "Nom: " << nom << endl;
    cout << "Espece: " << espece << endl;
    cout << "Age: " << age << endl;
}

Animal::~Animal() {}

// Mammifere
Mammifere::Mammifere(string n, string e, int a, string t, string r)
    : Animal(n, e, a), typePelage(t), regime(r) {}

void Mammifere::afficher() {
    Animal::afficher();
    cout << "Type de pelage: " << typePelage << endl;
    cout << "Regime Alimentaire: " << regime << endl;
    cout << "=================="<<endl;
}

// Oiseau
Oiseau::Oiseau(string n, string e, int a, string ev)
    : Animal(n, e, a), envergureAiles(ev) {}

void Oiseau::afficher() {
    Animal::afficher();
    cout << "Envergure des Ailes: " << envergureAiles << endl;
    cout << "=================="<<endl;
}

// Reptile
Reptile::Reptile(string n, string e, int a, string t, int f)
    : Animal(n, e, a), typePeau(t), frequenceMue(f) {}

void Reptile::afficher() {
    Animal::afficher();
    cout << "Type de Peau: " << typePeau << endl;
    cout << "Frequence Mue: " << frequenceMue << endl;
    cout << "=================="<<endl;
}

// Amphibien
Amphibien::Amphibien(string n, string e, int a, string t, int b)
    : Animal(n, e, a), typePeau(t), besoinEau(b) {}

void Amphibien::afficher() {
    Animal::afficher();
    cout << "Type de Peau: " << typePeau << endl;
    cout << "Besoin d'eau: " << besoinEau << endl;
    cout << "=================="<<endl;
}

// Insecte
Insecte::Insecte(string n, string e, int a, int nbr, string r)
    : Animal(n, e, a), nombrePattes(nbr), regime(r) {}

void Insecte::afficher() {
    Animal::afficher();
    cout << "Nombre de Pattes: " << nombrePattes << endl;
    cout << "Regime: " << regime << endl;
    cout << "=================="<<endl;
}

// Zoo
Zoo::Zoo(int cp, int tl)
    : zo(nullptr), capacite(cp), taille(tl) {
    zo = new Animal*[capacite];
}

bool Zoo::verifierAnimal(string nom) {
    for (int i = 0; i < taille; i++) {
        if (zo[i]->nom == nom) {
            return true;
        }
    }
    return false;
}

void Zoo::ajouter(Animal* a) {
    if (taille < capacite && !verifierAnimal(a->nom)) {
        zo[taille] = a;
        taille++;
    }
}

void Zoo::supprimer(Animal* a){
    int j=0; 
    bool trouve = false;
    for (int i = 0; i < taille; i++) {
        if (zo[i]->nom != a->nom) {
            zo[j] = zo[i];
            j++;
        }else{
            trouve = true;
        }
    }
    if(trouve){
        taille --;
        cout<<"L'animal a ete supprimee!"<<endl;
    }else{
        cout<<"impossible de supprimer!"<<endl;
    }
}

void Zoo::afficherZoo() {
    for (int i = 0; i < taille; i++) {
        zo[i]->afficher();
    }
}

Zoo::~Zoo() {
    for (int i = 0; i < taille; i++) {
        delete zo[i];
    }
    delete[] zo;
}
