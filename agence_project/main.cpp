#include "agence.h"

int main() {
    ville v1, v2;

    cout << "Enter details for Ville 1:\n";
    v1.saisieVille();
    cout << "Details for Ville 1:\n";
    v1.afficheVille();

    cout << "Enter details for Ville 2:\n";
    v2.saisieVille();
    cout << "Details for Ville 2:\n";
    v2.afficheVille();

    int result = comparerVille(v1, v2);
    if (result == 0) {
        cout << "Les deux villes sont égales!\n";
    } else if (result == 1) {
        cout << "Le code de Ville 1 est plus grand que celui de Ville 2!\n";
    } else {
        cout << "Le code de Ville 2 est plus grand que celui de Ville 1!\n";
    }

    circuit c1;
    cout << "Enter Circuit 1:\n";
    c1.saisieCircuit();
    cout << "Details du Circuit 1:\n";
    c1.afficheCircuit();

    cout << "Entrer le code de la ville a chercher:\n";
    int code;
    cin >> code;
    if (c1.villeExiste(code) == 0) {
        cout << "La ville existe dans le circuit!\n";
    } else {
        cout << "La ville n'existe pas dans le circuit!\n";
    }

    cout << "Ajout de Ville au circuit!\n";
    c1.addVille(v2);
    c1.afficheCircuit();

    cout << "La duree totale du circuit est de : " << c1.dureeCircuit() << " jours.\n";

    cout << "Retirer ville du circuit!\n";
    c1.retireVille(v2);
    c1.afficheCircuit();

    circuit *x;
    int z;
    cout << "Entrer le nombre de circuit :\n";
    cin>>z;
    x = new circuit[z];
    CIRCUITcour(x,z).afficheCircuit();
    return 0;
}
