#include <iostream>
using namespace std;

int main() {
    
    int x = 2;
    int y = 2;
    int z = 3;
    int C[x][y][z] = {{{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};

    //imprimir las primeras filas de cada cara  
    for(int(*p)[y][z] = C; p < C + x; p++){
        int(*q)[z] = *p;
        for(int* r = *q; r < *q + z; r++)
            cout << *r << ' ';
        cout << endl;
    }
    
    return 0;
}
