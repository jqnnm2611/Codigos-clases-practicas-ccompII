#include <iostream>
using namespace std;

class Iterator{
    int** p;
    public:
        friend class Matriz;
        Iterator(){ 
            p = nullptr;
        } 
        Iterator(int** itr){
            p = itr;
        }
        Iterator operator++(int){
            if(p == M)
        }
};

class Matriz{
    int fil;
    int col;
    int** M;
    public:
        Matriz(int x, int y){
            fil = x;
            col = y;
            M = new int*[fil];
            for(int** p = M; p < M + fil; p++)
                *p = new int[col];
        }
        ~Matriz(){
            for(int** p = M; p < M + fil; p++)
                delete[] *p;
            delete[] M;
        }
};

int main() {
    
    Matriz m1(4,5);
    
    return 0;
}
