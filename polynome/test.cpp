#include <iostream>
#include"polynome.h"

int main() {
    // Test de la saisie d'un polynôme
    polynome poly1;
    cout << "Saisie du premier polynome :" << endl;
    cin >> poly1;
    cout << "Polynome saisi :" << endl;
    cout << poly1 << endl;

    // Test de la dérivation
    polynome derivee = ~poly1;
    cout << "Dérivée du polynome :" << endl;
    cout << derivee << endl;

    // Test de l'opérateur d'évaluation pour x=2
    float resultat = poly1(2.0);
    cout << "Evaluation du polynome pour x=2 : " << resultat << endl;

    // Test de l'opérateur d'assignation
    polynome poly2;
    cout << "Saisie du deuxième polynome :" << endl;
    cin >> poly2;
    poly1 = poly2;
    cout << "Polynome après assignation :" << endl;
    cout << poly1 << endl;

    // Test de l'opérateur de multiplication
    polynome produit = poly1 * poly2;
    cout << "Produit des deux polynomes :" << endl;
    cout << produit << endl;

    return 0;
}
