#include<iostream>
using namespace std;

class complexe{
	private:
	 int im;
	 int re;
	 static	 int cpt;

	 public:
	 void saisir();
	 void afficher();
	 complexe(int a=1,int b=0);
	 float Module();
	 complexe(complexe &);
	 void copie(complexe &);
     friend complexe& AfficherReel(int n,complexe T[]);
     
};

void RemplirTC(int n,complexe T[]);
void  AfficherTC(int n,complexe T[]);
complexe& GetMin(int n,complexe T[]);
complexe& AfficherReel(int n,complexe T[]);
