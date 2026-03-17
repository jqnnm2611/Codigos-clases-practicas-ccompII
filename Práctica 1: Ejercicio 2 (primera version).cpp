#include <iostream>
using namespace std;

//REDUCCION DE ARRAYS POR GRUPOS (completar)

int main()
{
  int n = 11;
    int A[n] = {3,1,0,-5,2,3,4,2,0,1,5};
    for(int* p = A; p < A + n; p++)
        cout << *p << ",";
    cout << endl;
    
    int m = 3;
    
    for(int* a = A; a < A + n; a++){
        for(int* p = A; p < A + n; p = p + m){
            int suma = 0;
            for(int* q = p; q < p + m; q++){
                if(q >= A + n){
                    suma = 0;
                    break;
                }
                suma = suma + *q;
            }
            //*a = suma;
        }
    }
    
    for(int* p = A; p < A + n; p++)
        cout << *p << ",";
    cout << endl;

    return 0;
}
