#include"hotel.h"

// CLIENT
Client::Client() : identifiant(0), nom(""), prenom(""), adresse("") {}

int Client::getIdentifiant() {
    return identifiant;
}
string Client::getNom() {
    return nom;
}
string Client::getPrenom() {
    return prenom;
}
string Client::getAdresse() {
    return adresse;
}
void Client::setIdentifiant(int id) {
    identifiant = id;
}
void Client::setNom(string nm) {
    nom = nm;
}
void Client::setPrenom(string pre) {
    prenom = pre;
}
void Client::setAdresse(string adr) {
    adresse = adr;
}
void Client::saisie() {
    cout << "Entrer l'identifiant du client: ";
    cin >> identifiant;
    cout << "Entrer le nom du client: ";
    cin >> nom;
    cout << "Entrer le prenom du client: ";
    cin >> prenom;
    cout << "Entrer l'adresse du client: ";
    cin >> adresse;
}
void Client::afficher() {
    cout << "Identifiant du client: " << identifiant << " | Nom du client: " << nom << " | Prenom du client: " << prenom << " | Adresse du client: " << adresse << endl;
}

// CHAMBRE
Chambre::Chambre() : identifiant(0), numTel("") {}

int Chambre::getIdentifiant() {
    return identifiant;
}
string Chambre::getNumTel() {
    return numTel;
}
void Chambre::setIdentifiant(int id) {
    identifiant = id;
}
void Chambre::setNumeroTelephone(string num) {
    numTel = num;
}
void Chambre::afficherChambre() {
    cout << "Identifiant de la chambre: " << identifiant << " | Numero de telephone: " << numTel << endl;
}
void Chambre::saisieChambre() {
    cout << "Entrer l'identifiant de la chambre: ";
    cin >> identifiant;
    cout << "Entrer le numero de telephone de la chambre: ";
    cin >> numTel;
}
bool Chambre::comparer(const Chambre& a) const {
    if(identifiant == a.identifiant){
        return true;
    }else{
        return false;
    }
}

// RESERVATION 
Reservation::Reservation()  : code(0), nbrch(0), ch(0), etat(true) {}
Reservation::~Reservation() {
    delete[] ch;
}
Client Reservation::getClient(){
    return client;
}
int Reservation::getcode(){
    return code;
}
int Reservation::getjourD(){
    return jourD;
}
int Reservation::getmoisD(){
    return moisD;
}
int Reservation::getanneeD(){
    return anneeD;
}
int Reservation::getjourF(){
    return jourF;
}
int Reservation::getmoisF(){
    return moisF;
}
int Reservation::getanneeF(){
    return anneeF;
}
Chambre* Reservation::getChambre() {
    return ch; 
}
void Reservation::saisieReservation() {
    cout << "Entrez le code de la reservation: ";
    cin >> code;
    cout << "Entrez le nbr de chambres: ";
    cin >> nbrch;
    ch = new Chambre[maxChambres];
    for (int i = 0; i < nbrch; i++) {
        ch[i].saisieChambre();
    }
    client.saisie();
    cout << "Saisir la date de debut de la reservation:\n";
    cout << "Jour: "; cin >> jourD;
    cout << "Mois: "; cin >> moisD;
    cout << "Annee: "; cin >> anneeD;
    cout << "Heure: "; cin >> heureD;
    cout << "Saisir la date de fin de la reservation:\n";
    cout << "Jour: "; cin >> jourF;
    cout << "Mois: "; cin >> moisF;
    cout << "Annee: "; cin >> anneeF;
    cout << "Heure: "; cin >> heureF;
}

void Reservation::afficherReservation() {
    cout << "Le code de la reservation: " << code << "\nLe nbr de chambres: " << nbrch << endl;
    for (int i = 0; i < nbrch; i++) {
        ch[i].afficherChambre();
    }
    client.afficher();
    cout << "Date de debut: " << jourD << "/" << moisD << "/" << anneeD << " " << heureD << endl;
    cout << "Date de fin: " << jourF << "/" << moisF << "/" << anneeF << " " << heureF<< endl;
    dureeReservation();
}

int Reservation::ChambreReserver(Chambre &x) {
    for (int i = 0; i < nbrch; i++) {
        if (x.comparer(ch[i])) {
                return 0;
            }
        }
        return 1;
    }

int Reservation::ChambreExiste(int id) {
    for (int i = 0; i < nbrch; i++) {
        if (ch[i].getIdentifiant() == id) {
            return 0;
        }
    }
    return 1;
}

void Reservation::ajouterChambre(Chambre& x) {
        if (nbrch < maxChambres && ChambreExiste(x.getIdentifiant()) != 0){
            ch[nbrch] = x;
            nbrch++;
            cout << "Chambre ajoutee a la reservation !" <<endl;
        } else {
            cout << "Nombre de chambre atteint ou la chambre existe, impossible d'ajouter" <<endl;
        }
}

