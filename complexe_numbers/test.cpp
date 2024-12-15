
#include "complexe.h"
#include<math.h>

int main(){
	int i,n;
	
	complexe C,A,D,T[10];
	complexe X(2,3);
	C.saisir();
	cout<<"le complexe est:";
	C.afficher();
	cout<<"Voici le module: "<<C.Module()<<endl;
	complexe B(C);
	cout<<"voici la copie a travers le constructeur de recopie:"<<endl;
    B.afficher();
    C.saisir();
    cout<<"**************"<<endl;
    B.afficher();
    C.afficher();
	C.copie(B);
	cout<<"voici la copie a travers une fonction:"<<endl;
	B.afficher();
	cout<<"donner la taille du tableau:"<<endl;
	cin>>n;
	RemplirTC(n,T);
	cout<<"vos complexes  sont:"<<endl;
	AfficherTC(n,T);
	A=GetMin(n,T);
	cout<<"le complexe ayant le plus petit module est:"<<endl;
	A.afficher();
	D=AfficherReel(n,T);
	cout<<"le complexe ayant la plus grande partie reelle:"<<endl;
	D.afficher();
	system("pause");
}