#include "produit.h"

void produit::saisieProduit(){
    cout<<"Entrer le nbr des prix:";
    cin>>taille;
    prix = (double *)malloc(sizeof(double)*taille);

        cout<<"Entrer le nom du produit:";
        cin>>nom;
        for(int i=0;i<taille;i++){
        cout<<"Entrer le prix n_" <<i+1<<" :";
        cin>>prix[i];
    }
}

void produit::afficheproduit(){
    cout<<nom<<"a les prix de vente suivante: "<<endl;
    for(int i=0;i<taille;i++){
        cout<< this->prix[i] <<endl;
    }
}

double produit::moyennePrix(){
    double moy=0.0,som=0.0;
    for(int i=0;i<taille;i++){
        som = som + prix[i];
    }
    moy = som / taille;
    return moy;
}

void produit::MinMaxPrix(){
    double min=prix[0];
    double max=this->prix[0];
    for(int i=0;i<taille;i++){
        if(this->prix[i]<min){
            min = prix[i];
        }
        else if (this->prix[i]>max)
        {
            max = prix[i];
        }
    }
    cout<<"MAX: "<<max<<" MIN: "<<min<<endl;
}

void produit::affichePosition(double val){
    for(int i=0;i<taille;i++){
        if(this->prix[i] == val){
            cout<<"la position de la valeur "<<this->prix[i]<<" est -> "<<i<<endl;
        }
    }
}