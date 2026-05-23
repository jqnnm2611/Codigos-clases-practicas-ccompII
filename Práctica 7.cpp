#include <iostream>
using namespace std;

//D. Funciones Vertical y Horizontal
int* Vertical(int* x, int columnas){
    return x + columnas;
}
int* Horizontal(int* x, int){
    return x + 1;
}

//G. Clase Movimiento con sus métodos Vertical y Horizontal
class Movimiento{
    public:
    int* Vertical(int* x, int columnas){
        return x + columnas;
    }
    int* Horizontal(int* x, int){
        return x + 1;
    }
};

int main() {
    
    //A. Cree una matriz en stack en C++. Llene la matriz con números en orden ascendente a partir del número 1 (Ej. Ver Fig. 1)
    int filas = 12;
    int columnas = 5;
    int A[filas][columnas];
    int num = 1;
    for(int* p = *A; p < *A + (filas*columnas); p++, num++)
        *p = num;
    
    //B. Cree un programa que imprima la matriz en donde cada fila de la misma quede impresa en cada fila de la pantalla
    for(int(*p)[columnas] = A; p < A + filas; p++){
        for(int* q = *p; q < *p + columnas; q++){
            if(*q < 10) cout << ' ' << *q << ' ';
            else cout << *q << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    //C. Cree un array 1D en stack que almacene ceros y unos que representen la configuración de tipo de recorrido (0:Vertical y 1:Horizontal). Ej. 1,0,0,0,0,0,1,1,0,0,0,0,0,1 en este caso, primero tendrá un recorrido horizontal luego vertical a lo largo de 5 celdas consecutivas, luego, un recorrido horizontal a lo largo de 2 celdas sucesivas, luego un recorrido vertical a lo largo de 5 celdas consecutivas y finalmente recorrerá 1 celda de forma horizontal (recorrido de la Fig.1). Este array de configuración debe servir para acceder, de manera automática, utilizando los números como índices, a los punteros a método en el array de punteros a función descrito a continuación
    int tam_mov = 14;
    int B[tam_mov] = {1,0,0,0,0,0,1,1,0,0,0,0,0,1};
    
    //D. Cree un array para almacenar punteros a las funciones “Vertical” y “Horizontal”, las mismas que implementan dichos recorridos. Las funciones “Vertical” y “Horizontal” recibirán un puntero a la celda actual y se encargarán de avanzar el puntero hacia la celda correspondiente de acuerdo al recorrido, retornando dicho puntero actualizado. Para simplificar el ejercicio, las configuraciones nunca rebasarán los límites de la matriz. No hay necesidad de hacer esa validación
    int tam_f = 2;
    int* (*funciones[tam_f])(int*, int) = {Vertical, Horizontal};
    
    //E. Cree un programa que se encargue de realizar el recorrido completo de acuerdo al array de configuración y haciendo uso del array de punteros a función, sobre la matriz de forma que cada celda recorrida quede con el valor de 0
    int* a = *A;
    for(int* b = B; b < B + tam_mov; b++){
        int* (*f)(int*, int) = *(funciones + *b);
        a = f(a, columnas);
        *a = 0;
        /*int* (**f)(int*, int) = funciones;
        f += *b;
        a = (*f)(a, columnas);
        *a = 0;
        */
    }
    
    //F. Cree un programa que imprima la matriz con el recorrido resultante donde cada fila de la matriz quede impresa en cada fila de la pantalla
    for(int(*p)[columnas] = A; p < A + filas; p++){
        for(int* q = *p; q < *p + columnas; q++){
            if(*q < 10) cout << ' ' << *q << ' ';
            else cout << *q << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    //G. Cree una clase llamada “Movimiento” que tenga como métodos las funciones “Vertical” y “Horizontal”
    //Definida arriba
    
    //H. Cree otra versión del código elaborado en los puntos anteriores de forma que ahora funcione con punteros a los métodos de la clase “Movimiento” en lugar de punteros a función
    num = 1;
    for(int* p = *A; p < *A + (filas*columnas); p++, num++)
        *p = num;
    Movimiento mov;
    int tam_c = 2;
    int* (Movimiento::*metodos[tam_c])(int*, int) = {&Movimiento::Vertical,&Movimiento::Horizontal};
    int* c = *A;
    for(int* b = B; b < B + tam_mov; b++){
        int* (Movimiento::*m)(int*, int) = *(metodos + *b);
        c = (mov.*m)(c, columnas);
        *c = 0;
        /*int movActual = *b;
        int* (Movimiento::*(*m))(int*, int) = metodos;
        pm += movActual;
        c = (mov.*(*m))(c, columnas);
        *c = 0;
        */
    }
    for(int(*p)[columnas] = A; p < A + filas; p++){
        for(int* q = *p; q < *p + columnas; q++){
            if(*q < 10) cout << ' ' << *q << ' ';
            else cout << *q << ' ';
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}
