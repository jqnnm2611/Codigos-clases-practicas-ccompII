#include <iostream>
using namespace std;

int mayorqueabs(int a, int b){
    if(a < 0) a = -a;
    if(b < 0) b = -b;
    return a > b;
}
int mayorque(int a, int b){
    return a > b;
}
int menorque(int a, int b){
    return a < b;
}

void BubbleSort(int A[], int n, int(*comp)(int, int)){
    int i, j, temp;
    for(i = 0; i < n; i++){
        for(j = 0; j < n - 1; j++){
            if(comp(A[j], A[j+1])){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main() {
    
    int(*q)(int, int);
    //q = mayorque;
    //q = menorque;
    //q = mayorqueabs;
    
    int tam_func = 3;
    int (*func[tam_func])(int, int) = {mayorque, menorque, mayorqueabs};
    int tam = 5;
    int A[] = {3, -1, 2, 6, -4};
    for(int(**p)(int, int) = func; p < func + tam_func; p++){
        BubbleSort(A, tam, *p);
        for(int* p = A; p < A + tam; p++)
            cout << *p << ',';
        cout << endl;
    }
    
    
    return 0;
}
