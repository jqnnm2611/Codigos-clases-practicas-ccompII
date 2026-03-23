#include <iostream>
using namespace std;

int main() {
    
    int tam = 12;
    char A[tam] = {' ',' ',' ',' ','j','a','v','a',' ','+',' ',' '};
    
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
        temp++;
        b--;
    }
    
    return 0;
}
