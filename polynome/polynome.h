#include<iostream>
using namespace std;
#include<ostream>
#include<istream>
#include "poly.h"

class polynome{
	private:
	  	Monome *T;
	  	int taille;
	public:
	  polynome();
	  polynome(Monome t[],int n);	
	  Monome&  operator[](int);
	  int poly_deg();
	  friend  ostream& operator<<(ostream&,const polynome&);
      friend  istream& operator>>(istream&,polynome&);
      void   tri();
      void ajouter(Monome&);
	  polynome operator+(const polynome&);
	  polynome operator*(polynome&);
	  float operator()(float);
	  polynome operator=(const polynome&);
	  polynome operator~();
};

  ostream& operator<<(ostream&,const polynome&);
  istream& operator>>(istream&,polynome&);
