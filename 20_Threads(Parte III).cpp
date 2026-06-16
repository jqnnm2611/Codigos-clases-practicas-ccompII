#include <iostream>
#include <thread>
using namespace std;

void incrementar(int& contador){
    for(int i = 0; i < 100; i++){
        contador ++;
        cout << "Incrementando a: " << contador << endl;
    }
}

int main() {
    
    int valor = 0;
    thread t(incrementar, ref(valor));
    t.join();
    cout << "Valor final: " << valor << endl;
    
    return 0;
}
