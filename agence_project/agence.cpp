#include "agence.h"
int circuit::cpt=0;

ville::ville(int c,string n,int nj)
:code(c),nom(n),nbrjours(nj)
{}

int ville::getnbr_jours(){
    return nbrjours;
}

int ville::getcode(){
    return code;
}

void ville::saisieVille(){
    cout<<"entrer le code_Ville: ";
    cin>>code;
    cout<<"entrer le nom_Ville: ";
    cin>>this->nom;
    cout<<"entrer le nbr_jours_Ville: ";
    cin>>this->nbrjours;
} 

void ville::afficheVille(){
    cout<<"Ville: "<<this->nom<<" Code :"<<this->code<<" Nombres de jours: "<<this->nbrjours<<endl;
}

int comparerVille(ville& v,ville& x){
    if(v.code == x.code){
        return 0;
    }else if(v.code > x.code){
        return 1;
    }
    else
    return -1;
}

circuit::circuit(string nc,int nv,ville *vv)
    :nomC(nc),nbrville(nv),v(vv)
{}

void circuit::saisieCircuit(){
    cout<<"entrer le nom du circuit: ";
    cin>>this->nomC;
    cout<<"entrer le nombre de ville: ";
    cin>>this->nbrville;
    cout<<"Saisie les ville"<<endl;
    v = new ville[nbrville];
    for(int i=0;i<this->nbrville;i++){
        v[i].saisieVille();
    }
}

void circuit::afficheCircuit(){
    cout<<"Le circuit "<<this->nomC<<" contient :"<<endl;
    for(int i=0;i<this->nbrville;i++){
        v[i].afficheVille();
    }
}

int circuit::villeExiste(int code){
        for(int i=0;i<nbrville;i++){
            if(v[i].getcode() == code ){
                return 0; 
            }
        }return 1; 
}

void circuit::addVille(ville& x) {
    const int max = 7;
    for(int i=0;i<nbrville;i++){
        if (nbrville < max && villeExiste(x.getcode())!=0){
            v[nbrville] = x;
            nbrville++;
            cout << "Ville ajoutee au circuit !" << endl;
        }
    }
    if(nbrville >= max or villeExiste(x.getcode())==0){
        cout<<"Nombre de ville atteint ou la ville existe, impossible d'ajouter"<<endl;
    }
}

int circuit::dureeCircuit(){
    int somj=0;
    for(int i=0;i<nbrville;i++){
        somj+=v[i].getnbr_jours();
    }
    return somj;
}

void circuit::retireVille(ville &x){
    int j=0;
    bool villeFound = false;
    for(int i=0;i<nbrville;i++){
        if(v[i].getcode() != x.getcode()){
            v[j] = v[i];
            j++;
        }else{
            villeFound=true;
        }
    }
    if (villeFound) {
        --nbrville;
        cout << "La ville a ete retiree du circuit." <<endl;
    } else {
        cout << "La ville n'existe pas dans le circuit !" <<endl;
    }
}

circuit CIRCUITcour(circuit *c,int taille){
    for(int i=0;i<taille;i++){
        c[i].saisieCircuit();
    }
    
    int min=c[0].dureeCircuit();
    int j=0;
    for(int i=0;i<taille;i++){
        if(c[i].dureeCircuit() < min){
            min = c[i].dureeCircuit();
            j=i;
        }
    }
    return c[j];
}