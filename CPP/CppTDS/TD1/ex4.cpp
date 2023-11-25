#include <iostream> 
using namespace std;

class Fifo{
    int size ; // nbr d'elements
    int  head ; //index de tete 
    int capacity;
    double *tab;
    public: 
        Fifo(int capacity){
            this->capacity = capacity;
            this->tab = new double[this->capacity];
            this->head = 0;
            this->size = 0;
        }
        bool isFull(){
            return this->size == this->capacity; 
        }
        bool isEmpty(){
            return this->size == 0;
        }
        void add(double val){
            if(isFull()){
                cout << "File Pleine !!";
                return;
            }

            int index = (this->head + this->size ) % this->capacity;
            
            if(this->head + this->size > this->capacity){
                index = (this->head + this->size ) - this->capacity;
            }
            
            this->tab[index] = val;
            this->size++ ;
        }
        void remove(){
            if(isEmpty()){
                cout << "File VIDE !!";
                return;
            }
            this->head++;
            this->size--;
        }
        void print(){
            int index = head;
            for(int i = 0 ; i < size ; i ++){
                 if(index == capacity ) 
                     index = 0;
                cout << this->tab[index++] << " ";
            }
            cout << endl ;
        }
};
int main(){

    Fifo F1(10);
    F1.add(12);
    F1.add(2);
    F1.add(3);
    F1.add(4);
    F1.add(5);
    F1.add(6);
    F1.print();
    F1.remove();
    F1.print();
     F1.add(12);
    F1.add(2);
    F1.add(3);
    F1.add(4);
    F1.add(5);
    F1.print();
     F1.remove();
    F1.add(100);
        F1.print();

    return 0;
}