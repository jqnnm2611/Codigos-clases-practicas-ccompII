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

    return 0;
}
