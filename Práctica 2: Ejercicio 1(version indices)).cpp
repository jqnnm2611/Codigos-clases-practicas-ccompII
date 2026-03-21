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
    int i = 0;//inicio repetidos
    int j = 1;//fin repetidos
    
    while(i != n){
        if(A[i] != A[j]){
            i++;
            j++;
        }
        else{
            while(A[i] == A[j] && j != n-1) //posiciona al final de los repetidos
                j++;
            int k = i;
            while(j != n){ //mover los enteros posteriores
                A[k] = A[j];
                k++;
                j++;
            }
            while(k != n){
                A[k] = 0;
                k++;
            }
            j = i+1;
        }
    }
    
    
    //imprimir
    for(int*a = A; a < A+n; a++)
        cout << *a << ',';
    cout << endl;


    return 0;
}
