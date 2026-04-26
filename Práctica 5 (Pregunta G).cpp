#include <iostream>
using namespace std;

int main() {
    
    int filas;
    int columnas;
    cout << "Ingresa número de filas: ";
    cin >> filas;
    cout << "Ingresa número de columnas: ";
    cin >> columnas;
    cout << endl;
    
    int*** A = new int**[filas];
    for(int*** f = A; f < A + filas; f++){
        *f = new int*[columnas];
        for(int** c = *f; c < *f + columnas; c++)
            *c = new int[2];
    }
    
    for(int*** a = A; a < A + filas; a++){
        for(int** b = *a; b < *a + columnas; b++){
            if(a == A || a == A + filas - 1)
                *(*b + 0) = -100;
            else{
                if(b == *a || b == *a + columnas - 1)
                    *(*b + 0) = -100;
                else
                    *(*b + 0) = 0;
            }
            *(*b + 1) = 0;
        }
    }
    
    int fil_ini;
    int col_ini;
    cout << "Ingresa fila de inicio (entre " << filas - (filas - 1) << " y " << filas - 2 << " ): ";
    cin >> fil_ini;
    cout << "Ingresa columna de inicio (entre " << columnas - (columnas - 1) << " y " << columnas - 2 << " ): ";
    cin >> col_ini;
    cout << endl;
    
    int fil_dest;
    int col_dest;
    cout << "Ingresa fila de destino (entre " << filas - (filas - 1) << " y " << filas - 2 << " ): ";
    cin >> fil_dest;
    cout << "Ingresa columna de destino (entre " << columnas - (columnas - 1) << " y " << columnas - 2 << " ): ";
    cin >> col_dest;
    cout << endl;
    *(*(*(A + fil_dest) + col_dest) + 0) = 100;
    
    cout << "MATRIZ INICIAL:" << endl;
    for(int*** p = A; p < A + filas; p++){
        for(int** q = *p; q < *p + columnas; q++){
            if(*(*q + 0) == 0)
                cout << ' ' << ' ' << ' ' << *(*q + 0) << ',' << *(*q + 1) << ' ';
            else if (*(*q + 0) == 100)
                cout << ' ' << *(*q + 0) << ',' << *(*q + 1) << ' ';
            else if(*(*q + 0) < 100 && *(*q + 0) > 0)
                cout << ' ' << ' ' << *(*q + 0) << ',' << *(*q + 1) << ' ';
            else 
                cout << *(*q + 0) << ',' << *(*q + 1) << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    for(int pol_aux = 0; pol_aux < filas * columnas; pol_aux++){
        for(int*** i = A + (filas-2); i > A; i--){
            for(int** j = *i + (columnas-2); j > *i; j--){
                if(i == A + fil_dest && j == *i + col_dest)
                    continue;
                int* arriba = *(*(i - 1) + (j - *i));
                int* abajo = *(*(i + 1) + (j - *i));
                int* derecha = *(j + 1);
                int* izquierda = *(j - 1);
                int mayor = *arriba;
                int politica = 2;
                if(*abajo > mayor){
                    mayor = *abajo;
                    politica = 1;
                }
                if(*derecha > mayor){
                    mayor = *derecha;
                    politica = 3;
                }
                if(*izquierda > mayor){
                    mayor = *izquierda;
                    politica = 4;
                }
                **j = mayor - 1;
                *(*j + 1) = politica;
            }
        }
    }
    
    cout << "MATRIZ CON POLÍTICA Y RECOMPENSAS:" << endl;
    for(int*** p = A; p < A + filas; p++){
        for(int** q = *p; q < *p + columnas; q++){
            if(*(*q + 0) == 0)
                cout << ' ' << ' ' << ' ' << *(*q + 0) << ',' << *(*q + 1) << ' ';
            else if (*(*q + 0) == 100)
                cout << ' ' << *(*q + 0) << ',' << *(*q + 1) << ' ';
            else if(*(*q + 0) < 100 && *(*q + 0) > 0)
                cout << ' ' << ' ' << *(*q + 0) << ',' << *(*q + 1) << ' ';
            else 
                cout << *(*q + 0) << ',' << *(*q + 1) << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    int*** filaActual = A + fil_ini;
    int col = col_ini;
    int** ini1 = *filaActual + col;
    int** ptrE = ini1;
    while(**ptrE != 100){
        if(*(*ptrE + 1) == 1){
            **ptrE = 0;
            filaActual++;
            ptrE = *filaActual + col;
        }
        else if(*(*ptrE + 1) == 2){
            **ptrE = 0;
            filaActual--;
            ptrE = *filaActual + col;
        }
        else if(*(*ptrE + 1) == 3){
            **ptrE = 0;
            ptrE++;
            col++;
        }
        else if(*(*ptrE + 1) == 4){
            **ptrE = 0;
            ptrE--;
            col--;
        }
    }
    **ptrE = 0;
    
    cout << "MATRIZ CON CAMINO:" << endl;
    for(int*** p = A; p < A + filas; p++){
        for(int** q = *p; q < *p + columnas; q++){
            if(*(*q + 0) == 0)
                cout << ' ' << ' ' << ' ' << *(*q + 0) << ',' << *(*q + 1) << ' ';
            else if (*(*q + 0) == 100)
                cout << ' ' << *(*q + 0) << ',' << *(*q + 1) << ' ';
            else if(*(*q + 0) < 100 && *(*q + 0) > 0)
                cout << ' ' << ' ' << *(*q + 0) << ',' << *(*q + 1) << ' ';
            else 
                cout << *(*q + 0) << ',' << *(*q + 1) << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    for(int*** a = A; a < A + filas; a++){
        for(int** b = *a; b < * a + columnas; b++)
            delete[] *b;
        delete[] *a;
    }
    delete[] A;
    
    return 0;
}
