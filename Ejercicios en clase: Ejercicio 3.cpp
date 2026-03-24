//ENCONTRAR UNA PALABRA EN UNA MATRIZ DE CARACTERES (BÚSQUEDA POR FILAS)

#include <iostream>
using namespace std;

int main() {
    
    int fil = 6;
    int col = 6;
    char A[6][6] = {
        {'e','s','u','c','a','n'},
        {'p','o','t','g','u','y'},
        {'b','w','y','j','f','o'},
        {'i','l','d','i','a','s'},
        {'z','f','k','q','n','a'},
        {'a','e','h','p','c','r'},
    };
    
    /*char A[6][6] = {
        {'e','s','u','c','a','n'},
        {'p','o','t','g','u','y'},
        {'b','w','y','j','f','o'},
        {'i','l','d','o','a','s'},
        {'z','f','k','q','n','a'},
        {'a','e','h','p','c','r'},
    };*/
    
    char B[3] = {'d','i','a'};
    int tam2 = sizeof(B)/sizeof(B[0]);
    
    bool hay = false;
    for(char (*p)[6] = A; p < A + fil; p++){
        for(char* a = *p; a < *p + col; a++){
            char* b = a;
            char* c = B;
            for(; c < B + tam2 - 1; b++, c++){
                if(*b != *c)
                    break;
            }
            if(*b == *c){
                hay = true;
                break;
            }
        }
    }
    
    for(char (*p)[6] = A; p < A + fil; p++){
        for(char* a = *p; a < *p + col; a++)
            cout << *a << ' ';
        cout << endl;
    }
    cout << "Palabra: ";
    for(char* p = B; p < B + tam2; p++)
        cout << *p;
    cout << endl;
    
    if(hay) cout << "El array si contiene la palabra";
    else cout << "El array no contiene la palabra";
    
    return 0;
}
