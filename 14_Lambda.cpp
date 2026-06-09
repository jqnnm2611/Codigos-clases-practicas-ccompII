#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    for(auto x:v) cout << x << ' ';
    cout << endl;
}

int main() {
    
    // tipo de dato<auto>  Nombre de la función = [acceso](parámetros) ->tipo de dato a retornar<opcional> {cuerpo de la función};
    auto sumar = [](int a, int b){
        return a+b;
    };
    sumar(3,4);
    
    //para el acceso se tiene:
    //= : captura todas las variables por copia
    //& : captura todas las variables por referencia
    //x, &x : se puede capturar cada variable por copia o por referencia en simultáneo con otras. Por ejemplo: [x, &y]
    
    
    vector<int> v1, v2, v3;
    
    auto porRef = [&](int m){
        v1.push_back(m);
        v2.push_back(m);
        v3.push_back(m);
    };
    
    //se usa la palabra 'mutable' cuando se acceda por valor [=]
    auto porVal = [=](int m) mutable {
        v1.push_back(m);
        v2.push_back(m);
        v3.push_back(m);
    };
    
    auto porMix = [=, &v1](int m) mutable {
        v1.push_back(m);
        v2.push_back(m);
        v3.push_back(m);
    };
    
    porRef(9); //modifica el vector
    porVal(20); //crea una copia y modifica esa
    porMix(100); //el v1 fue el unico modificado porque se accedió por referencia
    porMix(12);
    
    print(v1);
    print(v2);
    print(v3);
    
    //lambda definida como parámetro en el momento
    auto it = find_if(v1.begin(), v1.end(), [](const int& a){
        return a%3 == 0;
    });
    
    cout << *it << ' ' << endl;
    cout << endl;
    
    //lambda en transform
    int tam = 5;
    int arr[] = {1,2,3,4,5};
    transform(arr, arr+tam, arr, [](const int &x){
        return x*x*x;
    });
    for(int* p = arr; p < arr+tam; p++)
        cout << *p << ' ';
    cout << endl;
    
    return 0;
}
