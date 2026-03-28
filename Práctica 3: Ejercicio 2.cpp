//PRACTICA 3: EJERCICIO 2
#include <iostream>
using namespace std;

int main() {
    
    int n = 10;
    int A[n] = {3,7,8,9,4,5,2,10,6,1};
    
    cout << "Array original: ";
    for(int* a = A; a < A + n; a++)
        cout << *a << ' ';
    cout << endl;
    
    for(int* p = A; p < A + n; p++){
        for(int* q = A; q < A + n - 1; q++){
            if(*q > *(q + 1)){
                int temp = *q;
                *q = *(q + 1);
                *(q + 1) = temp;
            }
        }
    }
    
    cout << "Array ordenado: ";
    for(int* a = A; a < A + n; a++)
        cout << *a << ' ';
    cout << endl;
    
    return 0;
}
