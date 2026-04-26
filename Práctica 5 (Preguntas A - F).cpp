#include <iostream>
using namespace std;

int main() {
    
//A. Cree un array dinámico 2D implementado con varios arrays (2da forma) que represente el grid de la Fig. 1.
    int filas = 14;
    int columnas = 7;
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
    *(*(A + 12) + 5) = 100;
    /*
    for(int** p = A; p < A + filas; p++){
        for(int* q = *p; q < *p + columnas; q++){
            if(*q == 0)
                cout << ' ' << ' ' << ' ' << *q << ' ';
            else if (*q == 100)
                cout << ' ' << *q << ' ';
            else 
                cout << *q << ' ';
        }
        cout << endl;
    }
    cout << endl;
    */
    for(int** a = A; a < A + filas; a++)
            delete[] *a;
    delete[] A;
    
//B. Modifique el array anterior para que contenga arrays de 2 posiciones en cada celda de la matriz para almacenar enteros. El primer entero será la recompensa que se muestra en la Fig. 1.
    int*** B = new int**[filas];
    for(int*** f = B; f < B + filas; f++){
        *f = new int*[columnas];
        for(int** c = *f; c < *f + columnas; c++)
            *c = new int[2];
    }
    for(int*** a = B; a < B + filas; a++){
        for(int** b = *a; b < *a + columnas; b++){
            if(a == B || a == B + filas - 1)
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
    *(*(*(B + 12) + 5) + 0) = 100;
    /*
    for(int*** p = B; p < B + filas; p++){
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
    */
    
//C. Cree un programa que recorra el array 2D desde la posición destino (verde) de derecha a izquierda y de abajo hacia arriba celda por celda.
    for(int*** i = B + 12; i > B; i--){
        for(int** j = *i + 5; j > *i; j--){}
    }
    
//D. Dentro del recorrido anterior cree un algoritmo que identifique, entre las celdas inmediatamente inferior y la siguiente a la derecha de la celda actual, cuál es la que tiene mayor recompensa. Luego debe remplazar en el primer entero del array de 2 posiciones de dicha celda, con el mayor valor menos 1 (lo cual indica que la recompensa es menor mientras más pasos el agente utilice) y en la segunda posición del array, colocar la política, es decir, la celda que tuvo mayor valor, con el siguiente detalle: 1: “Abajo”, 2: “Arriba”, 3: “Derecha”, 4: “Izquierda”.
    for(int*** i = B + 12; i > B; i--){
        for(int** j = *i + 5; j > *i; j--){
            if(i == B + 12 && j == *i + 5)
                continue;
            int* abajo = *(*(i + 1) + (j - *i));
            int* derecha = *(j + 1);
            if(*abajo > *derecha){
                **j = *abajo - 1;
                *(*j + 1) = 1;
            }
            else{
                **j = *derecha - 1;
                *(*j + 1) = 3;
            }
        }
    }
    for(int*** p = B; p < B + filas; p++){
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
    
//E. Finalmente, recorra cada celda de la matriz que se encuentre en la ruta calculada, comenzando desde la celda origen y avanzando de acuerdo a la “política”, colocando ceros en el miembro dato “recompensa” en cada una de las celdas por las que pasa, hasta llegar a la celda destino.
    int*** filaActual = B + 1;
    int col = 1;
    int** ini1 = *filaActual + col;
    int** fin1 = *(B + 12) + 5;
    int** ptrE = ini1;
    while(**ptrE != 100){
        if(*(*ptrE + 1) == 1){
            **ptrE = 0;
            filaActual++;
            ptrE = *filaActual + col;
        }
        else if(*(*ptrE + 1) == 3){
            **ptrE = 0;
            ptrE++;
            col++;
        }
    }
    
//F. Imprima tanto la matriz original con sus recompensas y la matriz final con ceros en la recompensa, mostrando el recorrido. Las Impresiones del array deben ser cada fila en una línea diferente en la pantalla.

    //La matriz original con sus recompensas ya se imprimió en la pregunta D.
    for(int*** p = B; p < B + filas; p++){
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
    
    //Borrar memoria
    for(int*** a = B; a < B + filas; a++){
        for(int** b = *a; b < * a + columnas; b++)
            delete[] *b;
        delete[] *a;
    }
    delete[] B;

    return 0;
}
