#include<iostream>
#include<string>

using namespace std;


class ville{
    private:
    int code;
    string nom;
    int nbrjours;

    public:
    ville(int c=0,string n="kenitra",int nj=0);
    int getnbr_jours();
    int getcode();
    void saisieVille();
    void afficheVille();
    friend int comparerVille(ville& v,ville& x);
};

class circuit{
    private:
    string nomC;
    int nbrville;
    ville *v;
    static int cpt;

    public:
    circuit(){};
    circuit(string nc,int nv,ville *vv);
    void saisieCircuit();
    void afficheCircuit();
    int villeExiste(int code);
    void addVille(ville& ville);
    int dureeCircuit();
    void retireVille(ville &x);
    
    friend circuit CIRCUITcour(circuit *c,int taille);
};


