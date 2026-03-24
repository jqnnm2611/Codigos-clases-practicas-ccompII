//ENCONTRAR UNA PALABRA EN UN ARRAY DE CARACTERES

#include <iostream>
using namespace std;

int main() {
    
    int tam = 12;
    char A[12] = {'e','n','s','a','m','a','h','o','l','a','d','u'};
    //char A[12] = {'e','n','s','a','m','a','h','r','l','a','d','u'};
    char B[4] = {'h','o','l','a'};
    int tam2 = sizeof(B)/sizeof(B[0]);
    
    bool hay = false;
    for(char* p = A; p <= A + tam - tam2; p++){
        char* q = p;
        char* r = B;
        for(;r < B + tam2 - 1; q++, r++){
            if(*q != *r)
                break;
        }
        if(*q == *r){
            hay = true;
            break;
        }
    }

    for(char* p = A; p < A + tam; p++)
        cout << *p << ",";
    cout << endl;
    
    if(hay) cout << "El array si contiene la palabra";
    else cout << "El array no contiene la palabra";
    
    return 0;
}
