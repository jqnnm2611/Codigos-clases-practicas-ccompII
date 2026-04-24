#include <iostream>
using namespace std;

int main() {
    
    int filas = 5;
    int columnas = 5;
    int** A = new int*[filas];
    for(int** f = A; f < A + filas; f++){
        *f = new int[columnas];
    }
    for(int** a = A; a < A + filas; a++){
        for(int* b = *a; b < *a + columnas; b++){
            if(a == A || a == A + filas - 1)
                *b = -100;
            else{
                if(b == *a || b == *a + columnas - 1)
                    *b = -100;
                else
                    *b = 0;
            }
        }
    }
    *(*(A + 3) + 3) = 100;
    
    for(int** p = A; p < A + filas; p++){
        for(int* q = *p; q < *p + columnas; q++){
            if(*q == 0|| not(q == *p + columnas - 1))
                cout << ' ' << ' ' << ' ' << *q;
            else if (*q == 100)
                cout << ' '
            else 
                cout << *q << ' ';
        }
        cout << endl;
    }
    
    return 0;
}
