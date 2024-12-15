#include "hotel.h"

int main() {
    Reservation *res;
    int nbrRes;
    cout << "Entrer le nbr de reservations: ";
    cin >> nbrRes;
    res = new Reservation[maxRes];
    for(int i=0;i<nbrRes;i++){
        res[i].saisieReservation();
        res[i].validerReservation();
    }
    
    int choix;
    Reservation rs;
    do {
        cout << "\n------ Gestion Hotel ------" << endl;
        cout << "1. Ajouter Reservation" << endl;
        cout << "2. Afficher les Reservations" << endl;
        cout << "3. Tester si un client a effectuer une Reservation" << endl;
        cout << "4. tester si une reservation est deja effectuer" << endl;
        cout << "5. Modifier une chambre d'une reservation donner" << endl;
        cout << "6. Supprimer Reservation" << endl;
        cout << "7. Afficher les Reservation effectuer Aujourd'hui" << endl;
        cout << "8. Afficher les Reservation qui seront expire Aujourd'hui" << endl;
        cout << "0. Exit" << endl;
        cout << "------------------------------------------" << endl;

        cout << "Entrer votre choix: ";
        cin >> choix;

        switch (choix) {
            case 1: {
                cout << "Saisir la reservation a ajouter: " << endl;
                rs.saisieReservation();
                ajouterReservation(res, nbrRes, rs);
                break;
            }
            case 2:
                cout << "\nAffichage des Reservation:" << endl;
                AfficherTousReservation(res, nbrRes);
                break;
            case 3: {
                int id;
                cout << "Entrer l'identifiant du client a chercher: ";
                cin >> id;
                if (testerClient(res, nbrRes, id) == 0) {
                    cout << "le client a deja effectue une reservation!" << endl;
                } else {
                    cout << "le client n'a pas effectue une reservation!" << endl;
                }
                break;
            }
            case 4: {
                int code;
                cout << "Entrer le code de la reservation a chercher: ";
                cin >> code;
                if (resEffectuer(res, nbrRes, code)) {
                    cout << "la reservation est deja effectue!" << endl;
                } else {
                    cout << "la reservation n'a pas ete effectue!" << endl;
                }
                break;
            }
            case 5: {
                int idf;
                cout << "Entrer l'identifiant de la chambre a modifier: ";
                cin >> idf;
                modifierResChambre(res,nbrRes,rs.getcode(),idf);
                cout<<"\nAffichage des Reservation apres la modification:"<<endl;
                AfficherTousReservation(res,nbrRes);
                break;
            }
            case 6: {
                int cdd;
                cout << "Entrer le code de la reservation a supprimer : ";
                cin >> cdd;
                SuppReservation(res, nbrRes,cdd);
                cout<<"\nAffichage des Reservation apres la suppression:"<<endl;
                AfficherTousReservation(res,nbrRes);
                break;
            }
            case 7: {
                int ct = 0;
                Reservation *t = ResToday(res, nbrRes, ct);
                cout << "\nAffichage des Reservation effectuer Aujourd'hui:" << endl;
                AfficherTousReservation(t, ct);
                delete[] t;
                break;
            }
            case 8: {
                int c = 0;
                Reservation *e = ResExp(res, nbrRes, c);
                cout << "\nAffichage des Reservation expirer Aujourd'hui:" << endl;
                AfficherTousReservation(e, c);
                annulerRes(e,c);
                delete[] e;
                break;
            }
            case 0:
                cout << "sortir du programme. Goodbye!" << endl;
                break;
            default:
                cout << "Choix invalide, choisir a nouveau!" << endl;
        }

    } while (choix != 0);

    delete[] res;

    return 0;
}
