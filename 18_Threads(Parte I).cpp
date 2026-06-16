#include <iostream>
#include <thread>
using namespace std;

class print{
    public:
    void operator()(int n){
        cout << n << endl;
    }
};

int main() {
    
    int n = 3;
    /*thread t([](int n){    //con lambda
        cout << n << endl;
    }, n);*/
    //print p; //para usar el functor o también puede ser print()
    thread t(print(), n);
    
    t.join();
    
    return 0;
}
