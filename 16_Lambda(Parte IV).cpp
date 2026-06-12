#include <iostream>
#include <functional>
using namespace std;

int main() {
    
    function<int(int)> funcioneslambda[3] = {
        [](int x){return x*2;},
        [](int x){return x*3;},
        [](int x){return x*4;}
    };
    
    cout << (funcioneslambda[0])(3) << endl;
    
    return 0;
}
