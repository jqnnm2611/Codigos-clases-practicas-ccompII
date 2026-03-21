//ELIMINAR NUMEROS CONSECUTIVOS IGUALES HASTA QUE YA NO QUEDEN MÁS ENTEROS CONSECUTIVOS IGUALES. COLOCAR 0 EN LAS POSICIONES RESTANTES

#include <iostream>
using namespace std;

int main() {
    
    int n = 11;
    int A[n] = {1,4,2,2,1,1,4,3,3,3,4};
    
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
            else if(*q == *p){
                while(*q == *p && q < A + n)
                    q++;
                q--;
                for(; q >= p; q--)
                    *q = 0;
            }
        }
        
        for(int* a = A; a < A + n; a++){
            if(*a == 0){
                for(int* b = a; b < A + n; b++){
                    int temp = *b;
                    *b = *(b + 1);
                    *(b + 1) = temp;
                }
            }
        }
        
        //imprimir
        for(int*a = A; a < A+n; a++)
            cout << *a << ',';
        cout << endl;
        
        for(int* c = A; c < A + n; c++){
            if(*c == *(c + 1) && *c != 0)
                break;
            else if(*c == *(c + 1) && *c == 0){
                rdc = false;
                break;
            }
        }
        
    }
    
    //imprimir
    for(int*a = A; a < A+n; a++)
        cout << *a << ',';
    cout << endl;


    return 0;
}
