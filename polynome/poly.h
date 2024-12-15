#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Monome {
private:
    double coefficient;
    int degre;
public:
    Monome() : coefficient(0.0), degre(0) {}
    Monome(double c,int d);
    Monome(Monome& m);
    double getCoe();
    int getDeg();
    friend ostream& operator<<(ostream& os, const Monome& monome);
    friend istream& operator>>(istream& is,Monome& monome);
    Monome operator+(const Monome& other) const;
    Monome operator*(const Monome& other) const;
    bool operator==(const Monome& other) const;
    bool operator<(const Monome& other) const;
    bool operator!() const; 
    Monome operator~() const;
    friend class polynome;
};