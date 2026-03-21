//VERIFICAR SI UN ARRAY DE CARACTERES TIENE AL MENOS UN PALINDROMO

#include <iostream>
using namespace std;

int main() {
    
    int n = 12;
    char A[12] = {'e','l',' ','a','l','a',' ','a','m','a',' ',' '};
    
    bool hay = false;
    for(char* p = A; p < A + n; p++){
        if(*p != ' '){
            char* q = p;
            char* r = p;
            while(*(r + 1) != ' ')
                r++;
            for(; q <= r; q++, r--){
                if(*q != *r)
                    break;
            }
            if(*q == *r)
                hay = true;
        }
    }
    
    for(char* p = A; p < A + n; p++)
        cout << *p << ",";
    cout << endl;
    
    if(hay) cout << "Hay al menos un palíndromo";
    else cout << "No hay ni un palíndromo";
    
    return 0;
}
