#include <iostream>
#include <string>
using namespace std;

typedef int jour;
typedef int mois;
typedef int annee;
typedef int heure;

const int maxChambres = 80;
const int maxRes = 80;

const jour jD = 06;
const mois mD = 01;
const annee aD = 2024;

class Client {
private:
    int identifiant;
    string nom;
    string prenom;
    string adresse;

public:
    Client();
    ~Client(){}
    void afficher();
    void saisie();
    int getIdentifiant();
    string getNom();
    string getPrenom();
    string getAdresse();
    void setIdentifiant(int);
    void setNom(string);
    void setPrenom(string);
    void setAdresse(string);
};

class Chambre {
private:
    int identifiant;
    string numTel;
public:
    Chambre();
    ~Chambre(){}
    int getIdentifiant();
    string getNumTel();
    void setIdentifiant(int);
    void setNumeroTelephone(string);
    void saisieChambre();
    void afficherChambre();
    bool comparer(const Chambre& a) const;
};

class Reservation {
private:
    int code;
    int nbrch;
    Chambre* ch;
    Client client;
    bool etat;
    jour jourD,jourF;
    mois moisD,moisF;
    annee anneeD,anneeF;
    heure heureD,heureF;

public:
    Reservation();
    ~Reservation(); 

    Client getClient();
    Chambre* getChambre();
    int getcode();
    int getjourD();
    int getmoisD();
    int getanneeD();
    int getjourF();
    int getmoisF();
    int getanneeF();

    void saisieReservation();
    void afficherReservation();
    int ChambreReserver(Chambre &x);
    int ChambreExiste(int id);
    void ajouterChambre(Chambre& x);
    void dureeReservation();
    void supprimerChambre(Chambre &x);
    void validerReservation();
    void annulerReservation();
};

    int testerClient(Reservation *res,int &nbrRes,int id);
    bool resEffectuer(Reservation *res,int &nbrRes,int code);
    void ajouterReservation(Reservation *res,int &nbrRes,Reservation& rs);
    void AfficherTousReservation(Reservation *res,int nbrRes);
    void modifierResChambre(Reservation *res,int nbrRes,int code,int id);
    void SuppReservation(Reservation* res, int& n, int Code);
    Reservation* ResToday(Reservation *res, int nbrRes, int &ct);
    Reservation* ResExp(Reservation *res, int nbrRes, int &ct);
    void annulerRes(Reservation* res, int n); 
