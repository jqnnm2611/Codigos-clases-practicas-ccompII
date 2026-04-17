#include <iostream>
using namespace std;

void encontrar_cara(int* inicio, int* actual, int fila, int colu){
    if(actual < inicio || actual >= inicio + fila*colu)
        return;
    if(*actual != 1)
        return;
    *actual = 2;
    int pos = actual - inicio;
    int col = pos % colu;
    if(col < colu - 1)
        encontrar_cara(inicio, actual + 1, fila, colu);
    if(col > 0)
        encontrar_cara(inicio, actual - 1, fila, colu);
    if(actual + colu < inicio + fila*colu)
        encontrar_cara(inicio, actual + colu, fila, colu);
    if(actual - colu >= inicio)
        encontrar_cara(inicio, actual - colu, fila, colu);
    if(col < colu - 1 && actual + colu + 1 < inicio + fila*colu)
        encontrar_cara(inicio, actual + colu + 1, fila, colu);
    if(col > 0 && actual + colu - 1 < inicio + fila*colu)
        encontrar_cara(inicio, actual + colu - 1, fila, colu);
    if(col < colu - 1 && actual - colu + 1 >= inicio)
        encontrar_cara(inicio, actual - colu + 1, fila, colu);
    if(col > 0 && actual - colu - 1 >= inicio)
        encontrar_cara(inicio, actual - colu - 1, fila, colu);
}


int main() {
    
    //a)Elaborar un programa en C++ que represente un territorio con minas por medio de un   array 3D de enteros x ϵ {0,1}, donde grupos contiguos de unos representan una mina y números cero representan espacios sin mineral (celdas en blanco en la Fig.1)
    int cara = 3;
    int fila = 14;
    int colu = 8;
    int C[cara][fila][colu] = {{{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0},{0,1,0,1,0,0,0,1},{0,1,0,1,0,0,0,0},{0,1,1,0,0,0,0,0},{0,0,1,0,0,0,0,0},{0,0,0,1,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,1,0},{0,0,0,0,1,1,1,0},{0,0,0,0,0,0,0,0}}
                                ,{{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,1,0,1,0,0,0,0},{0,1,0,1,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,1,1,1,0},{0,0,0,0,0,0,0,0}}
                                ,{{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,1,0},{0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{1,0,0,0,0,0,0,1},{1,0,0,0,0,0,1,0},{1,0,0,0,0,0,1,0},{1,0,0,0,1,1,1,0},{0,0,0,0,0,0,0,0}}};
    
    //b)Elaborar un programa que imprima toda la matriz 3D en la pantalla, imprimiendo cada cara separada por un retorno de carro, cada fila de una cara en un renglón diferente de la pantalla
    for(int(*p)[fila][colu] = C; p < C + cara; p++){
        for(int(*q)[colu] = *p; q < *p + fila; q++){
            for(int* r = *q; r < *q + colu; r++)
                cout << *r << ' ';
            cout << endl;
        }
        cout << endl;
    }
    
    //c)Elaborar un programa que recorra una cara de la matriz 3D e imprima la cantidad de unos de dicha cara. En la Fig.1 para la primera cara debe imprimir 16
    int cont1 = 0;
    for(int* p = **C; p < **C + (fila*colu); p++){
        if(*p == 1)
            cont1++;
    }
    cout << cont1 << endl;
    cout << endl;
    
    //d)Elaborar un programa que recorra cada cara de la matriz 3D e imprima la cantidad de unos de cada cara. En la Fig.1 debe imprimir 16, 7, 12
    int cont2 = 0;
    for(int(*p)[fila][colu] = C; p < C + cara; p++){
        for(int(*q)[colu] = *p; q < *p + fila; q++){
            for(int* r = *q; r < *q + colu; r++)
                if(*r == 1)
                    cont2++;
        }
        cout << cont2 << ',';
        cont2 = 0;
    }
    cout << endl;
    cout << endl;
    
    //e)Elaborar un programa que recorra cada fila de una cara de la matriz 3D e imprima la cantidad de minas (grupos de unos contiguos) en cada fila. En la Fig.1 para la primera cara debe imprimir 1,3,2,1,1,1,1,1,1,1
    for(int(*q)[colu] = *C; q < *C + fila; q++){
        int minas_fila1 = 0;
        for(int* r = *q; r < *q + colu; r++){
            if(*r == 1){
                if(r == *q || *(r - 1) == 0)
                    minas_fila1++;
            }
        }
        if(minas_fila1 != 0)
            cout << minas_fila1 << ',';
    }
    cout << endl;
    cout << endl;
    
    //f)Elaborar un programa que recorra cada fila de cada cara de la matriz 3D e imprima la cantidad de minas (grupos de unos contiguos) en cada fila de cada cara. Los resultados de una fila en un renglón de la pantalla. En la Fig.1 debería imprimir: 1,3,2,1,1,1,1,1,1,1 - 2,2,1 - 1,1,2,2,2,2
    int minas_fila2 = 0;
    for(int(*p)[fila][colu] = C; p < C + cara; p++){
        for(int(*q)[colu] = *p; q < *p + fila; q++){
            for(int* r = *q; r < *q + colu; r++){
                if(*r == 1){
                    if(r == *q || *(r - 1) == 0)
                        minas_fila2++;
                }
            }
            if(minas_fila2 != 0)
                cout << minas_fila2 << ',';
            minas_fila2 = 0;
        }
        cout << endl;
    }
    cout << endl;
    
    //g)Elaborar un programa que recorra una cara de la matriz 3D e imprima la cantidad de minas (grupos de unos contiguos). En la Fig.1 para la primera cara debe imprimir 3
    int minas_cara1 = 0;
    int* inicio = **C;
    for(int* p = inicio; p < inicio + fila*colu; p++){
        if(*p == 1){
            minas_cara1++;
            encontrar_cara(inicio, p, fila, colu);
        }
    }
    for(int* p = **C; p < **C + (fila*colu); p++){
    if(*p == 2)
        *p = 1;
    }
    cout << minas_cara1 << endl;
    cout << endl;
    
    //h)Elaborar un programa que recorra cada cara de la matriz 3D imprima la cantidad de minas (grupos de unos contiguos) de cada cara. En la Fig.1 el programa debe mostrar como resultado 3,3,3.
    int minas_cara2 = 0;
    for(int(*p)[fila][colu] = C; p < C + cara; p++){
        int* inicio = **p;
        for(int* r = inicio; r < inicio + fila*colu; r++){
            if(*r == 1){
                minas_cara2++;
                encontrar_cara(inicio, r, fila, colu);
            }
        }
        cout << minas_cara2 << ',';
        minas_cara2 = 0;
        for(int* r = inicio; r < inicio + fila*colu; r++){
            if(*r == 2)
                *r = 1;
        }
    }
    cout << endl;
    cout << endl;
    
    
    return 0;
}
