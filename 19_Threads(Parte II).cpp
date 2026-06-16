#include <iostream>
#include <thread>
using namespace std;

void proceso1(){
    for(int a = 0; a < 100; a++)
        cout << "proceso1: " << a << endl;
}

void proceso2(){
    for(int a = 0; a < 100; a++)
        cout << "proceso2: " << a << endl;
}

int main() {
    
    int n = 3;
    thread t1(proceso1);
    thread t2(proceso2);
    
    t1.join();
    t2.join();
    
    return 0;
}
