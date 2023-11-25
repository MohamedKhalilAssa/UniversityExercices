#include <iostream>
using namespace std;

int NextNumCpte = 100;

//! Structure 
// struct Compte {
//         long numCompte;
//         string nom;
//         double solde;    
// };
// void initCompte(Compte & c, string n, double s){
//     c.nom = n;
//     c.solde = s;
//     c.numCompte = ++NextNumCpte;
// }
// void crediter(Compte & c, double som){ 
//     if(som > 0)
//         c.solde+= som;
// }

// void debiter(Compte & c, double som){
//     if(c.solde >= som)
//         c.solde-= som;
// }
// void virer(Compte & cs, Compte & cd, double som){
//     if(cs.solde >= som && som > 0){
//         cs.solde -= som;
//         cd.solde += som;
//     }
// }
// void afficher(const Compte & cb){
//    cout <<  cb.nom<<", Compte numero: " <<  cb.numCompte<<", Solde : "<< cb.solde <<"dhs"<<endl;
// }

// TODO: Transformation en Class

class Compte{
        long numCompte;
        string nom;
        double solde;
    public:   
    //getters
        long getNum(){
            return this->numCompte;
        }
        string getNom(){
            return this->nom;
        }
        double getSolde(){
            return this->solde;
        }
    // Setters
        void setNom(string nom){
            this->nom = nom;
        }
        void setSolde(double solde){
            this->solde = solde;
        }

        // LES METHODES
        void initCompte(string n, double s){
            this->nom = n;
            this->solde = s;
            this->numCompte = ++NextNumCpte;
        }
        void crediter(double som){ 
            if(som > 0)
                this->solde+= som;
        }

        void debiter( double som){
            if(this->solde >= som)
                this->solde-= som;
        }
        void virer(Compte & cd, double som){
            if(this->solde >= som && som > 0){
                this->solde -= som;
                cd.solde += som;
            }
        }
        void afficher(){
            cout <<  this->nom<<", Compte numero: " <<  this->numCompte<<", Solde : "<< this->solde <<"dhs"<<endl;
        }

};



int main(){

//? Test de structure
    // Compte C1, C2;
    // initCompte(C1,"Alaoui",15000);
    // initCompte(C1,"Hamid",1000);
    // afficher(C1);
    // debiter(C1,1000);
    // afficher(C1);
    // crediter(C1, 500);
    // afficher(C1);
    // virer(C1,C2,5000);
    // afficher(C1);
    // afficher(C2);

//? test de Class 

    Compte C1,C2;
    C1.initCompte("Alaoui",15000);
    C2.initCompte("Hamid",1000);
    C1.afficher();
    C1.crediter(1000);
    C1.afficher();
    C1.debiter(500);
    C1.afficher();
    C1.virer(C2,5000);
    C1.afficher();
    C2.afficher();

    return 0;
}