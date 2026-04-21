//ARRAYS 2D Y PUNTEROS EN MEMORIA DINÁMICA
#include <iostream>
using namespace std;

int main() {
    
    //Un solo array (primera forma)
    int filas = 3;
    int columnas = 3;
    int* matriz = new int[filas*columnas];
    int dato = 1;
    for(int*p = matriz; p < matriz + (filas*columnas); p++){
        *p = dato;
        dato++;
    }
    cout << "Matriz traspuesta: " << endl; 
    for(int* a = matriz; a < matriz + columnas; a++){
        for(int* b = a; b < matriz + (filas*columnas); b+=columnas)
            cout << *b << ',';
        cout << endl;
    }
    delete[] matriz;
    
    //Con varios arrays (segunda forma)
    int filas = 3;
    int columnas = 3;
    int dato = 1;
    int** matriz = new int*[filas];
    for(int** c = matriz; c < matriz + filas; c++){
        *c = new int[columnas];
        for(int* d = *c; d < *c + columnas; d++){
            *d = dato;
            dato++;
        }
    }
    
    //Versión mía
    cout << "Matriz traspuesta: " << endl;
    for(int* e = *matriz; e < *matriz + columnas; e++){
        for(int** f = matriz; f < matriz + filas; f++)
            cout << *(*f + (e - *matriz)) << ' ';
        cout << endl;
    }
    
    //Versión profe
    cout << "Matriz traspuesta: " << endl;
    for(int col = 0; col < columnas; col++){
        for(int** e = matriz; e < matriz + filas; e++){
            int* f = *e + col;
            cout << *f << ' ';
        }
        cout << endl;
    }
    
    for(int** g = matriz; g < matriz + filas; g++)
            delete[] *g;
    delete[] matriz;
        
    
    return 0;
}
