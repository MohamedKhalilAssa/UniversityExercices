#include <iostream>
#include <cstdlib>

using namespace std;

class Horaire {
    int Heures;
    int minutes;

public:
    Horaire(int Heures = 0 , int minutes = 0 ){
        if(Heures >= 0 && Heures < 24)
            this->Heures = Heures;
        if(minutes >= 0 && minutes < 60)
            this->minutes = minutes;
    }
    Horaire toHoraire(int minutes) const {
        return Horaire(minutes / 60, minutes % 60);
    }    
    int toMinutes() const{
        return this->Heures * 60 + this->minutes;
    }
    Horaire & operator+ (int minutes){
        this->Heures = (this->Heures + (minutes/60)) % 24;
        this->minutes = (this->minutes + (minutes % 60)); 
        if(this->minutes / 60 > 0){
            int heureAjoute = this->minutes / 60;
            this->Heures = (this->Heures +  heureAjoute) % 24;
            this->minutes = this->minutes % 60;
        }
        return *this;
    }
    int operator- (const Horaire & H ) const{
        return abs(this->toMinutes() - H.toMinutes());
    }

    bool operator< ( const Horaire & H) const{
        if(this != &H){
            if(this->toMinutes() < H.toMinutes())
                return true;
            else 
                return false;
        }
        return false;
    }

    friend ostream & operator<<(ostream & OUT, const Horaire & H){
        OUT << H.Heures <<"h " << H.minutes << "min" << endl;
        return OUT;
    }
};
int main(){
    Horaire H1(16,30);
    Horaire H2 (12,15);
    
    // duree qui les separe 

        cout <<"Duree qui separe H2 et H1 est: " <<  H2 - H1 << "min" << endl;

    // ajout De minutes

     H1 = H1 + 45;
     cout << "H1: " <<  H1;

     H2 = H2 + 135;
     cout << "H2: " << H2;

    // comparaison
    if(H2 < H1)
        cout << "H2 precede H1!";
    else 
        cout << "H1 precede H2!";

        
    return 0;
}