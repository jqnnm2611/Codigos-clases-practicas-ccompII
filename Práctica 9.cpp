#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template<class T>
bool ascendente_fun(T a, T b){
    return a > b;
}

template<class T>
class ascendente_ftr{
    public:
        bool operator()(T a, T b){
            return a > b;
        }
};

template<class T>
auto ascendente_lbd = [](T a, T b){return a > b;};







template<class T, class C>
void ordenamiento(T* vector, int tam, C criterio){
    T temp;
    for(T* p = vector; p < vector + tam; p++){
        for(T* q = vector; q < vector + tam; q++){
            if(criterio(*q, *(q+1))){
                temp = *q;
                *q = *(q+1);
                *(q+1) = temp;
            }
        }
    }
}

int main() {
    
    srand(time(0));
    int tam = 100;
    int A[tam];
    for(int* p = A; p < A + tam; p++)
        *p = rand() % 99;
    int(*pf) (int, int) = ascendente_fun;
    
    
    
    return 0;
}






















