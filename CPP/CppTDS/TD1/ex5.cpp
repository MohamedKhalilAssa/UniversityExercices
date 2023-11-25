#include <iostream>
using namespace std;

class Vecteur{
    int taille;
    int* tab;

public:
    Vecteur(int taille){
        this->taille = taille;
        this->tab = new int[taille];
    }
    Vecteur(const Vecteur & V){
        this->taille = V.taille;
        this->tab = new int[this->taille];
        for(int i = 0 ; i < this->taille; i++){
            this->tab[i] = V.tab[i];
        }
    }
    ~Vecteur(){
        delete [] this->tab;
    }
    int getTaille() const{
        return this->taille;
    }
    int getElement(int i) const{
        return this->tab[i];
    }
    void setElement(int index,int val){
        if(index < this->taille )
            this->tab[index] = val; 
    }
    void setTaille(int taille){
        int *temp = new int[taille];
        for(int i = 0; i < this->taille; i++){
            temp[i] = this->tab[i];
        }
        delete[] this->tab;
        this->tab = new int[taille];
        for(int i = 0; i < taille; i++){
            if(i < this->taille)
                this->tab[i] = temp[i];
            else
                this->tab[i] = 0;
        }
        this->taille = taille;
    }
    void addElement(int val, int pos){
        this->setTaille(this->taille + 1);
        for(int i = 0; i < this->taille; i++){
            if(i == pos){
                for(int j = this->taille - 1; j > i ; j--){
                    this->tab[j] = this->tab[j-1];
                }
                this->tab[pos] = val;
                return;
            }
        }
    }
    Vecteur operator+(const Vecteur& V){
        Vecteur result(this->taille + V.taille);
        for(int i = 0; i < this->taille;i++)
            result.tab[i] = this->tab[i];
        for(int i = 0;i < V.taille; i++){
            result.tab[i + this->taille] = V.tab[i];
        }
        return result;
    }
    friend ostream& operator<<(ostream & OUT, const Vecteur& V){
        for(int i = 0; i < V.taille;i++)
            OUT << V.tab[i] << " ";
        OUT << endl;
        return OUT;
    }
};

int main(){

    Vecteur V1(5);
    V1.setElement(0,1);
    V1.setElement(1,2);
    V1.setElement(2,3);
    V1.setElement(3,4);
    V1.setElement(4,5);
 
    Vecteur V2(5);
     V2.setElement(0,1);
    V2.setElement(1,2);
    V2.setElement(2,3);
    V2.setElement(3,4);
    V2.setElement(4,5);
    cout << V1 + V2;
    return 0;
}