void Reservation::dureeReservation(){
    jour j = jourF - jourD;
    mois m = moisF - moisD;
    annee a = anneeF - anneeD;
    heure h = heureF - heureD;
    if (h < 0) {
        h += 24;
        j--;
    }
    if (j < 0) {
        m--;
        if(moisF == 1 || moisF == 3 || moisF == 5 || moisF == 7 || moisF == 8 || moisF == 10 || moisF == 12){
            j += 31 ;
        }else if (moisF == 4 || moisF == 6 || moisF == 9 || moisF == 11)
        {
            j += 30 ;
        }else if(anneeF % 4 == 0 && (anneeF % 100 != 0 || anneeF % 400 == 0)){
            j+=29;
        }else{
            j+=28;
        }       
    }
    if (m < 0) {
        m += 12;
        a--;
    }
    cout << "La duree de la reservation est: "<<j<<" jours, "<<m<<" mois, "<<a<<" annees, "<<h<<" heures."<<endl;
}

void Reservation::supprimerChambre(Chambre &x){
    int j=0;
    bool Trouvee=false ;
    for(int i=0;i<nbrch;i++){
        if(ch[i].getIdentifiant() != x.getIdentifiant()){
            ch[j] = ch[i];
            j++;
        }else{
            Trouvee = true;
        }
    }
    if(Trouvee){
        nbrch--;
        cout<<"La chambre a ete supprimee de la reservation!"<<endl;
    }else{
        cout<<"impossible de supprimer la chambre!"<<endl;
    }
}


void Reservation::validerReservation() {
        etat = true;
        cout << "La reservation a ete validee !" << endl;
    }

void Reservation::annulerReservation() {
        etat = false;
        cout << "La reservation a ete annulee !" << endl;
    }

//TABLEAU DE RESERVATONS
int testerClient(Reservation *res,int &nbrRes,int id){
    for(int i=0;i<nbrRes;i++){
        if(res[i].getClient().getIdentifiant() == id){
            return 0;
        }
    }
    return 1;
}

bool resEffectuer(Reservation *res,int &nbrRes,int code){
    for(int i=0;i<nbrRes;i++){
        if(res[i].getcode() == code){
            return true;
        }
    }
    return false;
}

void ajouterReservation(Reservation *res, int &nbrRes, Reservation &rs) {
    if (nbrRes < maxRes && !resEffectuer(res, nbrRes, rs.getcode())) {
        res[nbrRes] = rs;
        nbrRes++;
        cout << "La Reservation a ete ajoutee !" << endl;
    } else {
        cout << "la Reservation existe, impossible d'ajouter (code: " << rs.getcode() << ")" << endl;
    }
}

void modifierResChambre(Reservation *res,int nbrRes,int code,int id){

    int identifiant;
    string numTel;
    cout << "Entrer le nouveau identifiant de la chambre: ";
    cin >> identifiant;
    cout << "Entrer le nouveau numero de telephone de la chambre: ";
    cin >> numTel;

    for(int i=0;i<nbrRes;i++){
        if(res[i].getcode()==code){
            if(res[i].getChambre()->getIdentifiant() == id){
                res[i].getChambre()->setIdentifiant(identifiant);
                res[i].getChambre()->setNumeroTelephone(numTel);
            }
        }
    }
}

void SuppReservation(Reservation* res, int& nbrRes, int Code){
    int j=0;
    bool Trouvee=false ;
    for(int i=0;i<nbrRes;i++){
        if(res[i].getcode() != Code){
            res[j] = res[i];
            j++;
        }else{
            Trouvee=true;
        }
    }
    if(Trouvee){
        nbrRes--;
        cout<<"La reservation a ete supprimee!"<<endl;
    }else{
        cout<<"la reservation n'existe pas, impossible de supprimer!"<<endl;
    }
}

void AfficherTousReservation(Reservation *res,int nbrRes){
    for(int i=0;i<nbrRes;i++){
        res[i].afficherReservation();
    }
}

Reservation* ResToday(Reservation *res, int nbrRes, int &ct) {
    Reservation* rs = new Reservation[maxRes];
    int j = 0;
    for (int i = 0; i < nbrRes; i++) {
        if (res[i].getjourD() == jD && res[i].getmoisD() == mD && res[i].getanneeD() == aD) {
            rs[j] = res[i];
            j++;
        }
    }
    ct = j;
    return rs;
}

Reservation* ResExp(Reservation *res, int nbrRes, int &ct) {
    Reservation* rs = new Reservation[maxRes];
    int j = 0;
    for (int i = 0; i < nbrRes; i++) {
        if (res[i].getjourF() == jD && res[i].getmoisF() == mD && res[i].getanneeF() == aD) {
            rs[j] = res[i];
            j++;
        }
    }
    ct = j;
    return rs;
}

void annulerRes(Reservation* res, int nbrRes){
    for(int i=0;i<nbrRes;i++){
        res[i].annulerReservation();
    }
}