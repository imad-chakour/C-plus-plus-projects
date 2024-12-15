#include "complexe.h"
#include<cmath>
int complexe::cpt=0;

complexe::complexe(int a,int b)
:re(a),im(b)
{
    cpt++;
}

complexe::complexe(complexe &c){
    cpt++;
    re = c.re;
    im = c.im;
}

void complexe::saisir(){
    cout<<"Entrer la partie imagin:";
    cin>>im;
    cout<<"Entrer la partie reel:";
    cin>>re;
}

void complexe::afficher(){
    cout<<re<<"+"<<im<<"i"<<endl;
    cout<<"compteur est :"<<cpt<<endl;
}

float complexe::Module(){
    float m=0.0;
    m = sqrt(pow(re,2)+pow(im,2));
    return m;
}

void RemplirTC(int n,complexe T[]){
    for(int i=0;i<n;i++){
        T[i].saisir();
    }
}

void  AfficherTC(int n,complexe T[]){
    for(int i=0;i<n;i++){
        T[i].afficher();
    }
}

void complexe::copie(complexe &c){
    re = c.re;
    im = c.im;
}

complexe& GetMin(int n,complexe T[]){
     int min=T[0].Module();
    int j=0;
    for(int i=0;i<n;i++){
        if(T[i].Module() < min){
            min=T[i].Module();
            j=i;
        }
    }
    return T[j];
}

complexe& AfficherReel(int n,complexe T[]){
    int max=T[0].re;
    int j=0;
    for(int i=0;i<n;i++){
        if(T[i].re > max){
            max=T[i].re;
            j=i;
        }
    }
    return T[j];
}