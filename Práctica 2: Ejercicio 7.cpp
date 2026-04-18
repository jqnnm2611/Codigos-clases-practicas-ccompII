#include <iostream>
using namespace std;

int main() {
    
    int n = 6;
    int A[n] = {1,4,6,11,12,18};
    int B[n] = {0,1,2,3,4,5};
    
    int C[2*n];
    
    int* a = A;
    int* b = B;
    int* c = C;
    while(c < C + n){
        *c = *a;
        c++;
        a++;
    }
    while(c < C + 2*n){
        *c = *b;
        c++;
        b++;
    }
    
    for(int* p = C; p < C + 2*n; p++){
        for(int* q = C; q < C + 2*n - 1; q++){
            if(*q > *(q + 1)){
                int temp = *q;
                *q = *(q + 1);
                *(q + 1) = temp;
            }
        }
    }
    
    cout << "Array A:" << endl;
    for(int* d = A; d < A + n; d++)
        cout << *d << ' ';
    cout << endl;
    cout << "Array B:" << endl;
    for(int* d = B; d < B + n; d++)
        cout << *d << ' ';
    cout << endl;
    cout << "Array C:" << endl;
    for(int* d = C; d < C + 2*n; d++)
        cout << *d << ' ';
    cout << endl;
    
    return 0;
}
