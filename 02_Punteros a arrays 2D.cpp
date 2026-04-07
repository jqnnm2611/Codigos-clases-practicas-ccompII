#include <iostream>
using namespace std;

int main() {
    
    int fil = 3;
    int col = 4;
    int B[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    
    /*
    int col_temp = 0;
    for(int* p = *B; p < *B + (fil*col); p = p + col){
        if(p + col >= *B + (fil*col)){
            cout << *p << endl;
            p = p + col_temp + 1;
        }
        else
            cout << *p << ' ';
    }
    */
    
    int* p = *B;
    int x = 0;
    bool flag = true;
    while(flag){
        if(p == *B + (fil*col) - 1){
            cout << *p;
            flag = false;
        }
        else if(p + col >= *B + (fil*col)){
            cout << *p << endl;
            x++;
            p = *B + x;
        }
        else{
            cout << *p << ' ';
            p = p + col;
        }
    }
    
    return 0;
}
