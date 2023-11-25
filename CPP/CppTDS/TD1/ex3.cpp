#include <iostream>
using namespace std;

class Fraction{
    int numerateur;
    int denumerateur;
    int PGCD(){
        int temp = this->numerateur > this->denumerateur ? this->numerateur : this->denumerateur;

        while(temp > 1){
            if(this->numerateur % temp == 0 && this->denumerateur % temp == 0)
                return temp;
            else {
                temp--;
            }    
        }
        return 1;
    }
    public : 

        Fraction(int num, int denum = 1 ){
            this->numerateur = num;
            this->denumerateur = denum;
        }
        // getters
        int getNum(){
            return this->numerateur;
        }
        int getDen() {
            return this->denumerateur;
        }
        // setters
        void setNum(int num){
            this->numerateur = num;
        }
        void setDen(int den){
            this->denumerateur = den;
        }
        // METHODES
      
        int signe(){
            int division =this->numerateur / this->denumerateur;

            if(division > 0 )
                return 1;
            else if (division < 0)
                return -1;
            else 
                return 0;                
        }
        void reduction (){
            int pgcd = this->PGCD();
            if(pgcd > 1){
                this->numerateur = this->numerateur / pgcd;
                this->denumerateur = this->denumerateur/pgcd;
            }
        }
        float reel(){
            return (float) this->numerateur / this->denumerateur;
        }
        void afficher(){
            cout << this->numerateur << " / " << this->denumerateur << endl;
        }
        // SOMME MAIS SURCHARGE
        Fraction operator+(const Fraction F){
            return Fraction(this->numerateur * F.denumerateur + F.numerateur * this->denumerateur , this->denumerateur * F.denumerateur);
        }
};

int main(){

    Fraction F1(60,36);
    F1.afficher();
    F1.reduction();
    F1.afficher();
    Fraction A(3), B(5);
    A.afficher(); B.afficher();

    Fraction C = A + B;
    
    C.afficher();

    return 0;
}