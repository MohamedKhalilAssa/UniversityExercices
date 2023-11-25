#include <iostream>
using namespace std;

class EnsEntier{
    int taille;
    int cardinal;
    int* ensemble;
public:
    EnsEntier(int taille = 0){
        this->taille = taille;
        this->ensemble = new int[this->taille];
        this->cardinal = 0;
    }
    EnsEntier(const EnsEntier & E){
        this->taille = E.taille;
        this->ensemble = new int[this->taille];
        for(int i = 0; i < E.cardinal; i++){
            this->ensemble[this->cardinal++]= E.ensemble[i];
        }
    }
    int getCardinal(){
        return this->cardinal;
    }
    int getTaille(){
        return this->taille;
    }
    bool contains(int val){
        for(int i = 0; i < this->cardinal; i++){
            if(val == this->ensemble[i])
                return true;
        }
        return false;
    }
    bool ajouterElement(int val){
        if(this->cardinal < this->taille){
            this->ensemble[cardinal++] = val;
            return true;
        }
        return false;
    }
    friend ostream& operator<< (ostream& OUT, const EnsEntier& E ){

        for(int i = 0; i < E.cardinal; i++)
            OUT << E.ensemble[i] << " " ;
        OUT << endl;
        return OUT;
    }
    ~EnsEntier(){
        delete[] this->ensemble;
    }
};
int main(){
    EnsEntier E(20);
    int n;
    for(int i = 0; i < E.getTaille(); i++){
        cout << "Entrez l'entier numero " << i + 1 << ": " << endl;
        cin >> n;
        if(!E.contains(n))
            E.ajouterElement(n);
    }

    cout << "Le nombre d'entiers differents est: " << E.getCardinal() << endl;

    //3 il faut faire un constructeur de copies
    return 0;
}