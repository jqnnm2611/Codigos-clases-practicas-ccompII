//ENCONTRAR UNA PALABRA EN UNA MATRIZ DE CARACTERES (BÚSQUEDA POR COLUMNAS)

#include <iostream>
using namespace std;

int main() {
    
    int fil = 6;
    int col = 6;
    char A[6][6] = {
        {'e','s','u','c','a','n'},
        {'p','o','t','g','u','y'},
        {'b','w','d','j','f','o'},
        {'i','l','i','y','k','s'},
        {'z','f','a','q','n','a'},
        {'a','e','h','p','c','r'},
    };
    
    /*char A[6][6] = {
        {'e','s','u','c','a','n'},
        {'p','o','t','g','u','y'},
        {'b','w','d','j','f','o'},
        {'i','l','j','y','k','s'},
        {'z','f','a','q','n','a'},
        {'a','e','h','p','c','r'},
    };*/
    
    char B[3] = {'d','i','a'};
    int tam2 = sizeof(B)/sizeof(B[0]);
    
    bool hay = false;
    int col_actual = 0;
    for(char (*p)[6] = A; p <= A + fil - tam2 + 1; p++){
        char* p2 = *p;
        if(p = A + fil - tam2 + 1){
            
        }
        
        char* q = *p;
        char* r = B;
        for(; r < B + tam2 - 1; r++, q = q + fil){
            if(*q != *r)
                break;
        }
        if(*q == *r){
            hay = true;
            break;
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
