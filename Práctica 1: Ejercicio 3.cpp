#include <iostream>
using namespace std;

//REPLICA DE ENTEROS EN ARRAY

int main()
{
    
    int tam = 12;
    int A[tam] = {1,3,2,4,0,0,0,0,0,0,0,0};
    int n = 3;
    
    for(int* p = A; p < A + tam; p++)
        cout << *p << ',';
    cout << endl;
    
    int* a = A + tam - 1;
    while(*a == 0)
        a--;
    
    for(int* b = A + tam - 1; b >= A; b = b - n, a--){
        for(int* c = b; c > b - n; c--)
            *c = *a;
    }
    
    for(int* p = A; p < A + tam; p++)
        cout << *p << ',';
    cout << endl;

    return 0;
}
