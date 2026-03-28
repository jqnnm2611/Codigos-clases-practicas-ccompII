//PRACTICA 3: EJERCICIO 1
#include <iostream>
using namespace std;

int main() {
    
    int tam = 12;
    char A[tam] = {' ',' ',' ',' ','j','a','v','a',' ','+',' ',' '};
    
    for(char* d = A; d < A + tam; d++)
        cout << *d << ",";
    cout << endl;
    
    int espacios = 0;
    char* p = A;
    while(*p == ' '){
        espacios++;
        p++;
    }
    char* q = A + tam - 1;
    while(*q == ' '){
        espacios++;
        q--;
    }
    
    int espacios_final = espacios / 2;
    int temp = 0;
    char* a = A;
    while(temp != espacios_final){
        temp++;
        a++;
    }
    
    int temp2 = 0;
    char* b = A + tam - 1;
    while(temp2 != espacios_final){
        temp2++;
        b--;
    }
    b++;
    
    for(char* c = a; c <= b; c++){
    *c = *(c + 1);
    }
    
    for(char* d = A; d < A + tam; d++)
        cout << *d << ",";
    cout << endl;
    
    return 0;
}
