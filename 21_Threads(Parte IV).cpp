#include <iostream>
#include <thread>
using namespace std;

void suma(int* ini, int* fin, int& suma){
    for(int* p = ini; p <= fin; p++)
        suma += *p;
}

int main() {
    
    int ar[1000];
    for(int i = 0; i < 1000; i++)
        ar[i] = 1;
    
    int* p1 = ar;
    int* p2 = ar + 499;
    int* p3 = ar + 999;
    int res1 = 0;
    int res2 = 0;
    
    thread t1(suma,p1,p2,ref(res1));
    thread t2(suma,p2+1,p3,ref(res2));
    t1.join();
    t2.join();
    cout << "Total: " << res1 + res2 << endl;
    
    return 0;
}
