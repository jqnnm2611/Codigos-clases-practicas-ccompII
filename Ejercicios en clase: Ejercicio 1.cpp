//REDUCIR UN ARRAY SUMANDO N ENTEROS CONSECUTIVOS Y COLOCAR LAS SUMAS DE MANERA CONSECUTIVA. COLOCAR 0 EN LAS POSICONES RESTANTES

#include <iostream>
using namespace std;

int main() {
    
    int n = 7;
    int A[n] = {3,2,5,4,6,8,9};
    int m = 3;
    
    //imprimir
    for(int*a = A; a < A+n; a++)
        cout << *a << ',';
    cout << endl;
    
    
    //algoritmo
    for(int*p = A; p < A + n; p++){
        if(p > A+n-m)
            *p = 0;
        else{
            int suma = 0;
            for(int* q = p; q < p+m; q++)
                suma = suma + *q;
            *p = suma;
        }
    }
    
    //imprimir
    for(int*a = A; a < A+n; a++)
        cout << *a << ',';
    cout << endl;


    return 0;
}
