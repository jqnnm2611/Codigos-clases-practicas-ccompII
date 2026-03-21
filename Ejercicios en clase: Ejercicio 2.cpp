//ELIMINAR NUMEROS CONSECUTIVOS IGUALES HASTA QUE YA NO QUEDEN MÁS ENTEROS CONSECUTIVOS IGUALES. COLOCAR 0 EN LAS POSICIONES RESTANTES

#include <iostream>
using namespace std;

int main() {
    
    int n = 7;
    int A[n] = {1,3,2,2,1,1,3};
    
    //imprimir
    for(int*a = A; a < A+n; a++)
        cout << *a << ',';
    cout << endl;
    
    
    //algoritmo
    bool rdc = true;
    while(rdc){
        //rdc = false;
        for(int*p = A; p < A + n; p++){
            int* q = p + 1;
            if(*q != *p)
                continue;
            else{
                while(*q == *p)
                    q++;
                for(; q >= p; q--)
                    *q = 0;
            }
        }
        
    }
    
    //imprimir
    for(int*a = A; a < A+n; a++)
        cout << *a << ',';
    cout << endl;


    return 0;
}
