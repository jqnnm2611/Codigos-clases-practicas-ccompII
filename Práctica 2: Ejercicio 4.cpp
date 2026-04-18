#include <iostream>
using namespace std;

int main() {
    
    int n = 11;
    char A[n] = {'c','+','+',' ','j','a','v','a','c','+','+'};
    int m = 3;
    char B[m] = {'c','+','+'};
    
    cout << "Array original:" << endl;
    for(char* p = A; p < A+n; p++)
        cout << *p;
    cout << '_' << endl;
    
    for(char* a = A; a <= A + n - m; a++){
        char* p = a;
        char* q = B;
        int contador = 0;
        
        while(q < B + m && *p == *q){
            p++;
            q++;
            contador++;
        }
        
        if(contador == m){
            char* borrar = a;
            for(int i = 0; i < m; i++){
                *borrar = ' ';
                borrar++;
            }
        }
    }
    
    char* esp = A;
    int espacios = 0;
    while(*esp == ' '){
        espacios++;
        esp++;
    }
    for(; esp < A + n; esp++){
        *(esp-espacios) = *esp;
        *esp = ' ';
    }
    
    cout << "Array modificado:" << endl;
    for(char* p = A; p < A+n; p++)
        cout << *p;
    cout << '_' << endl;
    
    return 0;
}
