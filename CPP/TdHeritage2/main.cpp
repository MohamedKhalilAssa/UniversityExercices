#include <iostream>
#include <string>
using namespace std;

class Article{
protected:
    int Code;
    string nom;
    string marque;
    double prixUnitaire;
    int qteStock;
public:
      Article(int Code = 0,string nom = "",string marque = "",double prixUnitaire = 0, int qteStock = 0) {
       this->Code = Code; this->nom = nom; this->marque = marque;
        this->prixUnitaire = prixUnitaire; this->qteStock = qteStock;
        }
        //getters
        virtual string getNom() const{
            return nom;
        }
         string getMarque()const{
            return marque;
        }
        int getCode()const{
            return this->Code;
        }
         double getPrix()const{
            return this->prixUnitaire;
        }
        int getQte()const{
            return this->qteStock;
        }
        friend ostream & operator<< (ostream & OUT, const Article & art){
            OUT << "La reference: " << art.Code << " Article: " << art.nom
            << " La marque: "<<art.marque << " PrixU: " << art.prixUnitaire << " dhs" << endl;
            return OUT;
        }
};

class Stylos : public Article {

    string couleur;
public:
  Stylos(int Code,string nom,string marque,double prixUnitaire, int qteStock,string couleurP) : Article(Code,nom,marque,prixUnitaire,qteStock) {
    this->nom = "stylo " + couleurP + " " + nom;
    this->couleur = couleur;
  }

};

class ramettesPapier : public Article{
    int grammage;
public:
     ramettesPapier(int Code,string nom,string marque,double prixUnitaire, int qteStock,int grammageP) : Article(Code,nom,marque,prixUnitaire,qteStock) {
         this->nom = "Ramette " + this->nom ;
        this->grammage = grammage;
  }
};


class Lots {
    Article art;

    string nom;
    string marque;
    int nombre;
    int reduction;
public :
    Lots(Article art,int nombre = 0, int reduction = 0){
        if(art.getQte() >= nombre){
            this->nombre = nombre;
            this->reduction = reduction;
            this->art = art;
            this->nom = "Lot de " + to_string(this->nombre) + " " +art.getNom();
            this->marque = this->art.getMarque();
        }
    }

    double calculPrix(){
        return ((art.getPrix() * this->nombre) * (100 - this->reduction)) / 100;
    }
    string getNom(){
        return this->nom;
    }
    friend ostream& operator<<(ostream& OUT,  Lots lot) {
        OUT << lot.nombre << " " << lot.art.getCode() << " " << lot.nom << " " << lot.marque << " " << lot.calculPrix();
        return OUT;
    }
};

class commande {
    Lots lot;
    Article art;
    int QteCommandeA = 0;
    int QteCommandeL = 0;

    double prixTotal;

public:
    void ajouterLot(Lots lot, int qte){
        this->lot = lot;
        this->QteCommandeL = qte;
    }
    void ajouterArt(Article art, int Qte){
        this->art = art;
        this->QteCommandeA = Qte;
    }
    void calculPrixTotal(){
        if(this->QteCommandeA){
            this->prixTotal = this->art.getPrix() * this->QteCommandeA;
        }
        else if (this->QteCommandeL){
            this->prixTotal = this->lot.calculPrix() * this->QteCommandeL;
        }
    };

};
/*
class facture {
private:
    int numero;
    string Date;
    string nom;
    Commande * C;


};*/
int main()
{
    Stylos S1(1,"B2","WSP",100,250,"Noir");
   // ramettesPapier R1(1, "W","Bic", 100,80);

//    cout << S1 << R1;
    Lots A(S1,10,20);

    cout << A;
    /*
    cout << S1.getNom();
    cout << A.getNom() << endl ;
    cout << A.calculPrix();
*/
    return 0;
}
