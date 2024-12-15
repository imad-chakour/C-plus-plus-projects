#include"polynome.h"

const int maxMono = 10;
polynome::polynome()
:T(nullptr),taille(0)
{
    T = new Monome[maxMono];
}

polynome::polynome(Monome t[],int n)
:T(t),taille(n)
{
    T = new Monome[maxMono];
}

Monome&  polynome::operator[](int i){
    return T[i];
}

int polynome::poly_deg(){
    return T[0].degre;
}

ostream& operator<<(ostream& os,const polynome& p){
    for(int i=0;i<p.taille;i++){
        os <<p.T[i]<<endl;
    }
    return os;
}
istream& operator>>(istream& is,polynome& p){
    Monome m;
    cout<<"Entrer le nbr de monome:"<<endl;
    is >> p.taille;
    for(int i=0;i<p.taille;i++){
        cout<<"Entrer le monome "<<i+1<<": "<<endl;
        is >> m;
        if(!!m){
            p.T[i] = m;
        }else{
            i--;
        }
    }
    p.tri();
    return is;
}

void  polynome::tri(){
    Monome m;
    for(int i=0;i<taille;i++){
        for(int j=i;j<taille;j++){
            if(T[i] < T[j]){
                m = T[i];
                T[i] = T[j];
                T[j] = m;
            }
        }
    }
}

void polynome::ajouter(Monome& m){
    bool mmdegre = false;
    for(int i=0;i<taille;i++){
        if(T[i].degre == m.degre){
            T[i] = T[i] + m;
            mmdegre = true;
            break;
        }
    }
    if(mmdegre == false){
        T[taille] = m;
        taille++;
        tri();
    }
}

polynome polynome::operator+(const polynome& p){
    polynome pol;
	for(int i=0;i<p.taille;i++)
		pol.ajouter(p.T[i]);
	for(int j=0;j<taille;j++)
		pol.ajouter(T[j]);
	return pol;
}

    polynome polynome::operator*(polynome& p) {
        polynome resultat;

        for (int i = 0; i < taille; i++) {
            for (int j = 0; j < p.taille; j++) {
                Monome monomeProduit = T[i] * p.T[j];
                resultat.ajouter(monomeProduit);
            }
        }

        return resultat;
    }

    // Implémentation de l'opérateur de calcul pour une valeur donnée x
    float polynome::operator()(float x) {
        float resultat = 0.0;

        for (int i = 0; i < taille; i++) {
            resultat += T[i].coefficient * pow(x, T[i].degre);
        }

        return resultat;
    }

    // Implémentation de l'opérateur d'assignation
    polynome polynome::operator=(const polynome& p) {
        if (this != &p) {
            delete[] T; // Libération de l'espace mémoire existant
            taille = p.taille;
            T = new Monome[taille];
            for (int i = 0; i < taille; i++) {
                T[i] = p.T[i];
            }
        }
        return *this;
    }

    // Implémentation de l'opérateur de dérivation
    polynome polynome::operator~() {
        polynome derivee;

        for (int i = 0; i < taille; i++) {
            Monome monomeDerive = ~T[i];
            derivee.ajouter(monomeDerive);
        }

        return derivee;
    }

