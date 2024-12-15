#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string nom;
    string espece;
    int age;
public:
    Animal(string n = "", string e = "", int a = 0);
    virtual void afficher();
    virtual ~Animal();
    friend class Zoo;
};

class Mammifere : public Animal {
protected:
    string typePelage;
    string regime;
public:
    Mammifere(string n = "", string e = "", int a = 0, string t = "", string r = "");
    void afficher() override;
};

class Oiseau : public Animal {
protected:
    bool capaciteVol;
    string envergureAiles;
public:
    Oiseau(string n = "", string e = "", int a = 0, string ev = "");
    void afficher() override;
};

class Reptile : public Animal {
protected:
    string typePeau;
    int frequenceMue;
public:
    Reptile(string n = "", string e = "", int a = 0, string t = "", int f = 0);
    void afficher() override;
};

class Amphibien : public Animal {
protected:
    string typePeau;
    int besoinEau;
public:
    Amphibien(string n = "", string e = "", int a = 0, string t = "", int b = 0);
    void afficher() override;
};

class Insecte : public Animal {
protected:
    int nombrePattes;
    string regime;
public:
    Insecte(string n = "", string e = "", int a = 0, int nbr = 0, string r = "");
    void afficher() override;
};

class Zoo {
private:
    Animal** zo;
    int capacite;
    int taille;
public:
    Zoo(int cp = 0, int tl = 0);
    bool verifierAnimal(string nom);
    void ajouter(Animal* a);
    void supprimer(Animal* a);
    void afficherZoo();
    ~Zoo();
};