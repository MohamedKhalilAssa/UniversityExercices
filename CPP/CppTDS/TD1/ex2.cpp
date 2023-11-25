#include <iostream>
using namespace std;


class SalleCinema{
        string titreFilm;
        unsigned int capacite;
        double prixBillet;
        unsigned int nbrePlacesVendues = 0;
    public : 
        // // getters 
        //     string getTitre(){
        //         return this->titreFilm;
        //     }
        //     unsigned int getNbrPlacesVendues(){
        //         return this->nbrePlacesVendues;
        //     }
        //     unsigned int getCapacite(){
        //         return this->capacite;
        //     }
        //     double getPrix(){
        //         return this->prixBillet;
        //     }
        // // setters
        //     void setPrix(double prix){
        //         this->prixBillet = prix;
        //     }
        //     void setTitre(string Titre){
        //         this->titreFilm = Titre;
        //     }
        //     //!.........
    // METHODES 
        void initSalleCinema(string titre, unsigned int capacite, double prix){
            this->titreFilm = titre;
            this->capacite = capacite;
            this->prixBillet = prix;
        }
        bool estPleine(){
            if(this->nbrePlacesVendues == this->capacite){
                return true;
            }
            return false;
        }
       void VendrePlace(){
            this->nbrePlacesVendues++;
       }
       unsigned int nbPlacesDisponibles(){
            return this->capacite - this->nbrePlacesVendues;
       }
       double TauxRemplissage(){
            return (double) (this->nbrePlacesVendues * 100) / this->capacite;
       }
       double ChiffreAffaires(){
            return this->nbrePlacesVendues * this->prixBillet;
       }
       void Afficher(){
            cout << "----------------- Resultat d'execution -----------------" << endl<<
                    "Titre du film : "<< this->titreFilm << endl <<
                    "Tarif : " << this->prixBillet << "dh\n" <<
                    "Taux remplissage : " << this->TauxRemplissage() << "%\n"
                    "Chiffre d'affaires : "<< this->ChiffreAffaires() <<"dh" << endl;
       }
};
int main(){
    SalleCinema SC;
    SC.initSalleCinema("Titanic", 200, 25.5);
    for(int i=0; i < 75;i++)
        SC.VendrePlace();
    SC.Afficher();

    return 0;
}