#include <iostream>
using namespace std;

//ALINEAR LOS CARACTERES DE UN ARRAY A LA DERECHA

int main()
{

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

    return 0;
}
