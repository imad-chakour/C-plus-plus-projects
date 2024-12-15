#include "dev.h"

int main() {
    Zoo zoo(100, 0);
    int choice;
    Animal *Lion = new Mammifere("Lion", "Felin", 5, "Pelage epais", "Carnivore");
    Animal *aigle = new Oiseau("Aigle", "Rapace", 8, "Large");
    Animal *Tortue = new Reptile("Tortue", "Reptile", 50, "Ecailles", 1);
    Animal *Grenouille = new Amphibien("Grenouille", "Amphibien", 2, "Peau humide", 1);
    Animal *Papillon = new Insecte("Papillon", "Insecte", 0, 6, "Nectar");
    do {
        cout << "Menu:\n";
        cout << "1. Ajouter un Mammifere\n";
        cout << "2. Ajouter un Oiseau\n";
        cout << "3. Ajouter un Reptile\n";
        cout << "4. Ajouter un Amphibien\n";
        cout << "5. Ajouter un Insecte\n";
        cout << "6. Supprimer un animal\n";
        cout << "7. Afficher les animaux du zoo\n";
        cout << "8. Quitter\n";
        cout << "Entrez votre choix: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                zoo.ajouter(Lion);
                break;
            }
            case 2: {
                zoo.ajouter(aigle);
                break;
            }
            case 3: {               
                zoo.ajouter(Tortue);
                break;
            }
            case 4: {             
                zoo.ajouter(Grenouille);
                break;
            }
            case 5: {
                zoo.ajouter(Papillon);
                break;
            }
            case 6: {
                cout << "Choisissez l'animal à supprimer :\n";
                cout << "1. Lion\n";
                cout << "2. Aigle\n";
                cout << "3. Tortue\n";
                cout << "4. Grenouille\n";
                cout << "5. Papillon\n";
                int Num;
                cin >> Num;
                switch (Num) {
                    case 1:
                        zoo.supprimer(Lion);
                        delete Lion;
                        break;
                    case 2:
                        zoo.supprimer(aigle);
                        delete aigle;
                        break;
                    case 3:
                        zoo.supprimer(Tortue);
                        delete Tortue;
                        break;
                    case 4:
                        zoo.supprimer(Grenouille);
                        delete Grenouille;
                        break;
                    case 5:
                        zoo.supprimer(Papillon);
                        delete Papillon;
                        break;
                    default:
                        cout << "Animal invalide.\n";
                }
                break;
            }
            case 7: {
                cout << "Animaux actuellement dans le zoo:\n";
                zoo.afficherZoo();
                break;
            }
            case 8: {
                cout << "Au revoir !\n";
                break;
            }
            default:
                cout << "Choix invalide.\n";
        }
    } while (choice != 8);

    return 0;
}
