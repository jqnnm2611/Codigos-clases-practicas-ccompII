#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int* p = &a;
    
    cout << a << endl;
    cout << *p << endl;//contenido de lo que apunta
    
    int n = 5;
    int A[5] = {1,2,3,4,5};//puntero constante al primer elemento
    p = A;
    cout << p << endl;//direccion de memoria
    cout << *p << endl;//contenio de la primera posicion del array 
    cout << (p+1) << endl;//le suma un entero (4 bytes) 
    cout << *(p+1) << endl;
    cout << *(A+1) << endl;
    
    //indices
    for(int i = 0; i < n; i++)
        cout << A[i] << ",";
    cout << endl;
    
    //indices notacion de puntero
    for(int i = 0; i < n; i++)
        cout << *(A+i) << ",";//indexar con el 'i'
    cout << endl;
    
    //puntero (cuando apunto con el puntero a la posicion de memoria)
    for(int* p = A; p < A+n; p++)
        cout << *p << ",";
    cout << endl;

    
    //PRACTICA 1 
    //EJERCICIO 1: ALINEAR LOS CARACTERES DE UN ARRAY A LA DERECHA

    //solucion con indices
    int tam = 11;
    char A[11] = {'c','+','+',' ','j','a','v','a',' ',' ',' '};
    int i = tam - 1;
    int espacios = 0;
    while(A[i] == ' '){
        espacios++;
        i--;
    }
    
    for(int i = 0; i < tam; i++)
        cout << A[i] << ",";
    cout << endl;
    
    for(int i = tam - 1 - espacios; i >= 0; i--){
        A[i + espacios] = A[i]; 
        A[i] = ' ';
    }
    
    cout << espacios << endl;
    
    for(int i = 0; i < tam; i++)
        cout << A[i] << ",";
    cout << endl;

    
    //solucion con punteros (revisada por profe)
    int tam = 11;
    char A[11] = {'c','+','+',' ','j','a','v','a',' ',' ',' '};
    char* i = A + tam - 1;
    int espacios = 0;
    while(*i == ' '){
        espacios++;
        i--;
    }
    
    for(char* p = A; p < A + tam; p++)
        cout << *p << ",";
    cout << endl;
    
    for(char* p = A + tam - 1 - espacios; p >= A; p--){
        *(p + espacios) = *p; 
        *p = ' ';
    }
    
    cout << espacios << endl;
    
    for(char* p = A; p < A + tam; p++)
        cout << *p << ",";
    cout << endl;


    //EJERCICIO 2: REDUCCION DE ARRAYS POR GRUPOS (completar)
    int n = 11;
    int A[n] = {3,1,0,-5,2,3,4,2,0,1,5};
    for(int* p = A; p < A + n; p++)
        cout << *p << ",";
    cout << endl;
    
    int m = 3;
    
    for(int* p = A; p < A + n; p = p + m){
        int suma = 0;
        for(int* q = p; q < p + m; q++){
            if(q >= A + n){
                suma = 0;
                break;
            }
            suma = suma + *q;
        }
        cout << suma << endl;
    }

    return 0;
}
