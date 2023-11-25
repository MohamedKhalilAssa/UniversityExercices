#include <iostream>
using namespace std;

class Moteur{
    int PuisFisc;
public:
    Moteur(int puiss = 0){
        this->PuisFisc = puiss;
    }
    int GetPuis() const{
        return this->PuisFisc;
    }
    friend ostream & operator<< (ostream & OUT, const Moteur& M){
        OUT << "Moteur de puissance: " << M.PuisFisc;
        return OUT;
    }
};
class Roue{
    int DiamRoue;
    int LargRoue ;
public :
    Roue(int Diam = 0, int Larg = 0 ){
        this->DiamRoue = Diam;
        this->LargRoue = Larg;
    }
    void GetDims(int& diam, int& larg){
        diam = this->DiamRoue;
        larg = this->LargRoue;
    }
};
class Voiture {
    int NbPlaces;
    Moteur M;
    Roue R[5];
public:
    Voiture(Moteur M , Roue R[5] ,int place){
        this->NbPlaces = place;
        this->M = M;
        for(int i = 0; i < 5; i++)
            this->R[i] = R[i];
    }
    Voiture() : NbPlaces(0){
        // NbPlaces is set to 0, M is default-constructed, R is value-initialized to {0, 0, 0, 0, 0}
    }
    void Afficher (){
        cout << "La Voiture a : " << NbPlaces << " places\n" << this->M <<  "\net 5 roues";
    }
    int ComparerPF (const Voiture& V){
        if(this->M.GetPuis() > V.M.GetPuis())
            return 1;
        else if (this->M.GetPuis() < V.M.GetPuis())
            return -1;
        else
            return 0;
    }


};
class Garage {
    Voiture * pVoitures ;
    int NbVoitures ;

public:
    Garage(){
        this->NbVoitures  = 0;
        this->pVoitures = nullptr;
    }

    void Ajouter(Voiture V) {
        Voiture* temp = this->pVoitures;
        this->pVoitures = new Voiture[++this->NbVoitures];

        // Copy old data to the new array
        for (int i = 0; i < this->NbVoitures - 1; i++) {
            this->pVoitures[i] = temp[i];
        }

        // Add the new Voiture
        this->pVoitures[this->NbVoitures - 1] = V;

        // Deallocate the old array
        delete[] temp;
    }
    Voiture& comparer(){
        int index;
        for(int i = 0; i < this->NbVoitures - 1;i++){
            if(this->pVoitures[i].ComparerPF(this->pVoitures[i+1]) == 1){
                index = i;
            }
            else {
                index = i+1;
            }
        }
        return this->pVoitures[index];
    }
    ~Garage(){
        delete[] this->pVoitures;
    }
};
int main() {
    // Instantiate Moteur
    Moteur M1(5);
    Moteur M2(7);
    Moteur M3(6);
    Moteur M4(8);

    // Instantiate Roues
    Roue R1(5, 10);
    Roue R2(6, 11);
    Roue R3(7, 12);
    Roue R4(8, 13);
    Roue R5(9, 14);

    // Create arrays of Roues
    Roue Rt1[5] = {R1, R2, R3, R4, R5};
    Roue Rt2[5] = {R5, R4, R3, R2, R1};
    Roue Rt3[5] = {R3, R3, R3, R3, R3};
    Roue Rt4[5] = {R1, R2, R3, R4, R5};

    // Instantiate Voiture objects
    Voiture V1(M1, Rt1, 5);
    Voiture V2(M2, Rt2, 4);
    Voiture V3(M3, Rt3, 3);
    Voiture V4(M4, Rt4, 6);

    // Display information about each car
//    cout << "Car 1:\n";
//    V1.Afficher();
//    cout << "\n\nCar 2:\n";
//    V2.Afficher();
//    cout << "\n\nCar 3:\n";
//    V3.Afficher();
//    cout << "\n\nCar 4:\n";
//    V4.Afficher();

    // Instantiate Garage and add cars
    Garage G1;
    G1.Ajouter(V1);
    G1.Ajouter(V2);
    G1.Ajouter(V3);
    G1.Ajouter(V4);
    G1.comparer().Afficher();
    return 0;
}
