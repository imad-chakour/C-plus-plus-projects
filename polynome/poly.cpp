#include"poly.h"

    Monome::Monome(double c,int d)
    :coefficient(c),degre(d)
    {}
    Monome::Monome(Monome& m)
    :coefficient(m.coefficient),degre(m.degre)
    {}
    double Monome::getCoe(){
        return coefficient;
    }
    int Monome::getDeg(){
        return degre;
    }
    ostream& operator<<(ostream& os, const Monome& monome) {
        os << monome.coefficient << "x^" << monome.degre;
        return os;
    }
    istream& operator>>(istream& is,Monome& monome){
        is>>monome.coefficient>>monome.degre;
        return is;
    }
    Monome Monome::operator+(const Monome& other) const{
        if(degre == other.degre){
            return Monome(coefficient + other.coefficient, degre);
        }
        else{
            return Monome();
        }
    }
    Monome Monome::operator*(const Monome& other) const{
        return Monome(coefficient * other.coefficient, degre + other.degre);
    }

    bool Monome::operator==(const Monome& other) const{
        if(coefficient == other.coefficient && degre == other.degre){
            return true;
        }else{
            return false;
        }
    }

    bool Monome::operator<(const Monome& other) const{
        if(degre < other.degre){
            return true;
        }else{
            return false;
        }
    }

    bool Monome::operator!() const{
        if(coefficient == 0.0){
            return true;
        }else{
            return false;
        }
    }

    Monome Monome::operator~() const{
        return Monome(degre * coefficient,degre-1);
    }