#include <iostream>
#include <memory>
using namespace std;

int main() {
    
    //Definición de un entero
    unique_ptr<int> p(new int(42));
    //unique_ptr<int> p = make_unique<int>(42);  <- es lo mismo que arriba
    int* q = p.get();
    cout << *p << endl;
    cout << *q << endl;
    
    //Definición de un array de enteros
    int n = 10;
    unique_ptr<int[]> A = make_unique<int[]>(n);   //Define un array de enteros, por eso <int[]>
    A[0] = 5;
    cout << A[0] << endl;
    for(int* q = A.get(); q < A.get() + n; q++)
        *q = 10;
    cout << A[5] << endl;
    
    //Definición de un array de arrays
    const int tam = 5;
    unique_ptr<unique_ptr<int>[]> B = make_unique<unique_ptr<int>[]>(tam);     //Define un array de punteros a enteros, por eso <unique_ptr<int>[]>
    for(unique_ptr<int>* q = B.get(); q < B.get()+tam; q++)
        *q = make_unique<int>(10);
    for(unique_ptr<int>* q = B.get(); q < B.get()+tam; q++)
        cout << **q << endl;
    
    return 0;
}
