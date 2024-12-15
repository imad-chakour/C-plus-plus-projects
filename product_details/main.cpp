#include<iostream>
#include "produit.h"

int main(){
    produit p;
    double val;
    p.saisieProduit();
    p.afficheproduit();
    cout<<"La moyenne des prix: "<<p.moyennePrix()<<endl;
    p.MinMaxPrix();
    cout<<"Entrer une valeur qui exist: ";
    cin>>val;
    p.affichePosition(val);
    return 0;
}