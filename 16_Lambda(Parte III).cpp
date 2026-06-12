#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

int main() {
    
    //Hay dos formas de usar templates con lambda: con typename y con auto
    /*
    auto suma = []<typename T>(T a, T b){
        return a + b;
    };
    */
    auto suma = [](auto a, auto b){
        return a + b;
    };
    cout << suma(5.6,6.1) << endl;
    
    string str1 = "C++ ";
    string str2 = "20";
    cout << suma(str1,str2) << endl;
    
    auto p1 = make_unique<int>(5);
    auto p2 = make_unique<int>(6);
    
    auto suma_p = [ptr1=move(p1),ptr2=move(p2)](){
        return *ptr1 + *ptr2;
    };
    cout << suma_p() << endl;
    
    return 0;
}
