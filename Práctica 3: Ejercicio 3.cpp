#include <iostream>
using namespace std;

int main(){
    
    int n = 11;
    char A[n] = {'c','+','+',' ','j','a','v','a',' ',' ',' '};
    //char A[n] = {' ','c','+','+',' ','j','a','v','a',' ',' '};
    //char A[n] = {'c','+','+',' ',' ',' ',' ','j','a','v','a'};
    
    for(char* d = A; d < A + n; d++)
        cout << *d << ",";
    cout << endl;

    char* p = A;
    while(*p == ' '){
        p++;
    }
    char* q = A + n - 1;
    while(*q == ' '){
        q--;
    }
    
    if(p != A){
        char* b = p;
        while(*b != ' ')
            b++;
        
        char* p_temp = A;
        for(; p < b; p++, p_temp++){
            char temp = *p;
            *p = *p_temp;
            *p_temp = temp;
        }
    }
    
    if(q != A + n - 1){
        char* c = A;
        while(*c != ' ')
            c++;

        char* q_temp = A + n - 1;
        for(; q > c; q--, q_temp--){
            char temp = *q;
            *q = *q_temp;
            *q_temp = temp;
        }
    }
    
    for(char* d = A; d < A + n; d++)
        cout << *d << ",";
    cout << endl;
    
    return 0;
}
