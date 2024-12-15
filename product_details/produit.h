#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class produit{
    private:
    string nom;
    double *prix;
    int taille;

    public:
    void saisieProduit();
    void afficheproduit();
    double moyennePrix();
    void MinMaxPrix();
    void affichePosition(double);
};