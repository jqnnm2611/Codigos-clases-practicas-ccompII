#include <iostream>
using namespace std;

int main() {
    
    int caras = 3;
    int filas = 2;
    int columnas = 3;
    int num = 1;
    
    //CON UN ARRAY
    /*
    int* B = new int[caras*filas*columnas];
    for(int* p = B; p < B + (caras*filas*columnas); p++){
        *p = num;
        num++;
    }
    for(int* i = B; i < B + (caras*filas*columnas); i += filas*columnas){
        for(int* j = i; j < i + columnas; j++)
            cout << *j << ' ';
        cout << endl;
    }
    delete[] B;
    */
    
    //CON VARIOS ARRAYS
    /*
    int*** B = new int**[caras];
    for(int*** p = B; p < B + caras; p++){
        *p = new int*[filas];
        for(int** q = *p; q < *p + filas; q++){
            *q = new int[columnas];
            for(int* r = *q; r < *q + columnas; r++){
                *r = num;
                num++;
            }
        }
    }
    
    for(int*** a = B; a < B + caras; a++){
        int** b = *a;
        for(int* c = *b; c < *b + columnas; c++)
            cout << *c << ' ';
        cout << endl;
    }
    
    for(int*** x = B; x < B + caras; x++){
        for(int** y = *x; y < *x + filas; y++)
            delete[] *y;
        delete[] *x;
    }
    delete[] B;
    */
    
    return 0;
}
