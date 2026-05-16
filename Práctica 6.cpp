#include <iostream>
#include <memory>
using namespace std;

int main() {
    
    //A. Realice los ejercicios de la Práctica 2 con Smart Pointers
    
    //1. ELIMINAR NUMEROS CONSECUTIVOS IGUALES HASTA QUE YA NO QUEDEN MÁS ENTEROS CONSECUTIVOS IGUALES. COLOCAR 0 EN LAS POSICIONES RESTANTES (revisar)
    const int tam1 = 8;
    unique_ptr<int[]> A = make_unique<int[]>(new int[]{6,4,4,2,9,9,9,1});
    
    bool iguales = true;
    while(iguales){
        bool verificar = true;
        for(int* a = A.get(); a < A.get() + tam1; a++){
            if(*q == *(q+1) && *q != 0){
                verificar = false;
            }
        }
    }
    
    
    
    //2. VERIFICAR SI UN ARRAY DE CARACTERES TIENE AL MENOS UN PALINDROMO
    int n2 = 12;
    unique_ptr<char[]> B = make_unique<char[]>(n2);
    B[0] = 'e';
    B[1] = 'l';
    B[2] = ' ';
    B[3] = 'a';
    B[4] = 'l';
    B[5] = 'a';
    B[6] = ' ';
    B[7] = 'a';
    B[8] = 'm';
    B[9] = 'a';
    B[10] = ' ';
    B[11] = ' ';

    bool hay = false;
    
    for(char* p = B.get(); p < B.get() + n2; p++){
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
    
    for(char* p = B.get(); p < B.get() + n2; p++)
        cout << *p << ",";
    cout << endl;
    
    if(hay) cout << "Hay al menos un palíndromo" << endl;
    else cout << "No hay ni un palíndromo" << endl;
    
    
    //3. CENTRAR EL ARRAY CON IGUALES ESPACIOS AL INICIO Y AL FINAL
    
    
    
    //4. ELIMINAR UNA PALABRA 'M' DE UN ARRAY DE CARACTERES Y ALINEAR A LA IZQUIERDA
    int n4 = 11;
    unique_ptr<char[]> D = make_unique<char[]>(n4);
    D[0] = 'c';
    D[1] = '+';
    D[2] = '+';
    D[3] = ' ';
    D[4] = 'j';
    D[5] = 'a';
    D[6] = 'v';
    D[7] = 'a';
    D[8] = 'c';
    D[9] = '+';
    D[10] = '+';
    int m4 = 3;
    unique_ptr<char[]> D_pal = make_unique<char[]>(m4);
    D_pal[0] = 'c';
    D_pal[1] = '+';
    D_pal[2] = '+';
    
    cout << "Array original:" << endl;
    for(char* d = D.get(); d < D.get() + n4; d++)
        cout << *d;
    cout << '_' << endl;
    
    for(char* d = D.get(); d <= D.get() + n4 - m4; d++){
        char* p4 = d;
        char* q4 = D_pal.get();
        int contador = 0;
        
        while(q4 < D_pal.get() + m4 && *p4 == *q4){
            p4++;
            q4++;
            contador++;
        }
        
        if(contador == m4){
            char* borrar = d;
            for(int i = 0; i < m4; i++){
                *borrar = ' ';
                borrar++;
            }
        }
    }
    
    char* esp = D.get();
    int espacios = 0;
    while(*esp == ' '){
        espacios++;
        esp++;
    }
    for(; esp < D.get() + n4; esp++){
        *(esp-espacios) = *esp;
        *esp = ' ';
    }
    
    cout << "Array modificado:" << endl;
    for(char* d = D.get(); d < D.get() + n4; d++)
        cout << *d;
    cout << '_' << endl;
    
    
    
    return 0;
}
